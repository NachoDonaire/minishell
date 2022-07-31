#include "minishell.h"

void	handle_cmd_pipes(general_data *gen_data, char *s, char *const env[])
{
	char	*cmd;
	int	i;
	char	**tmp;

	gen_data->cmd.cmd = malloc(sizeof(char **) * lens(s));
	tmp = ft_split(s, '|');
	i = 0;
	while (tmp[i])
	{
		cmd = obtain_cmd(tmp, i);
		gen_data->cmd.cmd[i] = check_cmd(cmd, env);
		i++;
	}
}

char	*handle_cont_pipe(char *join)
{
	int	i;

	i = 0;
	if (finder(join, "|") == 1)
	{
		while (join[i] != '|')
			i++;
		join[i] = '\0';
	}
	return (join);
}

void	process_string_with_pipes(general_data *gen_data, char *s, char *const env[])
{
	printf("--%d--", gen_data->n_pipes);
	handle_cmd_pipes(gen_data, s, env);
}





