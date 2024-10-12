#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 100
#define TABSIZE 4

int _getline(char**s);
void _copy(char**to, char*from);
int _strLen(char*string);

int main(void) {
    int len;
    char *line = NULL;
    char *buffer = NULL;
    while ((len = _getline(&line)) > 0) {
        if (line != NULL) {
            _copy(&buffer, line);
        }
        free(line);
        line = NULL;
    }
    if (buffer != NULL) {
        printf("\n\nSOLUCION:\n\n%s", buffer);
    }
    free(line);
    free(buffer);
    return 0;
}

int _getline(char**s) {
    int i, c, numero;
    numero = MAXLINE;
    *s = (char*)malloc(numero * sizeof(char));
    if (*s == NULL) {
        printf("(_getLine) malloc failed\n");
        return -1;
    }
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        if (i >= numero -1) {
            numero += 100;
            char*temp = realloc(*s, numero);
            if (temp == NULL) {
                printf("(_getLine) realloc failed\n");
                free(*s);
                return -1;
            }
            *s = temp;
        }
        if ( c == '\t') {
            int n, espacios;
            espacios = TABSIZE - (i % TABSIZE);
            for (n = 0; n < espacios; ++n) {
                int ind = i+n;
                (*s)[ind] = ' ';
            }
            i += espacios-1;
        } else {
            (*s)[i] = c;
        }
    }
    if (c == '\n') {
        (*s)[i] = '\n';
        i++;
    }
    (*s)[i] = '\0';
    int algo = _strLen(*s);
    return i;
}

void _copy(char **to, char *from) {
    int i, length, length2, numero;
    numero = MAXLINE;
    i = 0;
    if (*to == NULL) {
        *to = (char *)malloc(sizeof(char) * _strLen(from)+1);
        if (*to == NULL) {
            printf("(_copy) malloc failed\n");
            return;
        }
        while(((*to)[i] = from[i]) != '\0') {
            ++i;
        }
    } else {
        length = _strLen(*to);
        length2 = _strLen(from);
        numero = length + length2;
        char *temp = realloc(*to, numero+100);
        if (temp == NULL) {
            printf("(_copy) realloc failed\n");
            return;
        }
        *to = temp;
        while(((*to)[length + i] = from[i]) != '\0') {
            ++i;
        }
    }
}

int _strLen(char*string) {
    int i = 0;
    while (string[i] != '\0') {
        i++;
    }
    return i;
}