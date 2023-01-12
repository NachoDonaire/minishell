/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_input2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 16:30:52 by sasalama          #+#    #+#             */
/*   Updated: 2023/01/12 14:13:20 by sasalama         ###   ########.fr       */
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

void	kajutels(t_general_data *gen_data, char *s, int y)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	while (s[i])
	{
		if (s[i] == '>')
		{
			while (s[i] == '>' && s[i])
				i++;
			z++;
		}
		i++;
	}
	gen_data->cmd[y].dred = malloc(sizeof(int ) * (z + 1));
}

void	dred_tucker(t_general_data *gen_data, char *s, int y)
{
	int	i;
	int	z;
	int	a;

	i = 0;
	a = 0;
	z = 0;
	while (s[i])
	{
		if (s[i] == '>')
		{
			while (s[i] == '>')
			{
				a++;
				i++;
			}
			if (a == 2)
				gen_data->cmd[y].dred[z++] = 1;
			else
				gen_data->cmd[y].dred[z++] = 0;
			a = 0;
		}
		i++;
	}
	gen_data->cmd[y].dred[z] = -1;
}
