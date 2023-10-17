/*
* Programa que lê números inteiros a partir
* do teclado e os armazena em uma pilha.
*/
#include <stdio.h>
#include <stdlib.h>
#define TAM 3 //mudar pra 10
typedef int elemento;
#include "pilhaold.h"
int main() {
int num;
pilha p;
CriarPilha(&p);

FILE *pont_arq;
pont_arq = fopen("pilha.txt", "w");

while(PilhaCheia(&p) == FALSO) {
printf("\nInforme um numero inteiro: ");
scanf("%d", &num);
Empilhar(&p, num);
}

while(PilhaVazia(&p) == FALSO) {
DesempilharArquivo(&p,pont_arq);
}
fclose(pont_arq);

pont_arq = fopen("pilha.txt", "r");

EmpilharArquivo(&p,pont_arq);

ImprimePilha(&p);

fclose(pont_arq);

printf("\n");
system("pause");
return 0;
}