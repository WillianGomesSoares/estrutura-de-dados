#include <stdio.h>

//Receba a cotação do dólar em reais e um valor que o usuário possui em dólares.
//Imprima este valor em reais.

int main()
{
    float dolar = 0.0;
    float cotacao = 0.0;
    float reais = 0.0;

    printf("Quantidade de Doláres:");
    scanf("%f:" , &dolar);
    printf("Cotação Atual do Dolar:");
    scanf("%f" , &cotacao);
    reais = dolar * cotacao;
    printf("Reais= %.2f\n", reais);

    return 0;
}