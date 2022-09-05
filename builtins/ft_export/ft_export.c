/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:57:51 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/05 09:47:47 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	ft_print_quote(char *env)
{
	int	x;

	x = 0;
	while (env[x])
	{
		printf("%c",env[x]);
		if (env[x] == '=')
			printf("'");
		x++;
	}
	if (ft_equal(env) == 0)
		printf("='");
	printf("'");
}

static void	ft_order(char **copy)
{
	int		x;
	int		y;
	char	*tmp;

	x = 0;
	while (copy[x + 1])
	{
		y = x + 1;
		while (copy[y])
		{
			if (ft_strcmp(copy[x], copy[y]) > 0)
			{
				tmp = copy[x];
				copy[x] = copy[y];
				copy[y] = tmp;
			}
			y++;
		}
		x++;
	}
}

static void	ft_print_export(char **env) // ! Copy Leaks
{
	int		x;
	char	**copy;

	x = 0;
	copy = malloc(1024);
	while (env[x])
	{
		copy[x] = ft_substr(env[x], 0, ft_strlen(env[x]));
		x++;
	}
	copy[x] = NULL;
	ft_order(copy);
	x = 0;
	while (copy[x])
	{
		if (ft_strncmp(copy[x], "?=", 2) != 0)
		{
			ft_print_quote(copy[x]);
			printf("\n");
		}
		x++;
	}
	ft_free_arg(copy);
}

static void	ft_export_arguments(char **env, char **arguments)
{
	int		x;
	char	*variable;
	char	*value;

	x = -1;
	while (arguments[++x])
	{
		variable = ft_variables(arguments[x]);
		value = ft_value(arguments[x]);
		if (ft_find_variable(variable, env) == 0)
			ft_create_variable(variable, value, env);
		else
			ft_replace_variable(variable, value, env);
		free(variable);
	}
}

void	ft_export(char **env)
{
	char	**arguments;

	arguments = ft_split("señor adios= hola=h", ' '); // ? Provisional, this is given by the structure
	if (arguments)
		ft_export_arguments(env, arguments);
	else
		ft_print_export(env);
	ft_change_good_status(env);
}
