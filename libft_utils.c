/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 21:45:27 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/08/03 02:08:05 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static void	ft_reset(t_fmt *fmt)
{
	fmt->hashtag = false;
	fmt->space = false;
	fmt->plus = false;
}

unsigned int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_unumlen(unsigned long long n, int base)
{
	if (!(n / base))
		return (1);
	return (1 + ft_unumlen(n / base, base));
}

void	ft_putunbr_base_fd(unsigned long long n, int base, int fd)
{
	const char	*digits = "0123456789abcdef";

	if (n / base)
		ft_putunbr_base_fd(n / base, base, fd);
	ft_putchar_fd(digits[n % base], fd);
}

void	ft_putfnbr_base_fd(long long n, int base, t_fmt *fmt, int fd)
{
	int			sign;
	const char	*digits = "0123456789abcdef";

	sign = 1;
	if (n < 0)
	{
		sign = -1;
		ft_putchar_fd('-', fd);
	}
	else if (n > 0 && fmt->hashtag && fmt->upper)
		ft_putstr_fd("0X", 1);
	else if (n > 0 && fmt->hashtag && !fmt->upper)
		ft_putstr_fd("0x", 1);
	else if (fmt->space)
		ft_putchar_fd(' ', fd);
	else if (fmt->plus)
		ft_putchar_fd('+', fd);
	if (fmt->upper)
		digits = "0123456789ABCDEF";
	while (fmt->pad-- > 0)
		ft_putchar_fd('0', fd);
	ft_reset(fmt);
	if (n / base)
		ft_putfnbr_base_fd(n / base * sign, base, fmt, fd);
	ft_putchar_fd(digits[n % base * sign], fd);
}
