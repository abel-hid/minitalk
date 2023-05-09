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
	while (str[j])
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
		usleep(1000);
	}
		j++;
	}
}
void sig_handler(int signum)
{
	static int i;

	if(signum == SIGUSR1)
	{
		ft_putstr("signal was sent successfully");
		exit(EXIT_SUCCESS);
	}
	if(signum == SIGUSR2)
	 i++;

}

int	main(int ac, char **av)
{
	int	server_pid;

	if (ac == 3)
	{

		signal(SIGUSR1, sig_handler);
		signal(SIGUSR2, sig_handler);
		server_pid = ft_atoi(av[1]);

		send_message(av[2], server_pid);
	}

	return (EXIT_FAILURE);
}
