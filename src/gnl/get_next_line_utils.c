/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:40:59 by ndonaire          #+#    #+#             */
/*   Updated: 2022/04/20 13:30:04 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
/*
void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*p;
	unsigned long	i;

	i = 0;
	p = (void *)malloc(nmemb * size);
	if (!p)
		return (0);
	while (i < nmemb * size)
	{
		((char *)p)[i] = '\0';
		i = i + 1;
	}
	return (p);
}

int	lens(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i = i + 1;
	return (i);
}
*/
int	find_nl(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '\n')
		return (1);
	while (s[i] != '\0' && s[i] != '\n')
	{
		i++;
		if (s[i] == '\n')
		{
			return (1);
		}
	}
	return (0);
}
/*
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*x;
	int		i;
	int		y;

	y = 0;
	i = 0;
	x = malloc((lens((char *)s1) + lens((char *)s2) + 1) * sizeof(char));
	if (s1 && s2)
	{
		while (s1[i] != '\0')
		{
			x[i] = s1[i];
			i++;
		}
		while (s2[y] != '\0')
			x[i++] = s2[y++];
		x[i] = '\0';
		return (x);
	}
	return (0);
}
*/
/*
int main()
{
	char *s1 = "holaa";
	char *s2 = malloc(sizeof(char) * 3);
	int i;
	s1 = joinstr(s1, s2);
	i = lens(s2);
	s1[6] = 'c';
	s1[100] = 'f';
	printf("%c", s1[6]);
	system("leaks a.out");
	return (0);
}*/
