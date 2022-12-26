/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:22:59 by sasalama          #+#    #+#             */
/*   Updated: 2022/12/26 13:25:32 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_reset_table_3(int *table)
{
	table[0] = 0;
	table[1] = -1;
	table[2] = 0;
	table[3] = 0;
}

void	ft_handle_cmd_pipes2(t_general_data *gen_data, int *t, char **tmp)
{
	gen_data->built = 0;
	if (gen_data->built != 1)
	{
		gen_data->sort[t[0]] = '1';
		process_string(tmp[t[1]], gen_data, t[2]);
		t[2]++;
	}
	else if (gen_data->built == 1)
		gen_data->sort[t[0]] = '0';
	t[0]++;
}

void	handle_cmd_pipes(t_general_data *gen_data, char *s, char *env[])
{
	int		table[4];
	char	**tmp;
	int		i;
	int		x;

	i = -1;
	ft_reset_table_3(table);
	if (ft_strlen(s) == 1 && s[0] == '|')
		tmp = ft_split(s, ' ');
	else
		tmp = ft_split(s, '|');
	(void)env;
	while (tmp[++table[1]])
		ft_handle_cmd_pipes2(gen_data, table, tmp);
	gen_data->sort[table[0]] = '\0';
	x = gen_data->n_pipes + 1;
	gen_data->pipe = malloc(sizeof(int *) * (x + 1));
	while (++i < x)
	{
		gen_data->pipe[i] = malloc(sizeof(int) * 3);
		gen_data->pipe[i][2] = 0;
	}
	gen_data->pipe[x] = NULL;
	ft_free_arg(tmp);
}

int	gest_ampersand(char *s, t_general_data *gen_data, int y)
{
	char	**tmp;
	int		i;

	tmp = ft_split(s, '&');
	i = 0;
	while (tmp[i])
	{
		gen_data->built = 0;
		check_builtins(tmp[i], gen_data, y);
		if (check_cmllas(tmp[i]) == 1)
			tmp[i] = gest_cmllas(tmp[i]);
		if (gen_data->built != 1)
			process_string(tmp[i], gen_data, y);
		i++;
		y++;
	}
	ft_free_arg(tmp);
	return (y);
}

void	process_string_w_pipes(t_general_data *gen_data, char *s, char *env[])
{
	handle_cmd_pipes(gen_data, s, env);
}
