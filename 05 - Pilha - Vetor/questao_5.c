/*
* Programa que lê um número inteiro a partir do teclado
* e o converte para o seu correspondente em binário.
*/
#include <stdio.h>
#include <stdlib.h>
#include<math.h>

#define TAM 5
typedef int elemento;
#include "pilhaold.h"
int main() {
int num, resto;
pilha p;
CriarPilha(&p);
printf("\nInforme um numero inteiro: ");
scanf("%d", &num);
if (num > 513){
    printf("Maior que 5 bits. Bits mais significativos não serão processados");
}
while(num != 0) {
resto = num % 2;
Empilhar(&p, resto);
num/=2;
}

printf("\nCorrespondente em binario: ");
while(PilhaVazia(&p) == FALSO) {
resto = Desempilhar(&p);
printf("%d", resto);

}

printf("\n");
system("pause");
return 0;
}