#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include "minishell.h"

void	gest_cmd(general_data *gen_data, char *s)
{
	int	i;

	i = 1;
	gen_data->cmd->cmd = ft_split(s, ' ');
	while (gen_data->cmd->cmd[i])
		free(gen_data->cmd->cmd[i++]);
}


int	find_spaces(char *s)
{
	int	i;
	int	count;
	
	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ' ')
			count++;
		i++;
	}
	return (count);
}

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
		y = 0;
		i++;
	}
	return (0);
}

void	process_string(char *const env[], char *s, general_data *gen_data)
{
	char	*path;
	char	**com;

	path = find_path(env);
	com = split_path(&path[5], s);
	if (!com)
	{
		free(com);
		return ;
	}
	gen_data->cmd->cmd = com;
		write(1, "bb", 2);
}

void	process_exit(char *s, int *i)
{
	if (finder(s, "exit") == 1)
		*i = 1;
	else
		*i = 0;
}

void	the_cmd(char *s, char *const env[], general_data *gen_data)
{
	char	**spliteo;
	int	y;

	y = 0;
	if (finder(s, ".") == 1 || finder(s, "/") == 1)
	{
		spliteo = ft_split(s, ' ');;
		gest_cmd(gen_data, s);
	}
//	else if (finder(s, "|") == 1)
//		check_cmd_pipe(gen_data, s, env);
	else
	{
		spliteo = ft_split(s, ' ');
		while (spliteo[y])
		{
			if (check_cmllas(spliteo[y]) == 1)
				spliteo[y] = gest_cmllas(spliteo[y]);
			y++;
		}
		process_string(env, spliteo[0], gen_data);
		write(1, "aa", 2);
	}
}

void	cmd_args(char *s, cmd_data *cmd)
{
	cmd->args = ft_split(s, ' ');
}

int	main(int argc, char **argv, char *const env[])
{
	int		i;
	char		*s;
	cmd_data	cmd;
	general_data	gen_data;

	if (argc == 0 || !argv)
		return (0);
	i = 0;
	while (i == 0)
	{
		gen_data.n_cmd = 0;
		s = readline("");
		the_cmd(s, env, &gen_data);
		write(1, "aa", 2);
		cmd_args(s, &cmd);
		n_pipes(&gen_data, s);
		if (cmd.cmd[0])
			printf("%s\n", cmd.cmd[0]);
		printf("%d", gen_data.n_cmd);
		process_exit(s, &i);
		free(s);
	}
	return (0);
}
