/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teophilus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:06:55 by sasalama          #+#    #+#             */
/*   Updated: 2022/11/21 10:48:18 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	tiberio_39(t_general_data *gen_data, char *of, int i, int w)
{
	of[w++] = gen_data->s[i++];
	w = comillas_simples(&gen_data->s[i], of, gen_data, 1, w);
	i = ft_tiberio_comillas_simples(gen_data, i);
	return (tiberio(gen_data, of, i, w));
}

int	tiberio_34(t_general_data *gen_data, char *of, int i, int w)
{
	of[w++] = gen_data->s[i++];
	w = comillas_dobles(&gen_data->s[i], of, gen_data, 0, w);
	i = ft_tiberio_comillas_dobles(gen_data, i);
	return (tiberio(gen_data, of, i, w));
}

int	tiberio_dollar(t_general_data *gen_data, char *of, int i, int w)
{
	if (gen_data->s[i + 1] != '"' && gen_data->s[i + 1] != 39)
	{
		w = dollar(&gen_data->s[i], of, gen_data, 0, w);
		while (gen_data->s[i] != ' ' && gen_data->s[i] != 39
			&& gen_data->s[i] != '"' && gen_data->s[i]
			&& gen_data->s[i] != '/' && gen_data->s[i] != '=')
		{
			if (gen_data->s[i] == '$')
			{
				i++;
				if (gen_data->s[i] >= '0' && gen_data->s[i] <= '9')
					return (tiberio(gen_data, of, i + 1, w));
			}
			i++;
		}
		return (tiberio(gen_data, of, i, w));
	}
	else
		return (tiberio(gen_data, of, i + 1, w));
}

int	tiberio(t_general_data *gen_data, char *of, int i, int w)
{
	if (gen_data->s[i])
	{
		if (gen_data->s[i] == '$')
			return (tiberio_dollar(gen_data, of, i, w));
		else if (gen_data->s[i] == 39)
			return (tiberio_39(gen_data, of, i, w));
		else if (gen_data->s[i] == '"')
			return (tiberio_34(gen_data, of, i, w));
		of[w++] = gen_data->s[i++];
		return (tiberio(gen_data, of, i, w));
	}
	return (w);
}

char	*teophilus(t_general_data *gen_data)
{
	int		i;
	char	*of;
	int		w;

	i = 0;
	w = 0;
	of = malloc(sizeof(char ) * (lens(gen_data->s) + 500));
	w = tiberio(gen_data, of, i, w);
	of[w] = '\0';
	free(gen_data->s);
	return (of);
}
