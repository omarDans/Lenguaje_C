#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define OUT 0
#define IN 1


void print_vertical(char **buffer, int verSize, int horSize) {
    int x, y;

    // Imprimir las palabras en columnas
    for (x = 0; x < verSize; x++) {
        for (y = 0; y < horSize; y++) { 
            if (x < strlen(buffer[y])) { 
                printf("%c", buffer[y][x]);  
            } else {
                printf(" ");
            }
        }
        printf("\n"); 
    }
}

int main()
{
    int nc, nw, bw; // number_character, new_word, biggest_word
    char **buffer = NULL;
    nc = nw = 0;
    int i = 0;
    char c;
    int state = OUT;

    int capacidad_palabras = 10;
    int tamaño_palabras = 100;

    buffer = (char**)malloc(capacidad_palabras * sizeof(char *));
    if (buffer == NULL) {
        printf("Error asignando memoria\n");
        return 1;
    }

    buffer[nw] = (char *)malloc(tamaño_palabras * sizeof(char));
    if (buffer[nw] == NULL){
        printf("Error asignando memoria\n");
        return 2;
    }

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t'){
            if (state == IN) {
                state = OUT;
                nw++;
                if (nc > bw) {
                    bw = nc;
                }
                nc = 0;

                if (nw > capacidad_palabras) {
                    capacidad_palabras *= 2;
                    buffer = (char**)realloc(buffer, capacidad_palabras * sizeof(char *));
                    if (buffer == NULL) {
                        printf("Error al redimensionar\n");
                        return 3;
                    }
                    printf("memoria añadida\n");
                }

                buffer[nw] = (char *)malloc(tamaño_palabras * sizeof(char));
                if (buffer[nw] == NULL) {
                    printf("Error asignando memoria para la palabra %d\n", nw);
                    return 4;
                }
            }
            
        } else {
            if (state == OUT) {
                state = IN;
            }
            buffer[nw][nc] = '0';
            nc++;
        }
        
    }
    printf("VERTICAL\n\n");
    print_vertical(buffer, bw, nw);
    
    printf("\n\nHORIZONTAL\n\n");
    for (i = 0; i < nw; i++) {
        printf("%s\n", buffer[i]);
        free(buffer[i]);
    }

    free(buffer);
    return 0;
}    