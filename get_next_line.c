
#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*full_str =  NULL; //declaración e inicializacion de full_str//
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	full_str = read_function(fd, full_str);
	if (!full_str)
		return (NULL);
	line = ft_getline(full_str);
	full_str = ft_getrest(full_str);
	return (line);
}
// read the first line of a file descriptor//

char	*read_function(int fd, char *str)
{
	char	*tmp;
	int		bytes;

	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(str, '\n') && (bytes != 0))
	{
		bytes = read(fd, tmp, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[bytes] = '\0';
		str = ft_strjoin(str, tmp);
	}
	free(tmp);
	return (str);
}
// función para obtener la primera linea de una cadena//

char	*ft_getline(char *full_str)

{
	int		i;
	char	*line;

	i = 0;
	if (!full_str[i])
		return (NULL);
	while (full_str[i] && full_str[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (full_str[i] && full_str[i] != '\n')
	{
		line[i] = full_str[i];
		i++;
	}
	if (full_str[i] == '\n')
	{
		line[i] = full_str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}
// función para obtener el resto de la cadena despues de la primera línea//

char	*ft_getrest(char *full_str)
{
	size_t	i;
	size_t	j;
	char	*rest;

	i = 0;
	while (full_str[i] && full_str[i] != '\n')
		i++;
	if (!full_str[i])
	{
		free(full_str);
		return (NULL);
	}
	rest = (char *)malloc(sizeof(char) * (ft_strlen(full_str) - i + 1)); // ajusto el tamaño de la asignacion de memoria//
	if (!rest)
		return (NULL);
	i++; //Incrementado i para omitir el '\n"
	j = 0;
	while (full_str[i])
	{
		rest[j] = full_str[i];
		i++;
		j++;
	}
	rest[j] = '\0';
	free(full_str);
	return (rest);
}
