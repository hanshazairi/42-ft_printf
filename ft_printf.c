/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 15:08:22 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/07/29 21:12:57 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>
#include "libft/libft.h"

int	ft_process_ptr(va_list ap)
{
	int			count;
	char		*str;
	char		*tmp;
	long long	num;

	num = va_arg(ap, long long);
	str = ft_itoa_base(num, 16);
	if (num < 0)
		num = ULONG_MAX + num + 1;
	tmp = str;
	str = ft_strjoin("0x", str);
	free(tmp);
	ft_putstr_fd(str, 1);
	count = ft_strlen(str);
	free(str);
	return (count);
}

int	ft_process_int(char fmt, va_list ap)
{
	int			count;
	char		*str;
	long long	num;

	count = 0;
	num = va_arg(ap, int);
	if ((fmt == 'd' || fmt == 'i') && num < 0 && ++count)
	{
		num = ULONG_MAX - num + 1;
		ft_putchar_fd('-', 1);
	}
	if ((fmt == 'u' || fmt == 'x' || fmt == 'X') && num < 0)
		num = UINT_MAX + num + 1;
	if (fmt == 'd' || fmt == 'i' || fmt == 'u')
		str = ft_itoa_base(num, 10);
	else if (fmt == 'x' || fmt == 'X')
		str = ft_itoa_base(num, 16);
	if (fmt == 'X')
		str = ft_strupr(str);
	ft_putstr_fd(str, 1);
	count += ft_strlen(str);
	free(str);
	return (count);
}

int	ft_process(char fmt, va_list ap)
{
	int		count;
	char	*str;

	count = 0;
	if (fmt == 'c' && ++count)
		ft_putchar_fd(va_arg(ap, int), 1);
	else if (fmt == 's')
	{
		str = va_arg(ap, char *);
		ft_putstr_fd(str, 1);
		count += ft_strlen(str);
	}
	else if (fmt == 'p')
		count += ft_process_ptr(ap);
	else if (fmt == 'd' || fmt == 'i' || fmt == 'u' || fmt == 'x' || fmt == 'X')
		count += ft_process_int(fmt, ap);
	else if (fmt == '%' && ++count)
		ft_putchar_fd(fmt, 1);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	int			count;
	va_list		ap;

	count = 0;
	va_start(ap, s);
	while (*s)
	{
		if (*s == '%' && *s++)
			count += ft_process(*s++, ap);
		else if (++count)
			ft_putchar_fd(*s++, 1);
	}
	va_end(ap);
	return (count);
}
