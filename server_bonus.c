/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:09:59 by abel-hid          #+#    #+#             */
/*   Updated: 2023/01/15 19:10:07 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_minitalk.h"

int	determine_bit(int signum)
{
	int	x;

	if (signum == SIGUSR1)
		x = 1;
	else
		x = 0;
	return (x);
}

void	handle_unicode(unsigned char c, siginfo_t *info)
{
	static t_list	unicode;
	static int		client_pid;

	if (client_pid != info->si_pid)
	{
		client_pid = info->si_pid;
		unicode.i = 0;
		unicode.n_bytes = 0;
		ft_bzero(unicode.p, 4);
	}
	if (c >= 194 && c <= 223)
		unicode.n_bytes = 2;
	else if (c >= 224 && c <= 239)
		unicode.n_bytes = 3;
	else if (c >= 240 && c <= 255)
		unicode.n_bytes = 4;
	unicode.p[unicode.i++] = c;
	if (unicode.i == unicode.n_bytes)
	{
		write(1, unicode.p, unicode.n_bytes);
		unicode.i = 0;
		unicode.n_bytes = 0;
		ft_bzero(unicode.p, 4);
	}
}

void	ft_segaction(int signum, siginfo_t *info, void *context)
{
	static unsigned char	c;
	static int				bits;
	static int				client_pid;

	(void)context;
	if (client_pid != info->si_pid)
	{
		client_pid = info->si_pid;
		bits = 0;
		c = 0;
	}
	c += determine_bit(signum);
	bits++;
	if (bits == 8)
	{
		if (c == '\0')
			kill(info->si_pid, SIGUSR1);
		if (c >= 0 && c <= 127)
			ft_putchar(c);
		else
			handle_unicode(c, info);
		c = 0;
		bits = 0;
	}
	c <<= 1;
}

int	main(int ac, char **av)
{
	struct sigaction	sig;
	int					pid;

	(void)av;
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
