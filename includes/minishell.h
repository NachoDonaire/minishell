/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:56:44 by sasalama          #+#    #+#             */
/*   Updated: 2022/11/08 09:06:00 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/ioctl.h>
# include <fcntl.h>
# include "get_next_line.h"

/*global*/

/*estructura inside cmd*/
typedef struct s_insidecmd
{
	char	**cmd_args;
}	t_inside_cmd;

/*estructura del builtin provisional*/
typedef struct s_builtin
{
	char	*blt;
	char	**args;
	char	**out;
	char	**in;
	int		*fd_out;
	int		*fd_in;
	int		*dred;
	int		*in_dred;
	int		nb_arguments;
}	t_builtin_data;

/* estructura del comando provisional*/
typedef struct s_comand
{
	char	*cmd;
	char	**args;
	char	**out;
	char	**in;
	int		*fd_out;
	int		*fd_in;
	int		*in_dred;
	int		*dred;
}	t_cmd_data;

/*estructura general proxisional*/
typedef struct s_general
{
	char			**env;
	int				red;
	t_cmd_data		*cmd;
	t_builtin_data	*blt;
	int				n_cmd;
	int				n_pipes;
	int				built;
	int				n_built;
	char			*sort;
	int				good_status;
	int				**pipe;
	int				exec_pos;
	int				*pid;
	int				pipe_pos;
	int				std_in;
	int				std_out;
	int				count_wait;
	int				smith_blt;
	char			*s;
}	t_general_data;

void	rl_replace_line(const char *text, int clear_undo);

/*en utils.c*/
char	*find_path(char *const env[]);
char	*pseudo_join(char *path, char *com);
void	split_path(char *env, char *arg, t_general_data *gen_data);
int		checkin_path(char *s, char *find);
int		lens(char *s);
void	freeear(char **sol, char *k, t_general_data *gen_data);

/*en utils2.c*/
int		extreme_finder(char *s, char *find);
int		finder(char *s, char *find);

/*en commillas.c, gesteo de las comillas en el comando(por el momento)*/
int		check_cmllas(char *s);
char	*gest_cmllas(char *s);
char	**dr_comillas(char *s);
void	ft_reset_table_6(int *t);
void	dr_comillas_aviso(char *s, char **wallace, int *t);
void	dr_comillas_not_aviso(char *s, char **wallace, int *t);

/*en ft_process_input.c*/
void	process_string(char *s, t_general_data *gen_data, char *env[], int y);
void	process_args(char *s, t_general_data *gen_data, int y, int ref);
void	process_input(char *s, t_general_data *gen_data, char *env[]);
void	ft_reset_blt(t_general_data *gen_data);

//void	finish_data(t_general_data *gen_data);

/*en prueba2.c */
void	the_cmd(char *s, char *env[], t_general_data *gen_data);
void	cmd_args(char *s, t_cmd_data *cmd);
void	needed_free_cmd(t_general_data *gen_data);

/*en n_cmd*/
void	n_pipes(t_general_data *gen_data, char *s);
void	check_cmd_pipe(t_general_data *gen_data, char *s, char *env[]);

/*en check_builtin.c*/
void	check_builtins(char *s, t_general_data *gen_data, int y);
int		args_with_reds(char *copy);
void	check_builtins2(char *s, t_general_data *gen_data, int y);
void	ft_reset_cmd(t_general_data *gen_data, int y);

/*ft_strjoin*/
char	*copy(char *s1, char *s2, char *x);
char	*cncat(char *s1, char *s2);

/*en check_cmd.c*/
char	*obtain_cmd(char **tmp, int i);
char	*free_for_checkin_cmd(char **sol, char *k, int y, char *cmd);
char	*check_cmd(char *cmd, char *env[]);

/*en check_pipes.c*/
void	handle_cmd_pipes(t_general_data *gen_data, char *s, char *env[]);
void	process_string_w_pipes(t_general_data *gen_data, char *s, char *env[]);
int		gest_ampersand(char *s, t_general_data *gen_data, char *env[], int y);
void	free_tmp(char **tmp);

/*en out_reds.c*/
int		find_red(t_general_data *gen_data, char *s, int pos, int ref);
void	gest_reds(t_general_data *gen_data, char *s, int y, int ref);
void	process_sing_red(t_general_data *gen_data, char *s, int y, int ref);
void	paste_tmp_red(t_general_data *gen_data, char **tmp, int y, int ref);
void	memory_for_red(t_general_data *gen_data, char **tmp, int y, int ref);
int		find_double_red(char *s);
void	ft_ref_one(t_general_data *gen_data, char *s, int y, int ref);
void	ft_ref_zero(t_general_data *gen_data, char *s, int y, int ref);
void	no_red_out(t_general_data *gen_data, int y);
void	memory_dred(t_general_data *gen_data, char *s, int pos, int ref);
void	ft_reset_table_5(int *t, t_general_data *gen_data);
void	ft_modify_table_2(int *t);
void	ft_modify_table_3(int *t);
void	paste_tmp_red_ref(t_general_data *gen_data, int y, int ref, int *t);

/*en in_reds.c*/
int		find_in_red(t_general_data *gen_data, char *s, int pos, int ref);
void	gest_in_reds(t_general_data *gen_data, char *s, int y, int ref);
void	process_in_red(t_general_data *gen_data, char *s, int y, int ref);
void	paste_tmp_in_red(t_general_data *gen_data, char **tmp, int y, int ref);
void	memory_for_in_red(t_general_data *gen_data, char **tmp, int y, int ref);
void	no_red_in(t_general_data *gen_data, int y);
void	memory_indred(t_general_data *gen_data, char *s, int pos, int ref);
void	ft_reset_table2(int *table, t_general_data *gen_data);
void	ft_modify_table(int *t);
void	ft_modify_table2(int *t);

/*en fd_reds*/
void	fd_reds_out_b(t_general_data *gen_data);
void	fd_reds_in_b(t_general_data *gen_data);
void	fd_reds_out(t_general_data *gen_data, int z);
void	fd_reds_in(t_general_data *gen_data, int z);
int		ft_count_cmd_in(t_general_data *gen_data);
int		ft_count_blt_out(t_general_data *gen_data);
void	ft_reset_table_7(int *t, t_general_data *gen_data);

/*exec cmd*/

void	ft_exec2(t_general_data *gen_data, int position, int n_built);

/*exec builtins*/

void	ft_check_comand(t_general_data *gen_data);
int		ft_check_cd(t_general_data *gen_data, int x);
int		ft_check_pwd(t_general_data *gen_data, int x);
int		ft_check_echo(t_general_data *gen_data, int x);
int		ft_check_export(t_general_data *gen_data, int x);
int		ft_check_unset(t_general_data *gen_data, int x);
void	ft_echo(t_general_data *gen_data, int position);
void	ft_cd(t_general_data *gen_data, int position);
void	ft_pwd(t_general_data *gen_data);
void	ft_unset(t_general_data *gen_data, int position);
void	ft_env(t_general_data *gen_data);
void	ft_export(t_general_data *gen_data, int position);

/*env*/
char	**get_env(char **envp);

/*echo*/
void	ft_print_v(char **nb_arguments, int x, int y, t_general_data *gen_data);
int		ft_dollar(char *argument);
int		ft_n(char *argument);
int		ft_equal(char *s);
int		ft_nb_arguments(char **nb_arguments);
void	ft_free_arg(char **arguments);
int		ft_check_nl(t_general_data *gen_data, int position);
void	ft_print_fdout(t_general_data *gen_data, char s);
void	ft_print(int x, t_general_data *gen_data, int position);
void	ft_print_fdout2(t_general_data *gen_data, char *s);

/*export*/

int		ft_find_variable(char *v, char **env);
void	ft_create_variable(char *variable, char *value, char **env);
void	ft_replace_variable(char *variable, char *value, char **env);
char	*ft_variables(char *v);
int		ft_strcmp(char *s1, char *s2);
char	*ft_value(char *v);

/*unset*/

void	ft_not_equal(t_general_data *gen_data, int p, int x);
void	ft_print_bad(t_general_data *gen_data, int p, int x);

/*status*/

void	ft_check_status(t_general_data *gen_data, int position);
void	ft_change_good_status(char **env, t_general_data *gen_data);
void	ft_change_bad_status(char **env, t_general_data *gen_data);
void	ft_change_permission_status(char **env, t_general_data *gen_data);

/*exec temporal*/
int		ft_exec(t_general_data *gen_data, int position, int n_built);
void	ft_path(char *command, char *envp[], char **fd_path);
void	dup_reds(t_general_data *gen_data, int position, int n_built);
void	dup_in_reds(t_general_data *gen_data, int position, int n_built);

/*funciones libft*/
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_itoa(int n);

/*en memory.c*/
void	reserva(t_general_data *gen_data);
void	needed_free(t_general_data *gen_data, int y);

/*signal*/
void	handle_sigint(int sig);

/*exit*/
void	ft_exit(char *texto, char **tmp);
int		ft_check_exit(char *s);

/*d_red.c*/
void	already_red(t_general_data *gen_data, int position, int n_built);
char	*double_red(t_general_data *gen_data, int position, int n_built);

char	*ft_expand(t_general_data *gen_data);
int		ft_quote(char *s);

#endif
