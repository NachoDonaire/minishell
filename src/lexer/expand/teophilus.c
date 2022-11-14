/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teophilus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:06:55 by sasalama          #+#    #+#             */
/*   Updated: 2022/11/14 10:10:43 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*variable(char **env, char *c)
{
	int		i;
	int		y;
	int		z;
	char	*jutels;

	y = 0;
	i = 0;
	while (env[i] && ft_strncmp(c, env[i], lens(c)) != 0)
		i++;
	if (!env[i])
		return ("");
	while (env[i][y])
	{
		if (env[i][y] == '=')
			break ;
		y++;
	}
	z = y;
	y++;
	while (env[i][z])
		z++;
	jutels = malloc(sizeof(char ) * ((z - y) + 1));
	z = 0;
	while (env[i][y])
		jutels[z++] = env[i][y++];
	jutels[z] = '\0';
	return (jutels);
}

char	*copy_var(char *s)
{
	int		i;
	char	*jefferson;

	i = 0;
	while (s[i] != ' ' && s[i] != '"'
		&& s[i] != 39 && s[i] != '/' && s[i] != '$')
		i++;
	jefferson = malloc(sizeof(char ) * (i + 1));
	i = 0;
	if (s[i] >= '0' && s[i] <= '9')
	{
		jefferson[i] = s[i];
		i++;
		jefferson[i] = '\0';
		return (jefferson);
	}
	while (s[i] != ' ' && s[i] != '"' && s[i] != 39
		&& s[i] != '/' && s[i] != '=' && s[i] != '$')
	{
		jefferson[i] = s[i];
		i++;
	}
	jefferson[i] = '\0';
	return (jefferson);
}

int	comillas_dobles(char *s, char *of, char **env, int ref, int w)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '"')
	{
		if (s[i] == 39)
			w = comillas_simples(&s[i], of, env, ref, w);
		else if (s[i] == '$')
		{
			w = dollar(&s[i], of, env, ref, w);
			while (s[i] != ' ' && s[i] != '"'
				&& s[i] != 39 && s[i] != '/' && s[i] != '=')
			{
				if (s[i] >= '0' && s[i] <= '9')
				{
					i++;
					break ;
				}
				i++;
			}
			if (s[i] == '"')
			{
				of[w++] = s[i];
				return (w);
			}
		}
		of[w++] = s[i++];
	}
	if (i == 0 && ref == 1)
		return (w);
	of[w++] = s[i++];
	return (w);
}

int	comillas_simples(char *s, char *of, char **env, int ref, int w)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != 39)
	{
		if (s[i] == '"')
			w = comillas_dobles(&s[i], of, env, ref, w);
		else if (s[i] == '$')
		{
			w = dollar(&s[i], of, env, ref, w);
			while (s[i] != ' ' && s[i] != '"'
				&& s[i] != 39 && s[i] != '/' && s[i] != '=')
			{
				if (s[i] >= '0' && s[i] <= '9')
				{
					i++;
					break ;
				}
				i++;
			}
			if (s[i] == 39)
			{
				of[w++] = s[i++];
				return (w);
			}
		}
		of[w++] = s[i++];
	}
	if (i == 0 && ref == 0)
		return (w);
	of[w++] = s[i++];
	return (w);
}

int	dollar(char *s, char *of, char **env, int ref, int w)
{
	int		i;
	int		y;
	char	*c;

	i = 0;
	y = 0;
	c = copy_var(&s[i + 1]);
	if (ref == 0)
	{
		c = variable(env, c);
		while (c[y])
			of[w++] = c[y++];
		i++;
		if (s[i] >= '0' && s[i] <= '9')
			return (w);
		while (s[i] != ' ' && s[i] != 39 && s[i] != '"'
			&& s[i] && s[i] != '/' && s[i] != '=' && s[i] != '$')
			i++;
		if (s[i] == '$')
			return (dollar(&s[i], of, env, ref, w));
	}
	else
	{
		if (s[i] == '$')
			of[w++] = s[i++];
		while (s[i] != ' ' && s[i] != 39 && s[i] != '"'
			&& s[i] && s[i] != '/' && s[i] != '=' && s[i] != '$')
			of[w++] = s[i++];
		if (s[i] == '$')
			return (dollar(&s[i], of, env, ref, w));
	}
	return (w);
}

int	tiberio(t_general_data *gen_data, char *of, int i, int w)
{
	if (gen_data->s[i])
	{
		if (gen_data->s[i] == '$')
		{
			w = dollar(&gen_data->s[i], of, gen_data->env, 0, w);
			while (gen_data->s[i] != ' ' && gen_data->s[i] != 39
				&& gen_data->s[i] != '"' && gen_data->s[i]
				&& gen_data->s[i] != '/' && gen_data->s[i] != '=')
			{
				if (gen_data->s[i] == '$')
				{
					i++;
					if (gen_data->s[i] >= '0' && gen_data->s[i] <= '9')
						return (tiberio(gen_data, of, i + 1, w));
				}
				i++;
			}
			return (tiberio(gen_data, of, i, w));
		}
		else if (gen_data->s[i] == 39)
		{
			of[w++] = gen_data->s[i++];
			w = comillas_simples(&gen_data->s[i], of, gen_data->env, 1, w);
			while (gen_data->s[i] != 39)
				i++;
			i++;
			return (tiberio(gen_data, of, i, w));
		}
		else if (gen_data->s[i] == '"')
		{
			of[w++] = gen_data->s[i++];
			w = comillas_dobles(&gen_data->s[i], of, gen_data->env, 0, w);
			while (gen_data->s[i] != '"')
				i++;
			i++;
			return (tiberio(gen_data, of, i, w));

		}
		of[w++] = gen_data->s[i++];
		return (tiberio(gen_data, of, i, w));
	}
	return (w);
}

char	*teophilus(t_general_data *gen_data)
{
	int		i;
	char	*of;
	int		w;

	i = 0;
	w = 0;
	of = malloc(sizeof(char ) * (lens(gen_data->s) + 500));
	w = tiberio(gen_data, of, i, w);
	of[w] = '\0';
	free(gen_data->s);
	return (of);
}