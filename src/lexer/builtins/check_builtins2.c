/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtins2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:42:23 by sasalama          #+#    #+#             */
/*   Updated: 2022/12/19 17:14:26 by ndonaire         ###   ########.fr       */
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

char	*the_arg(char *s)
{
	int		i;
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

int	starty(char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ' && s[i])
		i++;
	while (s[i] && s[i] != ' ')
		i++;
	return (i);
}

void	check_builtins2(char *s, t_general_data *gen_data, int y)
{
	char	**tmp;
	char	*cp;

	tmp = dr_comillas(s);
	gen_data->blt[gen_data->n_built].blt = ft_substr(tmp[0], 0, lens(tmp[0]));
	ft_free_arg(tmp);
	cp = 0;
	gen_data->blt[gen_data->n_built].args = dr_comillas(s);
	if (gen_data->n_pipes > 0)
	{
		cp = the_arg(s);
		ft_free_arg(gen_data->blt[gen_data->n_built].args);
		gen_data->blt[gen_data->n_built].args = dr_comillas(cp);
		free(cp);
	}
	gen_data->built = 1;
	gen_data->blt[gen_data->n_built].can_exec = 1;
	if (check_tukle(s) == 1)
		gen_data->blt[gen_data->n_built].can_exec = 0;
	process_sing_red(gen_data, s, y, 1);
	process_in_red(gen_data, s, y, 1);
	gen_data->n_built++;
}
