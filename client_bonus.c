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

void	char_to_binary(unsigned char c, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & 128)
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(EXIT_FAILURE);
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(EXIT_FAILURE);
		}
		c <<= 1;
		i++;
		pause();
		usleep(200);
	}
}


void	send_message(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
		char_to_binary(str[i++], pid);
		char_to_binary('\0', pid);
}
void sig_handler(int signum)
{
	static int i;

	if(signum == SIGUSR1)
	{
		ft_putstr("DONE");
		exit(EXIT_SUCCESS);


	}
	if(signum == SIGUSR2)
	 i++;

}

int	main(int ac, char **av)
{
	int	server_pid;
	int	client_pid;

	client_pid = getpid();
	if (ac == 3)
	{

		signal(SIGUSR1, sig_handler);
		signal(SIGUSR2, sig_handler);
		server_pid = ft_atoi(av[1]);

		send_message(av[2], server_pid);
	}

	return (EXIT_FAILURE);
}
