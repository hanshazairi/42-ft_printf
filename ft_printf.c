/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 15:08:22 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/08/02 02:51:12 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "ft_printf.h"

char	*ft_process(char *str, t_format *fmt);

static t_format	ft_init(t_format *fmt)
{
	fmt->len = 0;
	fmt->offset = 0;
	fmt->pad = 0;
	fmt->width = 0;
	fmt->precision = 0;
	fmt->zero = false;
	fmt->minus = false;
	fmt->space = false;
	fmt->plus = false;
	fmt->dot = false;
	return (*fmt);
}

static t_format	ft_reset(t_format *fmt)
{
	fmt->offset = 0;
	fmt->pad = 0;
	fmt->width = 0;
	fmt->precision = 0;
	fmt->zero = false;
	fmt->minus = false;
	fmt->space = false;
	fmt->plus = false;
	fmt->dot = false;
	return (*fmt);
}

int	ft_printf(const char *str, ...)
{
	int			ret;
	t_format	*fmt;

	ret = 0;
	fmt = malloc(sizeof(t_format));
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
