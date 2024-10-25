#include <stdio.h>
#include <stdlib.h>

#define SIZE_BUF 100

int _getLine(char **s);
int hexToInt(char*s, int len);
int power(int base, int exp);

int main(void) {
    int size, value;
    char *buf;
    printf("Escribar el valor hexadecimal que quiere cambiar: ");
    size = _getLine(&buf);
    if (size > 0) {
        value = hexToInt(buf, size);
        if (value >= 0) {
            printf("HEXADECIMAL: %d\n", value);
        }
    }
    return 0;
}

int hexToInt(char*s, int len) {
    int i = 0;
    int counter = len;
    int number, value;
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
        i = 2;
        counter -= 2;
    }
    --counter;
    value = 0;
    for (i; i < len; ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
            number = s[i] - '0';
        } else if (s[i] >= 'a' && s[i] <= 'f') {
            number = s[i] - 'a' + 10;
        } else if (s[i] >= 'A' && s[i] <= 'F') {
            number = s[i] - 'A' + 10;
        } else {
            printf("Error, revisa haber introducido un valor correcto\n");
            return -1;
        }
        value += number * power(16, counter);
        --counter;
    }
    return value;
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

int power(int base, int exp) {
    int result = 1;
    while (exp) { result *= base; exp--; }
    return result;
}