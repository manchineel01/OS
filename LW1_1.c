#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x);
double g(double x);

int main(){
    double x;
    printf("Enter x: ");
    if(scanf("%lf", &x) == 0){
        printf("Wrong value provided");
        exit(-1);
    }

    printf("f(x) = %f \t g(x) = %f", f(x), g(x));
}

double f(double x){
    return exp(-fabs(x)) * sin(x);
}

double g(double x){
    return exp(-fabs(x)) * cos(x);
}
