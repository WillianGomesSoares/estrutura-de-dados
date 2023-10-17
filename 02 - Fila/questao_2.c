/*
* Programa que lê números inteiros a partir
* do teclado e os armazena em uma fila.
*/
#include <stdio.h>
#include <stdlib.h>
#define TAM 3
typedef int elemento;
#include "fila.h"
int main() {
int num;
fila f;
FILE *pont_arq;
pont_arq = fopen("fila.txt", "w");

CriarFila(&f);
while(FilaCheia(&f) == FALSO) {
printf("\nInforme um numero inteiro: ");
scanf("%d", &num);
Enfileirar(&f, num);
}

while(FilaVazia(&f) == FALSO) {
DesenfileirarArquivo(&f,pont_arq);
}
fclose(pont_arq);

pont_arq = fopen("fila.txt", "r");

EnfileirarArquivo(&f,pont_arq);//also imprime


printf("\n");
system("pause");
fclose(pont_arq);
return 0;
}