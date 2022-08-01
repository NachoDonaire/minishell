/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salustianosalamanca <salustianosalamanc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:16:24 by salustianos       #+#    #+#             */
/*   Updated: 2022/08/01 15:27:53 by salustianos      ###   ########.fr       */
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
void	ft_echo(char **env);
void	ft_cd();
void	ft_pwd();
int	ft_comprobar_comando(char *s, char **enpv);
int	ft_comprobar_echo(char *s, char **enpv);
int	ft_comprobar_pwd(char *s);
int ft_comprobar_cd(char *s, char **env);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_unset(char **env);
void	ft_env(char **env);
void	ft_export(char **env);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(const char *s, int c);
char	**get_env(char **envp);

#endif