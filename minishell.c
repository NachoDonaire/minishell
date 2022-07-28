/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salustianosalamanca <salustianosalamanc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:16:04 by salustianos       #+#    #+#             */
/*   Updated: 2022/07/28 19:59:27 by salustianos      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*x1;
	unsigned char	*x2;

	i = 0;
	x1 = (unsigned char *)s1;
	x2 = (unsigned char *)s2;
	while (i < n)
	{
		if (x1[i] == '\0')
			return ((x1[i] - x2[i]));
		if (x1[i] != x2[i])
			return ((x1[i] - x2[i]));
		i++;
	}
	return (0);
}

void	ft_pwd()
{
	char *buf;

	buf = getcwd(NULL, 0);
	printf("%s\n", buf);
}

void	ft_echo()
{

}

void	ft_cd()
{

}
