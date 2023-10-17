#include <stdio.h>

//Faça um programa que receba o salário de um funcionário, calcule e mostre o novo
//salário, sabendo-se que ele teve um aumento de 25%.

int main()
{
    float salario = 0.0;
    float novo = 0.0;

    printf("Sálario Antigo:");
    scanf("%f:" , &salario);

    novo = salario * 1.25;
    printf("Novo salario= %.2f\n", novo);

    return 0;
}