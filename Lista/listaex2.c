#include <stdio.h>
#include <stdlib.h>

struct no {
    int info;
    struct no *prox;
};
typedef struct no LISTA;

LISTA *iniciar() {
    return NULL;
}

LISTA *insereInicio(LISTA *p, int num) {
    LISTA *novo;
    novo = (LISTA*)malloc(sizeof(LISTA));
    novo->info = num;
    novo->prox = p;
    p = novo;
    return p;
}

void pesquisar(LISTA *p, int num) {
    LISTA *aux = p;
    int achou = 0;
    while (aux != NULL) {
        if (aux->info == num) {
            achou = 1;
        }
        aux = aux->prox;
    }

    if (achou) {
        printf("O numero %d esta na lista!\n", num);
        return;
    }
    printf("Numero nao encontrado na lista!\n");
}

LISTA *insereFim(LISTA *p, int num) {
    LISTA *novo, *aux;
    novo = (LISTA*)malloc(sizeof(LISTA));
    novo->info = num;
    aux = p;
    
    while(aux->prox != NULL) {
        aux = aux->prox;
    }

    novo->prox = aux->prox;
    aux->prox = novo;
    return p;
}

void mostrarLista(LISTA *p) {
    LISTA *aux = p;
    while (aux != NULL) {
        printf(" %d", aux->info);
        aux = aux->prox;
    }
    printf("\n");
}

int main() {
    LISTA *p;
    int num, op = 1;
    p = iniciar();

    do {
        printf("Digite um valor inteiro para ser inserido na lista: ");
        scanf(" %d", &num);
        p = insereInicio(p, num);
        printf("Deseja adicionar algum novo numero a lista?(1/0): ");
        scanf(" %d", &op);
    } while (op != 0);

    printf("Qual numero deseja procurar na lista? ");
    scanf(" %d", &num);
    pesquisar(p, num);

    printf("Digite um numero a ser inserido no final da lista: ");
    scanf(" %d", &num);
    p = insereFim(p, num);
    mostrarLista(p);

    return 0;
}