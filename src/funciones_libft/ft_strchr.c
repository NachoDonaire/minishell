/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:59:41 by sasalama          #+#    #+#             */
/*   Updated: 2022/11/14 13:32:39 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	s2;

	i = 0;
	s2 = (unsigned char)c;
	if (!s)
		return (0);
	while (*(s + i) && s2 != *(s + i))
		i++;
	if (*(s + i) == s2)
		return ((char *)(s + i));
	return (0);
}
