#include <stdio.h>

int main(void) {
    int c, lc;
    while ((c = getchar()) != EOF) {
        if (c != ' ') {
            lc = c;
            putchar(c);
        } else {
            if ( lc == ' ' ) {
                continue;
            }
            lc = c;
            putchar(c);
        }
    }
    return 0;
}