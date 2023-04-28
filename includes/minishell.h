/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:56:44 by sasalama          #+#    #+#             */
/*   Updated: 2023/01/14 16:36:45 by ndonaire         ###   ########.fr       */
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
	int		syn_er;
	int		nb_arguments;
	int		can_exec;
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
	int		syn_er;
	int		*in_dred;
	int		*dred;
	int		can_exec;
}	t_cmd_data;

/*estructura general proxisional*/
typedef struct s_general
{
	char			**env;
	char			**s_env;
	int				path;
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
	int				pid;
	int				pipe_pos;
	int				std_in;
	int				std_out;
	int				raskolnikof;
	int				smith_blt;
	int				taker;
	int				otrostdin;
	int				ojito;
	char			*s;
}	t_general_data;

typedef struct s_dr
{
	char	**wallace;
	int		i;
	int		w;
}	t_dr;

typedef struct s_teo
{
	int		i;
	char	*of;
	int		w;
	int		f;
	int		ojito;
}	t_teo;

void	rl_replace_line(const char *text, int clear_undo);

/*en teophilus, lexer/expand*/
char	*teophilus(t_general_data *gen_data);
int		tiberio(t_general_data *gen_data, t_teo teophi);
int		tiberio_dollar(t_general_data *gen_data, t_teo teophi);
int		tiberio_39(t_general_data *gen_data, t_teo teophi);
int		tiberio_34(t_general_data *gen_data, t_teo teophi);
char	*variable_pwd(t_general_data *gen_data);
char	*variable_oldpwd(t_general_data *gen_data);
char	*variable_path(t_general_data *gen_data);
int		variable_size(t_general_data *gen_data, char *c);
char	*not_variable(t_general_data *gen_data, char *c);
int		char_size(t_general_data *gen_data, int i);
char	*variable(t_general_data *gen_data, char *c);
char	*copy_var(char *s);
int		comillas_dobles_i(char *s, int i);
int		comillas_dobles(char *s, t_general_data *data, int f, t_teo teophi);
int		comillas_simples_i(char *s, int i);
int		comillas_simples(char *s, t_general_data *data, int f, t_teo teophi);
int		dollar_ref_0_i(char *s, int i);
int		not_dollar(char *s, int w, int i, char *of);
int		dollar_ref_0_w(char *c, char *of, int w);
int		dollar_d(char *s, t_general_data *data, int i, t_teo teophi);
int		dollar_2(char *s, t_general_data *data, int i, t_teo teophi);
int		dollar(char *s, t_general_data *gen_data, int ref, t_teo teophi);
int		ft_tiberio_comillas_simples(t_general_data *gen_data, int i);
int		ft_tiberio_comillas_dobles(t_general_data *gen_data, int i);
int		tiberio_dollar2(t_general_data *gen_data, t_teo teophi);

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

/*en syntax_error, en lexer/input*/
int		syntax_error(char *s);

/*en commillas.c, gesteo de las comillas en el comando(por el momento)*/
int		check_cmllas(char *s);
char	*gest_cmllas(char *s);
char	**dr_comillas(char *s);
void	ft_reset_table_6(int *t);
void	dr_comillas_aviso(char *s, char **wallace, int *t);
void	dr_comillas_not_aviso(char *s, char **wallace, int *t);
int		gest_comillas(char *s, t_dr dr_comillas, int y);
int		gest_comillas_34(char *s, t_dr dr_comillas, int y);
int		gest_comillas_39(char *s, t_dr dr_comillas, int y);
int		dr_no_comillas(char *s, t_dr dr_comillas, int y);
char	**dr_comillas(char *s);
void	gest_comillas_not_y(char *s, t_dr dr_comillas, int y);
void	gest_comillas_not_s(char *s, t_dr dr_comillas, int y);
int		memory_for_wallace(char *s, t_dr dr_comillas, int y);
char	**fill_wallace(char *s);

/*en ft_process_input.c*/
void	process_string(char *s, t_general_data *gen_data, int y);
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
int		n_spaces(char *copy);

/*ft_strjoin*/
char	*copy(char *s1, char *s2, char *x);
char	*cncat(char *s1, char *s2);

/*en check_cmd.c*/
char	*obtain_cmd(char **tmp, int i);
char	*free_for_checkin_cmd(char **sol, char *k, int y, char *cmd);
char	*check_cmd(char *cmd, t_general_data *gen_data);

/*en check_pipes.c*/
void	handle_cmd_pipes(t_general_data *gen_data, char *s, char *env[]);
void	process_string_w_pipes(t_general_data *gen_data, char *s, char *env[]);
int		gest_ampersand(char *s, t_general_data *gen_data, int y);
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
void	ft_status_error(t_general_data *gen_data, int position, int n_built);
int		ft_find_path(t_general_data *gen_data);
void	ft_change_root(t_general_data *gen_data, char **s3, int position);
void	ft_child_2(t_general_data *gen_data, char **s3, int position);
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
void	ft_check_secret_env(t_general_data *gen_data);
char	**check_env(char **env, char **envp);
void	ft_envs(t_general_data	*gen_data, char **env);

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
void	ft_replace_v2(char *variable, char *value, t_general_data *gen_data);
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
void	dup_in_reds(t_general_data *gen_data, int position,
			int n_built, int ref);
void	ft_dup_in_reds_exit(char *s, int *pipedo);
void	ft_dup_in_reds_wait(int piddy_gonzalez, int *pipedo,
			t_general_data *gen_data);
void	ft_dup_in_reds_blt(t_general_data *gen_data, int n_built, int *pipedo);
void	ft_dup_in_reds_cmd(t_general_data *gen_data, int position,
			int *pipedo, int ref);
void	ft_dup_in_reds_blt2(t_general_data *gen_data, int n_b, int *p, int i);
void	ft_dup_in_reds_cm2(t_general_data *gen_data, int p, int *pipedo, int i);

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
void	needed_free_cmd(t_general_data *gen_data);
void	ft_free_all(t_general_data *gen_data, char *s);
void	close_fds(t_general_data *gen_data);

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

/*syntax_error.c*/
int		ft_space(char *joined, int i);
int		ft_free_joined(char *joined);
int		check_single(char *s, int a, int n_pipes);
int		check_double(char *s, int a, int n_pipes);
int		check_reds(char *s);
int		double_quotes(char *s);
int		single_quotes(char *s);
int		check_millas(char *s);
int		check_pipes(char *s);
int		pipes_count(char *s);

/*ft_cd.c*/
void	ft_change_pwd(char **env);
void	ft_change_oldpwd_2(char *tmp, t_general_data *gen_data, int x, int y);
void	ft_change_oldpwd(char *tmp, t_general_data *gen_data);
void	ft_error_cd(char *arguments, char **env, t_general_data *gen_data);
void	ft_reset_pwd_2(t_general_data *gen_data, char *buf, int y);

/* en hasta los huevos. tema de heredoc para builtins*/
void	dup_in_reds_blt(t_general_data *gen_data, int n_built, int pipedo[2]);
int		check_tukle(char *s);
void	so_f_tired(t_general_data *gen_data, int z);
void	error_can_exec(t_general_data *gen_data,
			int n_built, int position, int ref);
void	initialise_dr(t_dr *doctorsito);
int		oficial_tukle(char *s, t_general_data *gen_data, int y);
void	qhagocntigo(t_general_data *gen_data, int y, char *s);
int		check_xlacara(t_general_data *gen_data, int position, int n_built);
void	free_heredoc(t_general_data *gen_data, int i);
int		in_dred_finder(int *tak);

void	ft_dup_in_reds_cm3(t_general_data *gen_data, int p, int *pipedo, int i);
void	ft_dup_in_reds_blt3(t_general_data *gen_data, int n_b, int *p, int i);
void	ft_child_pipes2(t_general_data *gen_data, int position, int n_built);
void	ft_child3(t_general_data *gen_data, int position,
			int n_built, char **s3);
void	find_in_red_quote(char *s, int *table);
void	find_red2_quote(char *s, int *table);
int		mela(char *s);
void	pela(t_general_data *gen_data, char *s, int y);
void	aunmas(t_general_data *gen_data, char *s, int y);
void	ft_not_built2(t_general_data *gen_data);
int		dollar_not(char *s, int i, t_teo teophi);
void	ft_free_c(char	*c);
int		dollar_else(char *s, t_general_data *gen_data, int i, t_teo teophi);
void	close_fds(t_general_data *gen_data);
void	close_fds2(t_general_data *gen_data);
void	ft_free_cmd(t_general_data *gen_data, int y);
void	frio_cmd(t_general_data *gen_data, int i);
void	ft_free_built(t_general_data *gen_data);
void	ft_free_built_0(t_general_data *gen_data);
void	oficial_tukle_1_2(t_general_data *gen_data, char *s, int y);
void	reset_table_pipes(int *t);

#endif
