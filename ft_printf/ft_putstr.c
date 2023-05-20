/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:23:33 by kogitsu           #+#    #+#             */
/*   Updated: 2023/02/26 15:16:21 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_putstr(char *s)
{
	size_t	i;
	int		putchar;
	int		putsize;

	i = 0;
	putsize = 0;
	while (s[i])
	{
		putchar = ft_putchar(s[i]);
		if (putchar == -1)
		{
			putsize = -1;
			break ;
		}
		else
			putsize += putchar;
		i++;
	}
	return (putsize);
}
