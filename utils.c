#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "minishell.h"

char	*freeear(char **sol, char *k)
{
	int	i;

	i = 0;
	while (sol[i])
		free(sol[i++]);
	free(sol);
	if (!k)
		return (NULL);
	return (k);
}

int	lens(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	checkin_path(char *s, char *find)
{
	int	i;
	int	y;

	y = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == find[y])
		{
			i++;
			y++;
			if (find[y] == '\0')
				return (1);
		}
		y = 0;
		i++;
	}
	return (0);
}

char	*find_path(char *const env[])
{
	int		i;
	int		check;

	i = 0;
	check = checkin_path(env[i], "PATH");
	while (check == 0)
	{
		i++;
		check = checkin_path(env[i], "PATH");
	}
	return (env[i]);
}

char	*pseudo_join(char *path, char *com)
{
	char	*sol;
	int		i;
	int		y;

	y = 0;
	i = 0;
	sol = malloc(sizeof(char) * (lens(path) + lens(com) + 1));
	while (path[i])
	{
		sol[i] = path[i];
		i++;
	}
	sol[i++] = '/';
	while (com[y])
	{
		sol[i++] = com[y++];
	}
	sol[i] = '\0';
	return (sol);
}

char	*split_path(char *env, char *arg)
{
	int		i;
	char	**sol;
	int		auxy;
	char	*k;

	if (!arg)
		return (NULL);
	auxy = 0;
	sol = ft_split(env, ':');
	auxy = 0;
	i = 0;
	k = pseudo_join(sol[i], arg);
	while (sol[auxy])
		auxy++;
	while (sol[i] && access(k, F_OK) < 0)
	{
		free(k);
		i++;
		if (sol[i])
			k = pseudo_join(sol[i], arg);
	}
	if (!sol[i])
	{
		freeear(sol, k);
		return (0);
	}
	return (freeear(sol, k));
}
