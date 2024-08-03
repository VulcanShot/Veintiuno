#include <stdio.h>

float rate(const int* arr, size_t n, int elem, int total)
{
    return (float) arr[elem] / total;
}

int random_inclusive(int lower, int upper)
{
    return (rand() % (upper - lower + 1)) + lower;
}