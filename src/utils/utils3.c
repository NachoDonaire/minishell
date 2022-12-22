#include "../../includes/minishell.h"

int	in_dred_finder(int	*tak)
{
	int	i;

	i = 0;
	while (tak[i] >= 0)
	{
		if (tak[i] == 1)
			return (1);
		i++;
	}
	return (0);
}
