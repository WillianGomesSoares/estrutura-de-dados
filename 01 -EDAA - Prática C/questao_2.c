#include <stdio.h>

//2) Receba o ano de nascimento de uma pessoa, o ano atual e imprima:2000
//a. A idade da pessoa no ano atual.
//b. A idade que a pessoa terá em 2050.

int main()
{
    int nascimento = 0;
    int ano_atual = 0;
    int idade_atual = 0;

    printf("Ano de Nascimento:");
    scanf("%d:" , &nascimento);
    printf("Ano atual:");
    scanf("%d" , &ano_atual);

    idade_atual = ano_atual-nascimento;
    int futuro = 0;
    futuro = 2050 - nascimento;
    printf("Idade Atual= %.d\n", idade_atual);
    printf("Idade em 2050= %.d", futuro);

    return 0;
}