/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:22:35 by sasalama          #+#    #+#             */
/*   Updated: 2022/10/04 19:46:33 by sasalama         ###   ########.fr       */
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

static void	ft_free_all(t_general_data *gen_data, char *s)
{
	free(s);
	if (!s)
		write(1, "aa", 2);
	needed_free(gen_data, gen_data->n_cmd);
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
			printf("hola");
			n_pipes(&gen_data, gen_data.s);
			if (ft_check_exit(gen_data.s) == 1)
				ft_exit(gen_data.s, gen_data.env);
			reserva(&gen_data);
			printf("adios");
			process_input(gen_data.s, &gen_data, gen_data.env);
			printf("que");
			ft_check_comand(&gen_data);
			printf("tal");
			copy_dup(&gen_data);
			ft_free_all(&gen_data, gen_data.s);
			printf("estas");
		}
		else if (!gen_data.s)
			ft_exit(gen_data.s, gen_data.env);
	}
	return (0);
}
