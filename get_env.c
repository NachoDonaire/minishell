/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama <sasalama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:16:04 by salustianos       #+#    #+#             */
/*   Updated: 2022/08/02 15:58:04 by sasalama         ###   ########.fr       */
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
ioctl: Dispositivo de control
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

// *! Necesito estructura para saber si tiene argumentos y cuales son

char	**get_env(char **envp) // *! MODIFICAR
{
	
}

void	ft_env(char **env)
{
	int		x;
	char	*tmp;

	x = 0;
	while (env[x])
	{
		tmp = ft_strchr(env[x], '=');
		tmp = ft_substr(tmp, 1, ft_strlen(tmp));
		if (tmp[ft_strlen(tmp) + 1] != '\0')
			printf("%s\n", env[x]);
		x++;
	}
}

// TODO Implementar libreria libft en Mafefile para no añadir los archivos a mano
