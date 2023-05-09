/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 16:16:43 by abel-hid          #+#    #+#             */
/*   Updated: 2023/01/01 16:16:46 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_message(char *str, int pid)
{
	int	j;
	int	i;

	j = 0;
	while (str[j])
	{
		i = 0;
		while (i < 8)
		{
			if ((str[j] << i) & 128)
			{
				if (kill(pid, SIGUSR1) == -1)
					exit(EXIT_FAILURE);
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1)
					exit(EXIT_FAILURE);
			}
			i++;
			usleep(1000);
		}
		j++;
	}
}

int	main(int ac, char **av)
{
	int	server_pid;

	if (ac == 3)
	{
		server_pid = ft_atoi(av[1]);
		send_message(av[2], server_pid);
	}
	else
		ft_putstr("Error");
	return (0);
}
