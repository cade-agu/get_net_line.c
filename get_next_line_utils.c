
#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *aux_line, char *buffer, int read_bytes)
{
	char	*str;
	int		i;
	int		j;

	if (!aux_line)
		aux_line = ft_calloc(1, 1);
	str = malloc((ft_strlen(aux_line) + ft_strlen(buffer) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (aux_line[j])
		str[i++] = aux_line[j++];
	j = 0;
	while (j < read_bytes)
		str[i++] = buffer[j++];
	str[i] = '\0';
	free (aux_line);
	return (str);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	len;
	size_t	i;

	len = size * count;
	ptr = malloc(len);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		((unsigned char *)ptr)[i] = '\0';
		i++;
	}
	return (ptr);
}

