/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:05:19 by sasalama          #+#    #+#             */
/*   Updated: 2022/11/14 20:25:31 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_check_exit(char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ')
		i++;
	if (ft_strncmp(&s[i], "exit", 4) == 0 && s[i + 4] && s[i + 4] != ' ')
		return (0);
	if (ft_strncmp(&s[i], "exit", 4) == 0)
		return (1);
	return (0);
}

void	ft_exit(char *texto, char **tmp)
{
	if (texto)
		printf("exit\n");
	else
		printf("exit\n");
	free(texto);
	ft_free_arg(tmp);
	exit(0);
}
