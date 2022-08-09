/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama <sasalama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 15:46:56 by sasalama          #+#    #+#             */
/*   Updated: 2022/08/09 17:24:36 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_print_quotation_s2(char *argument)
{
	int	x;

	x = ft_strlen(argument);
	while (x > 0)
	{
		if (argument[x] == 39)
			return (0);
		x--;
	}
	return (1);
}

int	ft_print_quotation_d2(char *argument)
{
	int	x;

	x = ft_strlen(argument);
	while (x > 0)
	{
		if (argument[x] == 34)
			return (0);
		x--;
	}
	return (1);
}

void	ft_print_variable(char **nb_arguments, int x, int y, char **env)
{
	int		z;
	char	*copy;
	char	*tmp;

	copy = ft_substr(nb_arguments[x], y + 1, ft_strlen(nb_arguments[x]));
	while (ft_print_quotation_d2(copy) == 0)
		copy[ft_strlen(copy) - 1] = '\0';
	while (ft_print_quotation_s2(copy) == 0)
		copy[ft_strlen(copy) - 1] = '\0';
	tmp = ft_strjoin(copy, "=");
	free(copy);
	z = -1;
	while (env[++z])
	{
		y = ft_strlen(tmp);
		if (ft_strncmp(env[z], tmp, y) == 0)
		{
			free(tmp);
			copy = ft_strchr(env[z], '=');
			tmp = ft_substr(copy, 1, ft_strlen(copy));
			printf("%s", tmp);
			free(tmp);
			break ;
		}
	}
}

int	ft_print_quotation_d(char *argument)
{
	int	x;
	int	z;

	x = 0;
	z = ft_strlen(argument) - 1;
	while (argument[x])
	{
		if (argument[x] == 39)
		{
			if (argument[x + 1] == 34 && argument[z] != 34)
				return (0);
			return (1);
		}
		x++;
	}
	return (1);
}

int	ft_print_quotation_s(char *argument)
{
	int	x;
	int	z;

	x = 0;
	z = ft_strlen(argument) - 1;
	while (argument[x])
	{
		if (argument[x] == 34)
		{
			if (argument[x + 1] == 39 && argument[z] != 39)
				return (0);
			return (1);
		}
		x++;
	}
	return (1);
}
