#include <stdio.h>

//11) Calcule e mostre a tabuada de multiplicação de um número informado pelo usuário no
//teclado.
//Exemplo:
//Informe um número: 7
//7 x 0 = 0
//7 x 1 = 7

int main()
{
    int numero = 0;
    int valor = 0;
    int i = 0;

    printf("Insira o numero:");
    scanf("%d:" , &numero);

    for(i=0; i<11; i++){
        valor = numero * i;
        printf("%d X %d = %d\n",numero,i,valor);
    }

    return 0;
}