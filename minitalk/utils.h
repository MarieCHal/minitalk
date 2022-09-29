/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchalard <mchalard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 13:48:53 by mchalard          #+#    #+#             */
/*   Updated: 2022/03/31 17:39:03 by mchalard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdalign.h>
# include <sys/types.h>

void	ft_putstr(char *str);
int		ft_atoi(const char *str);
void	ft_putnbr(int n);
void	ft_putchar(char c);
void	recieved(int signal);

#endif
