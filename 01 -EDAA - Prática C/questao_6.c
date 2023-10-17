#include <stdio.h>

//Receba uma temperatura em Celsius, calcule e mostre essa temperatura em Fahrenheit.
//OBS: F = (C * 1,8) + 32.

int main()
{
    float celsius = 0.0;
    float fahrenheit = 0.0;

    printf("Temperatura em Celsius:");
    scanf("%f:" , &celsius);

    fahrenheit = (celsius * 1.8)+32 ;
    printf("Temperatura para Americanos incapazes de usar o sistema métrico superior= %.2f\n", fahrenheit);

    return 0;
}