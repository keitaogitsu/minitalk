/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:34:56 by kogitsu           #+#    #+#             */
/*   Updated: 2023/02/26 16:58:42 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putunnbr(unsigned int num, int *n)
{
	if (num > 9)
	{
		ft_putunnbr(num / 10, n);
		ft_putunnbr(num % 10, n);
	}
	else
		*n += ft_putchar((char)(num + '0'));
}

void	ft_print_unint(const char **fmt, int *n, va_list *ap)
{
	unsigned int	num;

	num = (unsigned int)va_arg(*ap, unsigned int);
	ft_putunnbr(num, n);
	(*fmt)++;
}
