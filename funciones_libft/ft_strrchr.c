/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:59:19 by sasalama          #+#    #+#             */
/*   Updated: 2022/08/24 10:59:20 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	char			*src;
	unsigned char	s2;

	i = 0;
	src = (char *)s;
	s2 = (unsigned char)c;
	while (*(s + i))
		i++;
	while (i >= 0)
	{
		if (s[i] == s2)
			return ((&src[i]));
		i--;
	}
	return (0);
}
