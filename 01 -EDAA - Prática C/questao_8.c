#include <stdio.h>

//Receba o peso de uma pessoa, calcule e apresente o novo peso:
//a. Se a pessoa engordar 15%.
//b. Se a pessoa emagrecer 20%.

int main()
{
    float peso = 0.0;

    printf("Peso:");
    scanf("%f:" , &peso);


    printf("Peso se engordar= %.2f\n", peso*1.15);
    printf("Peso se emagrecer= %.2f\n", peso*0.80);


    return 0;
}