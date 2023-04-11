/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofgonza <sofgonza@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:29:32 by sofgonza          #+#    #+#             */
/*   Updated: 2023/04/11 15:36:24 by sofgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] != '\0' && stash[i] != '\n')
			++i;
	line = malloc (sizeof(char) * i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
	{
		line[i] = stash[i];
		++i;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}
//recorrer stash hasta un salto de linea o el final del str y almacenar el contador (i). Crear un malloc con ese largo +2 (salto de linea + nulo) (+ proteccion)
//ir almacenando en el nuevo str la linea. Agregar salto de line si es que se encuentra con uno.
//cerrar con el nulo
//retornar el str

char	*ft_new_stash(char *stash)
{
	int		i;
	int		j;
	char	*n_stash;

	i = 0;
//	printf("%p\n", stash);
//	printf("%c\n", stash[i]);
	while (stash[i] != '\0' && stash[i] != '\n')
	{
//		printf("%c", stash[i]);
		i++;
	}
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	n_stash = malloc (sizeof(char) * (ft_strlen(stash) - i + 1));
//	printf("%p\n", n_stash);	
	if (!n_stash)
		return (NULL);
	j = 0;
	++i;
	while (stash[i])
		n_stash[j++] = stash[i++];
	n_stash[j] = '\0';
	free (stash);
	return (n_stash);
}
//recorrer hasta salto de linea o fin del stash y almacenar contador
//si llego al final del stash (!stash[i]) liberar el stash y retornar nullo.
//almacenar espacio en el str del largo del stash - i (- la linea) + 1 (agregar nulo)
//ir almacenando desde el contador ++i del shash (incrementar antes porque quedo en el \n) con un nuevo contador en el nuevo str
//liberar stash
//retornar str

char	*ft_read(int fd, char *stash)
{
	char	*buff;
	int		bytes;

	buff = malloc ((BUFFER_SIZE + 1) * sizeof(char *));
	if (!buff)
		return (NULL);
	bytes = 1;
	while (ft_strchr(stash, '\n') == NULL && bytes != 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free (buff);
			return (NULL);
		}
		buff[bytes] = '\0';
		stash = ft_strjoin(stash, buff);
	}
	free (buff);
	return (stash);
}
//mientras no encuentra \n en el stash y bytes != 0: guardar en bytes los bytes leidos (retorno del read). Si no se ejecuta la funcion read correctamente (bytes == -1) hay que liberar el buffer y retornar null.
//Agregar el caracter nullo al final de buff (buff[bytes] = '\0') y almacenar en el stash la union del buff con el stash ya existente (strjoin)
//liberar buff!! y retornar el nuevo stash.

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_read(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_line(stash);
	stash = ft_new_stash(stash);
	return (line);
}

int main(void)
{
    char    fd;
    int     x;
    char    *aux;
    x = 0;
    fd = open("prueba.txt", O_RDWR);
    while (x < 20)
    {
        printf("%s", aux = get_next_line (fd));
        free(aux);
        x++;
    }
    close(fd);
}
