

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *aux_line, char *buffer, int read_bytes);
void	*ft_calloc(size_t count, size_t size);
char	*ft_read_line(int fd, char *aux_line);
char	*get_next_line(int fd);
char	*ft_get_line(char *aux_line);
char	*ft_clean_line(char *aux_line);

#endif
