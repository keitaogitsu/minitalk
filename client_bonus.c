/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:29:47 by kogitsu           #+#    #+#             */
/*   Updated: 2023/05/20 16:30:20 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

void	bit_sending(char c, int p_id)
{
	unsigned int	n;
	unsigned int	specific_digit;

	n = 7;
	while (1)
	{
		specific_digit = (unsigned int)1 << n;
		if ((c & specific_digit) == 0)
			kill((pid_t)p_id, SIGUSR1);
		else
			kill((pid_t)p_id, SIGUSR2);
		if (n == 0)
			break ;
		n--;
		usleep(50);
	}
}

int	main(int argc, char *argv[])
{
	int		p_id;
	char	*str;

	if (argc != 3)
		ft_printf("エラー：引数は３つです。\n");
	else
	{
		p_id = ft_atoi(argv[1]);
		str = argv[2];
		while (*str)
		{
			bit_sending(*str, p_id);
			usleep(200);
			str++;
		}
	}
	return (0);
}
