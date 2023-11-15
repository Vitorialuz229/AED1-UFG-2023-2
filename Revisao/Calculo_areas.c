//Exercicio 10 - Cálculo de áreas 
/*Considera-se que vocês conhecem as “fórmulas matemáticas” de cálculo para as áreas destas figuras, mas
você pensou numa solução mais sofisticada: elaborar um programa de computador C que seja capaz de
receber as informações necessárias e retornar a área da figura.
Observação: Utilize π = 3,14159265.*/
#include <stdio.h>
#include <math.h>
#define PI 3.14159265

double areaCirculo (double);
double areaElipse (double, double);
double areaTriangulo (double, double, double);
double areaTrapezio (double, double, double);

int main(){
    int qtd, i=0;
    char figura;
    double R, r, l1, l2, l3, B, b, h;

    scanf("%d", &qtd);

    while(i < qtd){
        scanf (" %c", &figura);

        switch(figura){
	    case 'C':
	        scanf("%lf", &R);
	        printf("%d ", (int)areaCirculo(R));

	        break;

	    case 'E':
	        scanf("%lf %lf", &R, &r);
	        printf("%d ", (int)areaElipse(R, r));

	        break;

	    case 'T':
	        scanf("%lf %lf %lf", &l1, &l2, &l3);
	        printf("%d ", (int)areaTriangulo(l1, l2, l3));

	        break;

	    case 'Z':
	        scanf("%lf %lf %lf", &B, &b, &h);
	        printf("%d ", (int)areaTrapezio(B, b, h));

	        break;
	    }

    i++;
    printf("\n");
    
    }

    return 0;
}

double areaCirculo(double R){
    double area, parteInteira;
  
    area = PI * pow(R, 2);

    if(modf(area, &parteInteira) < 0.5)
        return floor(area);
    else
        return ceil(area);
}

double areaElipse(double R, double r){
    double area, parteInteira;
    area = (PI * R * r);

    if(modf(area, &parteInteira) < 0.5)
        return floor(area);
    else
        return ceil(area);
}

double areaTriangulo (double l1, double l2, double l3){
    double p, parteInteira, area;
  
    p = (l1 + l2 + l3) / 2;
    area = (sqrt(p * (p - l1) * (p - l2) * (p - l3)));
  
    if(modf(area, &parteInteira) < 0.5)
        return floor(area);
    else
        return ceil(area);
}

double areaTrapezio(double B, double b, double h){
    double parteInteira, area;
    area = ((B + b) * h) / 2;
    
    if(modf(area, &parteInteira) < 0.5)
        return floor(area);
    else
        return ceil(area);
}