/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 00:50:31 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/07/31 02:04:11 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "ft_printf.h"

void	ft_putfnbr_fd(int n, t_format *fmt, int fd);

void	ft_print_char(t_format *fmt)
{
	int			offset;
	const char	c = va_arg(fmt->args, int);

	offset = 0;
	if (fmt->width && fmt->width > fmt->precision)
		offset = fmt->width - 1;
	fmt->count += offset + 1;
	if (fmt->minus)
	{
		ft_putchar_fd(c, 1);
		while (offset--)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (offset--)
			ft_putchar_fd(' ', 1);
		ft_putchar_fd(c, 1);
	}
}

void	ft_print_str(t_format *fmt)
{
	int			offset;
	const char	*str = va_arg(fmt->args, char *);
	const int	len = ft_strlen(str);

	offset = 0;
	if (!fmt->dot || fmt->precision > len)
		fmt->precision = len;
	if (fmt->width && fmt->width > fmt->precision)
		offset = fmt->width - fmt->precision;
	fmt->count += fmt->precision + offset;
	if (fmt->minus)
	{
		ft_putstr_fd((char *)str, 1);
		while (offset--)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (offset--)
			ft_putchar_fd(' ', 1);
		ft_putstrn_fd((char *)str, fmt->precision, 1);
	}
}

void	ft_print_ptr(t_format *fmt)
{
	int				offset;
	const long long	num = va_arg(fmt->args, long long) + ULONG_MAX + 1;
	const int		len = ft_unumlen(num, 16) + 2;

	offset = 0;
	if (fmt->width && fmt->width > len)
		offset = fmt->width - len;
	fmt->count += len + offset;
	if (fmt->minus)
	{
		ft_putstr_fd("0x", 1);
		ft_putnbr_base_fd(num, 16, 1);
		while (offset--)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (offset--)
			ft_putchar_fd(' ', 1);
		ft_putstr_fd("0x", 1);
		ft_putnbr_base_fd(num, 16, 1);
	}
}

void	ft_print_int(t_format *fmt)
{
	const int	num = va_arg(fmt->args, int);
	const int	len = ft_numlen(num, 10, false);
	const int	alen = ft_numlen(num, 10, true);

	if (fmt->precision > alen)
		fmt->lead = fmt->precision - alen;
	if (fmt->zero && num < 0 && fmt->lead)
		--fmt->lead;
	if (fmt->width > fmt->lead + len)
		fmt->offset = fmt->width - fmt->lead - len;
	if ((fmt->space || fmt->plus) && num >= 0 && ++fmt->count && fmt->offset)
		--fmt->offset;
	fmt->count += fmt->offset + fmt->lead + len;
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

void	ft_print_uint(char c, t_format *fmt)
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
	fmt->count += count;
}
