/* No estoy completamente seguro si este ejercicio era esto lo que buscaba, me parece excesivamente trivial 
Tal vez existe otra forma de lograr esto sin usar && o ||. Si por algo estás leyendo esto y sabes hacerlo de otra forma no dudes en crear un pull request o comentármelo
de alguna manera*/

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