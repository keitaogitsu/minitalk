/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 21:01:29 by kogitsu           #+#    #+#             */
/*   Updated: 2023/04/22 17:31:56 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void	bit_sending(char c, int p_id)
{
	unsigned int	n;
	unsigned int	specific_digit;

	n = 7;
	while (1)
	{
		// printf("n = %d", n);
		specific_digit = (unsigned int)1 << n;
		if ((c & specific_digit) == 0)
		{

			printf("n = %d, p_id = %d, 0\n", n, p_id);
			kill((pid_t)p_id, SIGUSR1);
		}
		else
		{
			printf("n = %d, p_id = %d, 1\n", n, p_id);
			kill((pid_t)p_id, SIGUSR2);
		}
		if (n == 0)
			break ;
		n--;
		// sleep(1);
	}
}

int	main(int argc, char *argv[])
{
	int		p_id;
	char	*str;

	p_id = atoi(argv[1]);
	str = argv[2];
	while (*str)
	{
		bit_sending(*str, p_id);
		str++;
	}
	return (0);
}
