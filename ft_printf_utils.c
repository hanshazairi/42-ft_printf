/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 00:50:31 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/08/02 03:15:30 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "ft_printf.h"

void	ft_putfnbr_fd(int n, t_format *fmt, int fd);

void	ft_printf_char(t_format *fmt)
{
	const char	c = va_arg(fmt->args, int);

	if (fmt->width > fmt->precision)
		fmt->offset = fmt->width - 1;
	fmt->len += fmt->offset + 1;
	if (fmt->minus)
	{
		ft_putchar_fd(c, 1);
		while (fmt->offset--)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (fmt->offset--)
			ft_putchar_fd(' ', 1);
		ft_putchar_fd(c, 1);
	}
}

void	ft_printf_str(t_format *fmt)
{
	char		*tmp;
	const char	*str = va_arg(fmt->args, char *);
	const int	len = ft_strlen(str);

	if (!fmt->dot || fmt->precision > len)
		fmt->precision = len;
	if (fmt->width > fmt->precision)
		fmt->offset = fmt->width - fmt->precision;
	fmt->len += fmt->offset + fmt->precision;
	if (fmt->minus)
	{
		ft_putstr_fd((char *)str, 1);
		while (fmt->offset--)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (fmt->offset--)
			ft_putchar_fd(' ', 1);
		tmp = ft_substr(str, 0, fmt->precision);
		ft_putstr_fd(tmp, 1);
		free(tmp);
	}
}

void	ft_printf_ptr(t_format *fmt)
{
	const long long	num = va_arg(fmt->args, long long) + ULONG_MAX + 1;
	const int		len = ft_unumlen(num, 16) + 2;

	if (fmt->width > len)
		fmt->offset = fmt->width - len;
	fmt->len += fmt->offset + len;
	if (fmt->minus)
	{
		ft_putstr_fd("0x", 1);
		ft_putnbr_base_fd(num, 16, 1);
		while (fmt->offset--)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (fmt->offset--)
			ft_putchar_fd(' ', 1);
		ft_putstr_fd("0x", 1);
		ft_putnbr_base_fd(num, 16, 1);
	}
}

void	ft_printf_int(t_format *fmt)
{
	const int	num = va_arg(fmt->args, int);
	const int	len = ft_numlen(num, 10, false);
	const int	alen = ft_numlen(num, 10, true);

	if (fmt->precision > alen)
		fmt->pad = fmt->precision - alen;
	if (fmt->zero && num < 0 && fmt->pad)
		--fmt->pad;
	if (fmt->width > fmt->pad + len)
		fmt->offset = fmt->width - fmt->pad - len;
	if ((fmt->space || fmt->plus) && num >= 0 && ++fmt->len && fmt->offset)
		--fmt->offset;
	fmt->len += fmt->offset + fmt->pad + len;
	if (fmt->minus)
	{
		ft_putfnbr_fd(num, fmt, 1);
		while (fmt->offset--)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (fmt->offset--)
			ft_putchar_fd(' ', 1);
		ft_putfnbr_fd(num, fmt, 1);
	}
}

void	ft_printf_uint(char c, t_format *fmt)
{
	int			count;
	char		*str;
	long long	num;

	count = 0;
	num = va_arg(fmt->args, int);
	if ((c == 'd' || c == 'i') && num < 0 && ++count)
	{
		num = ULONG_MAX - num + 1;
		ft_putchar_fd('-', 1);
	}
	if ((c == 'u' || c == 'x' || c == 'X') && num < 0)
		num = UINT_MAX + num + 1;
	if (c == 'd' || c == 'i' || c == 'u')
		str = ft_itoa_base(num, 10);
	else if (c == 'x' || c == 'X')
		str = ft_itoa_base(num, 16);
	if (c == 'X')
		str = ft_strupr(str);
	ft_putstr_fd(str, 1);
	count += ft_strlen(str);
	free(str);
	fmt->len += count;
}
