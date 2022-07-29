/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salustianosalamanca <salustianosalamanc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:16:04 by salustianos       #+#    #+#             */
/*   Updated: 2022/07/29 19:22:29 by salustianos      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// *! Necesito estructura para saber si tiene argumentos y cuales son
// *! OBTENER PRIMERO EL ENVIRONMENT
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
