/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 09:40:12 by ndonaire          #+#    #+#             */
/*   Updated: 2022/11/14 13:30:45 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_char_count(const char *str, char c)
{
	int	i;
	int	cont;

	i = 0;
	cont = 0;
	while (*str)
	{
		if (*str != c && cont == 0)
		{
			cont = 1;
			i++;
		}
		else if (*str == c)
			cont = 0;
		str++;
	}
	return (i);
}

static size_t	ft_strclen(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	return (len);
}

char	**ft_free(char **x, int pos)
{
	char	**aux;

	aux = 0;
	while (pos >= 0)
	{
		free(x[pos]);
		pos--;
	}
	free(x);
	return (aux);
}

char	**ft_reserva(const char *s, char c)
{
	char	**aux;

	aux = malloc(sizeof(char **) * (ft_char_count(s, c) + 1));
	if (!aux)
		return (NULL);
	return (aux);
}

char	**ft_split(char const *s, char c)
{
	size_t	charlen[2];
	char	**x;

	charlen[1] = 0;
	if (!s)
		return (NULL);
	x = ft_reserva(s, c);
	if (!x)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			charlen[0] = ft_strclen(s, c);
			x[charlen[1]] = (char *)ft_calloc(charlen[0] + 1, sizeof(char));
			if (!x[charlen[1]])
				return (ft_free(x, charlen[1]));
			ft_memcpy(x[charlen[1]++], s, charlen[0]);
			s += charlen[0];
		}
	}
	x[charlen[1]] = NULL;
	return (x);
}
