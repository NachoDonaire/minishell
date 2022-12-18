/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_input2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 16:30:52 by sasalama          #+#    #+#             */
/*   Updated: 2022/11/14 09:05:42 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_reset_blt(t_general_data *gen_data)
{
	gen_data->blt[gen_data->n_built].blt = malloc(sizeof(char) * 1);
	gen_data->blt[gen_data->n_built].blt[0] = '\0';
	gen_data->blt[gen_data->n_built].args = malloc(sizeof(char *) * 1);
	gen_data->blt[gen_data->n_built].args[0] = NULL;
	gen_data->blt[gen_data->n_built].out = malloc(sizeof(char *) * 1);
	gen_data->blt[gen_data->n_built].out[0] = NULL;
	gen_data->blt[gen_data->n_built].fd_out = malloc(sizeof(int) * 2);
	gen_data->blt[gen_data->n_built].fd_out[0] = 1;
	gen_data->blt[gen_data->n_built].fd_out[1] = -1;
	gen_data->blt[gen_data->n_built].dred = malloc(sizeof(int) * 1);
	gen_data->blt[gen_data->n_built].in = malloc(sizeof(char *) * 1);
	gen_data->blt[gen_data->n_built].in[0] = NULL;
	gen_data->blt[gen_data->n_built].fd_in = malloc(sizeof(int) * 1);
	gen_data->blt[gen_data->n_built].fd_in[0] = -1;
}

int	mela(char *s)
{
	int	i;

	i = 0;
	while ((s[i] == '<' || s[i] == ' ') && s[i])
		i++;
	return (i);
}

void	pela(t_general_data *gen_data, char *s, int y)
{
	int	i;
	int	z;
	int	a;

	i = 0;
	a = 0;
	z = 0;
	while (s[i])
	{
		if (s[i] == '<')
		{
			while (s[i] == '<')
			{
				a++;
				i++;
			}
			z++;
		}
		i++;
	}
	gen_data->cmd[y].in_dred = malloc(sizeof(int ) * (z + 1));
}

void	aunmas(t_general_data *gen_data, char *s, int y)
{
	int	i;
	int	z;
	int	a;

	i = 0;
	a = 0;
	z = 0;
	while (s[i])
	{
		if (s[i] == '<')
		{
			while (s[i] == '<')
			{
				a++;
				i++;
			}
			if (a == 2)
				gen_data->cmd[y].in_dred[z++] = 1;
			else
				gen_data->cmd[y].in_dred[z++] = 0;
			a = 0;
		}
		i++;
	}
}

int	oficial_tukle(char *s, t_general_data *gen_data, int y)
{
	if (check_tukle(s) == 1)
	{
		gen_data->cmd[y].can_exec = 0;
		gen_data->cmd[y].syn_er = 420;
		gen_data->n_cmd--;
		gen_data->cmd[y].in = dr_comillas(&s[mela(s)]);
		if (!gen_data->cmd[y].in[0])
			gen_data->cmd[y].syn_er = 23;
		if (gen_data->n_pipes == 0)
		{
			gen_data->sort[0] = '1';
			gen_data->sort[1] = '\0';
		}
		pela(gen_data, s, y);
		aunmas(gen_data, s, y);
		return (1);
	}
	gen_data->cmd[y].syn_er = 0;
	return (0);
}
