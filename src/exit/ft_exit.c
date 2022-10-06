/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:05:19 by sasalama          #+#    #+#             */
/*   Updated: 2022/10/06 15:29:04 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_check_exit(char *s)
{
	if (ft_strncmp(s, "exit", 5) == 0)
		return (1);
	return (0);
}

void	ft_exit(char *texto, char **tmp)
{
	if (texto)
		printf("%s\n", texto);
	else
		printf("exit\n");
	free(texto);
	ft_free_arg(tmp);
	exit(0);
}
