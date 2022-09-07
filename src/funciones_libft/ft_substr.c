/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:59:14 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/07 16:50:43 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	x;
	size_t	y;
	char	*s1;

	x = 0;
	y = 0;
	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		return (ft_calloc(1, sizeof(char)));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	s1 = malloc(len + 1);
	if (!s1)
		return (0);
	while (s[x])
	{
		if (x >= start && y < len)
			s1[y++] = s[x];
		x++;
	}
	s1[y] = '\0';
	return (s1);
}
