/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_input2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 16:30:52 by sasalama          #+#    #+#             */
/*   Updated: 2022/12/19 10:22:38 by ndonaire         ###   ########.fr       */
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
	int	a;

	i = 0;
	a = 0;
	z = 0;
	while (s[i])
	{
		if (s[i] == '>')
		{
			while (s[i] == '>' && s[i])
			{
				a++;
				i++;
			}
			z++;
		}
		i++;
	}
	gen_data->cmd[y].dred = malloc(sizeof(int ) * (z + 1));
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
	gen_data->cmd[y].in_dred[z] = -1;
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


int	oficial_tukle(char *s, t_general_data *gen_data, int y)
{
	char	**caligula;
	char	*megajoin;
	char	*tmp;
	int	i;

	i = 0;
	megajoin = NULL;
	tmp = "tmp";
	if (check_tukle(s) == 2)
	{
	caligula = ft_split(s, '<');
		//while (caligula[i])
		//	megajoin = ft_strjoin(caligula[i++], "");
		gen_data->cmd[y].can_exec = 0;
		gen_data->cmd[y].syn_er = 23;
		gen_data->ojito = 23;
		//gen_data->n_cmd--;
		gen_data->cmd[y].in = dr_comillas(s);
		if (!gen_data->cmd[y].in)
			gen_data->cmd[y].syn_er = 23;
		if (gen_data->n_pipes == 0)
		{
			gen_data->sort[0] = '1';
			gen_data->sort[1] = '\0';
		}
		pela(gen_data, s, y);
		aunmas(gen_data, s, y);
		free(megajoin);
		ft_free_arg(caligula);
		return (1);
	}
	else if (check_tukle(s) == 1)
	{
	caligula = ft_split(s, '<');
		megajoin = ft_strjoin(caligula[i++], "");
		while (caligula[i])
			megajoin = ft_strjoin(megajoin, caligula[i++]);
		process_sing_red(gen_data, megajoin, y, 0);
		gen_data->cmd[y].in = dr_comillas(megajoin);
		i = 0;
		while (gen_data->cmd[y].out[i])
			printf("--%s--", gen_data->cmd[y].out[i++]);
		//i = 0;
		//while (gen_data->cmd[y].in_dred[i] > 0)
		//	printf("--%d--\n", gen_data->cmd[y].in_dred[i++]);
		gen_data->cmd[y].syn_er = 420;
		gen_data->cmd[y].can_exec = 0;
		gen_data->n_cmd++;
		if (gen_data->n_pipes == 0)
		{
			gen_data->sort[0] = '1';
			gen_data->sort[1] = '\0';
		}
		pela(gen_data, s, y);
		aunmas(gen_data, s, y);
		free(megajoin);
		ft_free_arg(caligula);
		return (1);
	}
	else if (check_tukle(s) == 3)
	{
		//caligula  = ft_split(s, '>');
		megajoin = ft_strjoin(tmp, s);
		//while (caligula[i])
		//	megajoin = ft_strjoin(megajoin, caligula[i++]);
		printf("--%s--\n", megajoin);
		//gen_data->cmd[y].out = dr_comillas(megajoin);
		process_sing_red(gen_data, megajoin, y, 0);
		process_in_red(gen_data, megajoin, y, 0);
		gen_data->cmd[y].syn_er = 420;
		gen_data->cmd[y].can_exec = 0;
		gen_data->n_cmd++;
		if (gen_data->n_pipes == 0)
		{
			gen_data->sort[0] = '1';
			gen_data->sort[1] = '\0';
		}
		//kajutels(gen_data, s, y);
		//dred_tucker(gen_data, s, y);
		free(megajoin);
		return (1);
	}
	gen_data->cmd[y].syn_er = 0;
	return (0);
}
