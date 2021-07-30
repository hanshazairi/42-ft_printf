/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 00:57:57 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/07/31 02:29:44 by hbaddrul         ###   ########.fr       */
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
	if (c == '-')
		fmt->minus = 1;
	else if (ft_isdigit(c))
		fmt->width = fmt->width * 10 + c - '0';
}

char	*ft_process(char *str, t_format *fmt)
{
	int		count;

	count = 0;
	while (*str && !ft_istype(*str))
		ft_subprocess(*str++, fmt);
	if (*str == 'c')
		ft_print_char(fmt);
	else if (*str == 's')
		ft_print_str(fmt);
	else if (*str == 'p')
		ft_print_ptr(fmt);
	else if (*str == 'd' || *str == 'i' || *str == 'u' || *str == 'x'
		|| *str == 'X')
		ft_print_int(*str, fmt);
	else if (*str == '%' && ++count)
		ft_putchar_fd(*str, 1);
	fmt->count += count;
	return (++str);
}
