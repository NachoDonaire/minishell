/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama <sasalama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:08:37 by sasalama          #+#    #+#             */
/*   Updated: 2022/08/09 16:21:03 by sasalama         ###   ########.fr       */
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
		free(buf);
	}
	else
		printf("pwd: Demasiados argumentos\n");
}
