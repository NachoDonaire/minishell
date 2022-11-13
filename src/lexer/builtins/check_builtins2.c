/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtins2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:42:23 by sasalama          #+#    #+#             */
/*   Updated: 2022/11/10 17:52:27 by sasalama         ###   ########.fr       */
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
	//int		x;
	//int		z;

	tmp = dr_comillas(s);
	printf("%s", tmp[0]);
	//paste_in_built(gen_data, ft_substr(tmp[0], 0, ft_strlen(tmp[0])));
	gen_data->blt[gen_data->n_built].blt = ft_substr(tmp[0], 0, lens(tmp[0]));
	//x = ft_strlen(gen_data->blt[gen_data->n_built].blt) + n_spaces(s);
	//z = args_with_reds(s) - ft_strlen(gen_data->blt[gen_data->n_built].blt);
	cp = ft_substr(s, starty(s), lens(s));
	gen_data->blt[gen_data->n_built].args = dr_comillas(s);
	if (gen_data->n_pipes > 0)
	{
		free(cp);
		cp = the_arg(s);
		ft_free_arg(gen_data->blt[gen_data->n_built].args);
		gen_data->blt[gen_data->n_built].args = dr_comillas(cp);
	}
	//free(cp);
	//ft_free_arg(tmp);
	gen_data->built = 1;
	gen_data->blt[gen_data->n_built].can_exec = 1;
	process_sing_red(gen_data, s, y, 1);
	process_in_red(gen_data, s, y, 1);
	gen_data->n_built++;
}
