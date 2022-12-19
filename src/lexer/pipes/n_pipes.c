/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_pipes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:23:12 by sasalama          #+#    #+#             */
/*   Updated: 2022/12/19 17:11:48 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	n_pipes(t_general_data *gen_data, char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i++] == '"')
			while (s[i] != '"' && s[i])
				i++;
		else if (s[i++] == '\'')
			while (s[i] != 39 && s[i])
				i++;
		else if (s[i++] == '|')
			gen_data->n_pipes++;
		else
			i++;
	}
}
