/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:22:35 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/09 13:07:46 by ndonaire         ###   ########.fr       */
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
}

static void	ft_free_all(t_general_data *gen_data, char *s)
{
	free(gen_data->sort);
	free(s);
	needed_free(gen_data, gen_data->n_pipes);
}

int	main(int argc, char **argv, char *env[])
{
	char			*s;
	t_general_data	gen_data;

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
			reserva(&gen_data);
			if (ft_check_exit(s) == 1)
				ft_exit(s, gen_data.env);
			process_input(s, &gen_data, gen_data.env);
			ft_check_comand(&gen_data);
			ft_free_all(&gen_data, s);
		}
		else if (!s)
			ft_exit(s, gen_data.env);
	}
	return (0);
}
