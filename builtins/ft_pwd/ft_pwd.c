/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salustianosalamanca <salustianosalamanc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:08:37 by sasalama          #+#    #+#             */
/*   Updated: 2022/08/04 14:21:33 by salustianos      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_pwd(void)
{
	char	*buf;
	int		argumentos;

	argumentos = 0; // ? Provisional, esto lo da la estructura
	if (argumentos == 0)
	{
		buf = getcwd(NULL, 0);
		printf("%s\n", buf);
	}
	else
		printf("pwd: Demasiados argumentos\n");
}