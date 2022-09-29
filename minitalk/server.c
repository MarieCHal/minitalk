/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchalard <mchalard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 13:12:10 by mchalard          #+#    #+#             */
/*   Updated: 2022/03/31 17:59:35 by mchalard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	get_pid(int signal)
{
	static int	pid = 0;
	static int	i = 0;

	if (signal == SIGUSR1)
		pid |= 1 << i;
	i++;
	if (i == 16)
	{
		usleep(85);
		kill(pid, SIGUSR1);
		i = 0;
		pid = 0;
		return (1);
	}
	return (0);
}

int	write_mess(int signal)
{
	static char	c = 0;
	static int	i = 0;

	if (signal == SIGUSR1)
		c += 1 << i;
	i++;
	if (i == 8)
	{
		if (c == '\0')
		{
			ft_putchar('\n');
			i = 0;
			c = 0;
			return (1);
		}
		else
		{
			ft_putchar(c);
			i = 0;
			c = 0;
		}
	}
	return (0);
}

void	get_mess(int signal)
{
	static int	end = 0;
	static int	count = 0;

	if (end == 1)
	{
		if (get_pid(signal) == 1)
		{
			end = 0;
			count = 1;
		}
	}
	if (end == 0 && count == 0)
	{
		if (write_mess(signal) == 1)
			end = 1;
	}
	if (count == 1)
		count = 0;
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putstr("Server PID: ");
	ft_putnbr(pid);
	ft_putchar('\n');
	signal(SIGUSR1, get_mess);
	signal(SIGUSR2, get_mess);
	while (1)
		;
	return (0);
}
