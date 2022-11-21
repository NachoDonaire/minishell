/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teophilus5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:42:24 by sasalama          #+#    #+#             */
/*   Updated: 2022/11/21 10:51:54 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	dollar_d(char *s, char *o, t_general_data *data, int f, int w, int i)
{
	if (s[i] == '$')
		return (dollar(&s[i], o, data, f, w));
	return (w);
}

int	dollar_2(char *s, char *o, t_general_data *data, int f, int w, int i)
{
	i++;
	if (s[i] >= '0' && s[i] <= '9')
		return (w);
	i = dollar_ref_0_i(s, i);
	return (dollar_d(s, o, data, f, w, i));
}

int	dollar(char *s, char *o, t_general_data *gen_data, int ref, int w)
{
	int		i;
	char	*c;

	i = 0;
	c = copy_var(&s[i + 1]);
	if (!c[0])
		return (not_dollar(s, w, i, o));
	if (ref == 0)
	{
		c = variable(gen_data, c);
		w = dollar_ref_0_w(c, o, w);
		return (dollar_2(s, o, gen_data, ref, w, i));
	}
	else
	{
		if (s[i] == '$')
			o[w++] = s[i++];
		while (s[i] != ' ' && s[i] != 39 && s[i] != '"'
			&& s[i] && s[i] != '/' && s[i] != '=' && s[i] != '$')
			o[w++] = s[i++];
		return (dollar_2(s, o, gen_data, ref, w, i));
	}
	return (w);
}

int	ft_tiberio_comillas_simples(t_general_data *gen_data, int i)
{
	while (gen_data->s[i] != 39)
		i++;
	i++;
	return (i);
}

int	ft_tiberio_comillas_dobles(t_general_data *gen_data, int i)
{
	while (gen_data->s[i] != '"')
		i++;
	i++;
	return (i);
}
