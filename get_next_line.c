/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofgonza <sofgonza@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:29:32 by sofgonza          #+#    #+#             */
/*   Updated: 2023/04/10 19:47:04 by sofgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_line(char *stash)
{
//recorrer stash hasta un salto de linea o el final del str y almacenar el contador (i). Crear un malloc con ese largo +2 (salto de linea + nulo) (+ proteccion)
//ir almacenando en el nuevo str la linea. Agregar salto de line si es que se encuentra con uno.
//cerrar con el nulo
//retornar el str
}

char	*ft_new_stash(char *stash)
{
//recorrer hasta salto de linea o fin del stash y almacenar contador
//si llego al final del stash (!stash[i]) liberar el stash y retornar nullo.
//almacenar espacio en el str del largo del stash - i (- la linea) + 1 (agregar nulo)
//ir almacenando desde el contador ++i del shash (incrementar antes porque quedo en el \n) con un nuevo contador en el nuevo str
//liberar stash
//retornar str
}

char	*ft_read(int fd, char *stash)
{
	char	*buff;
	int		bytes;

	buff = malloc ((BUFFZISE + 1) * sizeof(char *)
	if (!buff)
		return (NULL);
	bytes = 1;
//mientras no encuentra \n en el stash y bytes != 0: guardar en bytes los bytes leidos (retorno del read). Si no se ejecuta la funcion read correctamente (bytes == -1) hay que liberar el buffer y retornar null.
//Agregar el caracter nullo al final de buff (buff[bytes] = '\0') y almacenar en el stash la union del buff con el stash ya existente (strjoin)
//liberar buff!! y retornar el nuevo stash.
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFERSIZE <= 0)
		return (NULL);
	stash = ft_read(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_line(stash);
	stash = ft_new_stash(stash);
	return (line);
}
