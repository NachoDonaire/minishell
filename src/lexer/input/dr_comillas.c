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
		if (s[i] == ' ' )//|| s[i] == '<' || s[i] == '>')
			y++;
		if (s[i] == '"' || s[i] == 39)
		{
			z++;
		}
		i++;
	}
/*	if (z % 2 == 0 || z == 0)
	{
		write(1, "aa", 2);
		wallace = malloc(sizeof(char *) * (y + z / 2));
		write(1, "ee", 2);
	}*/
	//else
	wallace = malloc(sizeof(char *) * (y + 1));
	return (wallace);
}

int	memory_for_wallace(char *s, char **wallace, int i, int w, int y)
{
	if (s[i] == 39)
	{
		i++;
		while (s[i] != 39 && s[i])
		{
			y++;
			i++;
		}
		i++;
		if (s[i] == 39)
			memory_for_wallace(s, wallace, i, w, y);
	}
	else if (s[i] == '"')
	{
		i++;
		while (s[i] != '"' && s[i])
		{
			y++;
			i++;
		}
		i++;
		if (s[i] == '"')
			memory_for_wallace(s, wallace, i, w, y);

	}
	else
	{
		while (s[i] != ' ' && s[i] != '<' && s[i] != '>' && s[i] != 39 && s[i] != '"' && s[i])
		{
			i++;
			y++;
		}
	}
	wallace[w] = malloc(sizeof(char ) * (y + 1));
	return (i);
}


int	gest_comillas(char *s, char **wallace, int i, int w, int y)
{
	if (y == 0)
		memory_for_wallace(s, wallace, i, w, y);
	if (s[i] == 39)
	{
		i++;
		while (s[i] != 39 &&  s[i])
			wallace[w][y++] = s[i++];
		wallace[w][y] = '\0';
		i++;
		if (s[i] == 39)
			return (gest_comillas(s, wallace, i, w, y));
	}
	if (s[i] == '"')
	{
		i++;
		while (s[i] != '"' && s[i])
			wallace[w][y++] = s[i++];
		wallace[w][y] = '\0';
		i++;
		if (s[i] == '"')
			return (gest_comillas(s, wallace, i, w, y));
	}
	return (i);
}

int	dr_no_comillas(char *s, char **wallace, int i, int w, int y)
{
//	printf("%d\n", i);
	memory_for_wallace(s, wallace, i, w, y);
	while (s[i] != ' ' && s[i] != '"' && s[i] != '<' && s[i] != '>' && s[i] != 39 && s[i])
	{
		wallace[w][y++] = s[i++];
	}
	wallace[w][y] = '\0';
	return (i);
}



char	**dr_comillas(char *s)
{
	char	**wallace;
	int	i;
	int	w;

	w = 0;
	i = 0;
	wallace = NULL;
	wallace = fill_wallace(wallace, s);
	while (s[i] && s[i] != '<' && s[i] != '>')
	{
		while (s[i] == ' ' && s[i])
			i++;
		if (s[i] == '"' || s[i] == 39)
		{
			i = gest_comillas(s, wallace, i, w, 0);
			w++;
		}
		else
		{
			i = dr_no_comillas(s, wallace, i, w, 0);
			w++;
		}
		while (s[i] == ' ' && s[i])
			i++;
		if (s[i] == '\0')
			break ;
	}
	wallace[w] = malloc(1);
	wallace[w] = NULL;
	return (wallace);
}
/*
int	main()
{
	char *s;
	int	i;
	char	**w;

	i = 0;
	s = "hola! que tal andan 'weaa' 're'iii";
	w = dr_comillas(s);
	while (w[i])
		printf("%s\n", w[i++]);
	return (0);
}
*/



