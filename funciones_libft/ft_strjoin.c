/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:59:36 by sasalama          #+#    #+#             */
/*   Updated: 2022/08/24 10:59:37 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		x;
	int		y;
	int		z;
	char	*s;

	if (!s1)
		return (0);
	x = ft_strlen(s1);
	y = ft_strlen(s2);
	s = malloc(x + y + 1);
	if (!s)
		return (0);
	z = 0;
	while (s1[z])
	{
		s[z] = (char)s1[z];
		z++;
	}
	y = 0;
	while (s2[y])
		s[x++] = (char)s2[y++];
	s[x] = '\0';
	return (s);
}
