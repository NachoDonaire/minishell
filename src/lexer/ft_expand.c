/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:00:59 by sasalama          #+#    #+#             */
/*   Updated: 2022/11/06 16:00:23 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
	int		x;
	char	*copy;
	char	*tmp;
	int		a;
	int		z;

	x = 0;
	if (s[x] == '\'')
		return (s);
	while (s[x] == '\'' || s[x] == '\"')
		x++;
	copy = ft_substr(s, x + 1, ft_strlen(s));
	copy = ft_change(copy);
	tmp = ft_strjoin(copy, "=");
	free(copy);
	a = 0;
	z = ft_strlen(tmp);
	while (gen_data->env[a])
	{
		if (ft_strncmp(gen_data->env[a], tmp, z) == 0)
		{
			free(tmp);
			copy = ft_strchr(gen_data->env[a], '=');
			tmp = ft_substr(copy, 1, ft_strlen(copy));
			copy = ft_substr(tmp, 0, ft_strlen(tmp));
			free(tmp);
			return (copy);
		}
		a++;
	}
	return (copy);
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
		if (finder(tmp[x], "$"))
			tmp[x] = ft_process(tmp[x], gen_data);
		x++;
	}
	x = 0;
	free(gen_data->s);
	copy = malloc (1);
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
