/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:58:12 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/07 16:53:56 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static void	ft_eliminate(char **env, int position)
{
	int	x;

	x = position;
	while (env[x + 1])
	{
		env[x] = env[x + 1];
		x++;
	}
	env[x] = NULL;
}

int	ft_equal(char *s)
{
	int	x;

	x = 0;
	while (s[x])
	{
		if (s[x] == '=')
			return (1);
		x++;
	}
	return (0);
}

static void	ft_find_env(char *argument, char **env)
{
	int	tmp;
	int	y;

	y = -1;
	while (env[++y])
	{
		tmp = ft_strlen(argument);
		if (ft_strncmp(argument, env[y], tmp) == 0)
		{
			ft_eliminate(env, y);
			break ;
		}
	}
}

void	ft_unset(t_general_data *gen_data, int position)
{
	int		x;
	int		z;
	int		tmp;

	x = -1;
	while (gen_data->blt[position].args[++x])
	{
		z = ft_strlen(gen_data->blt[position].args[x]) - 1;
		tmp = ft_equal(gen_data->blt[position].args[x]);
		if (gen_data->blt[position].args[x][z] != '=' && gen_data->blt[position].args[x][z + 1] == '\0' && tmp == 0)
		{
			gen_data->blt[position].args[x] = ft_strjoin(gen_data->blt[position].args[x], "=");
			z++;
		}
		if (gen_data->blt[position].args[x][z] == '=' && gen_data->blt[position].args[x][z + 1] == '\0')
			ft_find_env(gen_data->blt[position].args[x], gen_data->env);
		else
		{
		printf("unset: %s: invalid parameter name\n", gen_data->blt[position].args[x]);
			break ;
		}
	}
	ft_change_good_status(gen_data->env);
}
