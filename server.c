/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 21:01:47 by kogitsu           #+#    #+#             */
/*   Updated: 2023/04/19 21:51:33 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void	func(int signum)
{
	printf("%dというPIDを受け取った\n", signum);
	exit(0);
}

int	main(void)
{
	pid_t	my_pid;
	int		num;

	num = 1234;
	my_pid = getpid();
	printf("my_pid=%d\n", (int)my_pid);
	signal(my_pid, func);
	while (1)
	{
		sleep(1);
	}
	return (0);
}
