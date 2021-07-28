/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 15:08:22 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/07/28 21:55:40 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>
#include "libft/libft.h"

#include <stdio.h>

int	ft_printf(const char *str, ...)
{
	int			num;
	char		*s;
	char		*tmp;
	va_list		ap;
	long long	llnum;

	va_start(ap, str);
	while (*str)
	{
		if (*str == '%' && *str++)
		{
			if (*str == 'c')
				ft_putchar_fd(va_arg(ap, int), 1);
			else if (*str == 's')
				ft_putstr_fd(va_arg(ap, char *), 1);
			else if (*str == 'p')
			{
				s = ft_itoa_base(va_arg(ap, long long), 16);
				tmp = s;
				s = ft_strjoin("0x", s);
				free(tmp);
				ft_putstr_fd(s, 1);
				free(s);
			}
			else if (*str == 'd')
			{
				s = ft_itoa(va_arg(ap, int));
				ft_putstr_fd(s, 1);
				free(s);
			}
			else if (*str == '%')
				ft_putchar_fd('%', 1);
			++str;
		}
		else
			ft_putchar_fd(*str++, 1);
	}
	va_end(ap);
	return (0);
}

int	main(void)
{
	int		num;
	char	*str;

	num = INT_MAX;
	str = "Hello World!";
	printf("%c %s %d %p %%\n", str[0], str, num, str);
	ft_printf("%c %s %d %p %%\n", str[0], str, num, str);
	return (0);
}
