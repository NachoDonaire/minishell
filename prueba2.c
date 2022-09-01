#include "minishell.h"

void    process_exit(char *s, int *i)
{
        if (finder(s, "exit") == 1)
                *i = 1;
        else
                *i = 0;
}

int     finder(char *s, char *find)
{
        int     i;
        int     y;

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
                y = 0;
                i++;
        }
        return (0);
}

int	extreme_finder(char *s, char *find)
{
        int     i;
        int     y;

        i = 0;
        y = 0;
        if (!s)
                return (0);
	while (s[i] == ' ')
		i++;
	while (s[i] == find[y])
	{
		y++;
		i++;
		if (find[y] == '\0')
			return (1);
	}
        return (0);
}

void	process_string(char *s, general_data *gen_data, char *const env[], int y)
{
	char	**com;
	int	i;

	i = 0;
	process_sing_red(gen_data, s, y);
	check_builtins(s, gen_data, 0);
	com = ft_split(s, ' ');
	if (finder(com[0], "./") == 1)
	{
		if (check_cmllas(com[0]) == 1)
			com[0] = gest_cmllas(com[i]);
		gen_data->cmd[y].cmd = com[0];
		process_args(s, gen_data, y);
		return ;
	}
	while (com[i])
	{
		if (check_cmllas(com[i]) == 1)
			com[i] = gest_cmllas(com[i]);
		i++;
	}
	gen_data->cmd[y].cmd = check_cmd(com[0], env);
	i = 0;
	process_args(s, gen_data, y);
	while (com[i])
		free(com[i++]);
}

void	process_args(char *s, general_data *gen_data, int y)
{
	char 	**com;
	int	i;

	i = 0;
	com = ft_split(s, ' ');
	while (com[i])
	{
		if (check_cmllas(com[i]) == 1)
			com[i] = gest_cmllas(com[i]);
		i++;
	}
	gen_data->cmd[y].args = com;
}

void	process_input(char *s, general_data *gen_data, char *const env[])
{
	char	**aux;
	int		i;

	i = 0;
	aux = ft_split(s, ' ');
//	check_builtins(s, gen_data, 0);
//	if (gen_data->built == 1)
//		return ;
	if (finder(s, "|") == 1 || finder(s, "&") == 1)
		process_string_with_pipes(gen_data, s, env);
	else
		process_string(s, gen_data, env, 0);
	while (aux[i])
		free(aux[i++]);
	free(aux);
}

void	needed_free_cmd(general_data *gen_data)
{
	int	i;

	i = 0;
	while (gen_data->cmd[i].cmd)
		free(gen_data->cmd[i++].cmd);
}

int     main(int argc, char **argv,  char *const env[])
{
        int             i;
        char            *s;
	int		y;
	int		z;
        general_data    gen_data;

        if (argc == 0 || !argv)
                return (0);
        i = 0;
	y = 0;
	z = 0;
	if (z == 1 || y == 1)
		write(1, "aa", 2);
        while (i == 0)
        {
		gen_data.n_pipes = 0;
		gen_data.built = 0;
                s = readline("");
                n_pipes(&gen_data, s);
		gen_data.cmd = malloc(sizeof(cmd_data) * (gen_data.n_pipes + 1));
		process_input(s, &gen_data, env);
		while (y <= gen_data.n_pipes && finder(s, ">") == 1)
		{
			while (gen_data.cmd[y].out[z])
				printf("%s\n", gen_data.cmd[y].out[z++]);
			printf("%d\n", gen_data.cmd[y].dred);
			z = 0;
			y++;
		}
		y = 0;
		process_exit(s, &i);
                free(s);
        }
        return (0);
}
  
