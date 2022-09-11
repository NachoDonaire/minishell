/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 10:52:00 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/08 10:52:22 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_print_bad(t_general_data *gen_data, int p, int x)
{
	printf("unset: %s: ", gen_data->blt[p].args[x]);
	printf("invalid parameter name\n");
	ft_change_bad_status(gen_data->env, gen_data);
}

void	ft_not_equal(t_general_data *gen_data, int p, int x)
{
	char	*cp;

	cp = gen_data->blt[p].args[x];
	gen_data->blt[p].args[x] = ft_strjoin(cp, "=");
	free(cp);
}
