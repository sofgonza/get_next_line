/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofgonza <sofgonza@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:29:32 by sofgonza          #+#    #+#             */
/*   Updated: 2023/04/12 02:30:39 by sofgonza         ###   ########.fr       */
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
	{
		i++;
	}
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
/*
void	ft_leaks()
{
	system("leaks a.out");
}

int main(void)
{
    char    fd;
    char    *line;

    fd = open("prueba.txt", O_RDWR);
	if (fd == -1)
		return (0);
	line = "";
//	line = get_next_line(fd);
//	printf("%s", line);
    while (line)
    {
		line = get_next_line(fd);
		printf("%s", line);
        free(line);
    }
    close(fd);
	return (0);
}
*/
int main()
{
    char    *line;
    int     fd;
    fd = open("el_quijote.txt", O_RDONLY);
    while (0 == 0)
    {
        line = get_next_line(fd);
        if (!line)
            break ;
        printf("%s", line);
    }
    return (0);
}
