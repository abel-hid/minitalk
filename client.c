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

int	ft_atoi(const char *str)
{
	int		i;
	int		n;
	long	result;


	i = 0;
	n = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			n = -1;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + str[i] - 48;
		i++;
	}
	return ((result * n));
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;

	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

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
