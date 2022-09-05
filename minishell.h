# ifndef MINILIB_H
#define MINILIB_H
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>

/*estructura inside cmd*/
typedef struct insidecmd{
	char	**cmd_args;
}	inside_cmd;

/*estructura del builtin provisional*/
typedef struct builtin{
	char	**blt;
	char	**args;
}	builtin_data;

/* estructura del comando provisional*/
typedef struct comand{
	char	*cmd;
	char	**args;
	char	**out;
	char	**in;
	int	dred;
}	cmd_data;

/*estructura general proxisional*/
typedef struct general{
	int		red;
	cmd_data	*cmd;
	builtin_data	blt;
	int		n_cmd;
	int		n_pipes;
	int		built;
}	general_data;

/*en utils.c*/
char	*find_path(char *const env[]);
char	*pseudo_join(char *path, char *com);
void	split_path(char *env, char *arg, general_data *gen_data);
int	checkin_path(char *s, char *find);
int	lens(char *s);
char	**ft_split(char const *s, char c);
void	freeear(char **sol, char *k, general_data *gen_data);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t n);

/*en commillas.c, gesteo de las comillas en el comando(por el momento)*/
int	check_cmllas(char *s);
char	*gest_cmllas(char *s);

/*en prueba2.c */
int     finder(char *s, char *find);
int	extreme_finder(char *s, char *find);
void    process_string(char *s, general_data *gen_data, char *const env[], int y);
void    process_exit(char *s, int *i);
void    the_cmd(char *s, char *const env[], general_data *gen_data);
void    cmd_args(char *s, cmd_data *cmd);
void	needed_free_cmd(general_data *gen_data);
void	process_args(char *s, general_data *gen_data, int y);

/*en n_cmd*/
void	n_pipes(general_data *gen_data, char *s);
void	check_cmd_pipe(general_data *gen_data, char *s, char *const env[]);

/*en check_builtin.c*/
void	check_builtins(char *s, general_data *gen_data, int y);

/*ft_strjoin*/
char     *copy(char *s1, char *s2, char *x);
char     *cncat(char *s1, char *s2);
char    *ft_strjoin(char *s1, char *s2);

/*en check_cmd.c*/
char    *obtain_cmd(char **tmp, int i);
char    *free_for_checkin_cmd(char **sol, char *k, int y);
char	*check_cmd(char *cmd, char *const env[]);

/*en check_pipes.c*/
void    handle_cmd_pipes(general_data *gen_data, char *s, char *const env[]);
void    process_string_with_pipes(general_data *gen_data, char *s, char *const env[]);
char	*handle_cont_pipe(char *join);
int	gest_ampersand(char *s, general_data *gen_data, char *const env[],  int y);
void	free_tmp(char **tmp);

/*en out_reds.c*/
int	find_red(char *s);
void	gest_reds(general_data *gen_data, char *s, int y);
void	process_sing_red(general_data *gen_data, char *s, int y);
void	paste_tmp_red(general_data *gen_data, char **tmp, int y);
void	memory_for_red(general_data *gen_data, char **tmp, int y);

/*en in_reds.c*/
int	find_in_red(char *s);
void	gest_in_reds(general_data *gen_data, char *s, int y);
void	process_in_red(general_data *gen_data, char *s, int y);
void	paste_tmp_in_red(general_data *gen_data, char **tmp, int y);
void	memory_for_in_red(general_data *gen_data, char **tmp, int y);

#endif
