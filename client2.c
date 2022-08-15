/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client2.c          	                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:41:07 by pshandy           #+#    #+#             */
/*   Updated: 2022/02/11 14:41:08 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	init(int pid, char *str, int *_pid, char **_str)
{
	if (pid)
		*_pid = pid;
	if (str)
	{
		*_str = ft_strdup(str);
		add_char(_str, '\n');
	}
	if (!*_str)
		quit(*_str);
}
