/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teophilus6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:22:01 by sasalama          #+#    #+#             */
/*   Updated: 2023/01/10 21:40:06 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	tiberio_dollar2(t_general_data *gen_data, t_teo teophi)
{
	if (gen_data->s[teophi.i] == ' ')
	{
		teophi.i--;
		return (tiberio(gen_data, teophi));
	}
	teophi.i++;
	return (tiberio(gen_data, teophi));
}

int	dollar_not(char *s, int i, t_teo teophi)
{
	teophi.ojito = 23;
	return (not_dollar(s, teophi.w, i, teophi.of));
}

void	ft_free_c(char	*c)
{
	if (c[0])
		free(c);
}

int	dollar_else(char *s, t_general_data *gen_data, int i, t_teo teophi)
{
	if (s[i] == '$')
		teophi.of[teophi.w++] = s[i++];
	while (s[i] != ' ' && s[i] != 39 && s[i] != '"' && s[i] != '|'
		&& s[i] && s[i] != '/' && s[i] != '=' && s[i] != '$')
		teophi.of[teophi.w++] = s[i++];
	return (dollar_2(s, gen_data, i, teophi));
}
