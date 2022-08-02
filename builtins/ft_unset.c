/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama <sasalama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:10:46 by sasalama          #+#    #+#             */
/*   Updated: 2022/08/02 14:39:45 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_unset(char **env) // *! MODIFICAR
{
	char	*v;
	int		x;
	char	*tmp;

	x = 0;
	v = "OLDPWD="; // ? Provisional, esto lo da la estructura
	while (env[x])
	{
		tmp = ft_substr(env[x], 0, ft_strlen(v));
		if (ft_strncmp(tmp, v, ft_strlen(v)) == 0)
		{
			while (env[x + 1])
			{
				env[x] = env[x + 1];
				x++;
			}
			env[x] = NULL;
			break ;
		}
		x++;
	}
}