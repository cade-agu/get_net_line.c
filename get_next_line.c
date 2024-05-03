
include "get_next_line.h"

char	*ft_read_function(int fd, char *aux_line)
{
	char	*tmp;
	int		read_bytes;
	char	*save_aux;

	tmp = ft_calloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(str, '\n') && read_bytes > 0)
	{
		read_bytes = read(fd, tmp, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free (aux_line);
			aux_line = NULL;
			return (NULL);
		}
		save_aux = aux_line;
		aux_line = ft_strjoin(save_aux, tmp, read_bytes);
	}
	free(tmp);
	if (ft_strlen(aux_line) == 0)
		return (free(aux_line), NULL);
	return (aux_line);
}

char	*ft_getline(char *aux_line)
{
	int		i;
	int		j;
	char	*get_line;

	i = 0;
	while (aux_line[i] != '\0' && aux_line[i] != '\n')
		i++;
	get_line = ft_calloc ((i + 1 + (aux_line[i]) == '\n'), sizeof (char));
	if (!get_line)
		return (NULL);
	j = 0;
	while (aux_line[j] != '\0' && aux_line[j] != '\n')
	{
		get_line[j] = '\0';
		return (get_line);
	}
}

char	*ft_getrest(char *full_str)
{
	size_t	i;
	size_t	j;
	char	*restof;

	i = 0;
	while (full_str[i] != '\0' && full_str[i] != '\n')
		i++;
	if (ft_strlen(full_str) - i <= 0)
	{
		free(full_str);
		full_str = NULL;
		return (NULL);
	}
	restof = ft_calloc(ft_strlen(full_str) - i + 1, sizeof(char));
	if (!restof)
		return (NULL);
	i++;
	while (full_str[i] != '\0')
		restof[j++] = full_str[i++];
	free(full_str);
	full_str = NULL;
	return (restof);
}

char	*get_next_line(int fd)
{
	static char	*full_str;
	char		*final_line;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		free(full_str);
		full_str = NULL;
		return (NULL);
	}
	full_str = ft_read_function(fd, full_str);
	if (!full_str)
		return (NULL);
	final_line = ft_getline(full_str);
	full_str = ft_getrest(full_str);
	return (final_line);
}
