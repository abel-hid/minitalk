/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_minitalk.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 23:38:20 by abel-hid          #+#    #+#             */
/*   Updated: 2023/05/09 23:38:23 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_MINITALK_H
# define BONUS_MINITALK_H

# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <string.h>

typedef struct s_list
{
	int		n_bytes;
	int		i;
	char	p[4];
}			t_list;

void	ft_putstr(char *s);
void	send_message(char *str, int pid);
void	sig_handler(int signum);
void	ft_handle(unsigned char c, siginfo_t *info);
void	ft_segaction(int signum, siginfo_t *info, void *context);
int		main(int ac, char **av);
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	ft_putnbr(int nb);
void	ft_putchar(char c);
size_t	ft_strlen(const char *s);

#endif
