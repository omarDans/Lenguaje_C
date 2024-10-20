#include <stdio.h>
#include <limits.h>

int main(void) {
    printf("Rangos usando headers estándar:\n");
    printf("char: signed [%d, %d], unsigned [0, %d]\n", CHAR_MIN, CHAR_MAX, UCHAR_MAX);
    printf("short: signed [%d, %d], unsigned [0, %d]\n", SHRT_MIN, SHRT_MAX, USHRT_MAX);
    printf("int: signed [%d, %d], unsigned [0, %u]\n", INT_MIN, INT_MAX, UINT_MAX);
    printf("long: signed [%ld, %ld], unsigned [0, %lu]\n", LONG_MIN, LONG_MAX, ULONG_MAX);

    printf("\nRangos por cálculo directo:\n");
    printf("char: signed [%d, %d], unsigned [0, %d]\n", -(1 << (sizeof(char) * 8 - 1)), (1 << (sizeof(char) * 8 - 1)) - 1, (1 << (sizeof(char) * 8)) - 1);
    printf("short: signed [%d, %d], unsigned [0, %d]\n", -(1 << (sizeof(short) * 8 - 1)), (1 << (sizeof(short) * 8 - 1)) - 1, (1 << (sizeof(short) * 8)) - 1);
    printf("int: signed [%lld, %lld], unsigned [0, %llu]\n", -(1L << (sizeof(int) * 8 - 1)), (1L << (sizeof(int) * 8 - 1)) - 1, (1UL << (sizeof(int) * 8)) - 1);
    
    // En este existe desbordamiento porque estoy representando el máximo valor que "lu" puede contener
    
    printf("long: signed [%lld, %lld], unsigned [0, %llu]\n", -(1L << (sizeof(long) * 8 - 1)), (1L << (sizeof(long) * 8 - 1)) - 1, (1UL << (sizeof(long) * 8)) - 1);

    return 0;
}