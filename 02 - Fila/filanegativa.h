/*
* Arquivo: fila.h
* Biblicoteca de operações para fila implementada
* com vetor.
*/
#define VERDADEIRO 1
#define FALSO 0
struct tipo_fila {
elemento vet[TAM];
int inicio, fim;
};
typedef struct tipo_fila fila;
//Cria fila.
void CriarFila(fila *f) {
(*f).inicio = -1;
(*f).fim = -1;
}
//Verifica se a fila está vazia.
int FilaVazia(fila *f) {
return((*f).inicio+1 == (*f).fim+1);
}
//Verifica se a fila está cheia.
int FilaCheia(fila *f) {
return((*f).fim+1 == TAM);
}
//Insere um elemento na fila.
void Enfileirar(fila *f, elemento e) {
(*f).vet[(*f).fim+1] = e;
(*f).fim++;
}
//Retira um elemento na fila.
elemento Desenfileirar(fila *f) {
(*f).inicio++;
return((*f).vet[(*f).inicio]);
}

void ImprimirFila(fila *f){
int num = 0;
printf("\nNumeros informados: ");
while(FilaVazia(f) == FALSO) {
num = Desenfileirar(f);
printf("\n%d", num);
}
}