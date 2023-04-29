/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 21:01:47 by kogitsu           #+#    #+#             */
/*   Updated: 2023/04/27 14:21:05 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

void	func(int signum)
{
	static int count = 0;
	static unsigned char buffer[MAX_BUFFER_SIZE];
	static int buffer_idx = 0;
	
	if (signum == SIGUSR1)
		buffer[buffer_idx] = (buffer[buffer_idx] << 1) | 0;
	else if (signum == SIGUSR2)
		buffer[buffer_idx] = (buffer[buffer_idx] << 1) | 1;
	count++;
	if (count == 8)
	{
		buffer_idx++;
		if (buffer_idx >= MAX_BUFFER_SIZE)
			exit(1);
		count = 0;
	}
	if (buffer_idx && buffer_idx % 8 == 0)
	{
		write(1, buffer, buffer_idx);
		memset(buffer, 0, MAX_BUFFER_SIZE);
		buffer_idx = 0;
	}
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
