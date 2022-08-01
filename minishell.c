/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salustianosalamanca <salustianosalamanc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:16:04 by salustianos       #+#    #+#             */
/*   Updated: 2022/08/01 13:07:52 by salustianos      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// *! Necesito estructura para saber si tiene argumentos y cuales son
// *! Necesito primero obtener las variables de entorno
void	ft_pwd()
{
	char *buf;
	int	argumentos;

	argumentos = 0; // ? Provisional, esto lo da la estructura
	if (argumentos == 0)
	{
		buf = getcwd(NULL, 0);
		printf("%s\n", buf);
	}
	else
		printf("pwd: Demasiados argumentos\n");
}
// *! Hay que modificar el codigo por las variables de entorno
// *! Ver si funciona con directorios sin permiso
void	ft_cd(char **env)
{
	char *argumento;
	int	x;
	char *tmp;
	char *buf;

	x = 0;
	argumento = ".."; // ? Provisional, esto lo da la estructura
	if (!argumento)
	{
		tmp = getcwd(NULL, 0);
		chdir(getenv("HOME"));
		buf = getcwd(NULL, 0);
		while (env[x])
		{
			if (ft_strncmp(env[x], "PWD=", 4) == 0)
				env[x] = ft_strjoin("PWD=", buf);
			if (ft_strncmp(env[x], "OLDPWD=", 7) == 0)
				env[x] = ft_strjoin("OLDPWD=", tmp);
			x++;
		}
	}
	else if (ft_strncmp(argumento, "..", 3) == 0)
	{
		tmp = getcwd(NULL, 0);
		chdir("..");
		buf = getcwd(NULL, 0);
		while (env[x])
		{
			if (ft_strncmp(env[x], "PWD=", 4) == 0)
				env[x] = ft_strjoin("PWD=", buf);
			if (ft_strncmp(env[x], "OLDPWD=", 7) == 0)
				env[x] = ft_strjoin("OLDPWD=", tmp);
			x++;
		}
	}
		
	else
	{
		tmp = getcwd(NULL, 0);
		if (chdir(argumento) != 0)
			printf("cd: No existe el directorio\n");
		buf = getcwd(NULL, 0);
		while (env[x])
		{
			if (ft_strncmp(env[x], "PWD=", 4) == 0)
				env[x] = ft_strjoin("PWD=", buf);
			if (ft_strncmp(env[x], "OLDPWD=", 7) == 0)
				env[x] = ft_strjoin("OLDPWD=", tmp);
			x++;
		}
	}
		
}

char	**get_env(char **envp) // ? Esta funcción la ejecutamos al principio para obtener las variables de entorno
{
	char **env;
	int x;
	int	y;

	env = malloc(sizeof(envp)); // ? Provisional, esto lo da la estructura
	x = 0;
	y = 0;
	env = envp;
	while (env[x])
	{
		if (ft_strncmp(env[x], "SHLVL=", 6) == 0)
		{
			y = ft_strlen(env[x]);
			while (y > 0)
			{
				if (env[x][y] >= '0' && env[x][y] <= '8')
				{
					env[x][y]++;
					break;
				}
				if (env[x][y] == '9')
				{
					env[x][y] = 0;
					env[x][y - 1]++;
					break;
				}
				y--;
			}
			break;
		}
		x++;
	}
	return (env);
}

void	ft_env(char **env)
{
	int x;

	x = 0;
	while (env[x])
		printf("%s\n",env[x++]);
}

void	ft_echo(char **env)
{
	int x;
	int y;
	int variable;
	char *argumento;
	char *copia;

	argumento = "TERM="; // ? Provisional, esto lo da la estructura
	copia = NULL;
	x = 0;
	y = 1;
	variable = 0; // ? Provisional, esto lo da la estructura
	if (variable == 1)
	{
		while (env[x])
		{
			if (ft_strncmp(env[x], argumento, ft_strlen(argumento)) == 0)
			{
				copia = ft_strchr(env[x], '=');
				while (copia[y])
					printf("%c", copia[y++]);
				printf("\n");
				break;
			}
			x++;
		}
	}
	else
		printf("%s\n", argumento);
	
}

void	ft_unset()
{
	
}

void	ft_export(char **env)
{
	
}

// TODO Implementar libreria libft en Mafefile para no añadir los archivos a mano
