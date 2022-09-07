#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "../includes/minishell.h"
/*
void	freeear(char **sol, char *k, t_general_data *gen_data)
{
	int	i;

	i = 0;
	while (sol[i])
		free(sol[i++]);
	free(sol);
	if (!k)
		gen_data->cmd.cmd = NULL;
	gen_data->cmd.cmd = ft_split(k, ' ');;
	i = 0;
//	printf("-%s-", gen_data->cmd.cmd[0]);
}
*/
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
	if (!path)
		return (com);
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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

/*
void	split_path(char *env, char *arg, t_general_data *gen_data)
{
	int		i;
	char	**sol;
	int		auxy;
	char	*k;

	if (!arg)
		return ;
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
	freeear(sol, k, gen_data);
}*/
