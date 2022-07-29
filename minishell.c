/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salustianosalamanca <salustianosalamanc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:16:04 by salustianos       #+#    #+#             */
/*   Updated: 2022/07/29 16:11:53 by salustianos      ###   ########.fr       */
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

void	ft_cd()
{
	int argumentos;
	char *buf;
	char *tmp;
	char *argumento;
	size_t	x;
	size_t 	y;

	buf = NULL;
	tmp = NULL;
	x = 0;
	y = 0;
	argumento = ".."; // ? Provisional, esto lo da la estructura
	argumentos = 1;  // ? Provisional, esto lo da la estructura
	if (argumentos == 0)
		chdir(getenv("HOME"));
	else if (argumento[0] != '.' && argumento[1] != '.')
	{
		if (chdir(argumento) != 0)
			printf("No existe el directorio\n");
	}
	else
	{
		tmp = buf;
		buf = getcwd(NULL, 0);
		free(tmp);
		x = ft_strlen(buf);
		y = ft_strlen(ft_strrchr(buf, '/'));
		tmp = buf;
		buf = ft_substr(buf, 0 , x - y);
		free(tmp);
		chdir(buf);
	}
}

void	ft_env()
{

}

void	ft_echo()
{

}

void	ft_unset()
{
	
}

void	ft_export()
{

}
