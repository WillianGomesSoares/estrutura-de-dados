#include <stdio.h>

//Calcule média aritmetica
int main()
{
    int a = 0;
    int b = 0;
    int c = 0;
    float media = 0.0;
    printf("Insira o valor de A, B e C. Aperte enter após digitar cada valor:");
    scanf("%d" , &a);
    scanf("%d" , &b);
    scanf("%d" , &c);

    media = (a+b+c) / 3;

    printf("Média= %.1f", media);

    return 0;
}