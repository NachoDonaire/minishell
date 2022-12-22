/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:22:35 by sasalama          #+#    #+#             */
/*   Updated: 2022/12/19 17:14:30 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_iniciate(t_general_data *gen_data)
{
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
	gen_data->n_pipes = 0;
	gen_data->built = 0;
	gen_data->smith_blt = 1;
	gen_data->n_built = 0;
	gen_data->n_cmd = 0;
	gen_data->exec_pos = 0;
	gen_data->pipe_pos = 0;
	gen_data->std_in = dup(0);
	gen_data->std_out = dup(1);
	gen_data->ojito = 0;
}

void	copy_dup(t_general_data	*gen_data)
{
	if (gen_data->n_pipes > 0)
	{
		dup2(gen_data->std_out, 1);
		dup2(gen_data->std_in, 0);
	}
}

int	check_spaces(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] == ' ' && s[i])
		i++;
	if (i == ft_strlen(s))
		return (0);
	return (1);
}

void	ft_can_syntax(t_general_data	*gen_data)
{
/*	int	i;
	int	y;
//
	y = 0;
	i = 0;
	*/
	if (syntax_error(gen_data->s) == 0)
	{
		reserva(gen_data);
		gen_data->s = teophilus(gen_data);
		//printf("--%s--\n", gen_data->s);
		process_input(gen_data->s, gen_data, gen_data->env);
		//while (y < gen_data->n_cmd)
		//{
		//while (gen_data->cmd[y].args[i])
		//	printf("--%s--\n", gen_data->cmd[y].args[i++]);
		//y++;
		//i = 0;
	//	}
	//	i = 0;
	//	y = 0;
	//	write(1, "aa", 2);
		//printf("--%d--", gen_data->n_cmd);
	//exit
	//	while (gen_data->blt[0].args[i])
	//		printf("--%s--\n", gen_data->blt[0].args[i++]);
		ft_check_comand(gen_data);
		//write(1, "1", 1);
//		write(1, "aa", 2);
		copy_dup(gen_data);
	//	ft_free_all(gen_data, gen_data->s);
	}
}

int	main(int argc, char **argv, char *env[])
{
	t_general_data	gen_data;

	ft_envs(&gen_data, env);
	while (argc && argv)
	{
		ft_iniciate(&gen_data);
		gen_data.s = readline("Minishell> ");
		if (gen_data.s && gen_data.s[0] && check_spaces(gen_data.s) == 1)
		{
			add_history(gen_data.s);
			n_pipes(&gen_data, gen_data.s);
			if (ft_check_exit(gen_data.s) == 1)
				ft_exit(gen_data.s, gen_data.env);
			ft_can_syntax(&gen_data);
		}
		else if (!gen_data.s)
			ft_exit(gen_data.s, gen_data.env);
	}
	return (0);
}
