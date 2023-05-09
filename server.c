/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 16:16:54 by abel-hid          #+#    #+#             */
/*   Updated: 2023/01/01 16:16:57 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_print_char(char c)
{
	ft_putchar(c);
	c = 0;
}

int	determine_bit(int signum)
{
	int	x;

	if (signum == SIGUSR1)
		x = 1;
	else
		x = 0;
	return (x);
}

void	ft_segaction(int signum, siginfo_t *info, void *context)
{
	static char	c;
	static int	bit;
	static int	client_pid;
	static int	current_pid;

	(void)context;
	if (!client_pid)
		client_pid = info->si_pid;
	current_pid = info->si_pid;
	if (client_pid != current_pid)
	{
		client_pid = current_pid;
		bit = 0;
		c = 0;
	}
	c += determine_bit(signum);
	bit++;
	if (bit == 8)
	{
		ft_print_char(c);
		bit = 0;
	}
	c <<= 1;
}

int	main(int ac, char **av)
{
	struct sigaction	sig;
	int					pid;

	(void) av;
	if (ac == 1)
	{
		pid = getpid();
		ft_putnbr(pid);
		ft_putchar('\n');
		sig.sa_sigaction = ft_segaction;
		sig.sa_flags = SA_SIGINFO;
		while (1)
		{
			sigaction(SIGUSR1, &sig, 0);
			sigaction(SIGUSR2, &sig, 0);
			pause();
		}
	}
	return (0);
}
