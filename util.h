#include <stdio.h>

#define EOL '\n'
#define null NULL
#define TRUE 1
#define FALSE 0
#define M_PI 3.14159265358979323846

void print_int(int _int)
{
    printf("%i %c", _int, EOL);
}

void print_float(float _float)
{
    printf("%f %c", _float, EOL);
}

void print_double(double _double)
{
    printf("%d %c", _double, EOL);
}

void print_string(const char *_string)
{
    printf("%s %c", _string, EOL);
}

void new_line()
{
    printf("\n");
}

void print_int_array(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%i %c", *(array + i), EOL);
    }
}