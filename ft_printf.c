/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 15:08:22 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/07/28 01:59:59 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "libft/libft.h"

#include <stdio.h>

int	ft_printf(const char *str, ...)
{
	int		num;
	char	*s;
	va_list	ap;

	va_start(ap, str);
	while (*str)
	{
		if (*str == '%' && *str++)
		{
			if (*str == 'c')
			{
				num = va_arg(ap, int);
				ft_putchar_fd(num, 1);
			}
			else if (*str == 's')
			{
				s = va_arg(ap, char *);
				ft_putstr_fd(s, 1);
			}
			else if (*str == 'd')
			{
				num = va_arg(ap, int);
				s = ft_itoa_base(num, 10);
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

	num = -17;
	str = "Hello World!";
	printf("%c %s %d %%\n", str[0], str, num);
	ft_printf("%c %s %d %%\n", str[0], str, num);
	return (0);
}
