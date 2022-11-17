/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_status.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 13:43:23 by sasalama          #+#    #+#             */
/*   Updated: 2022/11/17 08:47:11 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_status_blt(t_general_data *gen_data, int position)
{
	char	*path;
	char	*copy;
	char	**tmp;
	int		x;

	x = ft_strlen(gen_data->cmd[position].cmd);
	copy = ft_substr(gen_data->cmd[position].cmd, 0, x);
	tmp = ft_split(copy, '/');
	free(copy);
	x = ft_nb_arguments(tmp) - 1;
	copy = ft_substr(tmp[x], 0, ft_strlen(tmp[x]));
	ft_free_arg(tmp);
	ft_path(copy, gen_data->env, &path);
	if (path == NULL)
		ft_change_bad_status(gen_data->env, gen_data);
	free(path);
	free(copy);
}

void	ft_status_cmd(t_general_data *gen_data, int position)
{
	char	*path;
	char	*copy;
	char	**tmp;
	int		x;

	x = ft_strlen(gen_data->blt[position].blt);
	copy = ft_substr(gen_data->blt[position].blt, 0, x);
	tmp = ft_split(copy, '/');
	free(copy);
	x = ft_nb_arguments(tmp) - 1;
	copy = ft_substr(tmp[x], 0, ft_strlen(tmp[x]));
	ft_free_arg(tmp);
	ft_path(copy, gen_data->env, &path);
	if (path == NULL)
		ft_change_bad_status(gen_data->env, gen_data);
	free(path);
	free(copy);
}

void	ft_check_status(t_general_data *gen_data, int position)
{
	int		x;

	ft_change_good_status(gen_data->env, gen_data);
	if (gen_data->n_cmd != 0)
		ft_status_blt(gen_data, position);
	else if (gen_data->n_built != 0)
		ft_status_cmd(gen_data, position);
	else if (gen_data->n_pipes != 0)
	{
		x = gen_data->n_pipes;
		if (ft_strncmp(gen_data->blt[position].blt, "pwd", 3) == 0
			&& gen_data->blt[position].args[0] && x > 0)
			ft_change_bad_status(gen_data->env, gen_data);
	}
}
