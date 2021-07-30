/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 00:50:31 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/07/30 18:08:56 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "ft_printf.h"

static void	ft_process_ptr(t_format *fmt)
{
	int			count;
	char		*str;
	char		*tmp;
	long long	num;

	num = va_arg(fmt->args, long long);
	str = ft_itoa_base(num, 16);
	if (num < 0)
		num = ULONG_MAX + num + 1;
	tmp = str;
	str = ft_strjoin("0x", str);
	free(tmp);
	ft_putstr_fd(str, 1);
	count = ft_strlen(str);
	free(str);
	fmt->count += count;
}

static void	ft_process_int(char s, t_format *fmt)
{
	int			count;
	char		*str;
	long long	num;

	count = 0;
	num = va_arg(fmt->args, int);
	if ((s == 'd' || s == 'i') && num < 0 && ++count)
	{
		num = ULONG_MAX - num + 1;
		ft_putchar_fd('-', 1);
	}
	if ((s == 'u' || s == 'x' || s == 'X') && num < 0)
		num = UINT_MAX + num + 1;
	if (s == 'd' || s == 'i' || s == 'u')
		str = ft_itoa_base(num, 10);
	else if (s == 'x' || s == 'X')
		str = ft_itoa_base(num, 16);
	if (s == 'X')
		str = ft_strupr(str);
	ft_putstr_fd(str, 1);
	count += ft_strlen(str);
	free(str);
	fmt->count += count;
}

void	ft_process(char s, t_format *fmt)
{
	int		count;
	char	*str;

	count = 0;
	if (s == 'c' && ++count)
		ft_putchar_fd(va_arg(fmt->args, int), 1);
	else if (s == 's')
	{
		str = va_arg(fmt->args, char *);
		ft_putstr_fd(str, 1);
		count += ft_strlen(str);
	}
	else if (s == 'p')
		ft_process_ptr(fmt);
	else if (s == 'd' || s == 'i' || s == 'u' || s == 'x' || s == 'X')
		ft_process_int(s, fmt);
	else if (s == '%' && ++count)
		ft_putchar_fd(s, 1);
	fmt->count += count;
}
