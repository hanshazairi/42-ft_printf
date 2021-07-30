/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 15:08:22 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/07/31 01:11:19 by hbaddrul         ###   ########.fr       */
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
	return (*fmt);
}

static t_format	ft_reset(t_format *fmt)
{
	fmt->minus = 0;
	fmt->width = 0;
	return (*fmt);
}

static int	ft_istype(char c)
{
	const char	*types = "cspdiuxX%";

	while (*types)
		if (c == *types++)
			return (1);
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int			count;
	t_format	*fmt;

	count = 0;
	fmt = malloc(sizeof(t_format));
	if (!fmt)
		return (-1);
	ft_init(fmt);
	va_start(fmt->args, s);
	while (*s)
	{
		if (*s == '%' && *s++)
		{
			while (*s && !ft_istype(*s))
				ft_preprocess(*s++, fmt);
			ft_process(*s++, fmt);
			ft_reset(fmt);
		}
		else if (++count)
			ft_putchar_fd(*s++, 1);
	}
	va_end(fmt->args);
	count += fmt->count;
	free(fmt);
	return (count);
}
