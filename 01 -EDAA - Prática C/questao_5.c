#include <stdio.h>

//Calcule e apresente a área de um losango. As diagonais maior e menor do losango
//devem ser informadas pelo usuário. OBS: AREA = (DIAGONAL MAIOR * DIAGONAL
//MENOR) / 2.

int main()
{
    float maior = 0.0;
    float menor = 0.0;
    float area = 0.0;

    printf("Diagonal Maior:");
    scanf("%f:" , &maior);
    printf("Diagonal Menor:");
    scanf("%f" , &menor);
    area = (maior * menor) / 2;
    printf("Area= %.2f\n", area);

    return 0;
}