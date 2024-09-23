/* Para Windows tienes que añaidr la cabecera <windows.h> para la funcion system() */
/* En este ejercicio me motive un poco ya lo sé, estaba aprendiendo cosas nuevas y lo metí todo ahí */

#include <stdio.h>
#include <ctype.h>
#include <signal.h>
#include <stdlib.h>

#define RED "\033[0;31m"
#define BLUE "\033[0;34m"
#define YELLOW "\033[0;33m"
#define PURPLE "\033[0;35m"
#define RESET_COLOR "\033[0m"

void celsiusToFahr(float);
void fahrToCelsius(float);
void CleanInputBuffer();
void handle_sigint(int); 

void main()
{
    signal(SIGINT, handle_sigint);
    float fahr, celsius;
    char medida;
    system("clear");
    printf("%sDegreesConverter - Created by omarDans%s\n", YELLOW, RESET_COLOR);
    printf("\n%sWhat do you want to convert, (F)ahrenheit/celsius / (C)elsius/fahrenheit?: %s", YELLOW, PURPLE);
    scanf("%c", &medida);
    medida = tolower(medida);
    if ('f' == medida) {
        printf("\n%sWhat fahrenheit number do you want to convert to celisus?: %s", BLUE, PURPLE);
        scanf("%f", &fahr);
        fahrToCelsius(fahr);
    } else if ('c' == medida) {
        printf("\n%sWhat Celsius number fo you want to convert to fahrenheit?: %s", RED, PURPLE);
        scanf("%f", &celsius);
        celsiusToFahr(celsius);
    } else {
        printf("%sError:%s Please input a valid option (f/c)\n", RED, RESET_COLOR);
        return;
    }
    //CleanInputBuffer();
    
}

// Limpiar el color de la terminal al cerrar con Ctrl+C
void (handle_sigint(int sig)) {
    printf("%s", RESET_COLOR);
    printf("\nSignal: (Ctrl+C), quitting...\n");
    exit(0);
} 

void celsiusToFahr(float celsius) {
    float fahr;
    fahr = celsius * 9.0 / 5.0 + 32;
    printf("\n%sFahr value for %.1f celsius: %s%.2f%s", RED, celsius, PURPLE, fahr, RESET_COLOR);
}

void fahrToCelsius(float fahr) {
    float celsius;
    celsius = (5.0/9.0) * (fahr - 32.0);
    printf("\n%sCelsius value for %.1f fahr: %s%.2f\n%s", BLUE, fahr, PURPLE, celsius, RESET_COLOR);
}

void CleanInputBuffer() {
    int c;
    while((c = getchar()) != '\n' || c != EOF) {}
}