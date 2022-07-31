#include "minishell.h"

void	check_builtins(char *s, general_data *gen_data)
{
	if (extreme_finder(s, "echo") == 1 || extreme_finder(s, "pwd") == 1
			|| extreme_finder(s, "cd") == 1 || extreme_finder(s, "export") == 1
			|| extreme_finder(s, "unset") == 1 || extreme_finder(s, "env") == 1)
	{
		write(1, "bb", 2);
		gen_data->blt.blt = ft_split(s, ' ');
		gen_data->blt.args = ft_split(s, ' ');
		//gen_data->cmd.cmd = NULL;
		//gen_data->cmd.args = NULL;
		gen_data->built = 1;
	}
}
