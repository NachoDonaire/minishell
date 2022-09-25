#include "../../../includes/minishell.h"

char	*double_red(t_general_data *gen_data, int position, int n_built)
{
	int	i;
	char	*s;
	char	*buff;

	s = NULL;
	i = 0;
	if (gen_data->sort[gen_data->exec_pos] == '1')
	{
		while (gen_data->cmd[position].fd_out[i] > 0)
			i++;
		i--;
		s = get_next_line(gen_data->cmd[position].fd_out[i]);
		while (s)
		{
			buff = ft_strjoin(buff, s);
			s = get_next_line(gen_data->cmd[position].fd_out[i]);
		}
	}
	else if (gen_data->sort[gen_data->exec_pos] == '0')
	{
		while (gen_data->blt[n_built].fd_out[i] > 0)
			i++;
		i--;
		s = get_next_line(gen_data->blt[n_built].fd_out[i]);
		while (s)
		{
			buff = ft_strjoin(buff, s);
			s = get_next_line(gen_data->blt[n_built].fd_out[i]);
		}
	}
	return (buff);
}

void	already_red(t_general_data *gen_data)
{







		





