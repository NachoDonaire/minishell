/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teophilus6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:22:01 by sasalama          #+#    #+#             */
/*   Updated: 2022/11/22 11:22:12 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	tiberio_dollar2(t_general_data *gen_data, t_teo teophi)
{
	teophi.i++;
	return (tiberio(gen_data, teophi));
}
