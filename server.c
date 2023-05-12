/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 21:01:47 by kogitsu           #+#    #+#             */
/*   Updated: 2023/05/08 10:13:20 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 8

void print_bits(unsigned char byte) 
{
	int	a;
    for (int i = 7; i >= 0; i--) {
		a = ((byte >> i) & 1) + '0';
        write(1, &a, 1);
    }
	write(1, ",", 1);
}

void	func(int signum)
{
	static int 				count;
	static unsigned char 	buf[MAX_BUFFER_SIZE];
	static int 				buf_idx;
	int						i;
	static unsigned char	c;
		
	if (signum == SIGUSR1)
		buf[buf_idx] = (buf[buf_idx] << 1) | 0;
	else if (signum == SIGUSR2)
		buf[buf_idx] = (buf[buf_idx] << 1) | 1;
	count++;
	i = 0;
	while (i < MAX_BUFFER_SIZE)
	{
		print_bits(buf[i]);
		i++;
	}
	printf("\n");
	if (count == 8)
	{
		printf("%c:%d\n", buf[buf_idx], buf_idx);
		buf_idx++;
		if (buf_idx >= MAX_BUFFER_SIZE)
			exit(1);
		count = 0;
	}
	i = 0;
	// if (buf_idx)
	// {
	// 	write(1, buf, buf_idx+1);
	// 	memset(buf, 0, MAX_BUFFER_SIZE);
	// 	buf_idx = 0;
	// }
}

int	main(void)
{
	pid_t	my_pid;

	my_pid = getpid();
	printf("my_pid=%d\n", (int)my_pid);
	signal(SIGUSR1, func);
	signal(SIGUSR2, func);
	while (1)
	{
		pause();
	}
	return (0);
}
