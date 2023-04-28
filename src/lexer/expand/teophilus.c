/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teophilus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:06:55 by sasalama          #+#    #+#             */
/*   Updated: 2023/01/14 16:45:56 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	tiberio_39(t_general_data *gen_data, t_teo teophi)
{
	teophi.of[teophi.w++] = gen_data->s[teophi.i++];
	teophi.w = comillas_simples(&gen_data->s[teophi.i], gen_data, 1, teophi);
	teophi.i = ft_tiberio_comillas_simples(gen_data, teophi.i);
	return (tiberio(gen_data, teophi));
}

int	tiberio_34(t_general_data *gen_data, t_teo teophi)
{
	teophi.of[teophi.w++] = gen_data->s[teophi.i++];
	teophi.w = comillas_dobles(&gen_data->s[teophi.i], gen_data, 0, teophi);
	teophi.i = ft_tiberio_comillas_dobles(gen_data, teophi.i);
	return (tiberio(gen_data, teophi));
}

int	tiberio_dollar(t_general_data *gen_data, t_teo teophi)
{
	if (gen_data->s[teophi.i + 1] != '"' && gen_data->s[teophi.i + 1] != 39)
	{
		teophi.w = dollar(&gen_data->s[teophi.i], gen_data, 0, teophi);
		teophi.i++;
		if (gen_data->s[teophi.i] >= '0' && gen_data->s[teophi.i] <= '9')
		{
			teophi.i++;
			return (tiberio(gen_data, teophi));
		}
		while (gen_data->s[teophi.i] != ' ' && gen_data->s[teophi.i] != 39
			&& gen_data->s[teophi.i] != '"' && gen_data->s[teophi.i]
			&& gen_data->s[teophi.i] != '/' && gen_data->s[teophi.i] != '='
			&& gen_data->s[teophi.i] != '|' && gen_data->s[teophi.i] != '$')
		{
			teophi.i++;
		}
		return (tiberio(gen_data, teophi));
	}
	else
		return (tiberio_dollar2(gen_data, teophi));
}

int	tiberio(t_general_data *gen_data, t_teo teophi)
{
	if (gen_data->s[teophi.i])
	{
		if (gen_data->s[teophi.i] == '$')
			return (tiberio_dollar(gen_data, teophi));
		else if (gen_data->s[teophi.i] == 39)
			return (tiberio_39(gen_data, teophi));
		else if (gen_data->s[teophi.i] == '"')
			return (tiberio_34(gen_data, teophi));
		teophi.of[teophi.w++] = gen_data->s[teophi.i++];
		return (tiberio(gen_data, teophi));
	}
	return (teophi.w);
}

char	*teophilus(t_general_data *gen_data)
{
	t_teo	teophi;

	teophi.i = 0;
	teophi.w = 0;
	teophi.of = malloc(sizeof(char ) * (lens(gen_data->s) + 500));
	teophi.w = tiberio(gen_data, teophi);
	teophi.of[teophi.w] = '\0';
	free(gen_data->s);
	return (teophi.of);
}
