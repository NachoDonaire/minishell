/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_reds3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:05:08 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/14 11:05:42 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	gest_reds(t_general_data *gen_data, char *s, int y, int ref)
{
	char	**tmp;
	int		i;

	tmp = ft_split(s, '>');
	i = 0;
	while (tmp[i])
		i++;
	if (ref == 0)
		gen_data->cmd[y].out = malloc(sizeof(char *) * (i));
	else if (ref == 1)
		gen_data->blt[gen_data->n_built].out = malloc(sizeof(char *) * (i));
	memory_for_red(gen_data, tmp, y, ref);
	paste_tmp_red(gen_data, tmp, y, ref);
	i = 0;
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
}
