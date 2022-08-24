/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:58:45 by sasalama          #+#    #+#             */
/*   Updated: 2022/08/24 12:14:27 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
readline: Lee una linea de la terminal y la devuelve, devuelve un malloc que hay que liberar
rl_clear_history: Elimina el historial
rl_on_new_line: Dice a las funciones actualizadas que nos hemos movido a una linea nueva vacia
rl_replace_line: Reemplaza el contenido de una string con texto
rl_redisplay: Cambia lo que se muestra en pantalla para reflejar el contenido actual
add_history: Guarda la linea en una lista de historial
printf: Escribe
malloc: Guarda memoria
free: Libera memoria
write: Escribe
access: Comprueba el acceso de un archivo o directorio
open: Abre un archivo
read: Lee un archivo
close: Cierra un archivo
fork: Crea un proceso
wait: Espera un cambio de estado de los procesos hijos
waitpid: Espera un cambio de estado de un proceso hijo en especifico
wait3: Espera la terminación de un proceso
wait4: Espera la terminación de un proceso
signal: Establece una función para manejar la señal
sigaction: Examina y cambia una acción de señal
kill: Envia señal a un proceso
exit: Finaliza un proceso
getcwd: Obtiene el directorio de trabajo actual
chdir: Cambia el directorio de trabajo actual
stat: Copia el estado de un archivo
lstat: Copia el estado de un archivo, en caso de ser un enlace examina el enlace
fstat: Copia el estado de un archivo, solo si está abierto
unlink: Elimina un nombre del sistema de archivos, y si no está siendo usado elimina el archivo
execve: Ejecuta un programa
dup: Duplica un descriptor de archivos
dup2: Duplica un descriptor de archivos a uno especificado
pipe: Establece una conexión entre dos procesos
opendir: Abre un directorio
readdir: Lee las entradas del directorio abierto
closedir: Cierra un directorio
strerror: Devuelve un error con un mensaje
perror: Devuelve un error con un mensaje personalizado
isatty: Prueba si un descriptor de archivo se refiere a una terminal
ttyname: Devuelve el nombre de una terminal
ttyslot: encuentre la ranura del terminal del usuario actual en algunos archivos
ioctl: Dispositivo de control escritura/lectura
getenv: Busca una variabe de entorno
tcsetattr: Establece los parámetros asociados con el terminal al que hace referencia el descriptor
tcgetattr: Establece los parámetros asociados con el terminal al que hace referencia el descriptor y los almacena
tgetent: Carga la entrada para el nombre
tgetflag: Obtiene la entrada booleana para id
tgetnum: Obtiene la entrada numérica para id
tgetstr: Devuelve la entrada de cadena para id
tgoto: Instancia los parámetros en la capacidad dada
tputs: Puede recuperar capacidades por nombre
*/

#include "minishell.h"

static int	ft_check_exit(char *s)
{
	if (ft_strncmp(s, "exit", 5) == 0)
		return (1);
	return (0);
}

static void	handle_sigint(int sig)
{
	if (sig == SIGINT)
	{
		ioctl(STDIN_FILENO, TIOCSTI, "\n"); // STDIN_FILENO: File descriptor terminal TIOCSTI: Simulation of stdin of the terminal
		rl_replace_line("", 0); // Unsave in the history in the case we don´t finish the command
		rl_on_new_line();
	}
}

/*
	Signals in child process:(Predeterminated management in the childs processes)

	signal(SIGINT, SIG_DFL); SIGINT: terminate process, interrupt program SIG_DFL: default handling for that signal will occur
	signal(SIGQUIT, SIG_DFL); SIGQUIT: create core image, quit program SIG_DFL: default handling for that signal will occur

	Signal in no builtins commands:(To not damage the command ejecution)

	signal(SIGINT, SIG_IGN); SIGINT: terminate process, interrupt program SIG_IGN: ignores the signal
	signal(SIGQUIT, SIG_IGN); SIGQUIT: create core image, quit program SIG_IGN: ignores the signal
*/

static void	ft_exit(char *texto, char **tmp)
{
	int	x;

	x = 0;
	if (texto)
		printf("%s\n",texto);
	else
		printf("exit\n");
	while (tmp[x])
		free(tmp[x++]);
	free(tmp);
	exit(0);
}

/*
void	ft_leaks()
{
	system("leaks -q minishell");
}
*/

int	main(int argc, char *argv[], char *envp[])
{
	char	*text;
	char	**tmp;
	char	*copy;

	//atexit(ft_leaks);
	tmp = get_env(envp);
	while (argc && argv)
	{
		signal(SIGINT, handle_sigint);// ? SIGINT: terminate process, interrupt program (Management control + C)
		signal(SIGQUIT, SIG_IGN); // ? SIGQUIT: create core image, quit program SIG_IGN: ignores the signal (Management control + \)
		text = readline("Minishell> ");
		if (text) // * To avoid segmentation fault with control + D
		{
			copy = text;
			text = ft_substr(text, 0, ft_strlen(text));
			free(copy);
			if (text[0]) // * Unsave control + C
				add_history(text);
			if (ft_check_exit(text) == 1)
				ft_exit(text, tmp);
			ft_check_comand(text, tmp);
			free(text);
		}
		else // * To exit with control + D
			ft_exit(text, tmp);
	}
	return (0);
}

// TODOS Start working with command status (We have to change command status for each command)