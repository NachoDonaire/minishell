/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dr_comillas.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:00:01 by sasalama          #+#    #+#             */
/*   Updated: 2022/11/09 10:04:32 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	**fill_wallace(char **wallace, char *s)
{
	int	i;
	int	y;
	int	z;

	z = 0;
	i = 0;
	y = 0;
	while (s[i])
	{
		if (s[i] == ' ' )
			y++;
		if (s[i] == '"' || s[i] == 39)
		{
			z++;
		}
		i++;
	}
	wallace = malloc(sizeof(char *) * (y + 2 + (z / 2)));
	return (wallace);
}

char	*memory_for_wallace(char *s, char *wallace, int ref, int y)
{
	int	i;

	i = 0;
	if (ref == 1)
	{
		while (s[i] != 39 && s[i])
		{
			y++;
			i++;
		}
		i++;
		if (s[i] != ' ' && s[i])
			return (memory_for_wallace(s, wallace, i, y));
	}
	else if (ref == 0)
	{
		//i++;
		while (s[i] != '"' && s[i])
		{
			y++;
			i++;
		}
		i++;
		if (s[i] != ' ' && s[i])
			return (memory_for_wallace(s, wallace, i, y));
	}
	else
	{
		while (s[i] != ' ' && s[i] != '<' && s[i] != '>'  && s[i])
		{
			i++;
			y++;
		}
	}
	y += 48;
	wallace = malloc(sizeof(char ) * (y + 2));
	return (wallace);
}

char	*gest_comillas(char *s, char *wallace, int ref, int y)
{
	int	i;

	i = 0;
	if (y == 0)
		wallace = memory_for_wallace(&s[i], wallace, ref, y);
	else if (y == -1)
		y = 0;
	if (ref == 0 && s[i])
	{
		//i++;
		while (s[i] != '"' && s[i])
		{
			while (s[i] == '"' && s[i])
				i++;
			wallace[y++] = s[i++];
		}
		wallace[y] = '\0';
		i++;
		if (s[i] == ' ' || !s[i])
			return (wallace);
		else if (s[i] != ' ' && s[i] != '\0')
			return (gest_comillas(&s[i], wallace, ref, y));
	}
	if (ref == 1 && s[i])
	{
		//i++;
		while (s[i] != 39 && s[i])
		{
			while (s[i] == 39)
				i++;
			wallace[y++] = s[i++];
		}
		wallace[y] = '\0';
		i++;
		if (s[i] == ' ' || !s[i])
			return (wallace);
		i++;
		if (s[i] != ' ' && s[i])
			return (gest_comillas(&s[i], wallace, ref,  y));
	}
	return (wallace);
}

char	*dr_no_comillas(char *s, char *wallace, int ref, int y)
{
	int	i;
	int	e;
	char	*anton;

	e = 0;
	i = 0;
	anton = NULL;
	if (y == 0)
	{
		wallace = memory_for_wallace(&s[i], wallace, ref, y);
		anton = memory_for_wallace(&s[i], anton, ref, y);
	}	
	anton[0] = '\0';
	while (s[i] != ' ' && s[i])
	{
		if (s[i] == '"')
		{
			e++;
			wallace[y] = '\0';
	//printf("//%s//\n", wallace);
			anton = gest_comillas(&s[i + 1], anton, 0, -1);
			while (s[i] != '"' && s[i])
				i++;
			//i--;
	//		printf("((%c))", s[i]);
		}
		else if (s[i] == 39)
		{
			e++;
			wallace[y] = '\0';
			anton = gest_comillas(&s[i + 1], anton, 1, -1);
			while (s[i] != 39  && s[i])
				i++;
			//i--;
		}
		if (s[i] == ' ')
		{

	//printf("//%s//\n", wallace);
			break ;
		}
		wallace[y++] = s[i++];
		//i++;
	}
	//printf("//%s//\n", wallace);
	//printf("$$%s$$\n", anton);
	
	//wallace[y] = '\0';
	if (e != 0)
		wallace = ft_strjoin(wallace, anton);
	else if (e == 0)
		wallace[y] = '\0';
	write(1, "aa", 2);
	return (wallace);
}

char	**dr_comillas(char *s)
{
	char	**wallace;
	int		i;
	int		w;
	int		y;

	y = 0;
	w = 0;
	i = 0;
	wallace = NULL;
	wallace = fill_wallace(wallace, s);
	while (s[i])
	{
		if (s[i] == '"')
		{
			wallace[w] = gest_comillas(&s[i + 1], wallace[w], 0, y);
			w++;
			while (s[i]) //&& s[i] == '"')
				i++;
			//i++;
		//	write(1, &s[i], 1);
		}
		else if (s[i] == 39)
		{
			printf("&&%c&&", s[i]);
			wallace[w] = gest_comillas(&s[i + 1], wallace[w], 1, y);
			w++;
			while (s[i] != 39 && s[i])
				i++;
		}
		else if (s[i] && s[i] != 39 && s[i] != '"' && s[i] != ' ')
		{
			wallace[w] = dr_no_comillas(&s[i], wallace[w], 2,  y);
			w++;
			while (s[i] != ' ' && s[i])
				i++;
		}
		if (s[i])
			i++;
	}
	wallace[w] = NULL;
	return (wallace);
}
