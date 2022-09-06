/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama <sasalama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:34:25 by sasalama          #+#    #+#             */
/*   Updated: 2022/08/02 13:30:36 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
