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

   //The bitwise OR operator compares each bit of the first operand to the corresponding bit of
   //the second operand. If either bit is 1, then the corresponding result bit is set to 1.
   // Otherwise, the corresponding result bit is set to 0.
   //In this case, the expression (signum == SIGUSR2) will evaluate to either 0
   //(if signum is not equal to SIGUSR2) or 1 (if signum is equal to SIGUSR2).
   //So, if signum is equal to SIGUSR2, the bit in c that corresponds to the least significant bit
   //of (signum == SIGUSR2) (which is 1) will be set to 1.
   //If signum is not equal to SIGUSR2, the corresponding bit in c will remain unchanged.

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
   printf("PID: %d\n", pid);

   sig.sa_sigaction = ft_segaction;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_SIGINFO;

   while (1)
	{
		sigaction(SIGUSR1, &sig, 0);
		sigaction(SIGUSR2, &sig, 0);
		pause();
	}
	return (EXIT_FAILURE);
}
