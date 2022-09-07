/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:22:35 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/07 17:22:37 by sasalama         ###   ########.fr       */
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

int main(int argc, char **argv, char *env[])
{
	char			*s;
	t_general_data	gen_data;
	char			*tmp;
	int				y;
	int			z;

	z = 0;
	y = 0;
	gen_data.env = get_env(env);
	if (y == 233333 || z == 987678)
		write(1, "a", 1);
	while (argc && argv)
	{
		signal(SIGINT, handle_sigint);
		signal(SIGQUIT, SIG_IGN);
		gen_data.n_pipes = 0;
		gen_data.built = 0;
		gen_data.n_built = 0;
		gen_data.n_cmd = 1;
		s = readline("Minishell> ");
		if (s)
		{
			if (s[0])
			{
				tmp = s;
				s = ft_substr(s, 0, ft_strlen(s));
				free(tmp);
				add_history(s);
				n_pipes(&gen_data, s);
				reserva(&gen_data);
				if (ft_check_exit(s) == 1)
					ft_exit(s, gen_data.env);
				process_input(s, &gen_data, gen_data.env);
/*				while (y < gen_data.n_built)
				{
					while (gen_data.blt[y].out[z])
						printf("%s\n", gen_data.blt[y].out[z++]);
					z = 0;
					y++;
				}
				*/

			//	while (gen_data.cmd->args[y])
			//		printf("%s\n", gen_data.cmd->args[y++]);
			//	printf("--%d--\n", gen_data.n_cmd);
				//ft_check_comand(&gen_data);
				y = 0;
				/*while (y <= gen_data.n_pipes && finder(s, "<") == 1)
				{
					while (gen_data.cmd[y].in[z])
						printf("%s\n", gen_data.cmd[y].in[z++]);
					printf("%d\n", gen_data.cmd[y].dred);
					z = 0;
					y++;
				}*/
				free(gen_data.sort);
				free(s);
				needed_free(&gen_data, gen_data.n_cmd);
			}
		//	printf("%s\n", gen_data.cmd[0].cmd);
		}
		else
			ft_exit(s, gen_data.env);
	}
	printf("exit\n");
	return (0);
}
