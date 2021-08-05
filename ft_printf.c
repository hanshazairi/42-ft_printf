/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 15:08:22 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/08/05 13:47:39 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "ft_printf.h"

char	*ft_process(char *str, t_fmt *fmt);

static void	ft_reset(t_fmt *fmt)
{
	fmt->offset = 0;
	fmt->pad = 0;
	fmt->width = 0;
	fmt->precision = 0;
	fmt->hashtag = 0;
	fmt->zero = 0;
	fmt->minus = 0;
	fmt->space = 0;
	fmt->plus = 0;
	fmt->dot = 0;
	fmt->upper = 0;
}

static void	ft_init(t_fmt *fmt)
{
	fmt->len = 0;
	ft_reset(fmt);
}

int	ft_printf(const char *str, ...)
{
	int		ret;
	t_fmt	*fmt;

	ret = 0;
	fmt = malloc(sizeof(t_fmt));
	if (!fmt)
		return (-1);
	ft_init(fmt);
	va_start(fmt->args, str);
	while (*str)
	{
		if (*str == '%' && *str++)
		{
			str = ft_process((char *)str, fmt);
			ft_reset(fmt);
		}
		else if (++ret)
			ft_putchar_fd(*str++, 1);
	}
	va_end(fmt->args);
	ret += fmt->len;
	free(fmt);
	return (ret);
}
