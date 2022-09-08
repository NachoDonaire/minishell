/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_pipes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:23:12 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/08 09:54:55 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	n_pipes(t_general_data *gen_data, char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '|' || s[i] == '&')
			gen_data->n_pipes++;
		i++;
	}
}

