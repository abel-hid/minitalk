/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:09:31 by abel-hid          #+#    #+#             */
/*   Updated: 2023/01/15 19:09:36 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_minitalk.h"


void	send_message(char *str, int pid)
{
	int	j;

	j = 0;
	while (j < (int)strlen(str) + 1)
	{
		int	i;
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
		usleep(500);
	}
		j++;
	}

}
void sig_handler()
{
		ft_putstr("signal was sent successfully");
		exit(1);
}

int	main(int ac, char **av)
{
	int	server_pid;

	if (ac == 3)
	{
		signal(SIGUSR1, sig_handler);
		server_pid = ft_atoi(av[1]);

		send_message(av[2], server_pid);
	}
	while(1)
		pause();

	return (EXIT_FAILURE);
}
