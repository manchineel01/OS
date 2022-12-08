#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char * argv[]){
    double r1, r2;
    double a = atof(argv[1]);
    double b = atof(argv[2]);
    double c = atof(argv[3]);
    double discriminant = b * b - 4 * a * c;
    
   if (discriminant > 0){
      r1 = -b + sqrt(discriminant) / (2 * a);
      r2 = -b - sqrt(discriminant) / (2 * a);
      printf ("Real roots = %f %f", r1, r2);
   }
   else if (discriminant == 0){
      r1 = -b / (2*a);
      printf ("There's a single root = %f", r1);
   }
   else
      printf("Roots are imaginary");

    return 0;
}