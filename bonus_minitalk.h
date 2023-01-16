#ifndef BONUS_MINITALK_H
#define BONUS_MINITALK_H

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <unistd.h>

void	ft_putstr(char *s);
void	char_to_binary(unsigned char c, int pid);
void	send_message(char *str, int pid);
void	 sig_handler(int signum);
void 	ft_action(char *c, int *client_pid, int *bit);
void 	ft_segaction(int signum, siginfo_t *info, void *context);
int		main(int ac, char **av);
int		ft_atoi(const char *str);


#endif
