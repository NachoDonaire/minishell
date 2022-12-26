/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_pipes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:23:12 by sasalama          #+#    #+#             */
/*   Updated: 2022/12/26 13:57:12 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	n_pipes2(t_general_data *gen_data, char *s, int i)
{
	if (s[i] == '"' && s[i])
	{
		i++;
		while (s[i] != '"' && s[i])
			i++;
		i++;
	}
	else if (s[i] == '\'' && s[i])
	{
		i++;
		while (s[i] != 39 && s[i])
			i++;
		i++;
	}
	else if (s[i] == '|' && s[i])
	{
		while (s[i] == '|')
			i++;
		gen_data->n_pipes++;
	}
	else
		i++;
	return (i);
}

void	n_pipes(t_general_data *gen_data, char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i = n_pipes2(gen_data, s, i);
	}
}
