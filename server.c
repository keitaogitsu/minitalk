/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 21:01:47 by kogitsu           #+#    #+#             */
/*   Updated: 2023/04/22 17:19:24 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void	func1(int signum)
{
	printf("0\n");
}

void	func2(int signum)
{
	printf("1\n");
}

int	main(void)
{
	pid_t	my_pid;

	my_pid = getpid();
	printf("my_pid=%d\n", (int)my_pid);
	signal(SIGUSR1, func1);
	signal(SIGUSR2, func2);
	while (1)
	{
		pause();
	}
	return (0);
}
