/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 15:09:33 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/07/31 19:29:31 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

typedef struct s_format
{
	va_list	args;
	int		count;
	int		minus;
	int		width;
	int		dot;
	int		precision;
}	t_format;

int		ft_printf(const char *str, ...);
char	*ft_process(char *str, t_format *fmt);
void	ft_print_char(t_format *fmt);
void	ft_print_str(t_format *fmt);
void	ft_print_ptr(t_format *fmt);
void	ft_print_int(char c, t_format *fmt);

#endif
