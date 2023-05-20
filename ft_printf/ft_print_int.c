/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:06:49 by kogitsu           #+#    #+#             */
/*   Updated: 2023/02/26 14:58:23 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr(int num, int *n)
{
	if (num < 0)
	{
		if (num == INT_MIN)
		{
			*n += ft_putstr("-2");
			num = 147483648;
		}
		else
		{
			*n += ft_putchar('-');
			num = -num;
		}
	}
	if (num > 9)
	{
		ft_putnbr(num / 10, n);
		ft_putnbr(num % 10, n);
	}
	else
		*n += ft_putchar((char)(num + '0'));
}

void	ft_print_int(const char **fmt, int *n, va_list *ap)
{
	int	num;

	num = (int)va_arg(*ap, int);
	ft_putnbr(num, n);
	(*fmt)++;
}
