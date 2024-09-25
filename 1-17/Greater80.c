#include <stdio.h>
#include <stdlib.h>

#define MINIMUM 80
#define MAXLINE 100

int _getline(char **line);
void _copy(char **to, char from[]);
int _strLen(char s[]);
void removeWhiteTab(char **s, int len);

int main()
{
    int c;
    int len;
    int max = MINIMUM;
    char *line = NULL;
    char *longest = NULL;

    while((len = _getline(&line)) > 0) {
        if (len >= max) {
            _copy(&longest, line);
        }
    } 
    if (longest != NULL) {
        printf("\n\nFRASES MAS LARGAS\n\n");
        printf("%s", longest);
    }
    free(line);
    free(longest);
    longest = NULL;
    line = NULL;

    return 0;
}


int _getline(char **s){
    free(*s);
    *s = NULL;
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
    int i, length, length2, numero;
    numero = MAXLINE;
    i = 0;
    if (*to == NULL) {
        length = _strLen(from);
        *to = (char *)malloc(sizeof(char) * length);
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
