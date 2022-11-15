/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:30:51 by sasalama          #+#    #+#             */
/*   Updated: 2022/11/15 12:57:20 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	double_quotes(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '"')
		i++;
	return (i);
}

int	single_quotes(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != 39)
		i++;
	return (i);
}


int	check_millas(char *s)
{
	int	i;
	int	cd;
	int	cs;

	i = 0;
	cd = 0;
	cs = 0;
	while (s[i])
	{
		if (s[i] == '"')
		{
			cd++;
			i++;
			i += double_quotes(&s[i]);
			while (s[i] == '"' && s[i]) 
			{
				i++;
				cd++;
			}
		}
		else if (s[i] == 39)
		{
			cs++;
			i++;
			i += single_quotes(&s[i]);
			while (s[i] == 39 && s[i])
			{
				i++;
				cs++;
			}
		}
		i++;
	}
	if (cs % 2 != 0 || cd % 2 != 0)
		return (1);
	return (0);
}

int	check_pipes(char *s)
{
	int	i;
	int	pipes;

	i = 0;
	pipes = 0;
	while (s[i])
	{
		if (s[i] == '|')
		{
			i++;
			if (!s[i])
				return (1);
			while (s[i])
			{
				if (s[i] != ' ' && s[i] != '|')
					pipes++;
				i++;
			}
			if (pipes == 0)
				return (1);
		}
		i++;
	}
	return (0);
}

int	pipes_count(char *s)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (s[i])
	{
		if (s[i] == '|')
			y++;
		i++;
	}
	return (y);
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
			{
				free(joined);
				return (1);
			}
			i++;
			while (joined[i] && joined[i] == ' ')
				i++;
			if (joined[i] == '|' || joined[i] == '<' || joined[i] == '>')
			{
				free(joined);
				return (1);
			}
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
			{
				free(joined);
				return (1);
			}
			i++;
			while (joined[i] && joined[i] == ' ')
				i++;
			if (joined[i] == '|' || joined[i] == '<' || joined[i] == '>')
			{
				free(joined);
				return (1);
			}
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
	if (check_millas(s) == 1)
	{
		perror("Minishell: Syntax error");
		free(s);
		return (1);
	}
	if (check_pipes(s) == 1)
	{
		perror("Minishell: Syntax error");
		free(s);
		return (1);
	}
	if (check_reds(s) == 1)
	{
		perror("Minishell: Syntax error");
		free(s);
		return (1);
	}
	if (check_dots(s) == 1)
	{
		perror("Minishell: Syntax error");
		free(s);
		return (1);
	}
	return (0);
}
