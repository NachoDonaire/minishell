#include "../../../includes/minishell.h"

char    *double_red(t_general_data *gen_data, int position, int n_built)
{
        int     i;
        char    *s;
        char    *buff;
	int	copy_fd;

	copy_fd = 0;
        s = malloc(sizeof(char) * 1);
	s = "b";
        i = 0;
	buff = malloc(sizeof(char ) * 1);
	buff = "a";
        if (gen_data->sort[gen_data->exec_pos] == '1')
        {
                while (gen_data->cmd[position].fd_out[i] > 0)
                        i++;
                i--;
		copy_fd = dup(gen_data->cmd[position].fd_out[i]);
                s = get_next_line(copy_fd);
                while (s)
                {
                        buff = ft_strjoin(buff, s);
                        s = get_next_line(copy_fd);
                }
        }
        else if (gen_data->sort[gen_data->exec_pos] == '0')
        {
                while (gen_data->blt[n_built].fd_out[i] > 0)
                        i++;
                i--;
		copy_fd = dup(gen_data->blt[n_built].fd_out[i]);
                s = get_next_line(copy_fd);
                while (s)
                {
                        buff = ft_strjoin(buff, s);
                        s = get_next_line(copy_fd);
                }
        }
        return (buff);
}

void    already_red(t_general_data *gen_data, int position, int n_built)
{
	int	i;

	if (n_built == 23)
		return ;
	i = 0;
	while (gen_data->cmd[position].fd_out[i] > 0)
		i++;
	i--;
	dup2(1, gen_data->cmd[position].fd_out[i]);
	dup2(gen_data->cmd[position].fd_out[i], 1);
}




	



