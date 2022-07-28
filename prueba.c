#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include "minishell.h"

int	finder(char *s, char *find)
{
	int	i;
	int	y;
	
	i = 0;
	y = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] == find[y])
		{
			y++;
			i++;
			if (find[y] == '\0')
				return (1);
		}
		i++;
	}
	return (0);
}

char	*process_string(char *const env[], char *s)
{
	char	*path;
	char	*com;

	path = find_path(env);
	com = split_path(&path[5], s);
	if (!com)
	{
		free(com);
		return (NULL);
	}
	return (com);
}

void	process_exit(char *s, int *i)
{
	if (finder(s, "exit") == 1)
		*i = 1;
	else
		*i = 0;
}

int	main(int argc, char **argv, char *const env[])
{
	int		i;
	char	*s;
	char	**spliteo;
	char	*com;
	int		y;

	if (argc == 0 || !argv)
		return (0);
	i = 0;
	y = 0;
	while (i == 0)
	{
		y = 0;
		s = readline("");
		if (finder(s, ".") == 1 || finder(s, "/") == 1)
		{
			spliteo = ft_split(s, ' ');;
			com = spliteo[0];
		}
		else
		{
			spliteo = ft_split(s, ' ');
			while (spliteo[y])
			{
				if (check_cmllas(spliteo[y]) == 1)
						spliteo[y] = gest_cmllas(spliteo[y]);
				y++;
			}
			com = process_string(env, spliteo[0]);
			process_exit(s, &i);
			free(s);
		}
		printf("%s\n", com);
	}
	return (0);
}
