#include <stdio.h>
#include <math.h>

//Receba os valores dos dois catetos de um triângulo, calcule e apresente o valor da
//hipotenusa. OBS - Teorema de Pitágoras: a2 = b2 + c2


int main()
{
    float cateto1 = 0.0;
    float cateto2 = 0.0;

    printf("Insira o cateto1:");
    scanf("%f:" , &cateto1);

    printf("Insira o cateto2:");
    scanf("%f:" , &cateto2);

    printf("Hipotenusa= %.2f\n",sqrt((cateto1*cateto1)+(cateto2*cateto2)));

    return 0;
}