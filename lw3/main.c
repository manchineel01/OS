#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define size 10

void fillMass(int mass[], int n){
   for(int i = 0; i < n; i++){
    mass[i] = rand() % 100 - 50;
    printf("%d\t", mass[i]);
  }
}

void calcAverage(int mass[], int n){
  int avr = 0, countOfHighers = 0;
  for(int i = 0; i < n; i++)
      avr += mass[i]; 
  
  avr /= n;
  for(int i = 0; i < n; i++){
      if(avr < mass[i]){
        countOfHighers++;
      }     
    }
    printf("\nAverage num - %d\n nums over average - %d\n", avr, countOfHighers);  
}

void afterNegative(int mass[], int n){
  int sum = 0;
  for(int i = 0; i < n; i++){
    if(mass[i] < 0){
      for(int j = i+1; j < n; j++){
        sum += abs(mass[j]); 
      }
      printf("Sum of elements in array after negative num - %d\n", sum);
      return;
    }
  }
}

int main(){
  srand(time(NULL));
  int mass[size];
  fillMass(mass, size);
  calcAverage(mass, size);
  afterNegative(mass, size);
  putchar('\n');
  return 0;
}

