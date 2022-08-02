/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salustianosalamanca <salustianosalamanc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:16:04 by salustianos       #+#    #+#             */
/*   Updated: 2022/08/02 10:05:22 by salustianos      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// *! Necesito estructura para saber si tiene argumentos y cuales son
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
// *! Ver si funciona con directorios sin permiso
void	ft_cd(char **env)
{
	char *argumentos;
	int	x;
	char *tmp;
	char *buf;

	x = 0;
	argumentos = ".."; // ? Provisional, esto lo da la estructura
	if (!argumentos)
	{
		tmp = getcwd(NULL, 0);
		chdir(getenv("HOME"));
		if (chdir(argumentos) != 0)
			printf("minishell : cd: HOME not set\n");
		buf = getcwd(NULL, 0);
		while (env[x])
		{
			if (ft_strncmp(env[x], "PWD=", 4) == 0)
				env[x] = ft_strjoin("PWD=", buf);
			if (ft_strncmp(env[x], "OLDPWD=", 7) == 0) // ? Tengo que comprobar si existe el OLDPWD
				env[x] = ft_strjoin("OLDPWD=", tmp);
			x++;
		}
	}
	else if (ft_strncmp(argumentos, "..", 3) == 0)
	{
		tmp = getcwd(NULL, 0);
		chdir("..");
		buf = getcwd(NULL, 0);
		while (env[x])
		{
			if (ft_strncmp(env[x], "PWD=", 4) == 0)
				env[x] = ft_strjoin("PWD=", buf);
			if (ft_strncmp(env[x], "OLDPWD=", 7) == 0) // ? Tengo que comprobar si existe el OLDPWD
				env[x] = ft_strjoin("OLDPWD=", tmp);
			x++;
		}
	}
		
	else
	{
		tmp = getcwd(NULL, 0);
		if (chdir(argumentos) != 0)
			printf("cd: No existe el directorio: %s\n", argumentos);
		buf = getcwd(NULL, 0);
		while (env[x])
		{
			if (ft_strncmp(env[x], "PWD=", 4) == 0)
				env[x] = ft_strjoin("PWD=", buf);
			if (ft_strncmp(env[x], "OLDPWD=", 7) == 0) // ? Tengo que comprobar si existe el OLDPWD
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
					break ;
				}
				if (env[x][y] == '9')
				{
					env[x][y] = 0;
					env[x][y - 1]++;
					break ;
				}
				y--;
			}
			break ;
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

int ft_n(char *argumento)
{
	int x;
	
	x = 1;
	while(argumento[x])
	{
		if (argumento[x] != 'n')
			return (1);
		x++;
	}
	return (0);
}

int ft_dollar(char *argumento)
{
	int x;
	
	x = 1;
	while(argumento[x])
	{
		if (argumento[x] != '$')
			return (1);
		x++;
	}
	return (0);
}

void	ft_echo(char **env) // ? Revisar
{
	int p_env;
	int y;
	int z;
	char *argumentos; // ? Provisional, esto lo da la estructura
	int	new_line;
	char *tmp;
	char **nb_argumentos;

	p_env = 0;
	new_line = 1;
	y = 0;
	z = 0;
	argumentos = "-nnnnnn t -nnnnn$TERM";
	if (argumentos)
	{
		nb_argumentos = ft_split(argumentos, ' ');
		while (nb_argumentos[p_env])
		{
			if (ft_strncmp(nb_argumentos[p_env], "-n", 2) == 0 && ft_n(nb_argumentos[p_env]) == 0)
				new_line = 0;
			else
			{
				if (ft_dollar(nb_argumentos[p_env]) == 0)
					printf("%s", nb_argumentos[p_env]);
				else
				{
					while (nb_argumentos[p_env][y])
					{
						if (nb_argumentos[p_env][y] != '$')
							printf("%c",nb_argumentos[p_env][y]);
						else if (nb_argumentos[p_env][y] == '$')
						{
							y++;
							tmp = ft_substr(nb_argumentos[p_env], y, ft_strlen(nb_argumentos[p_env]));
							tmp = ft_strjoin(tmp, "=");
							while (env[z])
							{
								if (ft_strncmp(env[z], tmp, ft_strlen(tmp)) == 0)
								{
									tmp = ft_strchr(env[z], '=');
									tmp = ft_substr(tmp, 1, ft_strlen(tmp));
									printf("%s", tmp);
									break ;
								}
								z++;
							}
							break ;
						}
						y++;
					}
				}
				if (nb_argumentos[p_env + 1])
					printf(" ");
			}
			p_env++;
		}
		p_env = 0;
		while (nb_argumentos[p_env])
			free(nb_argumentos[p_env++]);
		free(nb_argumentos);
	}
	if(new_line == 0)
		printf("%%");
	printf("\n");
	
}

void	ft_unset(char **env)
{
	char	*variable;
	int		x;

	x = 0;
	variable = "PRUEBA="; // ? Provisional, esto lo da la estructura
	while (env[x])
	{
		if (ft_strncmp(ft_substr(env[x], 0, ft_strlen(variable)), variable, ft_strlen(variable)) == 0)
		{
			while (env[x + 1])
			{
				env[x] = env[x + 1];
				x++;
			}
			env[x] = NULL;
			break ;
		}
		x++;
	}
}

void	ft_export(char **env)
{
	char	*argumento;
	char	*variable;
	int		x;
	int		is_there;

	variable = "PRUEBA="; // ? Provisional, esto lo da la estructura
	argumento = "Hola"; // ? Provisional, esto lo da la estructura
	x = 0;
	is_there = 0;
	while (env[x])
	{
		if (ft_strncmp(ft_substr(env[x], 0, ft_strlen(variable)), variable, ft_strlen(variable)) == 0 && ft_strncmp(ft_strchr(env[x], '='),ft_strjoin("=", argumento) , ft_strlen(argumento)) == 0)
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
				break;
			}
			x++;
		}
		env[x] = ft_strjoin(variable,argumento);
		env[x + 2] = NULL;
	}
}

// TODO Implementar libreria libft en Mafefile para no añadir los archivos a mano
