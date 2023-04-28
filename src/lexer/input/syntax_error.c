/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:30:51 by sasalama          #+#    #+#             */
/*   Updated: 2023/01/14 16:12:57 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	mini_check_dots(char *tommy, int a, int n_pipes)
{
	int		i;
	char	*s;

	i = 0;
	if (a != n_pipes)
		s = ft_strjoin(tommy, "|");
	else
		s = ft_strjoin(tommy, "");
	while (s[i] == ' ' && s[i])
		i++;
	if (s[i] == '.' && s[i])
	{
		i++;
		if (s[i] == ' ' || !s[i])
		{
			free(s);
			return (1);
		}
	}
	free(s);
	return (0);
}

int	check_dots(char *s)
{
	int		i;
	int		n_pipes;
	char	**tommy;

	tommy = ft_split(s, '|');
	n_pipes = pipes_count(s);
	i = 0;
	while (tommy[i])
	{
		if (mini_check_dots(tommy[i], i, n_pipes) == 1)
		{
			ft_free_arg(tommy);
			return (1);
		}
		i++;
	}
	ft_free_arg(tommy);
	return (0);
}

int	syntax_error(char *s)
{
	if (check_millas(s) == 1 || check_pipes(s) == 1
		|| check_reds(s) == 1 || check_dots(s) == 1)
	{
		perror("Minishell: Syntax error");
		free(s);
		return (1);
	}
	return (0);
}
