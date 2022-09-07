/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:34:25 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/07 16:50:43 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	x;
	char	*s;

	x = 0;
	s = malloc(sizeof(char) * count * size);
	if (s == 0)
		return (0);
	while (x < sizeof(char) * count * size)
	{
		s[x] = '\0';
		x++;
	}
	return (s);
}
