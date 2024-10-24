#include <stdio.h>
#include <string.h>

int main(void) {
    int lim = 10;
    int c, i;
    char buf[lim];
    for (i = 0; i < lim; ++i) {
        if ((c = getchar()) == '\n') {
            break;
        }
        if (c == EOF) {
            break;
        }
        buf[i] = c;
    }
    buf[++i] = '\0';
    printf("FRASE: %s", buf);
    return 0;
}