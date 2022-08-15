/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:41:07 by pshandy           #+#    #+#             */
/*   Updated: 2022/02/11 14:41:08 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*s;
	char		*d;

	if (src == NULL && dest == NULL)
		return (NULL);
	s = (const char *)src;
	d = (char *)dest;
	while (n--)
		*d++ = *s++;
	return (dest);
}

size_t	ft_strlen(const char *str)
{
	const char	*end;

	end = str;
	while (*end != '\0')
		end++;
	return (end - str);
}

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*result;

	size = ft_strlen(s) + 1;
	result = malloc(size);
	if (result == 0)
		return (0);
	return ((char *)ft_memcpy(result, s, size));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*strc;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return ((char *)s2);
	if (s2 == NULL)
		return ((char *)s1);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	strc = str;
	while (*s1 != '\0')
		*str++ = *s1++;
	while (*s2 != '\0')
		*str++ = *s2++;
	*str = '\0';
	return (strc);
}

void	add_char(char **message, char c)
{
	char	*tmp;
	char	*t;

	tmp = *message;
	t = malloc(sizeof(char) * 2);
	if (!t)
		return ;
	t[0] = c;
	t[1] = '\0';
	*message = ft_strjoin(tmp, t);
	if (tmp != NULL)
	{
		free(t);
		free(tmp);
	}
}
