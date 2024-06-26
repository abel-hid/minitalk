/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 16:17:06 by abel-hid          #+#    #+#             */
/*   Updated: 2023/01/01 16:17:09 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <unistd.h>

void	ft_putstr(char *s);
int		ft_atoi(char *str);
void	ft_segaction(int signum, siginfo_t *info, void *context);
void	send_message(char *str, int pid);
void	ft_print_char(char c);
void	ft_putnbr(int nb);
void	ft_putchar(char c);

#endif
