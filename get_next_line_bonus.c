/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofgonza <sofgonza@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:00:08 by sofgonza          #+#    #+#             */
/*   Updated: 2023/04/14 17:04:36 by sofgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	if (!stash || stash[0] == '\0')
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

char	*ft_new_stash(char *stash)
{
	int		i;
	int		j;
	char	*n_stash;

	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	n_stash = malloc (sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!n_stash)
		return (NULL);
	j = 0;
	++i;
	while (stash[i])
		n_stash[j++] = stash[i++];
	n_stash[j] = '\0';
	free(stash);
	return (n_stash);
}

char	*ft_read(int fd, char *stash)
{
	char	*buff;
	int		bytes;

	buff = malloc ((BUFFER_SIZE + 1) * sizeof(char *));
	if (!buff)
		return (NULL);
	bytes = 1;
	while (!(ft_strchr(stash, '\n')) && bytes != 0)
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

char	*get_next_line(int fd)
{
	static char	*stash[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	stash[fd] = ft_read(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = ft_line(stash[fd]);
	stash[fd] = ft_new_stash(stash[fd]);
	return (line);
}
/*
#include <stdio.h>
int main()
{
    char    *line1;
	char	*line2;
    int     fd1;
	int		fd2;

    fd1 = open("read_error.txt", O_RDONLY);
    fd2 = open("prueba.txt", O_RDONLY);
	if (fd1 == -1 || fd2 == -1)
	{
		close(fd1);
		close(fd2);
		return (0);
	}
	line1 = "";
	line2 = "";
    while (line1 != NULL || line2 != NULL)
    {
        line1 = get_next_line(fd1);
		line2 = get_next_line(fd2);
		if (!line1 || !line2)
		{
			free (line1);
			free (line2);
			break;
		}
        printf("%s", line1);
        printf("%s", line2);
		free(line1);
		free(line2);
    }
	free(line1);
	free(line2);
	close(fd1);
	close(fd2);
	//system("leaks a.out");
    return (0);
}*/
