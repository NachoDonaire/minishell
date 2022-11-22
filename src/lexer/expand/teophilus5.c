/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teophilus5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:42:24 by sasalama          #+#    #+#             */
/*   Updated: 2022/11/22 11:14:05 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	dollar_d(char *s, t_general_data *data, int i, t_teo teophi)
{
	if (s[i] == '$')
		return (dollar(&s[i], data, teophi.f, teophi));
	return (teophi.w);
}

int	dollar_2(char *s, t_general_data *data, int i, t_teo teophi)
{
	i++;
	if (s[i] >= '0' && s[i] <= '9')
		return (teophi.w);
	i = dollar_ref_0_i(s, i);
	return (dollar_d(s, data, i, teophi));
}

int	dollar(char *s, t_general_data *gen_data, int ref, t_teo teophi)
{
	int		i;
	char	*c;

	i = 0;
	teophi.f = ref;
	c = copy_var(&s[i + 1]);
	if (!c[0])
		return (not_dollar(s, teophi.w, i, teophi.of));
	if (ref == 0)
	{
		c = variable(gen_data, c);
		teophi.w = dollar_ref_0_w(c, teophi.of, teophi.w);
		return (dollar_2(s, gen_data, i, teophi));
	}
	else
	{
		if (s[i] == '$')
			teophi.of[teophi.w++] = s[i++];
		while (s[i] != ' ' && s[i] != 39 && s[i] != '"'
			&& s[i] && s[i] != '/' && s[i] != '=' && s[i] != '$')
			teophi.of[teophi.w++] = s[i++];
		return (dollar_2(s, gen_data, i, teophi));
	}
	return (teophi.w);
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
