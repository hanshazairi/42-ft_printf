/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 00:57:57 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/08/02 01:47:43 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static int	ft_istype(char c)
{
	const char	*types = "cspdiuxX%";

	while (*types)
		if (c == *types++)
			return (1);
	return (0);
}

static void	ft_subprocess(char c, t_format *fmt)
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
	else if (c == '-')
		fmt->minus = 1;
	else if (c == '.')
		fmt->dot = 1;
	else if (c == ' ')
		fmt->space = 1;
	else if (c == '+')
		fmt->plus = 1;
}

char	*ft_process(char *str, t_format *fmt)
{
	int	count;

	count = 0;
	while (*str && !ft_istype(*str))
		ft_subprocess(*str++, fmt);
	if (*str == 'c')
		ft_print_char(fmt);
	else if (*str == 's')
		ft_print_str(fmt);
	else if (*str == 'p')
		ft_print_ptr(fmt);
	else if (*str == 'd' || *str == 'i')
		ft_print_int(fmt);
	else if (*str == 'u' || *str == 'x' || *str == 'X')
		ft_print_uint(*str, fmt);
	else if (*str == '%' && ++count)
		ft_putchar_fd(*str, 1);
	fmt->count += count;
	return (++str);
}
