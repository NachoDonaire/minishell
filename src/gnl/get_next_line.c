/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:19:29 by ndonaire          #+#    #+#             */
/*   Updated: 2022/09/26 11:44:06 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include "../../includes/minishell.h"

char	*join(char *sol, char *buff)
{
	char	*solu;

	solu = ft_strjoin(sol, buff);
	if (sol)
		free(sol);
	return (solu);
}

char	*lecture(char *buff, int fd)
{
	int		lec;
	char	*sol;
	int		size;

	size = 1;
	if (!buff)
		buff = ft_calloc(size + 1, sizeof(char));
	lec = 1;
	sol = malloc((size + 1) * sizeof(char));
	while (lec > 0)
	{
		lec = read(fd, sol, size);
		if (lec < 0)
		{
			free(buff);
			free(sol);
			return (NULL);
		}
		sol[lec] = '\0';
		buff = join(buff, sol);
		if (find_nl(buff))
			break ;
	}
	free(sol);
	return (buff);
}

char	*the_line(char *buff)
{
	char	*sol;
	int		i;

	i = 0;
	if (!buff[i])
	{
		return (NULL);
	}
	while (buff[i] && buff[i] != '\n')
		i++;
	sol = ft_calloc((i + 2), sizeof(char));
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		sol[i] = buff[i];
		i++;
	}
	if (buff[i] && buff[i] == '\n')
	{
		sol[i] = buff[i];
		i++;
	}
	sol[i] = '\0';
	return (sol);
}

char	*next_line(char *buff)
{
	int		i;
	char	*sol;
	int		y;

	i = 0;
	y = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\0')
	{
		free(buff);
		return (NULL);
	}
	else if (buff[i] == '\n')
		i++;
	sol = ft_calloc((lens(buff) - i + 1), sizeof(char));
	while (buff[i])
		sol[y++] = buff[i++];
	sol[y] = '\0';
	if (buff)
		free(buff);
	return (sol);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*sol;

	if (fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buff = lecture(buff, fd);
	if (!buff)
		return (NULL);
	sol = the_line(buff);
	buff = next_line(buff);
	return (sol);
}
