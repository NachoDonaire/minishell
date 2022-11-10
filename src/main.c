/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:22:35 by sasalama          #+#    #+#             */
/*   Updated: 2022/11/10 17:39:10 by sasalama         ###   ########.fr       */
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

void	ft_iniciate(t_general_data *gen_data) // static
{
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
	gen_data->n_pipes = 0;
	gen_data->built = 0;
	gen_data->smith_blt = 1;
	gen_data->n_built = 0;
	gen_data->n_cmd = 1;
	gen_data->exec_pos = 0;
	gen_data->pipe_pos = 0;
	gen_data->std_in = dup(0);
	gen_data->std_out = dup(1);
	gen_data->count_wait = 0;
}

void	ft_free_all(t_general_data *gen_data, char *s) //static
{
	free(s);
	needed_free(gen_data, gen_data->n_cmd - gen_data->n_built);
}

void	copy_dup(t_general_data	*gen_data)
{
	if (gen_data->n_pipes > 0)
	{
		dup2(gen_data->std_out, 1);
		dup2(gen_data->std_in, 0);
	}
}

int	main(int argc, char **argv, char *env[])
{
	t_general_data	gen_data;

	gen_data.env = get_env(env);
	while (argc && argv)
	{
		ft_iniciate(&gen_data);
		gen_data.s = readline("Minishell> ");
		if (gen_data.s && gen_data.s[0])
		{
			add_history(gen_data.s);
			n_pipes(&gen_data, gen_data.s);
			if (ft_check_exit(gen_data.s) == 1)
				ft_exit(gen_data.s, gen_data.env);
			if (syntax_error(gen_data.s) == 0)
			{
				reserva(&gen_data);
				gen_data.s = ft_expand(&gen_data);
				process_input(gen_data.s, &gen_data, gen_data.env);
				ft_check_comand(&gen_data);
				copy_dup(&gen_data);
				ft_free_all(&gen_data, gen_data.s);
			}
		}
		else if (!gen_data.s)
			ft_exit(gen_data.s, gen_data.env);
	}
	return (0);
}
