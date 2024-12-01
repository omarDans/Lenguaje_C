#include <stdio.h>
#include <stdlib.h>

#define SIZE_BUF 100

int _getLine(char **s);
int _strLen(char *s);
int any(char *s1, char *s2);

int main(void) {
    char *line = NULL;
    char *line2 = NULL;
    int c, c2, n;
    printf("Write first line: ");
    c = _getLine(&line);
    printf("Characters to search: ");
    c2 = _getLine(&line2);
    n = any(line, line2);
    printf("Founded at: %d\n", n);
    return 0;
}
int any(char *s1, char *s2) {
    int i;
    while (i++ < _strLen(s1)) {
        for (int n = 0; n < _strLen(s2); n++) {
            if (s1[i] == s2[n]) {
                return i;
            }
        }
    }
    return -1;
}

int _getLine(char **s) {
    int i, c;
    int size = SIZE_BUF;
    *s = (char *)malloc(sizeof(char) * size);
    if (*s == NULL) {
        return -1;
    }
    for (i = 0; (c = getchar()) != '\n' && c != EOF; ++i) {
        if (i >= size - 1) {
            size += 100;
            char *temp = (char *)realloc(*s, size);
            if (temp == NULL) {
                free(*s);
                perror("Error realocando buffer\n");
                return -1;
            }
            *s = temp;
        }
        (*s)[i] = c;
    }
    (*s)[i] = '\0';
    return i;
}

int _strLen(char *s) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}
