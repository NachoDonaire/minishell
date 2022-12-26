/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teophilus6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:22:01 by sasalama          #+#    #+#             */
/*   Updated: 2022/12/26 14:30:20 by sasalama         ###   ########.fr       */
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
