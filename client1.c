/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c          	                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:41:07 by pshandy           #+#    #+#             */
/*   Updated: 2022/02/19 16:50:12 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	quit(char *str)
{
	ft_putstr("Error!");
	if (str)
		free(str);
	exit(-1);
}

int	send_null(int pid, char *str)
{
	static int	i = 0;

	if (i++ != 8)
	{
		if (kill(pid, SIGUSR2) == -1)
			quit(str);
		return (0);
	}
	return (1);
}

int	send_bit(int pid, char *str)
{
	static char	*_str = 0;
	static int	_pid = 0;
	static int	bit = -1;

	init(pid, str, &_pid, &_str);
	if (_str[bit / 8] != '\0' && _str[++bit / 8])
	{
		if (_str[bit / 8] & (128 >> (bit % 8)))
		{
			if (kill(_pid, SIGUSR1) == -1)
				quit(_str);
		}
		else if (kill(_pid, SIGUSR2) == -1)
			quit(_str);
		return (0);
	}
	if (!send_null(_pid, _str))
		return (0);
	free(_str);
	return (1);
}

void	handler(int sig)
{
	int	end;

	end = 0;
	if (sig == SIGUSR1)
		end = send_bit(0, 0);
	else if (sig == SIGUSR2)
		exit(-1);
	if (end)
	{
		ft_putstr("Message recieved\n");
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !is_numeric(argv[1]))
	{
		ft_putstr("Usage ./client [pid] [message]\n");
		exit(-1);
	}
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	send_bit(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
}
