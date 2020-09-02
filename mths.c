#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <cstring>
#include <stdbool.h>
#include <time.h> 
#include "headers.h"
#include UTIL_HEADER



int main(int arg_count, char** arguments)
{
    if(arg_count == 1)
    {
        print_string("No arguments where given");
        exit(0);
    }

    char* qeury = arguments[1];
    bool k = qeury == "pi";

    if(strcmp(qeury,"pi") == 0)
    {
        printf("%f", M_PI);
    }

    
    return 0;
}