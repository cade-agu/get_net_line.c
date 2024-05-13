

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *aux_line, char *buffer, int read_bytes);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_read_function(int fd, char *aux_line);
char	*ft_get_line(char *aux_line);
char	*ft_getrest(char *aux_line);
void	*ft_calloc(size_t count, size_t size);
void    free(void *ptr);

#endif
