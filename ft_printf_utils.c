/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 00:50:31 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/11/24 02:01:17 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdarg.h>
#include "ft_printf.h"
#include "libft/libft.h"

void	ft_printf_char(t_fmt *fmt)
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

void	ft_printf_str(t_fmt *fmt)
{
	int			len;
	const char	*str = va_arg(fmt->args, char *);

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
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
		ft_putnstr_fd((char *)str, fmt->precision, 1);
	}
}

void	ft_printf_ptr(t_fmt *fmt)
{
	const long long	n = va_arg(fmt->args, long long) + ULONG_MAX + 1;
	const int		len = ft_unumlen(n, 16) + 2;

	if (fmt->width > len)
		fmt->offset = fmt->width - len;
	fmt->len += fmt->offset + len;
	if (fmt->minus)
	{
		ft_putstr_fd("0x", 1);
		ft_putunbr_base_fd(n, 16, 1);
		while (fmt->offset--)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (fmt->offset--)
			ft_putchar_fd(' ', 1);
		ft_putstr_fd("0x", 1);
		ft_putunbr_base_fd(n, 16, 1);
	}
}

void	ft_printf_int(t_fmt *fmt)
{
	const int	n = va_arg(fmt->args, int);
	const int	len = ft_numlen(n, 10);
	const int	alen = ft_unumlen(ft_abs(n), 10);

	if (fmt->precision > alen)
		fmt->pad = fmt->precision - alen;
	if (fmt->zero && n < 0 && fmt->pad)
		--fmt->pad;
	if (fmt->width > fmt->pad + len)
		fmt->offset = fmt->width - fmt->pad - len;
	if ((fmt->space || fmt->plus) && n >= 0 && ++fmt->len && fmt->offset)
		--fmt->offset;
	fmt->len += fmt->offset + fmt->pad + len;
	if (fmt->minus)
	{
		ft_putfnbr_base_fd(n, 10, fmt, 1);
		while (fmt->offset--)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (fmt->offset--)
			ft_putchar_fd(' ', 1);
		ft_putfnbr_base_fd(n, 10, fmt, 1);
	}
}

void	ft_printf_uint(char c, int base, t_fmt *fmt)
{
	const unsigned int	n = va_arg(fmt->args, unsigned int);
	const int			len = ft_unumlen(n, base);

	if (c == 'X')
		fmt->upper = 1;
	if (fmt->hashtag && n > 0)
		fmt->len += 2;
	if (fmt->precision > len)
		fmt->pad = fmt->precision - len;
	if (fmt->width > fmt->pad + len)
		fmt->offset = fmt->width - fmt->pad - len;
	fmt->len += fmt->offset + fmt->pad + len;
	if (fmt->minus)
	{
		ft_putfnbr_base_fd(n, base, fmt, 1);
		while (fmt->offset--)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (fmt->offset--)
			ft_putchar_fd(' ', 1);
		ft_putfnbr_base_fd(n, base, fmt, 1);
	}
}
