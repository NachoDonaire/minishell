/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salustianosalamanca <salustianosalamanc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:16:04 by salustianos       #+#    #+#             */
/*   Updated: 2022/07/29 19:57:54 by salustianos      ###   ########.fr       */
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
void	ft_cd()
{
	char *argumento;

	argumento = NULL; // ? Provisional, esto lo da la estructura
	if (!argumento)
		chdir(getenv("HOME"));
	else if (ft_strncmp(argumento, "..", 3) == 0)
		chdir("..");
	else
	{
		if (chdir(argumento) != 0)
			printf("cd: No existe el directorio\n");
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

// TODO Implementar libreria libft en Mafefile para no añadir los archivos a mano
