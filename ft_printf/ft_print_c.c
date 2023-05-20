/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:20:23 by kogitsu           #+#    #+#             */
/*   Updated: 2023/02/26 14:01:18 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_c(const char **fmt, int *n, va_list *ap)
{
	char	c;
	int		putsize;

	c = (char)va_arg(*ap, int);
	putsize = ft_putchar(c);
	if (putsize == -1)
		*n = -1;
	else
		*n += putsize;
	(*fmt)++;
}
