#include <stdio.h>
#include <math.h>

float mean(const int* arr, size_t n)
{
    float sum = 0;

    for (size_t i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    
    return sum / n;
}

float mode(const int* arr, size_t n)
{
    int max_value = 0, max_count = 0, i, j;

    for (i = 0; i < n; ++i)
    {
        int count = 0;

        for (j = 0; j < n; ++j)
        {
            if (arr[j] == arr[i])
                ++count;
        }

        if (count > max_count)
        {
            max_count = count;
            max_value = arr[i];
        }
    }

    return max_value;
}

float stddev(const int* arr, size_t n)
{
    float sum_of_squares = 0;
 
    for (int i = 0; i < n; i++)
    {
        sum_of_squares += pow(arr[i] - mean(arr, n), 2);
    }
 
    float variance = sum_of_squares / n;
    
    return sqrt(variance);
}

float rate(const int* arr, size_t n, int elem)
{
    int count = 0;

    for (size_t i = 0; i < n; i++)
    {
        if (arr[i] == elem)
            count++;
    }
    
    return (float) count / n;
}