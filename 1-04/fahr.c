#include <stdio.h>

void main()
{
    float fahr, celsius;
    int lower, upper, step;


    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    
    printf("fahr | celsius\n\n");
    while(fahr <= upper) {
        celsius = (5.0/9.0) * (fahr - 32.0);
        printf("%3.0f %9.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
    celsius = lower;
    printf("celsius | fahr\n\n");
    while (celsius <= upper) {
        fahr = celsius * 9.0 / 5.0 + 32;
        printf("%3.0f %9.0f\n", celsius, fahr);
        celsius = celsius + step;
    }
}