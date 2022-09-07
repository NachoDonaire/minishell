#include "../minishell.h"

char	*obtain_cmd(char **tmp, int i)
{
	int		y;
	int		z;
	char	*cmd;

	z = 0;
	y = 0;
	cmd = malloc(sizeof(char) * (lens(tmp[i]) + 1));
	while (tmp[i][y] == ' ')
		y++;
	while (tmp[i][y] != ' ' && tmp[i][y])
		cmd[z++] = tmp[i][y++];
	cmd[z] = '\0';
/*	if (check_cmllas(cmd) == 1)
		cmd = gest_cmllas(cmd);
		*/
	return (cmd);
}

char	*free_for_checkin_cmd(char **sol, char *k, int y)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!sol[y])
	{
		while (sol[i])
			free(sol[i++]);
		k = NULL;
	}
	if (!k)
	{
		free(k);
		tmp = ft_substr("no_cmd", 0, 7);
		return (tmp);
	}
	return (k);
}

char	*check_cmd(char *cmd, char *const env[])
{
	char	*path;
	char	*k;
	char	**sol;
	int		i;

	i = 0;
	path = find_path(env);
	sol = ft_split(&path[5], ':');
	k = pseudo_join(sol[i], cmd);
	while (sol[i] && access(k, F_OK) < 0)
	{
//		printf("--%d--\n", access(k, F_OK));
		free(k);
		i++;
		if (sol[i])
			k = pseudo_join(sol[i], cmd);
	}
	return (free_for_checkin_cmd(sol, k, i));
}	




