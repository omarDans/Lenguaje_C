#include <stdio.h>

// c = getchar() != EOF  -- sin parentesis aposta para obtener el resultado de la condición, si escribes cualquier cosa devuelve 1, si presions ctrl+D (EOF) devuelve 0. Puede que en windows sea ctrl + Z
int main(void) {
    int c;
    while (1==1) {
        if (c = getchar() != EOF) {
            printf("%d\n", c);
        }
        else {
            printf("%d\n", c);
            break;
        }
    }
    return 0;
}