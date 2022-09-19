/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:07:33 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/19 20:19:56 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_print_q(t_general_data *gen_data, int x, int p)
{
	ft_print(x, gen_data, p);
	if (gen_data->blt[p].args[x + 1])
		ft_print_fdout(gen_data, ' ');
}

int	ft_check_nl2(t_general_data *gen_data, int position)
{
	int	x;
	int	z;
	int	new_line;

	x = 0;
	new_line = 1;
	while (gen_data->blt[position].args[x])
	{
		z = ft_n(gen_data->blt[position].args[x]);
		if (ft_strncmp(gen_data->blt[position].args[x], "-n", 2) == 0 && z == 0)
			new_line = 0;
		else
			ft_print_q(gen_data, x, position);
		x++;
	}
	return (new_line);
}

int	ft_check_nl(t_general_data *gen_data, int position)
{
	int	new_line;

	new_line = ft_check_nl2(gen_data, position);
	return (new_line);
}
