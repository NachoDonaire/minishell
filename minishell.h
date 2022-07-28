# ifndef MINILIB_H
#define MINILIB_H
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*find_path(char *const env[]);
char	*pseudo_join(char *path, char *com);
char	*split_path(char *env, char *arg);
int	checkin_path(char *s, char *find);
int		lens(char *s);
char	**ft_split(char const *s, char c);
char	*freeear(char **sol, char *k);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int	check_cmllas(char *s);
//char	**gesteo_cmllas(char **spliteao);
char	*gest_cmllas(char *s);

#endif
