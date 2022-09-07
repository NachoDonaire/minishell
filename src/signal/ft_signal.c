/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:03:32 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/07 17:04:05 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	handle_sigint(int sig)
{
	if (sig == SIGINT)
	{
		ioctl(STDIN_FILENO, TIOCSTI, "\n"); // STDIN_FILENO: File descriptor terminal TIOCSTI: Simulation of stdin of the terminal
		rl_replace_line("", 0); // Unsave in the history in the case we don´t finish the command
		rl_on_new_line();
	}
}
