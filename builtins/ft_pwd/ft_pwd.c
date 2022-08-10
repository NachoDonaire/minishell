/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama <sasalama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:08:37 by sasalama          #+#    #+#             */
/*   Updated: 2022/08/10 12:45:26 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_pwd(char **env)
{
	char	*buf;

	buf = getcwd(NULL, 0);
	printf("%s\n", buf);
	ft_change_good_status(env);
	free(buf);
}
