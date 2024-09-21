// No encontré otra manera de hacer esto sin usar la libreria ncurses ya que getchar() no registra el retroceso
// Instalación libreria ncurses en linux: sudo apt-get install libncurses5-dev libncursesw5-dev

#include <stdio.h>
#include <ncurses.h>

int main(void) {
    initscr();             

    int c;
    printw("Escribe algo (Ctrl+D para salir): ");
    refresh();

    while ((c = getch()) != 4) { 
        if (c == '\t') {
            printf("\\t");      
        } else if (c == 127) {
            printf("\\b");        
        } else if (c == 10 || c == KEY_ENTER) {
            printf("\\n");        
        } else if (c == '\\') {
            printf("\\\\");       
        } else {
            putchar(c);           
        }
    }
    endwin();  
    return 0;
}