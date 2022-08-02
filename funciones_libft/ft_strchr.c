/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama <sasalama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:15:58 by sasalama          #+#    #+#             */
/*   Updated: 2022/08/02 13:30:41 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	s2;

	i = 0;
	s2 = (unsigned char)c;
	while (*(s + i) && s2 != *(s + i))
		i++;
	if (*(s + i) == s2)
		return ((char *)(s + i));
	return (0);
}
