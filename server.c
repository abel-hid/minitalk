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


void ft_action(char *c, int *client_pid, int *bit)
{

    ft_putstr(c);

   if(*c == '\0')
   {
      *c = 0;

      if (kill(*client_pid, SIGUSR1) == -1)
        exit(EXIT_FAILURE);
   }
   *bit = 0;

}

void ft_segaction(int signum, siginfo_t *info, void *context)
{
   static char	c;
	static int	bit;
   static int client_pid;
   static int  current_pid;

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
   c |= (signum == SIGUSR2);
   bit++; 
   if(bit == 8)

      ft_action(&c,&client_pid,&bit);

   c <<=1;
   usleep(100);

   kill(client_pid ,SIGUSR2);

}
int main(void)
{
   struct sigaction sig;

   int pid;


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
	return (EXIT_FAILURE);
}
