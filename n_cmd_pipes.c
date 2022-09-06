#include "minishell.h"

void	check_cmd_pipe(t_general_data *gen_data, char *s)
{
	int	i;


	

void	n_pipes(t_general_data *gen_data, char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '|' || s[i] == '&')
			gen_data->n_cmd++;
		i++;
	}
	gen_data->n_cmd++;
}

