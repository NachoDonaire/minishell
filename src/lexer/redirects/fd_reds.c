#include "../../../includes/minishell.h"

void	fd_reds_out_b(t_general_data *gen_data)
{
	int	i;
	int	y;

	y = 0;
	i = 0;
	while (gen_data->blt[gen_data->n_built].out[i])
		i++;
	gen_data->blt[gen_data->n_built].fd_out = malloc(sizeof(int) * (i + 1));
	i = 0;
	while (gen_data->blt[gen_data->n_built].out[i])
	{
		gen_data->blt[gen_data->n_built].fd_out[y] = open(gen_data->blt[gen_data->n_built].out[i++], O_WRONLY |  O_CREAT | O_TRUNC, 0644);
		if (gen_data->blt[gen_data->n_built].fd_out[y] < 0)
			write(2, "error\n", 7);
		y++;
	}
	gen_data->blt[gen_data->n_built].fd_out[y] = -1;
}

void	fd_reds_in_b(t_general_data *gen_data)
{
	int	i;
	int	y;

	y = 0;
	i = 0;
	while (gen_data->blt[gen_data->n_built].in[i])
		i++;
	gen_data->blt[gen_data->n_built].fd_in = malloc(sizeof(int) * (i + 1));
	i = 0;
	while (gen_data->blt[gen_data->n_built].in[i])
	{
		gen_data->blt[gen_data->n_built].fd_in[y] = open(gen_data->blt[gen_data->n_built].in[i++], O_WRONLY |  O_CREAT | O_TRUNC, 0644);
		if (gen_data->blt[gen_data->n_built].fd_in[y] < 0)
			write(2, "error\n", 7);
		y++;
	}
	gen_data->blt[gen_data->n_built].fd_in[y] = -1;
}

void	fd_reds_out(t_general_data *gen_data, int z)
{
	int	i;
	int	y;

	y = 0;
	i = 0;
	while (gen_data->cmd[z].out[i])
		i++;
	gen_data->cmd[z].fd_out = malloc(sizeof(int) * (i + 1));
	i = 0;
	while (gen_data->cmd[z].out[i])
	{
		gen_data->cmd[z].fd_out[y] = open(gen_data->cmd[z].out[i++], O_WRONLY |  O_CREAT | O_TRUNC, 0644);
		if (gen_data->cmd[z].fd_out[y] < 0)
			write(2, "error\n", 7);
		y++;
	}
//	printf("--%d--", gen_data->cmd[z].fd_out[y - 1]);
	gen_data->cmd[z].fd_out[y] = -1;
}

void	fd_reds_in(t_general_data *gen_data, int z)
{
	int	i;
	int	y;

	y = 0;
	i = 0;
	while (gen_data->cmd[z].in[i])
		i++;
	gen_data->cmd[z].fd_in = malloc(sizeof(int) * (i + 1));
	i = 0;
	while (gen_data->cmd[z].in[i])
	{
		gen_data->cmd[z].fd_in[y] = open(gen_data->cmd[z].in[i++], O_WRONLY |  O_CREAT | O_TRUNC, 0644);
		if (gen_data->cmd[z].fd_in[y] < 0)
			write(2, "error\n", 7);
		y++;
	}
	gen_data->cmd[z].fd_in[y] = -1;
}
