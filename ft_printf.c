/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 15:08:22 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/07/29 02:49:17 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>
#include "libft/libft.h"

int	ft_printf(const char *str, ...)
{
	int			count;
	char		*s;
	char		*tmp;
	va_list		ap;
	long long	llnum;

	count = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%' && *str++)
		{
			if (*str == 'c' && ++count)
				ft_putchar_fd(va_arg(ap, int), 1);
			else if (*str == 's')
			{
				s = va_arg(ap, char *);
				ft_putstr_fd(s, 1);
				count += ft_strlen(s);
			}
			else if (*str == 'p')
			{
				s = ft_itoa_base(va_arg(ap, long long), 16);
				tmp = s;
				s = ft_strjoin("0x", s);
				free(tmp);
				ft_putstr_fd(s, 1);
				count += ft_strlen(s);
				free(s);
			}
			else if (*str == 'd' || *str == 'i')
			{
				s = ft_itoa(va_arg(ap, int));
				ft_putstr_fd(s, 1);
				count += ft_strlen(s);
				free(s);
			}
			else if (*str == 'u' || *str == 'x')
			{
				llnum = va_arg(ap, long);
				if (llnum < 0)
					llnum = UINT_MAX + 1 - llnum;
				if (*str == 'u')
					s = ft_itoa_base(llnum, 10);
				else if (*str == 'x')
					s = ft_itoa_base(llnum, 16);
				ft_putstr_fd(s, 1);
				count += ft_strlen(s);
				free(s);
			}
			else if (*str == '%' && ++count)
				ft_putchar_fd('%', 1);
			++str;
		}
		else
		{
			ft_putchar_fd(*str++, 1);
			++count;
		}
	}
	va_end(ap);
	return (count);
}
