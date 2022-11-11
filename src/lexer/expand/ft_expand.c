/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:00:59 by sasalama          #+#    #+#             */
/*   Updated: 2022/11/11 13:09:31 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_last(char	*s, int x)
{
	while (s[x])
	{
		if (s[x] == '\'' || s[x] == '\"')
		{
			x--;
			return (x);
		}
		x++;
	}
	return (x);
}

char	*ft_change(char *s)
{
	int		x;
	char	*copy;

	x = 0;
	copy = malloc(ft_strlen(s) + 1);
	while (s[x])
	{
		if (s[x] == '\'' || s[x] == '\"')
		{
			break ;
		}
		copy[x] = s[x];
		x++;
	}
	free(s);
	copy[x] = '\0';
	return (copy);
}

char	*ft_process(char *s, t_general_data *gen_data)
{
	int			x;
	char		*copy;
	char		*tmp;
	char		*pc;
	size_t		a;
	size_t		z;
	size_t		y;

	x = 0;
	if ((s[x] == '\'' && s[ft_strlen(s) - 1] == '\'')
		|| (s[x] == '"' && s[ft_strlen(s) - 1] == '\''))
		return (s);
	while (s[x] == '\'' || s[x] == '\"')
		x++;
	copy = ft_substr(s, x + 1, ft_strlen(s));
	copy = ft_change(copy);
	tmp = ft_strjoin(copy, "=");
	free(copy);
	a = -1;
	z = ft_strlen(tmp);
	while (gen_data->env[++a])
	{
		if (ft_strncmp(gen_data->env[a], tmp, z) == 0)
		{
			free(tmp);
			copy = ft_strchr(gen_data->env[a], '=');
			tmp = ft_substr(copy, 1, ft_strlen(copy));
			copy = ft_substr(tmp, 0, ft_strlen(tmp));
			free(tmp);
			if (s[ft_strlen(s) - 1] == '"')
			{
				if (s[ft_strlen(s) - 2] == '\'')
				{
					tmp = ft_strjoin("'", copy);
					free(copy);
					copy = ft_strjoin(tmp, "'");
					free(tmp);
					return (copy);
				}
				tmp = ft_strjoin(copy, "\"");
				free(copy);
				return (tmp);
			}
			return (copy);
		}
	}
	a = 0;
	copy = malloc(1024);
	while (s[a] && s[a] != '$')
	{
		copy[a] = s[a];
		a++;
	}
	copy[a] = '\0';
	y = a;
	a++;
	tmp = ft_substr(&s[a], 0, ft_strlen(s));
	z = ft_strlen(tmp) - 1;
	while (tmp[z] == '\'' || tmp[z] == '"')
		z--;
	z++;
	pc = ft_substr(tmp, 0, z);
	pc = ft_strjoin(pc, "=");
	free(tmp);
	z = 0;
	while (gen_data->env[z])
	{
		if (ft_strncmp(gen_data->env[z], pc, ft_strlen(pc)) == 0)
		{
			free(pc);
			tmp = ft_strchr(gen_data->env[z], '=');
			pc = ft_substr(tmp, 1, ft_strlen(tmp));
			tmp = ft_substr(pc, 0, ft_strlen(pc));
			free(pc);
			z = 0;
			a = ft_strlen(copy);
			pc = ft_strjoin(copy, tmp);
			free(tmp);
			tmp = ft_strjoin(pc, &s[y + 1]);
			return (tmp);
		}
		z++;
	}
	free(tmp);
	s = ft_substr("\b", 0, 1);
	return (s);
}

char	*ft_expand(t_general_data *gen_data)
{
	size_t		x;
	char		**tmp;
	char		*copy;

	x = 0;
	while (gen_data->s[x])
	{
		if (gen_data->s[x] == '$')
			break ;
		x++;
	}
	if (x == ft_strlen(gen_data->s))
		return (gen_data->s);
	x = 0;
	tmp = ft_split(gen_data->s, ' ');
	while (tmp[x])
	{
		if (finder(tmp[x], "$") && finder(tmp[x - 1], "'") == 0)
			tmp[x] = ft_process(tmp[x], gen_data);
		x++;
	}
	x = 0;
	free(gen_data->s);
	copy = malloc (1);
	copy = "";
	while (tmp[x])
	{
		copy = ft_strjoin(copy, tmp[x]);
		copy = ft_strjoin(copy, " ");
		x++;
	}
	ft_free_arg(tmp);
	gen_data->s = ft_substr(copy, 0, ft_strlen(copy));
	free(copy);
	return (gen_data->s);
}
