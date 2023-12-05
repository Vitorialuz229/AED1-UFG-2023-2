/*Escreva uma função recursiva, em C, que seja capaz de determinar o 
número reverso de um certo número natural estritamente positivo n 
fornecido como entrada.*/

#include <stdio.h>
int sum=0, rem;
int reverse_function(int num) {
  if(num) {
    rem=num%10;
    sum=sum*10+rem;
    reverse_function(num/10);
  }
  else
    return sum;
  return sum;
}
int main() {
  int num,reverse_number;
    printf("");
  scanf("%d",&num);
    reverse_number=reverse_function(num);
    printf("%d",reverse_number);
return 0;
}