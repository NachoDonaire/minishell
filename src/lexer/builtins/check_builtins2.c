/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtins2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:42:23 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/29 13:21:36 by sasalama         ###   ########.fr       */
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
	free(s);
	gen_data->blt[gen_data->n_built].blt[z] = '\0';
}

void	ft_reset_cmd(t_general_data *gen_data, int y)
{
	gen_data->cmd[y].cmd = malloc(1);
	gen_data->cmd[y].args = malloc(1);
	gen_data->cmd[y].args[0] = malloc(1);
	gen_data->cmd[y].args[0] = 0;
/*	gen_data->cmd[y].out = malloc(1);
	gen_data->cmd[y].in = malloc(1);
	gen_data->cmd[y].out[0] = malloc(1);
	gen_data->cmd[y].out[0] = 0;
	gen_data->cmd[y].in[0] = malloc(1);
	gen_data->cmd[y].in[0] = 0;
	*/
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

char	*the_arg(char *s)
{
	int	i;
	char	*z;

	i = 0;
	z = malloc(sizeof(char ) * (ft_strlen(s) + 1));
	while (s[i])
	{
		if (s[i] == '<' || s[i] == '>')
			break ;
		z[i] = s[i];
		i++;
	}
	z[i] = '\0';
	return (z);
}

void	check_builtins2(char *s, t_general_data *gen_data, int y)
{
	char	**tmp;
	char	*cp;
	int		x;
	int		z;

	tmp = dr_comillas(s);
	paste_in_built(gen_data, ft_substr(tmp[0], 0, ft_strlen(tmp[0])));
	x = ft_strlen(gen_data->blt[gen_data->n_built].blt) + n_spaces(s);
	z = args_with_reds(s) - ft_strlen(gen_data->blt[gen_data->n_built].blt);
	cp = ft_substr(s, x, z);
	gen_data->blt[gen_data->n_built].args = ft_split(cp, ' ');
	if (gen_data->n_pipes > 0)
	{
		cp = the_arg(s);
		gen_data->blt[gen_data->n_built].args = dr_comillas(cp);
	}
	free(cp);
	ft_free_arg(tmp);
	//ft_reset_cmd(gen_data, y);
	gen_data->built = 1;
	process_sing_red(gen_data, s, y, 1);
	process_in_red(gen_data, s, y, 1);
	gen_data->n_built++;
}
