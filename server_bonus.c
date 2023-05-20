/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:30:05 by kogitsu           #+#    #+#             */
/*   Updated: 2023/05/20 16:30:34 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include "ft_printf/ft_printf.h"

void	func(int signum)
{
	static int				count;
	static unsigned char	buf;

	if (signum == SIGUSR1)
		buf = (buf << 1) | 0x00;
	else if (signum == SIGUSR2)
		buf = (buf << 1) | 0x01;
	count++;
	if (count == 8)
	{
		write(1, &buf, 1);
		count = 0;
		buf = 0;
	}
}

int	main(void)
{
	pid_t	my_pid;

	my_pid = getpid();
	ft_printf("my_pid=%d\n", (int)my_pid);
	signal(SIGUSR1, func);
	signal(SIGUSR2, func);
	while (1)
	{
		pause();
	}
	return (0);
}