#include "minishell.h"

void	handle_cmd_pipes(general_data *gen_data, char *s, char *const env[])
{
	char	*cmd;
	int	i;
	char	**tmp;

	tmp = ft_split(s, '|');
	i = 0;
	if (!gen_data->cmd.cmd)
		gen_data->cmd.cmd = ft_split(s, '|');
	while (tmp[i])
	{
		gen_data->built = 0;
		check_builtins(tmp[i], gen_data);
		if (check_cmllas(tmp[i]) == 1)
			tmp[i] = gest_cmllas(tmp[i]);
		//printf("--%s--", tmp[i]);
		if (gen_data->built == 1)
			gen_data->cmd.cmd[i] = "no_cmd";
		else
		{
			cmd = obtain_cmd(tmp, i);
			gen_data->cmd.cmd[i] = check_cmd(cmd, env);
		}
		i++;
	}
	gen_data->cmd.cmd[i] = NULL;
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
	//printf("--%d--", gen_data->n_pipes);
	handle_cmd_pipes(gen_data, s, env);
}





