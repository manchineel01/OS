#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(){
    double x;
    printf("Enter x: ");
    if(scanf("%lf", &x) == 0){
        printf("Wrong value provided");
        exit(-1);
    }

    printf("f(x) = %f \t g(x) = %f", f(x), g(x));
}
