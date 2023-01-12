/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:34:48 by sasalama          #+#    #+#             */
/*   Updated: 2023/01/12 14:23:04 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	fts_print_s(char *s, int *p)
{
	ft_putstr_fd(s, p[1]);
	ft_putstr_fd("\n", p[1]);
}

void	ft_dup_in_reds_blt3(t_general_data *gen_data, int n_b, int *p, int i)
{
	char	*s;
	int		x;
	int		y;

	y = lens(gen_data->blt[n_b].in[i]);
	close(p[0]);
	s = readline("> ");
	x = lens(s);
	if (y > x)
		x = y;
	if (ft_strncmp(s, gen_data->blt[n_b].in[i], x) != 0)
		fts_print_s(s, p);
	while (ft_strncmp(s, gen_data->blt[n_b].in[i], x) != 0)
	{
		fts_print_s(s, p);
		free(s);
		s = readline("> ");
		x = lens(s);
		if (y > x)
			x = y;
	}
	ft_dup_in_reds_exit(s, p);
}

void	ft_dup_in_reds_cm3(t_general_data *gen_data, int p, int *pipedo, int i)
{
	char	*s;
	int		x;
	int		y;

	y = lens(gen_data->cmd[p].in[i]);
	s = readline("> ");
	x = lens(s);
	if (y > x)
		x = y;
	if (ft_strncmp(s, gen_data->cmd[p].in[i], x) != 0 || !s[0])
	{
		ft_putstr_fd(s, pipedo[1]);
		ft_putstr_fd("\n", pipedo[1]);
	}
	while (ft_strncmp(s, gen_data->cmd[p].in[i], x) != 0 || !s[0])
	{
		ft_putstr_fd(s, pipedo[1]);
		ft_putstr_fd("\n", pipedo[1]);
		free(s);
		s = readline("> ");
		x = lens(s);
		if (y > x)
			x = y;
	}
	ft_dup_in_reds_exit(s, pipedo);
}

void	ft_child3(t_general_data *gen_data, int position,
		int n_built, char **s3)
{
	if (gen_data->sort[gen_data->exec_pos] == '1')
	{
		if (gen_data->cmd[position].can_exec != 0)
		{
			dup_reds(gen_data, position, n_built);
			s3[0] = gen_data->cmd[position].cmd;
		}
		if (gen_data->cmd[position].can_exec == 0)
			error_can_exec(gen_data, n_built, position, 0);
		ft_child_2(gen_data, s3, position);
	}
	else if (gen_data->sort[gen_data->exec_pos] == '0')
	{
		dup_reds(gen_data, position, n_built);
		s3[1] = gen_data->blt[n_built].blt;
		s3[1] = check_cmd(s3[1], gen_data);
		if (gen_data->blt[n_built].can_exec == 0)
			error_can_exec(gen_data, n_built, position, 1);
		execve(s3[1], gen_data->blt[n_built].args, gen_data->env);
	}
}

void	ft_child_pipes2(t_general_data *gen_data, int position, int n_built)
{
	(void)position;
	(void)n_built;
	close(gen_data->pipe[gen_data->pipe_pos][0]);
	dup2(gen_data->pipe[gen_data->pipe_pos - 1][0], 0);
	close(gen_data->pipe[gen_data->pipe_pos - 1][0]);
	dup2(gen_data->pipe[gen_data->pipe_pos][1], 1);
	close(gen_data->pipe[gen_data->pipe_pos][1]);
}
