/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_input3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:08:56 by sasalama          #+#    #+#             */
/*   Updated: 2023/01/14 16:45:58 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

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

int	oficial_tukle_2(char *s, t_general_data *gen_data, int y)
{
	char	**caligula;

	caligula = ft_split(s, '<');
	gen_data->cmd[y].can_exec = 0;
	gen_data->cmd[y].syn_er = 23;
	gen_data->ojito = 23;
	gen_data->cmd[y].in = dr_comillas(s);
	if (!gen_data->cmd[y].in)
		gen_data->cmd[y].syn_er = 23;
	if (gen_data->n_pipes == 0)
	{
		gen_data->sort[0] = '1';
		gen_data->sort[1] = '\0';
	}
	gen_data->n_cmd++;
	pela(gen_data, s, y);
	aunmas(gen_data, s, y);
	ft_free_arg(caligula);
	return (1);
}

int	oficial_tukle_1(char *s, t_general_data *gen_data, int y)
{
	char	**caligula;
	char	*megajoin;
	char	*aux;
	int		i;

	i = 0;
	caligula = ft_split(s, '<');
	megajoin = ft_strjoin(caligula[i++], "\0");
	while (caligula[i])
	{
		aux = megajoin;
		megajoin = ft_strjoin(aux, caligula[i++]);
		free(aux);
	}
	process_sing_red(gen_data, megajoin, y, 0);
	gen_data->cmd[y].in = dr_comillas(megajoin);
	gen_data->cmd[y].syn_er = 420;
	gen_data->cmd[y].can_exec = 0;
	gen_data->cmd[y].fd_in = malloc(sizeof(int) * 1);
	gen_data->taker = 2333;
	gen_data->n_cmd++;
	oficial_tukle_1_2(gen_data, s, y);
	free(megajoin);
	ft_free_arg(caligula);
	return (1);
}

int	oficial_tukle_3(char *s, t_general_data *gen_data, int y)
{
	char	*megajoin;
	char	*tmp;

	tmp = "tmp";
	megajoin = ft_strjoin(tmp, s);
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
	free(megajoin);
	return (1);
}

int	oficial_tukle(char *s, t_general_data *gen_data, int y)
{
	if (check_tukle(s) == 2)
		return (oficial_tukle_2(s, gen_data, y));
	else if (check_tukle(s) == 1)
		return (oficial_tukle_1(s, gen_data, y));
	else if (check_tukle(s) == 3)
		return (oficial_tukle_3(s, gen_data, y));
	gen_data->cmd[y].syn_er = 0;
	return (0);
}
