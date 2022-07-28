/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salustianosalamanca <salustianosalamanc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:16:24 by salustianos       #+#    #+#             */
/*   Updated: 2022/07/28 20:01:28 by salustianos      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <readline/readline.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_echo();
void	ft_cd();
void	ft_pwd();
int	ft_comprobar_comando(char *s);
int	ft_comprobar_echo(char *s);
int	ft_comprobar_pwd(char *s);
int ft_comprobar_cd(char *s);

#endif