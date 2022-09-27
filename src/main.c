/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:22:35 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/26 13:28:45 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	needed_free_cmd(t_general_data *gen_data)
{
	int	i;

	i = 0;
	while (gen_data->cmd[i].cmd)
		free(gen_data->cmd[i++].cmd);
}

static void	ft_iniciate(t_general_data *gen_data)
{
	gen_data->n_pipes = 0;
	gen_data->built = 0;
	gen_data->n_built = 0;
	gen_data->n_cmd = 1;
	gen_data->exec_pos = 0;
	gen_data->pipe_pos = 0;
	gen_data->std_in = dup(0);
	gen_data->std_out = dup(1);
	gen_data->count_wait = 0;
}

static void	ft_free_all(t_general_data *gen_data, char *s)
{
	free(gen_data->sort);
	free(s);
//	needed_free(gen_data, gen_data->n_cmd);
}

int	main(int argc, char **argv, char *env[])
{
	char			*s;
	t_general_data	gen_data;
/*	int	y;
	int	i;

	i = 0;
	
	y = 0;
*/
	gen_data.env = get_env(env);
	while (argc && argv)
	{
		signal(SIGINT, handle_sigint);
		signal(SIGQUIT, SIG_IGN);
		ft_iniciate(&gen_data);
		s = readline("Minishell> ");
		if (s && s[0])
		{
			add_history(s);
			n_pipes(&gen_data, s);
			if (ft_check_exit(s) == 1)
			{
				ft_exit(s, gen_data.env);
			}
			reserva(&gen_data);
			process_input(s, &gen_data, gen_data.env);
	/*		
			while (y < gen_data.n_pipes + 1)
			{
				while (gen_data.cmd[y].args[i])
				{
					printf("--%s--\n", gen_data.cmd[y].args[i++]);
				}
				i = 0;
				y++;
			}
			y = 0;
	*/	
			ft_check_comand(&gen_data);
			if (gen_data.n_pipes > 0)
			{
				dup2(gen_data.std_out, 1);
				dup2(gen_data.std_in, 0);
			}
			ft_free_all(&gen_data, s);
		}
		else if (!s)
		{
			ft_exit(s, gen_data.env);
		}
	}
	return (0);
}
