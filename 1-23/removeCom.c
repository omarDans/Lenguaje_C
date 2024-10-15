#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_READ 100

char* _deleteCom(char*s, size_t len);
void _writeContent(char*buf, size_t number_chars, char*filename);

int main(void) {
    char *buf = malloc(SIZE_READ);
    char filename[100];
    printf("What file do you want to edit?: ");
    scanf("%s", filename);
    if (!buf) {
        perror("Error alocando memoria a buf\n");
        return -1;
    }
    FILE *fd;
    fd = fopen(filename, "r");
    if (fd == NULL) {
        perror("Error abriendo el archivo para lectura\n");
        return -1;
    }
    size_t count_bytes = 0;
    size_t num;
    while (1) {
        char temp[SIZE_READ];
        num = fread(temp, sizeof(char), SIZE_READ, fd);
        if (num == 0) {
            if (feof(fd)) break;
            printf("Error al leer el archivo\n");
            free(buf);
            fclose(fd);
            return -1;
        }
        if (count_bytes) {
            printf("Se realoca\n");
            char *temp_buf = (char*)realloc(buf, count_bytes + num);
            if (temp_buf == NULL) {
                perror("Error realocando buf\n");
                free(buf);
                fclose(fd);
                return -1;
            }
            buf = temp_buf;
        }
        memcpy(buf + count_bytes, temp, num);
        count_bytes += num;
    }

    printf("Se leyeron %d caracteres\n", count_bytes);
    // printf("El contenido es:\n%s", buf);
    char *new_content = _deleteCom(buf, count_bytes);
    printf("%s", new_content);
    int char_to_write = strlen(new_content);
    _writeContent(new_content, char_to_write, filename);
    fclose(fd);
    free(buf);
    return 0;
}

void _writeContent(char*buf, size_t number_chars, char*filename) {
    size_t bytes_written;
    FILE *fd = fopen(filename, "w");
    if (fd == NULL) {
        perror("Error abriendo el archivo para escritura\n");
        return;
    }
    bytes_written = fwrite(buf, sizeof(char), number_chars, fd);
    if (bytes_written < number_chars) {
        perror("Error escribiendo en el archivo\n");
        return;
    }
    fclose(fd);
}

char* _deleteCom(char*s, size_t len) {
    int index, togle_quote;
    char *temp = (char*)malloc(sizeof(char) * len);
    index = 0;
    togle_quote = 0;
    for (int i = 0; i < len; ++i) {
        if (s[i] == '"') {
            togle_quote = !togle_quote;
        }
        if (s[i] == '/' && s[i+1] == '/' && !togle_quote) {
            while (s[i] != '\n') {
                ++i;
            }
        } else if (s[i] == '/' && s[i+1] == '*' && !togle_quote) {
            while (s[i] != '*' || s[i+1] != '/') {
                ++i;
            }
            i += 2;
        }
        temp[index] = s[i];
        ++index;
    }
    return temp;
}

