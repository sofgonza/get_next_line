/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofgonza <sofgonza@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:30:48 by sofgonza          #+#    #+#             */
/*   Updated: 2023/04/11 13:12:28 by sofgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_read(int fd, char *stash);
char	*ft_new_stash(char *stash);
char	*ft_line(char *stash);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *stash, char *s2);
int		ft_strlen(const char *s);

#endif
