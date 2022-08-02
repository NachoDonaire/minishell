/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama <sasalama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:10:10 by sasalama          #+#    #+#             */
/*   Updated: 2022/08/02 15:36:50 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_n(char *argumento)
{
	int	x;

	x = 1;
	while (argumento[x])
	{
		if (argumento[x] != 'n')
			return (1);
		x++;
	}
	return (0);
}

int	ft_dollar(char *argumento)
{
	int	x;

	x = 1;
	while (argumento[x])
	{
		if (argumento[x] != '$')
			return (1);
		x++;
	}
	return (0);
}

void	ft_echo(char **env) // *! MODIFICAR
{
	int		p_env;
	int		y;
	int		z;
	char	*argumentos; // ? Provisional, esto lo da la estructura
	int		new_line;
	char	*tmp;
	char	**nb_argumentos;

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
	if (new_line == 0)
		printf("%%");
	printf("\n");
	
}