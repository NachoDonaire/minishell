/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:27:40 by sasalama          #+#    #+#             */
/*   Updated: 2023/01/14 16:48:13 by ndonaire         ###   ########.fr       */
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

int	check_reds_quote(char *s, int *i)
{
	if (s[i[0]] == '"')
	{
		i[0]++;
		while (s[i[0]] != '"' && s[i[0]])
			i[0]++;
		i[0]++;
	}
	if (s[i[0]] == 39)
	{
		i[0]++;
		while (s[i[0]] != 39 && s[i[0]])
			i[0]++;
		i[0]++;
	}
	if (s[i[0]] == '>' || s[i[0]] == '<')
	{
		while ((s[i[0]] == '<' || s[i[0]] == '>' || s[i[0]] == ' ') && s[i[0]])
			i[0]++;
		if (s[i[0]] == '|' || s[i[0]] == '\0' || s[i[0]] == '>'
			|| s[i[0]] == '<')
			return (1);
		if ((s[0] == '<' || s[0] == '>') && s[1] != '<')
			return (1);
	}
	return (0);
}

int	check_reds(char *s)
{
	int	i[1];
	int	x;

	i[0] = 0;
	while (s[i[0]])
	{
		x = check_reds_quote(s, i);
		if (x == 1)
			return (1);
		i[0]++;
	}
	return (0);
}
