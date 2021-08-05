/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 15:09:33 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/08/05 14:03:03 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

typedef struct s_fmt
{
	int		len;
	int		offset;
	int		pad;
	int		width;
	int		precision;
	int		hashtag;
	int		zero;
	int		minus;
	int		space;
	int		plus;
	int		dot;
	int		upper;
	va_list	args;
}	t_fmt;

int	ft_printf(const char *str, ...);

#endif
