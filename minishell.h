# ifndef MINILIB_H
#define MINILIB_H
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/ioctl.h>

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
	int		nb_arguments;
}	t_builtin_data;

/* estructura del comando provisional*/
typedef struct s_comand
{
	char	*cmd;
	char	**args;
	char	**out;
	char	**in;
	int	dred;
}	t_cmd_data;

/*estructura general proxisional*/
typedef struct s_general
{
	char	**env;
	int		red;
	t_cmd_data	*cmd;
	t_builtin_data	*blt;
	int		n_cmd;
	int		n_pipes;
	int		built;
	int		n_built;
	char	*sort;
}	t_general_data;

void	rl_replace_line(const char *text, int clear_undo);

/*en utils.c*/
char	*find_path(char *const env[]);
char	*pseudo_join(char *path, char *com);
void	split_path(char *env, char *arg, t_general_data *gen_data);
int	checkin_path(char *s, char *find);
int	lens(char *s);
char	**ft_split(char const *s, char c);
void	freeear(char **sol, char *k, t_general_data *gen_data);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t n);

/*en commillas.c, gesteo de las comillas en el comando(por el momento)*/
int	check_cmllas(char *s);
char	*gest_cmllas(char *s);

/*en prueba2.c */
int     finder(char *s, char *find);
int	extreme_finder(char *s, char *find);
void    process_string(char *s, t_general_data *gen_data, char *const env[], int y);
void    process_exit(char *s, int *i);
void    the_cmd(char *s, char *const env[], t_general_data *gen_data);
void    cmd_args(char *s, t_cmd_data *cmd);
void	needed_free_cmd(t_general_data *gen_data);
void	process_args(char *s, t_general_data *gen_data, int y);

/*en n_cmd*/
void	n_pipes(t_general_data *gen_data, char *s);
void	check_cmd_pipe(t_general_data *gen_data, char *s, char *const env[]);

/*en check_builtin.c*/
void	check_builtins(char *s, t_general_data *gen_data, int y);

/*ft_strjoin*/
char     *copy(char *s1, char *s2, char *x);
char     *cncat(char *s1, char *s2);
char    *ft_strjoin(char *s1, char *s2);

/*en check_cmd.c*/
char    *obtain_cmd(char **tmp, int i);
char    *free_for_checkin_cmd(char **sol, char *k, int y);
char	*check_cmd(char *cmd, char *const env[]);

/*en check_pipes.c*/
void    handle_cmd_pipes(t_general_data *gen_data, char *s, char *const env[]);
void    process_string_with_pipes(t_general_data *gen_data, char *s, char *const env[]);
char	*handle_cont_pipe(char *join);
int	gest_ampersand(char *s, t_general_data *gen_data, char *const env[],  int y);
void	free_tmp(char **tmp);

/*en out_reds.c*/
int	find_red(char *s);
void	gest_reds(t_general_data *gen_data, char *s, int y);
void	process_sing_red(t_general_data *gen_data, char *s, int y);
void	paste_tmp_red(t_general_data *gen_data, char **tmp, int y);
void	memory_for_red(t_general_data *gen_data, char **tmp, int y);

/*en in_reds.c*/
int	find_in_red(char *s);
void	gest_in_reds(t_general_data *gen_data, char *s, int y);
void	process_in_red(t_general_data *gen_data, char *s, int y);
void	paste_tmp_in_red(t_general_data *gen_data, char **tmp, int y);
void	memory_for_in_red(t_general_data *gen_data, char **tmp, int y);


/*exec builtins*/

void	ft_check_comand(t_general_data *gen_data);
int		ft_check_cd(t_general_data *gen_data);
int		ft_check_pwd(t_general_data *gen_data);
int		ft_check_echo(t_general_data *gen_data);
int		ft_check_export(t_general_data *gen_data);
int		ft_check_unset(t_general_data *gen_data);
void	ft_echo(t_general_data *gen_data);
void	ft_cd(t_general_data *gen_data);
void	ft_pwd(char **env);
void	ft_unset(t_general_data *gen_data);
void	ft_env(char **env);
void	ft_export(t_general_data *gen_data);

/*env*/
char	**get_env(char **envp);

/*echo*/
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
int		ft_nb_arguments(char **nb_arguments);
void	ft_free_arg(char **arguments);

/*export*/

int		ft_find_variable(char *v, char **env);
void	ft_create_variable(char *variable, char *value, char **env);
void	ft_replace_variable(char *variable, char *value, char **env);
char	*ft_variables(char *v);
int		ft_strcmp(char *s1, char *s2);
char	*ft_value(char *v);

/*status*/

void	ft_change_good_status(char **env);
void	ft_change_bad_status(char **env);
void	ft_change_permission_status(char **env);

/*exec temporal*/
void	ft_exec(t_general_data *gen_data);
void	ft_path(char *command, char *envp[], char **fd_path);

/*funciones libft*/
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/*en memory.c*/
void	reserva(t_general_data *gen_data);
void	needed_free(t_general_data *gen_data, int y);

#endif
