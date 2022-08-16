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
//	char	*path;
	char	**com;
	int	i;

	i = 0;
	com = ft_split(s, ' ');
	while (com[i])
	{
		if (check_cmllas(com[i]) == 1)
			com[i] = gest_cmllas(com[i]);
		i++;
	}
//	path = find_path(env);
//	split_path(&path[5], com[0], gen_data);
	gen_data->cmd[y].cmd = check_cmd(com[0], env);
	i = 0;
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
//	if (finder(s, "|") == 0)
			check_builtins(s, gen_data, 0);
	if (gen_data->built == 1)
		return ;
	if (finder(s, ".") == 1 || finder(s, "/") == 1)
	{
		gen_data->cmd[0].cmd = aux[0];
		process_args(s, gen_data, 0);
	}
	else if (finder(s, "|") == 1)
	{
		process_string_with_pipes(gen_data, s, env);
	}
	else
	{
		process_string(s, gen_data, env, 0);
		process_args(s, gen_data, 0);
	}
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
//        cmd_data        cmd;
        general_data    gen_data;

        if (argc == 0 || !argv)
                return (0);
        i = 0;
	y = 0;
        while (i == 0)
        {
//		if (gen_data.cmd.cmd)
//			needed_free_cmd(&gen_data);
		gen_data.n_pipes = 0;
		gen_data.built = 0;
                s = readline("");
                n_pipes(&gen_data, s);
		process_input(s, &gen_data, env);
		//printf("--%d--", gen_data.built);
                /*if (cmd.cmd[0])
                        printf("%s\n", cmd.cmd[0]);
                printf("%d", gen_data.n_cmd);
                process_exit(s, &i);
		*/
		//while (gen_data.cmd[y].cmd)
		if (gen_data.cmd[0].cmd)
			printf("%s\n", gen_data.cmd[0].cmd);
		y = 0;
		process_exit(s, &i);
                free(s);
        }
        return (0);
}
  
