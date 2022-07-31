#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
char	*ft_strjoin(char *s1, char *s2);
int	lens(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	main()
{
	char *s;
	char *s2;

	s2 = malloc(sizeof(char) * 3);
	s2 = "aa";
	printf("%s\n", ft_strjoin(s, s2));
	return (0);
}
