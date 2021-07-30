/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 00:50:31 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/07/30 17:03:29 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "ft_printf.h"

static int	ft_process_ptr(t_format *ap)
{
	int			count;
	char		*str;
	char		*tmp;
	long long	num;

	num = va_arg(ap->args, long long);
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

static int	ft_process_int(char fmt, t_format *ap)
{
	int			count;
	char		*str;
	long long	num;

	count = 0;
	num = va_arg(ap->args, int);
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

int	ft_process(char fmt, t_format *ap)
{
	int		count;
	char	*str;

	count = 0;
	if (fmt == 'c' && ++count)
		ft_putchar_fd(va_arg(ap->args, int), 1);
	else if (fmt == 's')
	{
		str = va_arg(ap->args, char *);
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
