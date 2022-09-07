#include "minishell.h"

void	reserva(t_general_data *gen_data)
{
	gen_data->cmd = malloc(sizeof(t_cmd_data) * (gen_data->n_pipes + 1));
	gen_data->blt = malloc(sizeof(t_builtin_data) * (gen_data->n_pipes + 1));
	gen_data->sort = malloc(sizeof(char) * (gen_data->n_pipes + 1));
}

void	needed_free(t_general_data *gen_data, int y)
{
	int	i;

	i = 0;
	while (i < gen_data->n_built)
	{
		if (gen_data->blt[i].blt)
			free(gen_data->blt[i].blt);
		if (gen_data->blt[i].args)
			ft_free_arg(gen_data->blt[i].args);
		i++;
	}
	i = 0;
	while (i < y)
	{
		if (gen_data->cmd[i].cmd)
			free(gen_data->cmd[i].cmd);
		if (gen_data->cmd[i].args)
			ft_free_arg(gen_data->cmd[i].args);
		if (gen_data->cmd[i].out)
			ft_free_arg(gen_data->cmd[i].out);
		if (gen_data->cmd[i].in)
			ft_free_arg(gen_data->cmd[i].in);
		i++;
	}
}



