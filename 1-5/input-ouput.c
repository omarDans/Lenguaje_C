#include <stdio.h>

void main()
{
    int c;
    int endOfFile = EOF;

    printf("%d", endOfFile);
    while (c = getchar() != EOF) {
            putchar(c);
    }
    printf("Saliendo del programa...\n");
}