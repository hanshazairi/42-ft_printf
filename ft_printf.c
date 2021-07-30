/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 15:08:22 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/07/30 16:24:57 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "ft_printf.h"

t_format	ft_initfmt(t_format *fmt)
{
	fmt->minus = 0;
	fmt->width = 0;
	return (*fmt);
}

static int	ft_istype(char c, char *type)
{
	while (*type)
		if (c == *type++)
			return (1);
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int			count;
	char		*types;
	t_format	*fmt;

	count = 0;
	types = "cspdiuxX%";
	fmt = malloc(sizeof(t_format));
	if (!fmt)
		return (-1);
	ft_initfmt(fmt);
	va_start(fmt->args, s);
	while (*s)
	{
		if (*s == '%' && *s++)
		{
			while (*s && !ft_istype(*s, types))
				ft_preprocess(*s++, fmt);
			count += ft_process(*s++, fmt->args);
		}
		else if (++count)
			ft_putchar_fd(*s++, 1);
	}
	va_end(fmt->args);
	return (count);
}
