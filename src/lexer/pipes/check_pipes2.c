/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipes2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 10:34:27 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/08 10:34:55 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*handle_cont_pipe(char *join)
{
	int	i;

	i = 0;
	if (finder(join, "|") == 1)
	{
		while (join[i] != '|')
			i++;
		join[i] = '\0';
	}
	return (join);
}
