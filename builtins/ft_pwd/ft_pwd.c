/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama <sasalama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:08:37 by sasalama          #+#    #+#             */
/*   Updated: 2022/08/09 17:04:32 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_pwd(void)
{
	char	*buf;
	int		arguments;

	arguments = 0; // ? Provisional, esto lo da la estructura
	if (arguments == 0)
	{
		buf = getcwd(NULL, 0);
		printf("%s\n", buf);
		free(buf);
	}
	else
		printf("pwd: too many arguments\n");
}
