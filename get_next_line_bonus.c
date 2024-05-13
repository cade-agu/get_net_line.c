
#include "get_next_line_bonus.h"

char	*ft_read_line(int fd, char *aux_line)
{
	char	*buffer;
	int		read_bytes;
	char	*save_aux;

	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (aux_line && !ft_strchr(aux_line, '\n') && read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(aux_line);
			free(buffer);
			return (NULL);
		}
		if (read_bytes == 0 && !aux_line[0])
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		save_aux = aux_line;
		aux_line = ft_strjoin(save_aux, buffer, read_bytes + 1);
		free(save_aux);
	}
	free(buffer);
	return (aux_line);
}

char	*ft_get_line(char *aux_line)
{
	int		i;
	int		j;
	char	*get_line;

	i = 0;
	while (aux_line[i] != '\0' && aux_line[i] != '\n')
		i++;
	get_line = ft_calloc (i + 2, sizeof(char));
	if (!get_line)
		return (NULL);
	j = 0;
	while (aux_line[j] != '\0' && aux_line[j] != '\n')
	{
		get_line[j] = aux_line[j];
		j++;
	}
	if (aux_line[j] == '\n')
		get_line[j++] = '\n';
	get_line[j] = '\0';
	return (get_line);
}

char	*ft_clean_line(char *aux_line)
{
	int		i;
	int		j;
	char	*new_aux_line;

	if (!aux_line)
		return (NULL);
	i = 0;
	while (aux_line[i] != '\0' && aux_line[i] != '\n')
		i++;
	if ((size_t)i >= ft_strlen(aux_line))
	{
		free(aux_line);
		return (NULL);
	}
	new_aux_line = ft_calloc(ft_strlen(aux_line) - i + 1,sizeof(char));
	if (!new_aux_line)
	{
		free(aux_line);
		return (NULL);
	}
	i++;
	j = 0;
	while (aux_line[i] != '\0')
		new_aux_line[j++] = aux_line[i++];
	new_aux_line[j] = '\0';
	free(aux_line);
	aux_line = NULL;
	return (new_aux_line);
}

char	*get_next_line(int fd)
{
	static char		*aux_line[999];
	char			*final_line;

	if (fd < 0 || BUFFER_SIZE <=1 || read(fd, 0, 0) < 0)
	{
		free(aux_line[fd]);
		aux_line[fd] = NULL;
		return (NULL);
	}
	aux_line[fd] = ft_read_line(fd, aux_line[fd]);
	if (!aux_line[fd])
		return (NULL);
	final_line = ft_get_line(aux_line[fd]);
	aux_line[fd] = ft_clean_line(aux_line[fd]);
	return (final_line);
}
