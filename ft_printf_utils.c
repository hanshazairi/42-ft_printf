/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 00:50:31 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/08/03 20:54:26 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "ft_printf.h"

unsigned int	ft_abs(int n);
int				ft_unumlen(unsigned long long n, int base);
void			ft_putunbr_base_fd(unsigned long long n, int base, int fd);
void			ft_putfnbr_base_fd(long long n, int base, t_fmt *fmt, int fd);

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
	char		*tmp;
	const char	*str = va_arg(fmt->args, char *);
	const int	len = ft_strlen(str);

	if (!fmt->dot || fmt->precision > len)
		fmt->precision = len;
	if (fmt->width > fmt->precision)
		fmt->offset = fmt->width - fmt->precision;
	fmt->len += fmt->offset + fmt->precision;
	if (!str)
		ft_putstr_fd("(null)", 1);
	else if (fmt->minus)
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

void	ft_printf_ptr(t_fmt *fmt)
{
	const long long	num = va_arg(fmt->args, long long) + ULONG_MAX + 1;
	const int		len = ft_unumlen(num, 16) + 2;

	if (fmt->width > len)
		fmt->offset = fmt->width - len;
	fmt->len += fmt->offset + len;
	if (fmt->minus)
	{
		ft_putstr_fd("0x", 1);
		ft_putunbr_base_fd(num, 16, 1);
		while (fmt->offset--)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (fmt->offset--)
			ft_putchar_fd(' ', 1);
		ft_putstr_fd("0x", 1);
		ft_putunbr_base_fd(num, 16, 1);
	}
}

void	ft_printf_int(t_fmt *fmt)
{
	const int	num = va_arg(fmt->args, int);
	const int	len = ft_numlen(num, 10);
	const int	alen = ft_numlen(ft_abs(num), 10);

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
		ft_putfnbr_base_fd(num, 10, fmt, 1);
		while (fmt->offset--)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (fmt->offset--)
			ft_putchar_fd(' ', 1);
		ft_putfnbr_base_fd(num, 10, fmt, 1);
	}
}

void	ft_printf_uint(char c, int base, t_fmt *fmt)
{
	const unsigned int	num = va_arg(fmt->args, unsigned int);
	const int			len = ft_unumlen(num, base);

	if (c == 'X')
		fmt->upper = true;
	if (fmt->hashtag && num > 0)
		fmt->len += 2;
	if (fmt->precision > len)
		fmt->pad = fmt->precision - len;
	if (fmt->width > fmt->pad + len)
		fmt->offset = fmt->width - fmt->pad - len;
	fmt->len += fmt->offset + fmt->pad + len;
	if (fmt->minus)
	{
		ft_putfnbr_base_fd(num, base, fmt, 1);
		while (fmt->offset--)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (fmt->offset--)
			ft_putchar_fd(' ', 1);
		ft_putfnbr_base_fd(num, base, fmt, 1);
	}
}
