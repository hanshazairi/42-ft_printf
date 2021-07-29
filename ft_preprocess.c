/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocess.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 00:57:57 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/07/30 01:01:48 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"

typedef struct s_format
{
	va_list	args;
	int		minus;
	int		width;
}	t_format;

void	ft_preprocess(char s, t_format *fmt)
{
	if (s == '-')
		fmt->minus = 1;
	else if (ft_isdigit(s))
		fmt->width = fmt->width * 10 + s - '0';
}
