#ifndef BONUS_MINITALK_H
#define BONUS_MINITALK_H

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

 typedef struct s_list
 {
	int n_bytes;
	int i;
	char p[4];
 }		t_list;

void	ft_putstr(char *s);
void	char_to_binary(char c, int pid);
void	send_message(char *str, int pid);
void	sig_handler(int signum);
void	ft_handle(unsigned char c, siginfo_t *info);
void 	ft_segaction(int signum, siginfo_t *info, void *context);
int		main(int ac, char **av);
int		ft_atoi(const char *str);
void	ft_putnbr(int nb);
void	ft_putchar(char c);


#endif
