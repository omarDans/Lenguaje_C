/* Compilalo con: "gcc -o charFreq charFreq.c -lm"
"-lm" hace referencia a la libreria math para usar floor()*/ 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int _strlen(char string[]) {
    int i = 0;
    while (string[i] != '\0'){
        i++;
    }
    return i;
}
int* contarLetras(char buffer[], char letras[], int *numero) {
    int sizeLetras = _strlen(letras);
    printf("sizeLetras: %d\n", sizeLetras);
    int *size = (int*)malloc(sizeLetras * sizeof(int));
    for (int c = 0; c < sizeLetras; c++){
        size[c] = 0;
    }
    int i;
    int j = 0;
    while (letras[j] != '\0') {
        i = 0;
        while (buffer[i] != '\0') {
            if (letras[j] == buffer[i]) {
                size[j] += 1;
            }
            i++;
        }
        j++;
    }
    *numero = sizeLetras;
    return size;
}
void main() 
{
    char buffer[100]; // maximo tamaño del buffer, si escribes más de la capacidad me da igual, no lo voy a hacer dinámico
    char letras[26]; // letras del abecedario
    int c, i;
    i = 0;
    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\n' && c != '\t') {
            buffer[i] = c;
            i++;
        }
    }
    buffer[i] = '\0';
    // Reseteamos las banderas de EOF y ERROR para que scanf se ejecute y no salga inmediatamente, esto se puede lograr con clearerr() pero esto mola mas
    stdin->_flags &= ~(_IO_EOF_SEEN | _IO_ERR_SEEN);
    printf("Que letras quieres ver la frecuencia del input: ");
    scanf("%s", letras);
    int* LetrasContadas = contarLetras(buffer, letras, &i);
    int sizeBuffer = _strlen(buffer);
    for (c = 0; c < i; c++) {
        printf("letra: %c: %.2f%%\n", letras[c], floor(((double)LetrasContadas[c] / sizeBuffer) * 100 * 100) / 100); // le aplicamos floor() para que no se pase del 100%, ahora se quedará en un 99.99% pero es más "matemáticamente" correcto
    }
    free(LetrasContadas);
    LetrasContadas = NULL;
}