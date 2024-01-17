#include <stdio.h>
#include <stdlib.h>
//
// Funcao de Ackermann - Programa Principal
//
unsigned long int ackermann(unsigned long int m, unsigned long int n) {
        
    if (m == 0) {
       return(n + 1);
    }
    if (n == 0) { 
       return (ackermann(m - 1, 1));
    }  
    return (ackermann(m - 1, ackermann(m, n - 1)));
}
int main() {
    unsigned long int m, n;
    
    scanf("%lu %lu", &m, &n);
    printf("%lu", ackermann(m, n));
    return 0;
}
