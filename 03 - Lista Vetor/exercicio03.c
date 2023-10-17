#include <stdio.h>
#include <string.h>

// Defina o tamanho máximo da lista (pode ser alterado conforme necessário).
#define TAM 10

typedef struct {
    char cpf[12];
    char nome[50];
    char endereco[100];
    char telefone[15];
    char celular[15];
    char dataNascimento[11];
    char dataAdmissao[11];
    char departamento[50];
    char cargo[50];
    float salario;
} Funcionario;

struct tipo_lista {
    Funcionario vet[TAM];
    int inicio, fim;
};

typedef struct tipo_lista lista;

void CriarLista(lista *l) {
    (*l).inicio = -1;
    (*l).fim = -1;
}

int ListaVazia(lista *l) {
    return ((*l).inicio == -1);
}

int ListaCheia(lista *l) {
    return ((*l).fim == (TAM - 1));
}

void Alistar(lista *l, Funcionario f) {
    if (ListaCheia(l))
        printf("\n ERRO: lista cheia!");
    else {
        if (ListaVazia(l))
            (*l).inicio = 0;
        (*l).fim++;
        (*l).vet[(*l).fim] = f;
    }
}

Funcionario Desalistar(lista *l, int pos) {
    int i;
    Funcionario f;
    if (ListaVazia(l))
        printf("\n ERRO: lista vazia!");
    else if ((pos < (*l).inicio) || (pos > (*l).fim)) {
        printf("\n ERRO: posição não existe!");
        printf("\n Posicoes válidas: [%d, %d].", (*l).inicio, (*l).fim);
    } else {
        f = (*l).vet[pos];
        for (i = pos; i < ((*l).fim); i++)
            (*l).vet[i] = (*l).vet[i + 1];
        (*l).fim--;
        if ((*l).inicio == (*l).fim) {
            (*l).inicio = -1;
            (*l).fim = -1;
        }
    }
    return f;
}

void ImprimeLista(lista *l) {
    int i;
    if (ListaVazia(l))
        printf("Lista vazia\n");
    else {
        printf("Conteúdo da lista:\n");
        for (i = (*l).inicio; i <= (*l).fim; i++) {
            printf("Funcionário %d:\n", i);
            printf("CPF: %s\n", (*l).vet[i].cpf);
            printf("Nome: %s\n", (*l).vet[i].nome);
            printf("Endereço: %s\n", (*l).vet[i].endereco);
            printf("Telefone: %s\n", (*l).vet[i].telefone);
            printf("Celular: %s\n", (*l).vet[i].celular);
            printf("Data de Nascimento: %s\n", (*l).vet[i].dataNascimento);
            printf("Data de Admissão: %s\n", (*l).vet[i].dataAdmissao);
            printf("Departamento: %s\n", (*l).vet[i].departamento);
            printf("Cargo: %s\n", (*l).vet[i].cargo);
            printf("Salário: %.2f\n", (*l).vet[i].salario);
            printf("\n");
        }
    }
}

void GravarEmArquivo(lista *l, const char *nomeArquivo) {
    FILE *arquivo;
    arquivo = fopen(nomeArquivo, "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita\n");
        return;
    }

    if (!ListaVazia(l)) {
        for (int i = (*l).inicio; i <= (*l).fim; i++) {
            fwrite(&(*l).vet[i], sizeof(Funcionario), 1, arquivo);
        }
    }

    fclose(arquivo);
}

void LerDoArquivo(lista *l, const char *nomeArquivo) {
    FILE *arquivo;
    arquivo = fopen(nomeArquivo, "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura\n");
        return;
    }

    Funcionario f;
    while (fread(&f, sizeof(Funcionario), 1, arquivo) == 1) {
        Alistar(l, f);
    }

    fclose(arquivo);
}

int PesquisarFuncionarioPorCPF(lista *l, const char *cpf) {
    if (ListaVazia(l)) {
        printf("Lista vazia. Nenhum funcionário para pesquisar.\n");
        return -1;
    }

    for (int i = (*l).inicio; i <= (*l).fim; i++) {
        if (strcmp((*l).vet[i].cpf, cpf) == 0) {
            return i;
        }
    }

    printf("Funcionário com CPF %s não encontrado.\n", cpf);
    return -1;
}

int main() {
    lista minhaLista;
    CriarLista(&minhaLista);

    // Leitura de 10 registros de funcionários a partir do teclado
    printf("Digite 10 registros de funcionários:\n");
    for (int i = 0; i < 10; i++) {
        Funcionario novoFuncionario;
        printf("Funcionário %d:\n", i + 1);
        printf("CPF: ");
        scanf("%s", novoFuncionario.cpf);
        printf("Nome: ");
        scanf("%s", novoFuncionario.nome);
        printf("Endereço: ");
        scanf("%s", novoFuncionario.endereco);
        printf("Telefone: ");
        scanf("%s", novoFuncionario.telefone);
        printf("Celular: ");
        scanf("%s", novoFuncionario.celular);
        printf("Data de Nascimento (dd/mm/aaaa): ");
        scanf("%s", novoFuncionario.dataNascimento);
        printf("Data de Admissão (dd/mm/aaaa): ");
        scanf("%s", novoFuncionario.dataAdmissao);
        printf("Departamento: ");
        scanf("%s", novoFuncionario.departamento);
        printf("Cargo: ");
        scanf("%s", novoFuncionario.cargo);
        printf("Salário: ");
        scanf("%f", &novoFuncionario.salario);

        Alistar(&minhaLista, novoFuncionario);
    }

    // Imprime o conteúdo da lista
    ImprimeLista(&minhaLista);

    // Grava os registros de funcionários em um arquivo binário
    GravarEmArquivo(&minhaLista, "funcionarios.dat");

    // Limpa a lista
    CriarLista(&minhaLista);

    // Lê os registros de funcionários do arquivo binário
    LerDoArquivo(&minhaLista, "funcionarios.dat");

    // Imprime o conteúdo da lista após ler do arquivo
    ImprimeLista(&minhaLista);

    // Pesquisa um funcionário por CPF
    char cpfPesquisa[12];
    printf("Digite o CPF a ser pesquisado: ");
    scanf("%s", cpfPesquisa);

    int pos = PesquisarFuncionarioPorCPF(&minhaLista, cpfPesquisa);

    if (pos != -1) {
        printf("Funcionário encontrado na posição %d:\n", pos);
        ImprimeLista(&minhaLista);
    }

    return 0;
}
