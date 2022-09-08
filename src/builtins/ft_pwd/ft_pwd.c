/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:58:03 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/08 12:22:03 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_pwd(t_general_data *gen_data)
{
	char	*buf;

	buf = getcwd(NULL, 0);
	printf("%s\n", buf); //change to write
	ft_change_good_status(gen_data->env);
	free(buf);
}
