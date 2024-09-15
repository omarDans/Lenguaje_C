#include <stdio.h>

int main(void) {
    int spaces, tabs, lines, c;
    
    spaces=0;
    tabs=0;
    lines=0;

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            ++lines;
        } else if (c == '\t') {
            ++tabs;
        } else if (c == ' ') {
            ++spaces;
        }
    }
    printf("spaces: %d, tabs: %d, lines: %d\n", spaces, tabs, lines);
    return 0;
}