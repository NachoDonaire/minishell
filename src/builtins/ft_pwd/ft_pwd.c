/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:58:03 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/07 16:53:33 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_pwd(char **env)
{
	char	*buf;

	buf = getcwd(NULL, 0);
	printf("%s\n", buf);
	ft_change_good_status(env);
	free(buf);
}
