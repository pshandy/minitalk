/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:41:07 by pshandy           #+#    #+#             */
/*   Updated: 2022/02/11 14:41:08 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
	}
	if (nb <= -10)
	{
		ft_putnbr(-(nb / 10));
		ft_putnbr(-(nb % 10));
	}
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		if (nb < 0)
			nb = -nb;
		ft_putchar('0' + nb);
	}
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

int	is_numeric(char *str)
{
	if (*str)
	{
		while (*str)
		{
			if (!(*str >= '0' && *str <= '9'))
				return (0);
			str++;
		}
		return (1);
	}
	return (0);
}
