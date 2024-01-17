/* escreva um programa, em C, para imprimir os n primeiros números naturais usando o conceito de recursividade, que os define da seguinte maneira:
n0 = 0
ni+1 = ni +1,i ∈ {0,1,2,...}
*/
#include <stdio.h> 

void naturais(int n) { 
    if(n > 0){
        naturais(n-1);
        printf("%d ",n);
    }
}
int main (){ 
    int n; 
    scanf("%d", &n);
    printf("");

    if(n >= 1 && n <= 5000) { 
        naturais(n);
    } else { 
        printf("");    
    }
    printf("\n");

return 0; 
}