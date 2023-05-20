/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_per.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:01:17 by kogitsu           #+#    #+#             */
/*   Updated: 2023/02/26 16:12:48 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_per(const char **fmt, int *n)
{
	int	putsize;

	putsize = ft_putchar('%');
	if (putsize == -1)
		*n = -1;
	else
		*n += putsize;
	(*fmt)++;
}
