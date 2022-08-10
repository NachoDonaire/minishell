/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama <sasalama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:11:16 by sasalama          #+#    #+#             */
/*   Updated: 2022/08/10 15:29:21 by sasalama         ###   ########.fr       */
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

static void	ft_print_export(char **env)
{
	int	x;

	x = 0;
	while (env[x])
	{
		if (ft_strncmp(env[x], "?=", 2) != 0)
		{
			ft_print_quote(env[x]);
			printf("\n");
		}
		x++;
	}
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
