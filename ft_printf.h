/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 15:09:33 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/08/02 03:25:23 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

typedef struct s_format
{
	int		len;
	int		offset;
	int		pad;
	int		width;
	int		precision;
	bool	zero;
	bool	minus;
	bool	space;
	bool	plus;
	bool	dot;
	va_list	args;
}	t_format;

int	ft_printf(const char *str, ...);

#endif
