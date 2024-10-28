#include <stdio.h>
#include <stdlib.h>

#define SIZE_BUF 100

void squeeze(char **s1, char *s2);
int _getLine(char **s);
int _strLen(char*s);

int main(void) {
    int len, len2;
    char *line;
    char *line2;
    printf("Escribe la primera frase: ");
    len = _getLine(&line);
    if (len <= 0) {
        printf("Error leyendo la primera linea\n");
        return -1;
    }
    printf("Escribe la segunda frase: ");
    len2 = _getLine(&line2);
    if (len2 <= 0) {
        printf("Error leyendo la segunda linea\n");
        return -1;
    }
    squeeze(&line, line2);

    printf("NUEVA FRASE: %s", line);
    return 0;
}

void squeeze(char **s1, char *s2) {
    int i, j, x, len, c, c2;
    i = x = 0;
    len = _strLen(s2);
    printf("LEN %d", len);
    while ((c = (*s1)[i]) != '\0') {
        printf("caracter uno: %c\n", c);
        for (j = 0; j < len; ++j) {
            c2 = s2[j];
            printf("caracter dos: %c\n", c2);
            if (c2 == c) {
                i++;
                break;
            }
        }
        (*s1)[x++] = (*s1)[i];
        i++;
    }
    printf("LA I: %d", i);
    (*s1)[x] = '\0';
}

int _getLine(char **s) {
    int i, c;
    int size = SIZE_BUF;
    *s = (char*)malloc(sizeof(char) * size);
    if (*s == NULL) {
        return -1;
    }
    for (i = 0; (c = getchar()) != '\n' && c != EOF; ++i) {
        if (i >= size -1) {
            size += 100;
            char *temp = (char*)realloc(*s, size);
            if (temp == NULL) {
                free(*s);
                perror("Error realocando buffer\n");
                return -1;
            }
            *s = temp;
        }
        (*s)[i] = c;
    }
    (*s)[i] == '\0';
    return i;
}

int _strLen(char*s) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}