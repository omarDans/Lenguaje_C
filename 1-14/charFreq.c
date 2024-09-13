#include <stdio.h>
#include <stdlib.h>

/* VAMOOOOOOOOOSSS */
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

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
    char buffer[100];
    char letras[10];
    int c, i;
    i = 0;
    while ((c = getchar()) != EOF) {
        if (' ' != c || '\n' != c || '\t' != c) {
            buffer[i] = c;
            i++;
        }
    }
    buffer[i] = '\0';
    printf("Que letras quieres ver la frecuencia del input: ");
    scanf("%s", letras);
    clearInputBuffer();
    printf("\nletras: %s\n", letras);
    int* LetrasContadas = contarLetras(buffer, letras, &i);
    int sizeBuffer = _strlen(buffer);
    for (c = 0; c < i; c++) {
        printf("letra: %c: %.2f%%\n", letras[c], ((double)LetrasContadas[c] / sizeBuffer) * 100);
    }
    free(LetrasContadas);
    LetrasContadas = NULL;
}