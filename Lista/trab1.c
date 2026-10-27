#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct no {
    int id;
    char nome[50];
    int qtd;
    struct no *prox;
};
typedef struct no LISTA;

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

LISTA *iniciar() {
    return NULL;
}

LISTA *cadastrar(LISTA *p) {
    LISTA *novo = (LISTA*)malloc(sizeof(LISTA));
    if (novo == NULL) {
        printf("Erro ao alocar memoria!\n");
        return p;
    }

    printf("==== Cadastro de produtos ====\n");
    printf("Digite o codigo: ");
    scanf(" %d", &novo->id);
    limparBuffer();
    printf("Digite o nome: ");
    fgets(novo->nome, 50, stdin);
    printf("Digite a quantidade: ");
    scanf(" %d", &novo->qtd);
    limparBuffer();
    novo->prox = NULL;
    printf("\nProduto cadastrado com sucesso!\n");

    if (p == NULL) {
        return novo;
    }

    LISTA *aux = p;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    aux->prox = novo;

    return p;
}

void buscar(LISTA *p) {
    if (p == NULL) {
        printf("A lista esta vazia!\n");
        return;
    }

    int id;
    printf("Digite o codigo do produto a ser buscado: ");
    scanf("%d", &id);
    limparBuffer();

    LISTA *aux = p;
    while (aux != NULL) {
        if (aux->id == id) {
            printf("O produto com o codigo %d foi encontrado!\n", aux->id);
            printf("Nome: %sQuantidade: %d\n", aux->nome, aux->qtd);
            return;
        }
        aux = aux->prox;
    }

    printf("Produto nao encontrado!\n");
}

void listarProdutos(LISTA *p) {
    LISTA *aux = p;

    printf("========= Produtos =========\n");
    while (aux != NULL) {
        printf(" Codigo: %d\n", aux->id);
        printf(" Nome: %s", aux->nome);
        printf(" Quantidade: %d\n", aux->qtd);
        printf("----------------------------\n");
        aux = aux->prox;
    }
}

void liberarLista(LISTA *p) {
    LISTA *aux;
    while (p != NULL) {
        aux = p;
        p = p->prox;
        free(aux);
    }
}

int main() {
    LISTA *p = iniciar();
    int op = 1;

    do {
        printf("============ MENU =============\n");
        printf(" 1 - Cadastrar produto:\n");
        printf(" 2 - Buscar um produto:\n");
        printf(" 3 - Listar todos os produtos:\n");
        printf(" 0 - Sair do programa:\n");
        printf("--> ");
        scanf(" %d", &op);

        switch (op) {
            case 1:
                p = cadastrar(p);
                break;
            case 2:
                buscar(p);
                break;
            case 3:
                listarProdutos(p);
                break;
            case 0:
                printf("Encerrando...\n");
                break;
            default:
                printf("Valor invalido!\n");
                op = 9;
                break;
        }
    } while (op != 0);

    liberarLista(p);

    return 0;
}