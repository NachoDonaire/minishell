#include "minishell.h"

void	handle_cmd_pipes(t_general_data *gen_data, char *s, char *const env[])
{
	int	i;
	char	**tmp;
	int	y;

	tmp = ft_split(s, '|');
	i = 0;
	y = 0;
	while (tmp[i])
	{
		if (finder(tmp[i], "&") == 1)
			y = gest_ampersand(tmp[i], gen_data, env, y);
		else
		{
			gen_data->built = 0;
			check_builtins(tmp[i], gen_data, y);
			if (check_cmllas(tmp[i]) == 1)
				tmp[i] = gest_cmllas(tmp[i]);
			if (gen_data->built != 1)
				process_string(tmp[i], gen_data, env, y);
			y++;
		}
		i++;
	}
	free_tmp(tmp);
}

int	gest_ampersand(char *s, t_general_data *gen_data, char *const env[], int y)
{
	char	**tmp;
	int	i;

	tmp = ft_split(s, '&');
	i = 0;
	while (tmp[i])
	{
		gen_data->built = 0;
		check_builtins(tmp[i], gen_data, y);
		if (check_cmllas(tmp[i]) == 1)
			tmp[i] = gest_cmllas(tmp[i]);
		if (gen_data->built != 1)
			process_string(tmp[i], gen_data, env, y);
		i++;
		y++;
	}
	free_tmp(tmp);
	return (y);
}

void	free_tmp(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
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

void	process_string_with_pipes(t_general_data *gen_data, char *s, char *const env[])
{
	handle_cmd_pipes(gen_data, s, env);
}




