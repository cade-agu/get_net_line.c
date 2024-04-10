
include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 32

char *get_next_line(int fd) {
    static char buffer[BUFFER_SIZE + 1];
    static char *pos = buffer;
    static int bytes_read = 0;
    static int total_bytes = 0;
    char *line = NULL;
    int bytes_needed = 1; // In case we only need to return '\0'

    while (1) {
        // If buffer is empty, read from file descriptor
        if (pos - buffer >= bytes_read) {
            bytes_read = read(fd, buffer, BUFFER_SIZE);
            if (bytes_read <= 0) // End of file or error
                return NULL;
            pos = buffer;
        }

        // Look for newline character in buffer
        char *newline_pos = NULL;
        while (pos < buffer + bytes_read) {
            if (*pos == '\n') {
                newline_pos = pos;
                break;
            }
            pos++;
        }

        // Allocate memory for line
        if (newline_pos) {
            bytes_needed = newline_pos - buffer + 1;
            line = (char *)malloc(bytes_needed);
            if (!line) // Memory allocation failed
                return NULL;
            total_bytes = 0;
            break;
        } else { // If no newline character found in current buffer
            int remaining_bytes = bytes_read - (pos - buffer);
            total_bytes += remaining_bytes;
            bytes_needed += remaining_bytes;
            char *temp = (char *)realloc(line, bytes_needed);
            if (!temp) {
                free(line);
                return NULL;
            }
            line = temp;
            pos = buffer + bytes_read; // Mark buffer as empty
        }
    }

    // Copy data from buffer to line
    for (int i = 0; i < total_bytes; i++) {
        line[i] = buffer[i];
    }
    line[total_bytes] = '\0';
    pos += bytes_needed;
    return line;
}

#undef BUFFER_SIZE // Clean up macro definition
