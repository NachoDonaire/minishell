/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salustianosalamanca <salustianosalamanc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:15:38 by salustianos       #+#    #+#             */
/*   Updated: 2022/07/28 17:23:15 by salustianos      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_comprobar_salida(char *s)
{
	int x;

	x = 0;
	while (s[x])
	{
		if (s[x] == 'e')
		{
			if (s[x + 1] == 'x')
			{
				if (s[x + 2] == 'i')
				{
					if (s[x + 3] == 't' && s[x + 4] == '\0')
						return (1);
				}
			}
		}
		x++;
	}
	return (0);
}

int main(void)
{
	int x;
	char *texto;

	x = 0;
	while (x == 0)
	{
		texto = readline("");
		printf("%s\n", texto);
		if (ft_comprobar_salida(texto) == 1)
			exit(0);
	}
	return (0);
}