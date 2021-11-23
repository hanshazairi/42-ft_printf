/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 15:09:33 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/11/24 01:51:39 by hbaddrul         ###   ########.fr       */
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

/* ft_printf.c */
int		ft_printf(const char *str, ...);

/* ft_printf_utils.c */
void	ft_printf_char(t_fmt *fmt);
void	ft_printf_str(t_fmt *fmt);
void	ft_printf_ptr(t_fmt *fmt);
void	ft_printf_int(t_fmt *fmt);
void	ft_printf_uint(char c, int base, t_fmt *fmt);

/* libft_utils.c */
void	ft_putnstr_fd(char *s, int len, int fd);
int		ft_unumlen(unsigned long long n, int base);
void	ft_putunbr_base_fd(unsigned long long n, int base, int fd);
void	ft_putfnbr_base_fd(long long n, int base, t_fmt *fmt, int fd);

#endif
