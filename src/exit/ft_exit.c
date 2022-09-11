/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:05:19 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/07 17:07:15 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_check_exit(char *s)
{
	if (ft_strncmp(s, "exit", 5) == 0)
		return (1);
	return (0);
}

void	ft_exit(char *texto)//, char **tmp)
{
	if (texto)
		printf("%s\n", texto);
	else
		printf("exit\n");
/*	while (tmp[x])
		free(tmp[x++]);
	free(tmp);
	*/
	exit(0);
}
