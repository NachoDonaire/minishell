/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:52:08 by sasalama          #+#    #+#             */
/*   Updated: 2022/12/26 13:20:51 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_child_2(t_general_data *gen_data, char **s3, int position)
{
	if (ft_find_path(gen_data) == 0)
		ft_change_root(gen_data, s3, position);
	execve(s3[0], gen_data->cmd[position].args, gen_data->env);
}

int	ft_find_path(t_general_data *gen_data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (gen_data->env[x])
	{
		if (ft_strncmp("PATH=", gen_data->env[x], 5) == 0)
			y = 1;
		x++;
	}
	return (y);
}

void	ft_change_root(t_general_data *gen_data, char **s3, int position)
{
	char	*cmd;

	cmd = gen_data->cmd[position].cmd;
	if (ft_strncmp(cmd, "echo", 4) == 0)
		s3[0] = "/bin/echo";
	if (ft_strncmp(cmd, "cd", 2) == 0)
		s3[0] = "/usr/bin/cd";
	if (ft_strncmp(cmd, "pwd", 3) == 0)
		s3[0] = "/bin/pwd";
}

void	error_can_exec(t_general_data *gen_data,
		int n_built, int position, int ref)
{
	if (ref == 0)
	{
		if (gen_data->cmd[position].syn_er == 23)
			perror("Syntax error ");
		exit (1);
	}
	else if (ref == 0)
	{
		if (gen_data->blt[n_built].syn_er == 23)
			perror("Syntax error ");
		exit (1);
	}
}

int	check_xlacara(t_general_data *gen_data, int position, int n_built)
{
	if (gen_data->sort[gen_data->exec_pos] == '1')
	{
		if (gen_data->cmd[position].in[0])
			return (23);
	}
	else if (gen_data->sort[gen_data->exec_pos] == '0')
		if (gen_data->blt[n_built].in[0])
			return (23);
	return (0);
}
