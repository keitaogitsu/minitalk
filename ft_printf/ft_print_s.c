/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:16:49 by kogitsu           #+#    #+#             */
/*   Updated: 2023/02/26 16:46:34 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_s(const char **fmt, int *n, va_list *ap)
{
	char	*s;
	int		len;
	int		putsize;

	s = (char *)va_arg(*ap, char *);
	if (s == NULL)
	{
		*n += ft_putstr("(null)");
		(*fmt)++;
	}		
	else
	{
		len = (int)ft_strlen(s);
		putsize = write(1, s, len);
		if (putsize == -1)
			*n = -1;
		else
			*n += putsize;
		(*fmt)++;
	}
}		
