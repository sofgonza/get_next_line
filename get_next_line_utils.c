/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofgonza <sofgonza@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:29:43 by sofgonza          #+#    #+#             */
/*   Updated: 2023/04/10 19:47:06 by sofgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_strlen(const char *s)
{
	int	n;

	n = 0;
	while (s[n] != '\0')
		n++;
	return (n);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		lens1;
	int		lens2;
	char	*str;

	if (!s1)
	{
		malloc (sizeof (char*)
	}
	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	str = (char *) malloc (sizeof(char) * (lens1 + lens2 + 1));
	if (str != NULL)
	{
		ft_strlcpy(str, (char *)s1, (lens1 + 1));
		ft_strlcat(str, (char *)s2, (lens1 + lens2 + 1));
		free (s1);
		return (str);
	}
	return (NULL);
}
//simplificar strjoin//
//agregar caso q el s1 este vacio y crear el malloc//
//crear malloc con el len de ambos str//
//simil strcat, ir almacenando en el contenido de s1 hasta terminar y luego comenzar a recorrer s2 y almacenar//
//agregar nulo al final//
//liberar malloc de stash (s1)//
//retornar str//
//hasta aca hay q corregir//

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		++i;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
