#include "../../../includes/minishell.h"

void	fill_table(int *t, int ref)
{
	if (ref == 0)
	{
		t[0] = 0;
		t[1] = 0;
		t[2] = 0;
	}
	else
	{
		t[0]++;
		t[1] = 0;
		t[2] = 0;
	}
}

int	check_tukle(char *s)
{
	int		t[3];
	char	**tmp;

	fill_table(t, 0);
	tmp = ft_split(s, '|');
	while (tmp[t[0]])
	{
		while (tmp[t[0]][t[1]] == ' ' && tmp[t[0]][t[1]++])
			t[2]++;
		while (tmp[t[0]][t[1]])
		{
			if (tmp[t[0]][t[1]] == '>' || tmp[t[0]][t[1]] == '<')
			{
				if (t[1] == t[2])
				{
					ft_free_arg(tmp);
					return (1);
				}
			}
			t[1]++;
		}
		fill_table(t, 420);
	}
	ft_free_arg(tmp);
	return (0);
}
