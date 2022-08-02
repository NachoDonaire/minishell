/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama <sasalama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:09:22 by sasalama          #+#    #+#             */
/*   Updated: 2022/08/02 14:04:35 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// *! Ver si funciona con directorios sin permiso

void	ft_change_pwd(char **env, char *buf)
{
	int	x;

	x = 0;
	while (env[++x])
	{
		if (ft_strncmp(env[x], "PWD=", 4) == 0)
			env[x] = ft_strjoin("PWD=", buf);
	}
}

void	ft_change_variable_oldpwd(char **env, char *tmp)
{
	int		x;
	int		oldpwd;
	char	*buf;

	x = 0;
	oldpwd = 0;
	buf = getcwd(NULL, 0);
	while (env[++x])
	{
		if (ft_strncmp(env[x], "OLDPWD=", 7) == 0)
		{
			env[x] = ft_strjoin("OLDPWD=", tmp);
			oldpwd = 1;
		}
	}
	if (oldpwd == 0)
	{
		printf("minishell : cd: OLDPWD not set\n");
		chdir(tmp);
	}
	else if (oldpwd == 1)
		ft_change_pwd(env, buf);
}

void	ft_cd(char **env)
{
	char	*argumentos;
	char	*tmp;

	argumentos = ".."; // ? Provisional, esto lo da la estructura
	if (!argumentos)
	{
		tmp = getcwd(NULL, 0);
		if (chdir(getenv("HOME")) != 0)
			printf("minishell : cd: HOME not set\n");
		else
			ft_change_variable_oldpwd(env, tmp);
	}
	else if (ft_strncmp(argumentos, "..", 3) == 0)
	{
		tmp = getcwd(NULL, 0);
		chdir("..");
		ft_change_variable_oldpwd(env, tmp);
	}
	else
	{
		tmp = getcwd(NULL, 0);
		if (chdir(argumentos) != 0)
			printf("cd: No existe el directorio: %s\n", argumentos);
		else
			ft_change_variable_oldpwd(env, tmp);
	}
}
