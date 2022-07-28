/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salustianosalamanca <salustianosalamanc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:15:38 by salustianos       #+#    #+#             */
/*   Updated: 2022/07/28 19:42:20 by salustianos      ###   ########.fr       */
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

void	ft_pwd()
{
	char *buf;

	buf = getcwd(NULL, 0);
	printf("%s\n", buf);
}

void	ft_comprobar_comando(char *s)
{
	int x;

	x = 0;
	while (s[x])
	{
		if (s[x] == 'p')
		{
			if (s[x + 1] == 'w')
			{
				if (s[x + 2] == 'd' && s[x + 3] == '\0')
					ft_pwd();
			}
		}
		x++;
	}
}

int main(void)
{
	int x;
	char *texto;

	x = 0;
	while (x == 0)
	{
		texto = readline("Minishell> ");
		printf("%s\n", texto);
		if (ft_comprobar_salida(texto) == 1)
			exit(0);
		ft_comprobar_comando(texto);
	}
	return (0);
}