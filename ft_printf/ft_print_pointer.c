/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 12:36:50 by kogitsu           #+#    #+#             */
/*   Updated: 2023/02/26 15:09:59 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_put_address(uintptr_t ptr, int *n)
{
	char	*base;

	base = "0123456789abcdef";
	if (ptr > 15)
	{
		ft_put_address(ptr / 16, n);
		ft_put_address(ptr % 16, n);
	}
	else
		*n += ft_putchar(base[ptr]);
}

void	ft_print_pointer(const char **fmt, int *n, va_list *ap)
{
	uintptr_t	ptr;

	ptr = (uintptr_t)va_arg(*ap, uintptr_t);
	*n += ft_putstr("0x");
	ft_put_address(ptr, n);
	(*fmt)++;
}
