/* Parece que funciona pero no me fio un pelo, tal vez tenga bugs... (De optimizacion ni me hables tampoco)*/

#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 100
#define TABSIZE 4

int _getline(char**s);
void _copy(char**to, char*from);
int _strLen(char*string);
char* _changeToTabs(char *s, int len);

int main(void) {
    int len;
    char *line = NULL;
    char *buffer = NULL;
    while ((len = _getline(&line)) > 0) {
        if (line != NULL) {
            line = (char*)_changeToTabs(line, len);
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
        (*s)[i] = c;
    }
    if (c == '\n') {
        (*s)[i] = '\n';
        i++;
    }
    (*s)[i] = '\0';
    return i;
}

char* _changeToTabs(char*s, int len) {
    int tabpos, counter_s, counter_bucle, counter_espacios, counter_buf;
    char *buffer = (char*)malloc(sizeof(char) * _strLen(s));
    counter_bucle = 0;
    counter_buf = 0;
    for (counter_s = 0; counter_s <= len; ++counter_s) {
        counter_espacios = 0;
        tabpos = TABSIZE - (counter_s % TABSIZE);
        counter_bucle = coun    printf("%s\n", buffer);le] == ' ') {
            counter_espacios++;
            counter_bucle++;
            if (tabpos == counter_espacios) {
                buffer[counter_buf++] = '\t';
                counter_espacios = 0;
                counter_s = counter_bucle;
                break;
            }
        }
        while (counter_espacios > 0) {
            buffer[counter_buf++] = ' ';
            counter_espacios--;
            counter_s++;
        }
        buffer[counter_buf] = s[counter_s];
        counter_buf++;
    }
    return buffer;
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