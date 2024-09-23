#include <stdio.h>
#include <stdlib.h>

// Arrays dinámicos, estoy SEGURO que nada que ver con el ejercicio pero ALV.

#define MAXLINE 20

int _getline(char **line);
void _copy(char **to, char from[]);
int _strLen(char s[]);

int main()
{
    int len;
    int max;
    char *line = NULL;
    char *longest = NULL;

    max = 0;
    while((len = _getline(&line)) > 0) {
        if (len > max) {
            max = len;
            _copy(&longest, line);
        }
    }    
    if (max > 0) {
        printf("%s", longest);
    }
    free(line);
    free(longest);
    return 0;
}

int _getline(char **s){
    int c, i, numero;
    numero = MAXLINE;
    *s = (char *)malloc(numero * sizeof(char));
    if (*s == NULL) {
        return -1;
    }
    for(i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        if (i >= numero -1) {
            char *temp = realloc(*s, numero + 100);
            if (temp == NULL) {
                free(*s);
                return -1;
            }
            *s = temp;
            numero += 100;
            printf("se realoco!\n");
        }
        (*s)[i] = c;
    }
    if (c == '\n') {
        (*s)[i] = c;
        ++i;
    }
    (*s)[i] = '\0';
    return i;
}

void _copy(char **to, char from[]) {
    int i, length;
    i = 0;
    length = _strLen(from);
    free(*to);
    *to = (char *)malloc(sizeof(char) * length + 1);
    if (*to == NULL) {
        printf("Fallo al asignar memoria en _copy\n");
        exit(-1);
    }
    // if ((length = _strLen(from)) > MAXLINE) {
    //     char *temp = realloc(*to, length + 1);
    //     if (temp == NULL) {
    //         return;
    //     }
    //     *to = temp;
    //     printf("se realoco 2!\n");
    // }
    while(i < length && ((*to)[i] = from[i]) != '\0') {
        ++i;
    }
    (*to)[i] = '\0';
}

int _strLen(char s[]) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}
