#include "minishell.h"

int	check_cmllas(char *s)
{
	int		i;

	i = 0;
	if (s[i] == '"' && lens(s) > 1)
	{
		while (s[i])
		{
			i++;
			if (s[i] == '\0' && s[i - 1] == '"')
			   return (1);
		}
	}
	return (0);
}
/*
char	*gesteo_cmllas(char *spliteao)
{
	int		i;
	char	**sol;
	int		y;

	i = 0;
	y = 0;
	while (spliteao[i])
		i++;
	sol = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (spliteao[i])
	{
		sol[y] = gest_cmllas(spliteao[i]);
		y++;
		i++;
	}
	sol[y] = NULL;
	return (sol);
}
*/
		


char	*gest_cmllas(char *s)
{
	char	*sol;
	int		i;
	int		y;

	i = 1;
	y = 0;
	sol = malloc(sizeof(char) * lens(s));
	while (s[i] != '"')
	{
		sol[y++] = s[i++];
	}
	sol[y] = '\0';
	return (sol);
}


