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
(*f).inicio = 0;
(*f).fim = 0;
}
//Verifica se a fila está vazia.
int FilaVazia(fila *f) {
return((*f).inicio == (*f).fim);
}
//Verifica se a fila está cheia.
int FilaCheia(fila *f) {
return((*f).fim == TAM);
}
//Insere um elemento na fila.
void Enfileirar(fila *f, elemento e) {
(*f).vet[(*f).fim++] = e;
}
//Retira um elemento na fila.
elemento Desenfileirar(fila *f) {
return((*f).vet[(*f).inicio++]);
}

void EnfileirarArquivo(fila *f, FILE *pont_arq) {
    int read_int = 0;
	int c[TAM];
	int contador = 0;
	while (!feof (pont_arq))
	{  
		fscanf (pont_arq, "\n%d", &read_int);   
		c[contador] = read_int;
		//printf ("\n%d ", c[contador]);
		contador = contador + 1;
	}
	fclose(pont_arq);
    int contador2 = 0;
	while (contador2 != contador){
		printf ("\n%d ", c[contador2]);
		Enfileirar(f,c[contador2]);
		contador2 = contador2 +1;
	}
}

void DesenfileirarArquivo(fila *f, FILE *pont_arq) {
int num = 0;
printf("\nNumeros informados: ");
while (FilaVazia(f) == FALSO) {
	num = Desenfileirar(f);
	fprintf(pont_arq,"\n%d", num);
}
}

void ImprimirFila(fila *f){
int num = 0;
printf("\nNumeros informados: ");
while(FilaVazia(f) == FALSO) {
num = Desenfileirar(f);
printf("\n%d", num);
}
}