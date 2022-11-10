#include <stdlib.h>
#include <math.h>
#include <stdio.h>

double get_average(int* values, int count);
int get_count_higher_than_average(int* values, int count);
int get_indexof_first_negative(int* values, int count);
int get_abs_sum_after_first_negative(int* values, int count);
void print_values(int* values, int count);

int main(int argc, char** argv){
    int values[] = {0, 2, 5, -4, 3, 6, -100};
    int count = sizeof(values)/sizeof(int);
    printf("Count: %d", count);

    printf("\nValues: ");
    print_values(values, count);

    printf("\nAverage: %f", get_average(values, count));
    printf("\nCount higher than average: %d", get_count_higher_than_average(values, count));

    printf("\nIndexOf first negative: %d", get_indexof_first_negative(values,count));
    printf("\nAbs sum after first negative: %d", get_abs_sum_after_first_negative(values,count));
}

double get_average(int* values, int count){
    int sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum += values[i];
    }
    return (double)sum/(double)count;
}

int get_count_higher_than_average(int* values, int count){
    double average = get_average(values, count);
    int higher_count = 0;
    for (int i = 0; i < count; i++)
    {
        if (values[i] > average)
        {
            higher_count++;
        }
    }
    return higher_count;
}

int get_indexof_first_negative(int* values, int count){
    for (int i = 0; i < count; i++)
    {
        if (values[i] < 0)
        {   
            return i;
        }
    }
    return -1;
}

int get_abs_sum_after_first_negative(int* values, int count){
    int i = get_indexof_first_negative(values, count) + 1;
    int sum = 0;
    for (; i < count; i++)
    {
        sum += abs(values[i]);
    }
    return sum;
}

void print_values(int* values, int count){
    for (int i = 0; i < count; i++)
    {
        printf("%d ", values[i]);
    }
    
}