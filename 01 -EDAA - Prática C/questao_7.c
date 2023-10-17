#include <stdio.h>

//Receba o valor do salário mínimo e o valor do salário de um funcionário. O algoritmo
//deve calcular e apresentar a quantidade de salários mínimos que esse funcionário
//recebe.

int main()
{
    float salario_minimo = 0.0;
    float salario = 0.0;

    printf("Valor do salario minimo:");
    scanf("%f:" , &salario_minimo);
    
    printf("Valor do salario do funcionario:");
    scanf("%f:" , &salario);

    printf("Razão do Salario= %.2f\n", salario/salario_minimo);

    return 0;
}