#include <stdio.h>

#define UPPER 300
#define LOWER 0
#define STEP -20

int main(void) {
    float celsius, fahr;

    fahr = UPPER;

    printf("%3s %6s\n", "fahr", "celsius");
    while (fahr >= LOWER) {
        celsius = (5.0/9.0) * (fahr - 32);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + STEP;
    }
    printf("\n\n");
    celsius = UPPER;
    printf("%3s %4s\n", "celsius", "fahr");
    while (celsius >= LOWER) {
        fahr = celsius * 9.0 / 5.0 + 32;
        printf("%3.0f %7.0f\n", celsius, fahr);
        celsius = celsius + STEP;
    }
    return 0;
}