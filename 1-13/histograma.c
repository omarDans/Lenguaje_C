#include <stdio.h>
#include <string.h>

#define OUT 0
#define IN 1

void main()
{
    char buffer[100];
    int nc = 0;
    int i = 0;
    char c;
    int state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t'){
            if (state == IN) {
                buffer[nc] = '\n';
                state = OUT;
                nc++;
            }
        } else {
            if (state == OUT) {
                state = IN;
            }
            buffer[nc] = '0';
            nc++;
        }
        
    }
    buffer[nc] = '\0';

    printf("HISTOGRAMA\n\n%s\n", buffer);

}