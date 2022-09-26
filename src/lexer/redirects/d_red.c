/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_red.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 09:37:51 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/26 09:49:03 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*double_red_one(t_general_data *gen_data, int position)
{
	int		i;
	int		copy_fd;
	char	*buff;
	char	*s;

	copy_fd = 0;
	s = malloc(sizeof(char) * 1);
	s = "b";
	i = ft_count_dr_cmd(gen_data, position);
	copy_fd = dup(gen_data->cmd[position].fd_out[i]);
	s = get_next_line(copy_fd);
	while (s)
	{
		buff = ft_strjoin(buff, s);
		s = get_next_line(copy_fd);
	}
	return (buff);
}

char	*double_red_zero(t_general_data *gen_data, int n_built)
{
	int		i;
	int		copy_fd;
	char	*buff;
	char	*s;

	copy_fd = 0;
	s = malloc(sizeof(char) * 1);
	s = "b";
	i = ft_count_dr_blt(gen_data, n_built);
	copy_fd = dup(gen_data->blt[n_built].fd_out[i]);
	s = get_next_line(copy_fd);
	while (s)
	{
		buff = ft_strjoin(buff, s);
		s = get_next_line(copy_fd);
	}
	return (buff);
}

char	*double_red(t_general_data *gen_data, int position, int n_built)
{
	char	*buff;

	buff = malloc(sizeof(char ) * 1);
	buff = "a";
	if (gen_data->sort[gen_data->exec_pos] == '1')
		buff = double_red_one(gen_data, position);
	else if (gen_data->sort[gen_data->exec_pos] == '0')
		buff = double_red_zero(gen_data, n_built);
	return (buff);
}

void	already_red(t_general_data *gen_data, int position, int n_built)
{
	int	i;

	if (n_built == 23)
		return ;
	i = 0;
	while (gen_data->cmd[position].fd_out[i] > 0)
		i++;
	i--;
	dup2(1, gen_data->cmd[position].fd_out[i]);
	dup2(gen_data->cmd[position].fd_out[i], 1);
}
