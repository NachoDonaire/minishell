/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:58:12 by sasalama          #+#    #+#             */
/*   Updated: 2022/11/17 10:03:07 by sasalama         ###   ########.fr       */
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

static void	ft_eliminate2(char **env, int position)
{
	int	x;

	printf("hola");
	x = position;
	while (env[x + 1])
	{
		env[x] = env[x + 1];
		x++;
	}
	env[x] = NULL;
}

static void	ft_find_env(t_general_data *gen_data, int p, int x)
{
	int		tmp;
	int		y;
	char	*copy;

	y = -1;
	while (gen_data->env[++y])
	{
		copy = gen_data->env[y];
		tmp = ft_strlen(gen_data->blt[p].args[x]);
		if (ft_strncmp(gen_data->blt[p].args[x], copy, tmp - 1) == 0)
		{
			ft_eliminate(gen_data->env, y);
			if (ft_strncmp(gen_data->blt[p].args[x], "PWD=", 4) == 0
				|| ft_strncmp(gen_data->blt[p].args[x], "OLDPWD=", 7) == 0)
				ft_eliminate2(gen_data->s_env, y);
			break ;
		}
	}
	if (ft_strncmp(gen_data->blt[p].args[x], "PATH=", 5) == 0)
	{
		y = -1;
		while (gen_data->s_env[++y])
		{
			copy = gen_data->s_env[y];
			tmp = ft_strlen(gen_data->blt[p].args[x]);
			if (ft_strncmp(gen_data->blt[p].args[x], copy, tmp - 1) == 0)
			{
				ft_eliminate(gen_data->s_env, y);
				break ;
			}
		}
	}
}

void	ft_unset(t_general_data *gen_data, int p)
{
	int		x;
	int		z;

	x = 0;
	while (gen_data->blt[p].args[++x])
	{
		z = ft_strlen(gen_data->blt[p].args[x]) - 1;
		if (gen_data->blt[p].args[x][z] != '=' &&
			gen_data->blt[p].args[x][z + 1] == '\0' &&
			ft_equal(gen_data->blt[p].args[x]) == 0)
		{
			ft_not_equal(gen_data, p, x);
			z++;
		}
		if (gen_data->blt[p].args[x][z] == '=' &&
			gen_data->blt[p].args[x][z + 1] == '\0')
			ft_find_env(gen_data, p, x);
		else
		{
			ft_print_bad(gen_data, p, x);
			break ;
		}
	}
	ft_change_good_status(gen_data->env, gen_data);
}
