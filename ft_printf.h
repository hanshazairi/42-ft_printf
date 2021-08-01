/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 15:09:33 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/08/02 00:39:28 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

typedef struct s_format
{
	va_list	args;
	int		offset;
	int		count;
	int		minus;
	int		width;
	int		dot;
	int		precision;
	int		lead;
	int		space;
	int		plus;
	int		zero;
	char	pad;
}	t_format;

int		ft_printf(const char *str, ...);
char	*ft_process(char *str, t_format *fmt);
void	ft_print_char(t_format *fmt);
void	ft_print_str(t_format *fmt);
void	ft_print_ptr(t_format *fmt);
void	ft_print_int(t_format *fmt);
void	ft_print_uint(char c, t_format *fmt);

#endif
