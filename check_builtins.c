#include "minishell.h"

void	check_builtins(char *s, t_general_data *gen_data, int y)
{
	char	**tmp;
	char	*copy;

	if (extreme_finder(s, "echo") == 1 || extreme_finder(s, "pwd") == 1
			|| extreme_finder(s, "cd") == 1 || extreme_finder(s, "export") == 1
			|| extreme_finder(s, "unset") == 1 || extreme_finder(s, "env") == 1)
	{
		tmp = ft_split(s, ' ');
		gen_data->blt->blt = ft_substr(tmp[0], 0, ft_strlen(tmp[0]));
		copy = ft_substr(s, ft_strlen(tmp[0]), ft_strlen(s));
		ft_free_arg(tmp);
		gen_data->blt->args = ft_split(copy, ' ');
		gen_data->cmd[y].cmd = "builtin";
		gen_data->cmd[y].args = NULL;
		gen_data->built = 1;
	}
}
