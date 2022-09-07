#include "../minishell.h"

int	find_in_red(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '<')
			return (1);
		i++;
	}
	return (0);
}

void    memory_for_in_red(t_general_data *gen_data, char **tmp, int y)
{
        int     i;
        int     z;
        int     w;

        i = 0;
        z = 1;
        w = 0;
        while (tmp[z])
        {
                while (tmp[z][i])
                        i++;
                gen_data->cmd[y].in[w] = malloc(sizeof(char) * (i + 1));
                z++;
                w++;
                i = 0;
        }
}

void    paste_tmp_in_red(t_general_data *gen_data, char **tmp, int y)
{
        int     z;
        int     i;
        int     w;
        int     k;

        k = 0;
        z = 1;
        i = 0;
        w = 0;
        while (tmp[z])
        {
                while (tmp[z][i])
                {
                        if (tmp[z][i] == ' ')
                                i++;
                        gen_data->cmd[y].in[w][k++] = tmp[z][i];
                        i++;
                }
                gen_data->cmd[y].in[w][k] = '\0';
                i = 0;
                k = 0;
                z++;
                w++;
        }
}

void	gest_in_reds(t_general_data *gen_data, char *s, int y)
{
	char	**tmp;
	int	i;

	tmp = ft_split(s, '<');
	i = 0;
	while (tmp[i])
		i++;
	gen_data->cmd[y].in = malloc(sizeof(char *) * (i + 1));
	memory_for_in_red(gen_data, tmp, y);
	paste_tmp_in_red(gen_data, tmp, y);
	i = 0;
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
}

void	process_in_red(t_general_data *gen_data, char *s, int y)
{
	if (find_in_red(s) == 1)
		gest_in_reds(gen_data, s, y);
	else
	{
		gen_data->cmd[y].in = malloc(sizeof(char) * 1);
		gen_data->cmd[y].in[0] = malloc(1);
	}
}
