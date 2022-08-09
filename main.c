/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama <sasalama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:15:38 by salustianos       #+#    #+#             */
/*   Updated: 2022/08/09 14:01:21 by sasalama         ###   ########.fr       */
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

static int	ft_comprobar_salida(char *s)
{
	if (ft_strncmp(s, "exit", 5) == 0)
		return (1);
	return (0);
}

void	handle_sigint(int sig) // ? Repasar
{
	if (sig == SIGINT)
	{
		ioctl(STDIN_FILENO, TIOCSTI, "\n"); // STDIN_FILENO: File descriptor terminal TIOCSTI: Este comando simula la entrada del terminal
		rl_replace_line("", 0); // Para no guardarlo en el historial en caso de no terminar el comando
		rl_on_new_line();
	}
}
/*
	Señales en procesos hijos:(Al ser otro proceso creado, que tenga el manejo predeterminado)

	signal(SIGINT, SIG_DFL); SIGINT: terminate process, interrupt program SIG_DFL: default handling for that signal will occur
	signal(SIGQUIT, SIG_DFL); SIGQUIT: create core image, quit program SIG_DFL: default handling for that signal will occur

	Señales en comando que no son builtins:(Para que no estropee la ejecucion de un comando)

	signal(SIGINT, SIG_IGN); SIGINT: terminate process, interrupt program SIG_IGN: ignores the signal
	signal(SIGQUIT, SIG_IGN); SIGQUIT: create core image, quit program SIG_IGN: ignores the signal
*/
int	main(int argc, char *argv[], char *envp[])
{
	char	*texto;
	char	**tmp;

	tmp = get_env(envp);
	while (argc && argv)
	{
		signal(SIGINT, handle_sigint);// SIGINT: terminate process, interrupt program (Manejo del control + C)
		signal(SIGQUIT, SIG_IGN); // SIGQUIT: create core image, quit program SIG_IGN: ignores the signal (Manejo control + \)
		texto = readline("Minishell> ");
		if (texto) // Para que no haga segmentation fault con control + D
		{
			if (texto[0]) // Para no guarda control + C
				add_history(texto);
			if (ft_comprobar_salida(texto) == 1)
			{
				printf("%s\n",texto);
				exit(0);
			}
			ft_comprobar_comando(texto, tmp);
		}
		else
		{
			printf("exit\n");
			exit(0);
		}
	}
	return (0);
}
