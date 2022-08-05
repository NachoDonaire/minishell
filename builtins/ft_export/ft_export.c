/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salustianosalamanca <salustianosalamanc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:11:16 by sasalama          #+#    #+#             */
/*   Updated: 2022/08/05 12:50:17 by salustianos      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_imprimir_export(char **env)
{
	int	x;

	x = 0;
	while (env[++x])
	{
		printf("%s", env[x]);
		if (ft_igual(env[x]) == 0)
			printf("=''");
		if (env[x][ft_strlen(env[x]) - 1] == '=')
			printf("''");
		printf("\n");
	}
}

void	ft_export_argumentos(char **env, char **argumentos)
{
	int		x;
	char	*variable;
	char	*valor;

	x = 0;
	while (argumentos[++x])
	{
		variable = ft_variables(argumentos[x]);
		valor = ft_valor(argumentos[x]);
		if (ft_buscar_variable(variable, env) == 0)
			ft_crear_variable(variable, valor, env);
		else
			ft_sustituir_variable(variable, valor, env);
	}
}

void	ft_export(char **env)
{
	char	**argumentos;

	argumentos = ft_split("señor adios= hola=h", ' ');
	if (argumentos)
		ft_export_argumentos(env, argumentos);
	else
		ft_imprimir_export(env);
}
