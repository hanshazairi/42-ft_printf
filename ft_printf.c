/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 15:08:22 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/08/02 00:39:43 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "ft_printf.h"

static t_format	ft_init(t_format *fmt)
{
	fmt->offset = 0;
	fmt->count = 0;
	fmt->minus = 0;
	fmt->width = 0;
	fmt->dot = 0;
	fmt->precision = 0;
	fmt->lead = 0;
	fmt->space = 0;
	fmt->plus = 0;
	fmt->zero = 0;
	fmt->pad = ' ';
	return (*fmt);
}

static t_format	ft_reset(t_format *fmt)
{
	fmt->offset = 0;
	fmt->minus = 0;
	fmt->width = 0;
	fmt->dot = 0;
	fmt->precision = 0;
	fmt->lead = 0;
	fmt->space = 0;
	fmt->plus = 0;
	fmt->zero = 0;
	fmt->pad = ' ';
	return (*fmt);
}

int	ft_printf(const char *str, ...)
{
	int			count;
	t_format	*fmt;

	count = 0;
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
		else if (++count)
			ft_putchar_fd(*str++, 1);
	}
	va_end(fmt->args);
	count += fmt->count;
	free(fmt);
	return (count);
}
