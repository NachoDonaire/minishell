/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:16:24 by salustianos       #+#    #+#             */
/*   Updated: 2022/08/24 14:39:26 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/ioctl.h>

void	rl_replace_line(const char *text, int clear_undo);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_echo(char **env);
void	ft_cd(char **env);
void	ft_pwd(char **env);
void	ft_check_comand(char *s, char **tmp);
int		ft_check_echo(char *s, char **enpv);
int		ft_check_pwd(char *s, char **env);
int		ft_check_cd(char *s, char **env);
int		ft_check_unset(char *s, char **env);
int		ft_check_export(char *s, char **env);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_unset(char **env);
void	ft_env(char **env);
void	ft_export(char **env);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(const char *s, int c);
char	**get_env(char **envp);
char	*ft_strrchr(const char *s, int c);
char	**ft_split(char const *s, char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_print_quotation_s(char *argument);
int		ft_print_quotation_d(char *argument);
void	ft_print_variable(char **nb_arguments, int x, int y, char **env);
int		ft_print_quotation_d2(char *argument);
int		ft_print_quotation_s2(char *argument);
int		ft_c_d(char *argument);
int		ft_c_s(char *argument);
int		ft_dollar(char *argument);
int		ft_n(char *argument);
int		ft_equal(char *s);
char	*ft_variables(char *v);
char	*ft_value(char *v);
int		ft_find_variable(char *v, char **env);
void	ft_create_variable(char *variable, char *value, char **env);
void	ft_replace_variable(char *variable, char *value, char **env);
void	ft_change_good_status(char **env);
void	ft_change_bad_status(char **env);
void	ft_change_permission_status(char **env);
void	ft_exec(char *arguments, char **env);
void	ft_path(char *command, char *envp[], char **fd_path);
void	ft_free_arg(char **arguments);
int	ft_strcmp(char *s1, char *s2);

#endif