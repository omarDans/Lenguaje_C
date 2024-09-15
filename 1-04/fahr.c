#include <stdio.h>

void main()
{
    float fahr, celsius;
    int lower, upper, step;


    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    
    printf("%3s %6s\n", "fahr", "celsius");
    while(fahr <= upper) {
        celsius = (5.0/9.0) * (fahr - 32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
    printf("\n\n");
    celsius = lower;
    printf("%3s %4s\n", "celsius", "fahr");
    while (celsius <= upper) {
        fahr = celsius * 9.0 / 5.0 + 32;
        printf("%3.0f %7.0f\n", celsius, fahr);
        celsius = celsius + step;
    }
}