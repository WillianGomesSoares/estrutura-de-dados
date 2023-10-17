#include <stdio.h>

//10) Receba o raio, calcule e apresente:

//a. O comprimento de uma esfera: C = 2 * π * R.
//b. A área de uma esfera: A = π * R2
//c. O volume de uma esfera: V = 3⁄4 * π * R3

//Volume correto = (4*pi*r3)/3

int main()
{
    float raio = 0.0;

    printf("Insira o raio:");
    scanf("%f:" , &raio);

    printf("Comprimento= %.2f\n",(2*3.14159*raio));
    printf("Area= %.2f\n",(3.14159*(raio*raio)));
    printf("Volume= %.2f\n",((4)*(3.14159)*(raio*raio*raio))/3);

    return 0;
}