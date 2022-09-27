/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comillas.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:23:04 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/08 09:57:38 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

/*en el propio comando*/
int	check_cmllas(char *s)
{
	int		i;

	i = 0;
	while (s[i] == ' ')
		i++;
	if ((s[i] == '"' || s[i] == 39) && lens(s) > 1)
	{
		while (s[i] != ' ' && s[i])
		{
			i++;
			if (s[i] == '"' || s[i] == 39)
				return (1);
		}
	}
	return (0);
}

char	*gest_cmllas(char *s)
{
	char	*sol;
	int		i;
	int		y;

	i = 0;
	y = 0;
	sol = malloc(sizeof(char) * lens(s));
	while (s[i] != '"' && s[i] != 39)
		i++;
	i++;
	while (s[i] != '"' && s[i] != 39)
	{
		sol[y++] = s[i++];
	}
	sol[y] = '\0';
	return (sol);
}
/*mas alla del comando*/
/*
void	cmllas_args(t_general_data *gen_data, int position)
{
	int	i;
	char	**s;
	char	*m;
	int	y;

	y = 0;
	i = 0;
	s = gen_data->cmd[position].args;
	while (s[i])
	{
		if (i == 0)
			m = ft_strjoin(s[i], " ");
		m = ft_strjoin(m, s[i]);
		i++;
	}
	i = 0;
	while (m[i])
	{
		if (m[i] == '"')
			y++;
*/









