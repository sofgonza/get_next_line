/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofgonza <sofgonza@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:00:35 by sofgonza          #+#    #+#             */
/*   Updated: 2023/04/13 15:00:37 by sofgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	n;

	n = 0;
	while (s[n] != '\0')
		n++;
	return (n);
}

char	*ft_strjoin(char *stash, char *buff)
{
	int		i;
	int		j;
	char	*str;

	if (!stash)
	{
		stash = malloc (sizeof(char) * 1);
		stash[0] = '\0';
	}
	if (!stash || !buff)
		return (NULL);
	str = malloc (sizeof(char) * (ft_strlen(stash) + ft_strlen(buff) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (stash[++i])
		str[i] = stash[i];
	while (buff[j])
		str[i++] = buff[j++];
	str[i] = '\0';
	free (stash);
	return (str);
}

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (1);
		++i;
	}
	return (0);
}