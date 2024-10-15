#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 10

int _getline(char **s);
void _copy(char **to, char*from);
int _strlen(char*str);
void dividirLinea(char **str, int len);

void main(void) {
    char* line = NULL;
    int len;
    char *buffer = NULL;
    while ((len = _getline(&line)) > 0) {
        dividirLinea(&line, len);
        _copy(&buffer, line);
    }
    if (buffer != NULL) {
        printf("\n\nSOLUCION\n%s", buffer);
        free(buffer);
        buffer = NULL;
    }
    free(line);
    line = NULL;
}

void dividirLinea(char**str, int len) {
    int i, size, division, j;
    char *buffer;
    size = MAXLINE;
    j = size;
    while ((*str)[j] != '\0' && j < len) {
        if ((*str)[j] == ' ') {
            (*str)[j] = '\n';
            j += size;
        }
        j++;
    }
}

int _getline(char **s) {
    char c;
    int i, numero;
    numero = 100;
    *s = (char *)malloc(numero);
    if (*s ==  NULL) {
        return -1;
    }
    for (i = 0; (c = getchar()) != EOF && c != '\n'; i++) {
        if (i > numero - 1) {
            numero += 100;
            char *temp = realloc(*s, numero);
            if (temp == NULL) {
                printf("problema realocando!\n");
                return -1;
            }
            *s = temp;
        }
        (*s)[i] = c;
    }
    if (c == '\n') {
        (*s)[i] = '\n';
        i++;
    }
    (*s)[i] = '\0';
    return i;
}

void _copy(char**to, char*from){
    int length, length2, i, numero;
    i = 0; 
    if (*to == NULL) {
        *to = (char*)malloc(_strlen(from));
        while (((*to)[i] = from[i]) != '\0') {
            i++;
        }
    } else {
        length = _strlen(*to);
        length2 = _strlen(from);
        numero = length2 + length -1;
        char *temp = realloc(*to, numero);
        if (temp == NULL) {
            printf("Error realocando\n");
            return;
        }
        *to = temp;
        while (((*to)[(length-1) + i] = from[i]) != '\0') {
            i++;
        }
    }
}

int _strlen(char*str) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    i++;
    return i;
}