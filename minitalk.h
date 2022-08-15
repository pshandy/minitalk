/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:41:07 by pshandy           #+#    #+#             */
/*   Updated: 2022/02/11 14:41:08 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

void	add_char(char **message, char c);
void	init(int pid, char *str, int *_pid, char **_str);
void	ft_putchar1(char c);
void	ft_putnbr(int nb);
void	ft_putstr(char *str);
int		is_numeric(char *str);
int		ft_atoi(const char *nptr);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
void	quit(char *str);

#endif
