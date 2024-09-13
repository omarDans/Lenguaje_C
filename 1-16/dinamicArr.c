#include <stdio.h>
#include <stdlib.h>

// Arrays dinámicos, estoy SEGURO que nada que ver con el ejercicio pero ALV.

#define MAXLINE 20

int getline(char **line);
void copy(char **to, char from[]);
int _strLen(char s[]);

main()
{
    int len;
    int max;
    char *line = NULL;
    char *longest = NULL;

    max = 0;
    while((len = getline(&line)) > 0) {
        if (len > max) {
            max = len;
            copy(&longest, line);
        }
    }    
    if (max > 0) {
        printf("%s", longest);
    }
    return 0;
}

int getline(char **s){
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

void copy(char **to, char from[]) {
    int i, length;
    i = 0;
    *to = (char *)malloc(sizeof(char) * MAXLINE);
    if ((length = _strLen(from)) > MAXLINE) {
        char *temp = realloc(*to, length + 1);
        if (temp == NULL) {
            return;
        }
        *to = temp;
        printf("se realoco 2!\n");
    }
    while(((*to)[i] = from[i]) != '\0') {
        ++i;
    }
}

int _strLen(char s[]) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}
