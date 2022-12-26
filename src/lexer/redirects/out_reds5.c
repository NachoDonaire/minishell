/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_reds5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:54:05 by sasalama          #+#    #+#             */
/*   Updated: 2022/12/26 13:54:24 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	find_red2_quote(char *s, int *table)
{
	if (s[table[2]] == '"')
	{
		table[2]++;
		while (s[table[2]] != '"' && s[table[2]])
			table[2]++;
	}
	else if (s[table[2]] == 39)
	{
		table[2]++;
		while (s[table[2]] != 39 && s[table[2]])
			table[2]++;
	}
}
