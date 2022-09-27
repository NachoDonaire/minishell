/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:40:59 by ndonaire          #+#    #+#             */
/*   Updated: 2022/09/26 11:43:28 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
