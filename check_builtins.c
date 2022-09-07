#include "minishell.h"

void	paste_in_built(t_general_data *gen_data, char *s)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	while (s[i])
		i++;
	gen_data->blt[gen_data->n_built].blt = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (s[i] == ' ')
		i++;
	while (s[i])
		gen_data->blt[gen_data->n_built].blt[z++] = s[i++];
	gen_data->blt[gen_data->n_built].blt[z] = '\0';
}

void	check_builtins(char *s, t_general_data *gen_data, int y)
{
	char	**tmp;
	char	*copy;

	if (extreme_finder(s, "echo") == 1 || extreme_finder(s, "pwd") == 1
			|| extreme_finder(s, "cd") == 1 || extreme_finder(s, "export") == 1
			|| extreme_finder(s, "unset") == 1 || extreme_finder(s, "env") == 1)
	{
		tmp = ft_split(s, ' ');
		paste_in_built(gen_data, tmp[0]);
		copy = ft_substr(s, ft_strlen(gen_data->blt[gen_data->n_built].blt), ft_strlen(s) + 1);
		gen_data->blt[gen_data->n_built].args = ft_split(copy, ' ');
		gen_data->cmd[y].cmd = malloc(sizeof(char) * 8); 
		gen_data->cmd[y].args = malloc(sizeof(char *) * 1);
		gen_data->cmd[y].args[0] = malloc(sizeof(char) * 2);
		gen_data->built = 1;
		gen_data->n_built++;
	}
}
