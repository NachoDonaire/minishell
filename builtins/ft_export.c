/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama <sasalama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:11:16 by sasalama          #+#    #+#             */
/*   Updated: 2022/08/02 15:42:16 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_export(char **env)
{
	char	*argumento;
	char	*v;
	int		x;
	int		is_there;
	char	*tmp;
	char	*buf;
	char	*buf2;

	v = "PRUEBA="; // ? Provisional, esto lo da la estructura
	argumento = "Hola"; // ? Provisional, esto lo da la estructura
	x = 0;
	is_there = 0;
	while (env[x])
	{
		tmp = ft_substr(env[x], 0, ft_strlen(v));
		buf = ft_strjoin("=", argumento);
		buf2 = ft_strchr(env[x], '=');
		if (ft_strncmp(tmp, v, ft_strlen(v)) == 0 && ft_strncmp(buf2, buf, ft_strlen(argumento)) == 0)
		{
			is_there = 1;
			break ;
		}	
		x++;
	}
	if (is_there == 0)
	{
		x = 0;
		while (env[x])
		{
			if (ft_strncmp(env[x], "_=", 2) == 0)
			{
				env[x + 1] = env[x];
				break ;
			}
			x++;
		}
		env[x] = ft_strjoin(v, argumento);
		env[x + 2] = NULL;
	}
}

/*
#include "../minishell.h"

void	ft_export(char **env) // *! MODIFICAR
{
	char	*argumento;
	int		x;
	char	**variable;
	char	*tmp;
	char	*buf;

	argumento = "PRUEBA=hola Adios= que=tal señor"; // ? Provisional, esto lo da la estructura
	variable = ft_split(argumento, " ");
	x = 0;
	if (argumento)
	{
		while (variable[x])
		{
			tmp = ft_strchr(variable[x], '=');
			if (tmp)
			{
				buf = ft_substr(variable[x], 0, ft_strlen(variable) - ft_strlen(tmp));
			}
			x++;
		}
	}
	else
	{
		
	}
}
*/