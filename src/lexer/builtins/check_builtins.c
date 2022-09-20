/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:22:49 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/14 10:59:02 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	paste_in_built(t_general_data *gen_data, char *s)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	while (s[i])
		i++;
	gen_data->blt[gen_data->n_built].blt = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (s[i] == ' ')
		i++;
	while (s[i])
		gen_data->blt[gen_data->n_built].blt[z++] = s[i++];
	gen_data->blt[gen_data->n_built].blt[z] = '\0';
}

void	ft_reset_cmd(t_general_data *gen_data, int y)
{
	gen_data->cmd[y].cmd = malloc(1);
	gen_data->cmd[y].args = malloc(1);
	gen_data->cmd[y].args[0] = malloc(1);
	gen_data->cmd[y].args[0] = 0;
	gen_data->cmd[y].out = malloc(1);
	gen_data->cmd[y].in = malloc(1);
	gen_data->cmd[y].out[0] = malloc(1);
	gen_data->cmd[y].out[0] = 0;
	gen_data->cmd[y].in[0] = malloc(1);
	gen_data->cmd[y].in[0] = 0;
}

int	args_with_reds(char *copy)
{
	int		i;

	i = 0;
	while (copy[i])
	{
		if (copy[i] == '>' || copy[i] == '<')
			break ;
		i++;
	}
	return (i);
}

int	n_spaces(char *copy)
{
	int	i;

	i = 0;
	while (copy[i] == ' ')
		i++;
	return (i);
}

void	check_builtins(char *s, t_general_data *gen_data, int y)
{
	char	**tmp;
	char	*cp;
	int		x;
	int		z;

	if (extreme_finder(s, "echo") == 1 || extreme_finder(s, "pwd") == 1
		|| extreme_finder(s, "cd") == 1 || extreme_finder(s, "export") == 1
		|| extreme_finder(s, "unset") == 1 || extreme_finder(s, "env") == 1)
	{
		tmp = ft_split(s, ' ');
		paste_in_built(gen_data, tmp[0]);
		x = ft_strlen(gen_data->blt[gen_data->n_built].blt) + n_spaces(s);
		z = args_with_reds(s) - ft_strlen(gen_data->blt[gen_data->n_built].blt);
		cp = ft_substr(s, x, z);
		gen_data->blt[gen_data->n_built].args = ft_split(cp, ' ');
		free(cp);
		if (gen_data->n_pipes > 0)
		{
			ft_free_arg(gen_data->blt[gen_data->n_built].args);
			gen_data->blt[gen_data->n_built].args = ft_split(s, ' ');
		}
		ft_reset_cmd(gen_data, y);
		gen_data->built = 1;
		process_sing_red(gen_data, s, y, 1);
		process_in_red(gen_data, s, y, 1);
		gen_data->n_built++;
	}
}
