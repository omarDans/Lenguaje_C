#include <stdio.h>
#include <stdlib.h>

#define MINIMUM 80
#define MAXLINE 100

int getline(char **line);
void copy(char **to, char from[]);
int _strLen(char s[]);
void removeWhiteTab(char **s, int len);

main()
{
    int c;
    int len;
    int max = MINIMUM;
    char *line = NULL;
    char *longest = NULL;

    while((len = getline(&line)) > 0) {
        if (len >= max) {
            copy(&longest, line);
        }
    } 
    if (longest != NULL) {
        printf("%s", longest);
        free(longest);
        longest = NULL;
    }
    free(line);
    line = NULL;
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
    int i, length, length2, numero;
    numero = MAXLINE;
    i = 0;
    if (*to == NULL) {
        *to = (char *)malloc(sizeof(char) * numero);
        if ((length = _strLen(from)) > numero) {
            char *temp = realloc(*to, length);
            if (temp == NULL) {
                return;
            }
            *to = temp;
            numero += 100;
            printf("se realoco 2!\n");
        }
        while(((*to)[i] = from[i]) != '\0') {
            ++i;
        }
    } else {
        length = _strLen(*to);
        length2 = _strLen(from);
        if ((length + length2) > numero) {
            numero = length + length2;
            char *temp = realloc(*to, numero);
            if (temp == NULL) {
                return;
            }
            *to = temp;
            printf("Se realoco 3!\n");
        }
        while(((*to)[length+i] = from[i]) != '\0') {
            ++i;
        }
    }

}

int _strLen(char s[]) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}
