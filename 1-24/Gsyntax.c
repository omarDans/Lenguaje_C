/* Este ejercicio me podría llevar MUUUUUUUCHO tiempo si lo hago bien.
No es mi plan quedarme haciendo un ejercicio 3 meses, se queda así
Lo siento si el codigo es ilegible pero he dejado comentarios en las partes mas confusas*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE_READ 100

char *read_content(char*filename, size_t*len);
int process_content(char*buf, size_t bufLen);

int main(void) {
    int status;
    char filename[100];
    size_t content_len;
    scanf("%s", filename);
    char *content = read_content(filename, &content_len);
    printf("Contenido leido: %d\n", content_len);
    printf("%s", content);
    process_content(content, content_len, 0);
    return 0;
}

int process_content(char* buf, size_t bufLen) {
    int toggle_quote = 0, stack_index = -1, line = 1, save_line = 0;
    char stack[10] = {0}; // BufferOverflow, me da igual
    for (int i = 0; i < bufLen; ++i) {
        // Contar las lineas
        if (buf[i] == '\n') {
            ++line;
        }
        // Checkeo de comillas
        if (buf[i] == '"') {
            toggle_quote = !toggle_quote;
            int checkpoint = i+1;
            while (buf[checkpoint] != '\n') {
                if (buf[checkpoint] == '"') {
                    toggle_quote = !toggle_quote;
                    i = checkpoint+1;
                    break;
                }
                ++checkpoint;
            }
            if (toggle_quote) {
                printf("Error comillas desparejas en la linea %d\n", line);
                toggle_quote = 0;
                continue;
            }
        }
        // Ignorar comentarios
        if (buf[i] == '/' && buf[i + 1] == '/') {
            while (buf[i] != '\n' && i < bufLen) {
                ++i;
            }
            ++line;
            continue;
        } else if (buf[i] == '/' && buf[i + 1] == '*') {
            i += 2;
            while (!(buf[i] == '*' && buf[i + 1] == '/') && i < bufLen) {
                if (buf[i] == '\n') {
                    ++line;
                }
                ++i;
            }
            i += 1;
            continue;
        }

        // Verificar correcta alineación de paréntesis, llaves y corchetes
        switch (buf[i]) {
            case ')':
                if (stack_index >= 0 && stack[stack_index] == ')') {               
                } else {
                    printf("Error: ) inesperado en línea %d, se esperaba %c\n", line, stack_index >= 0 ? stack[stack_index] : 0);
                }
                --stack_index;
                break;
            case '}':
                if (stack_index >= 0 && stack[stack_index] == '}') {
                } else {
                    printf("Error: } inesperado en línea %d, se esperaba %c\n", line, stack_index >= 0 ? stack[stack_index] : 0);
                }
                --stack_index;
                break;
            case ']':
                if (stack_index >= 0 && stack[stack_index] == ']') {
                } else {
                    printf("Error: ] inesperado en línea %d, se esperaba %c\n", line, stack_index >= 0 ? stack[stack_index] : 0);
                }
                --stack_index;
                break;
            case '(':
                ++stack_index;
                stack[stack_index] = ')';
                break;
            case '{':
                ++stack_index;
                stack[stack_index] = '}';
                break;
            case '[':
                ++stack_index;
                stack[stack_index] = ']';
                break;
        }
    }
    return 0;
}

char * read_content(char* filename, size_t*len) {
    char *buf = malloc(SIZE_READ);
    if (!buf) {
        perror("Error alocando memoria a buf\n");
        return NULL;
    }
    FILE *fd;
    fd = fopen(filename, "r");
    if (fd == NULL) {
        perror("Error abriendo el archivo para lectura\n");
        return NULL;
    }
    size_t count_bytes = 0;
    size_t num;
    while (1) {
        char temp[SIZE_READ];
        num = fread(temp, sizeof(char), SIZE_READ, fd);
        if (num == 0) {
            if (feof(fd)) break;
            perror("Error leyendo el archivo\n");
            fclose(fd);
            return NULL;
        }
        if (count_bytes) {
            char *temp_buf = (char*)realloc(buf, count_bytes + num);
            if (temp_buf == NULL) {
                perror("Error ralocando buf\n");
                free(buf);
                fclose(fd);
                return NULL;
            }
            buf = temp_buf;
        }
        memcpy(buf + count_bytes, temp, num);
        count_bytes += num;
    }
    *len = count_bytes;
    return buf;
}