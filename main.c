/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salustianosalamanca <salustianosalamanc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:15:38 by salustianos       #+#    #+#             */
/*   Updated: 2022/08/01 11:30:00 by salustianos      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_comprobar_salida(char *s)
{
	if (ft_strncmp(s, "exit", 5) == 0)
		return (1);
	return (0);
}

int main(int argc, char *argv[], char *envp[])
{
	int x;
	char *texto;

	(void)argc;
	(void)argv;
	x = 0;
	while (x == 0)
	{
		texto = readline("Minishell> ");
		printf("%s\n", texto);
		if (ft_comprobar_salida(texto) == 1)
			exit(0);
		ft_comprobar_comando(texto, envp);
	}
	return (0);
}