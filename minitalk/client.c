/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchalard <mchalard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 13:14:47 by mchalard          #+#    #+#             */
/*   Updated: 2022/03/31 17:58:14 by mchalard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

//send pid
void	send_pid(pid_t pidserv)
{
	pid_t	pidcli;
	int		i;

	pidcli = getpid();
	i = 0;
	while (i < 16)
	{
		usleep(85);
		if (pidcli & 1)
			kill(pidserv, SIGUSR1);
		else
			kill(pidserv, SIGUSR2);
		pidcli = pidcli >> 1;
		i++;
	}
}

//checks the validity of pid
void	check_pid(char *pid)
{
	int	i;

	i = 0;
	while (pid[i])
	{
		if (pid[i] > 57 || pid[i] < 48)
		{
			ft_putstr("Error PID\n");
			exit(0);
		}
		else
			i++;
	}
}

//sends bit per bit to the server the character (sigusr1 = 1 and sigusr2 = 0)
void	send_char(char c, pid_t pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		usleep(85);
		if (c & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c = c >> 1;
		i++;
	}
}

//sends character per character to send_char
void	send_msg(char *msg, pid_t pid)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		send_char(msg[i], pid);
		i++;
	}
	send_char('\0', pid);
	send_pid(pid);
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
	{
		ft_putstr("Error, invalid number of arguments\n");
		exit(0);
	}
	check_pid(argv[1]);
	pid = ft_atoi(argv[1]);
	send_msg(argv[2], pid);
	signal(SIGUSR1, recieved);
	while (1)
		;
	return (0);
}
