/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 15:08:22 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/07/31 19:29:40 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "ft_printf.h"

static t_format	ft_init(t_format *fmt)
{
	fmt->count = 0;
	fmt->minus = 0;
	fmt->width = 0;
	fmt->dot = 0;
	fmt->precision = 0;
	return (*fmt);
}

static t_format	ft_reset(t_format *fmt)
{
	fmt->minus = 0;
	fmt->width = 0;
	fmt->dot = 0;
	fmt->precision = 0;
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
