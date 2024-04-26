
#include "get_next_line.h"

int	main(void)
{
	int		fd; // descriptor de archivo
	char	*line; // Variable para almacenar la linea leida
	//Abre un arcivo para lectura
	fd = open("primeraprueba", O_RDONLY);
	if (fd < 0)
	{
		printf("Error al abrir el archivo");
		return (1);
	}
	//lee lineas del archivo hasta que se alcanza el final
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line); //Imprime la linea leida 
		free(line); //libera la memoria asignada por get_next_line 
		line = get_next_line(fd); // lee la siguiente línea
	}
	//cierra el archivo
	close(fd);
	return (0);
}
