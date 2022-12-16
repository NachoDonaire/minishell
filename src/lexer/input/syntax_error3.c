/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntx_error3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:27:40 by sasalama          #+#    #+#             */
/*   Updated: 2022/12/16 19:44:08 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_free_joined(char	*joined)
{
	free(joined);
	return (1);
}

int	check_single(char *s, int a, int n_pipes)
{
	int		i;
	char	*joined;

	i = 0;
	if (a != n_pipes)
		joined = ft_strjoin(s, "|");
	else
		joined = ft_strjoin(s, "");
	while (joined[i])
	{
		if (joined[i] == '<')
		{
			i++;
			if (joined[i] == '|')
				return (ft_free_joined(joined));
			i++;
			while (joined[i] && joined[i] == ' ')
				i++;
			if (joined[i] == '|' || joined[i] == '<' || joined[i] == '>')
				return (ft_free_joined(joined));
		}
		i++;
	}
	free(joined);
	return (0);
}

int	check_double(char *s, int a, int n_pipes)
{
	int		i;
	char	*joined;

	i = 0;
	if (a != n_pipes)
		joined = ft_strjoin(s, "|");
	else
		joined = ft_strjoin(s, "");
	while (joined[i])
	{
		if (joined[i] == '>')
		{
			i++;
			if (joined[i] == '|' || joined[i] == '<')
				return (ft_free_joined(joined));
			i++;
			while (joined[i] && joined[i] == ' ')
				i++;
			if (joined[i] == '|' || joined[i] == '<' || joined[i] == '>')
				return (ft_free_joined(joined));
		}
		i++;
	}
	free(joined);
	return (0);
}

int	check_reds(char *s)
{
	int		i;
	char	**tommy;
	int		n_pipes;

	tommy = ft_split(s, '|');
	n_pipes = pipes_count(s);
	i = 0;
	while (tommy[i])
	{
		if (check_double(tommy[i], i, n_pipes) == 1)
		{
			ft_free_arg(tommy);
			return (1);
		}
		if (check_single(tommy[i], i, n_pipes) == 1)
		{
			ft_free_arg(tommy);
			return (1);
		}
		i++;
	}
	ft_free_arg(tommy);
	return (0);
}

int	check_tukle(char *s)
{
	int		i;
	int		y;
	int		z;
	char	**tmp;

	y = 0;
	z = 0;
	i = 0;
	tmp = ft_split(s, '|');
	while (tmp[i])
	{
		while (tmp[i][y] == ' ' && tmp[i][y])
		{
			z++;
			y++;
		}
		while (tmp[i][y])
		{
			if (tmp[i][y] == '>' || tmp[i][y] == '<')
			{
				if (y == z)
				{
					ft_free_arg(tmp);
					return (1);
				}
			}
			y++;
		}
		i++;
		y = 0;
		z = 0;
	}
	ft_free_arg(tmp);
	return (0);
}

				
