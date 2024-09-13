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
        removeWhiteTab(&line, len);
        if (line != NULL) {
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

void removeWhiteTab(char **s, int len) {
    int c;
    int i;
    for (i = len-1; i > 0; i--) {
        if ((*s)[i] == ' ' || (*s)[i] == '\t' || (*s)[i] == '\n') {
            (*s)[i] = '\0';
        } else {
            (*s)[i+1] = '\n';
            break;
        }
    }
    if (i == 0) {
        *s = NULL;
    }
}

void copy(char **to, char from[]) {
    int i, length, length2, numero;
    numero = MAXLINE;
    i = 0;
    if (*to == NULL) {
        *to = (char *)malloc(sizeof(char) * _strLen(from));
        while(((*to)[i] = from[i]) != '\0') {
            ++i;
        }
    } else {
        length = _strLen(*to);
        length2 = _strLen(from);
        numero = length + length2;
        char *temp = realloc(*to, numero);
        if (temp == NULL) {
            return;
        }
        *to = temp;
        printf("Se realoco!\n");
        while(((*to)[length + i] = from[i]) != '\0') {
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
