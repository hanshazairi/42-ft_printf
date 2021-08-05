/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 00:57:57 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/08/05 13:52:16 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"
#include "ft_printf.h"

void	ft_printf_char(t_fmt *fmt);
void	ft_printf_str(t_fmt *fmt);
void	ft_printf_ptr(t_fmt *fmt);
void	ft_printf_int(t_fmt *fmt);
void	ft_printf_uint(char c, int base, t_fmt *fmt);

static int	ft_istype(char c)
{
	const char	*types = "cspdiuxX%";

	while (*types)
		if (c == *types++)
			return (1);
	return (0);
}

static void	ft_subprocess(char c, t_fmt *fmt)
{
	if (ft_isdigit(c))
	{
		if (fmt->dot || fmt->zero)
			fmt->precision = fmt->precision * 10 + c - '0';
		else
		{
			if (!fmt->width && c == '0')
				fmt->zero = 1;
			else
				fmt->width = fmt->width * 10 + c - '0';
		}
	}
	else if (c == '#')
		fmt->hashtag = 1;
	else if (c == '-')
		fmt->minus = 1;
	else if (c == ' ')
		fmt->space = 1;
	else if (c == '+')
		fmt->plus = 1;
	else if (c == '.')
		fmt->dot = 1;
}

char	*ft_process(char *str, t_fmt *fmt)
{
	while (*str && !ft_istype(*str))
		ft_subprocess(*str++, fmt);
	if (*str == 'c')
		ft_printf_char(fmt);
	else if (*str == 's')
		ft_printf_str(fmt);
	else if (*str == 'p')
		ft_printf_ptr(fmt);
	else if (*str == 'd' || *str == 'i')
		ft_printf_int(fmt);
	else if (*str == 'u')
		ft_printf_uint(*str, 10, fmt);
	else if (*str == 'x' || *str == 'X')
		ft_printf_uint(*str, 16, fmt);
	else if (*str == '%' && ++fmt->len)
		ft_putchar_fd(*str, 1);
	return (++str);
}
