/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 15:09:33 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/08/03 20:56:06 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdbool.h>

typedef struct s_fmt
{
	int		len;
	int		offset;
	int		pad;
	int		width;
	int		precision;
	bool	hashtag;
	bool	zero;
	bool	minus;
	bool	space;
	bool	plus;
	bool	dot;
	bool	upper;
	va_list	args;
}	t_fmt;

int	ft_printf(const char *str, ...);

#endif
