/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teophilus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:06:55 by sasalama          #+#    #+#             */
/*   Updated: 2022/11/16 16:23:24 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*variable(t_general_data *gen_data, char *c)
{
	int		i;
	int		y;
	int		z;
	char	*jutels;
	int		x;

	y = 0;
	i = 0;
	c = ft_strjoin(c, "=");
	while (gen_data->env[i] && ft_strncmp(c, gen_data->env[i], lens(c)) != 0)
		i++;
	if (!gen_data->env[i])
	{
		x = 0;
		if (ft_strncmp(c, "PWD=", 4) == 0 && gen_data->path == 1)
		{
			while (gen_data->secret_env[x])
			{
				if (ft_strncmp(gen_data->secret_env[x], "PWD=", 4) == 0)
					break ;
				x++;
			}
			if (x == ft_nb_arguments(gen_data->secret_env))
				return ("");
			while (gen_data->secret_env[x][y]
				&& gen_data->secret_env[x][y] != '=')
				y++;
			jutels = ft_substr(&gen_data->secret_env[x][y + 1], 0, ft_strlen(&gen_data->secret_env[x][y + 1]));
			return (jutels);
		}
		else if (ft_strncmp(c, "OLDPWD=", 7) == 0 && gen_data->path == 1)
		{
			while (gen_data->secret_env[x])
			{
				if (ft_strncmp(gen_data->secret_env[x], "OLDPWD=", 7) == 0)
					break ;
				x++;
			}
			if (x == ft_nb_arguments(gen_data->secret_env))
				return ("");
			while (gen_data->secret_env[x][y]
				&& gen_data->secret_env[x][y] != '=')
				y++;
			jutels = ft_substr(&gen_data->secret_env[x][y + 1], 0, ft_strlen(&gen_data->secret_env[x][y + 1]));
			return (jutels);
		}
		else if (ft_strncmp(c, "PATH=", 5) == 0 && gen_data->path == 1)
		{
			while (gen_data->secret_env[x])
			{
				if (ft_strncmp(gen_data->secret_env[x], "PATH=", 5) == 0)
					break ;
				x++;
			}
			if (x == ft_nb_arguments(gen_data->secret_env))
				return ("");
			while (gen_data->secret_env[x][y]
				&& gen_data->secret_env[x][y] != '=')
				y++;
			jutels = ft_substr(&gen_data->secret_env[x][y + 1], 0, ft_strlen(&gen_data->secret_env[x][y + 1]));
			return (jutels);
		}
		return ("");
	}
	while (gen_data->env[i][y])
	{
		if (gen_data->env[i][y] == '=')
			break ;
		y++;
	}
	z = y;
	y++;
	while (gen_data->env[i][z])
		z++;
	jutels = malloc(sizeof(char ) * ((z - y) + 1));
	z = 0;
	while (gen_data->env[i][y])
		jutels[z++] = gen_data->env[i][y++];
	jutels[z] = '\0';
	return (jutels);
}

char	*copy_var(char *s)
{
	int		i;
	char	*jefferson;

	i = 0;
	while (s[i] != ' ' && s[i] != '"' && s[i] != '='
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

int	comillas_dobles(char *s, char *of, t_general_data *gen_data, int ref, int w)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '"')
	{
		if (s[i] == 39)
			w = comillas_simples(&s[i], of, gen_data, ref, w);
		else if (s[i] == '$')
		{
			w = dollar(&s[i], of, gen_data, ref, w);
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

int	comillas_simples(char *s, char *of, t_general_data *gen_data, int ref, int w)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != 39)
	{
		if (s[i] == '"')
			w = comillas_dobles(&s[i], of, gen_data, ref, w);
		else if (s[i] == '$')
		{
			w = dollar(&s[i], of, gen_data, ref, w);
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

int	dollar(char *s, char *of, t_general_data *gen_data, int ref, int w)
{
	int		i;
	int		y;
	char	*c;

	i = 0;
	y = 0;
	c = copy_var(&s[i + 1]);
	if (!c[0])
	{
		while (s[i] == '$' &&  s[i])
			of[w++] = s[i++];
		return (w);
	}
	if (ref == 0)
	{
		c = variable(gen_data, c);
		while (c[y])
			of[w++] = c[y++];
		i++;
		if (s[i] >= '0' && s[i] <= '9')
			return (w);
		while (s[i] != ' ' && s[i] != 39 && s[i] != '"'
			&& s[i] && s[i] != '/' && s[i] != '=' && s[i] != '$')
			i++;
		if (s[i] == '$')
			return (dollar(&s[i], of, gen_data, ref, w));
	}
	else
	{
		if (s[i] == '$')
			of[w++] = s[i++];
		while (s[i] != ' ' && s[i] != 39 && s[i] != '"'
			&& s[i] && s[i] != '/' && s[i] != '=' && s[i] != '$')
			of[w++] = s[i++];
		if (s[i] == '$')
			return (dollar(&s[i], of, gen_data, ref, w));
	}
	return (w);
}

int	tiberio(t_general_data *gen_data, char *of, int i, int w)
{
	if (gen_data->s[i])
	{
		if (gen_data->s[i] == '$')
		{
			w = dollar(&gen_data->s[i], of, gen_data, 0, w);
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
			w = comillas_simples(&gen_data->s[i], of, gen_data, 1, w);
			while (gen_data->s[i] != 39)
				i++;
			i++;
			return (tiberio(gen_data, of, i, w));
		}
		else if (gen_data->s[i] == '"')
		{
			of[w++] = gen_data->s[i++];
			w = comillas_dobles(&gen_data->s[i], of, gen_data, 0, w);
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
