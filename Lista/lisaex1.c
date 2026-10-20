#include <stdio.h>
#include <stdlib.h>

struct no {
    int info;
    struct no *prox;
};
typedef struct no LISTA;


LISTA *iniciaLista() {
    return NULL;
}

LISTA *adicionar(LISTA *p, int num) {
    LISTA *novo;
    novo = (LISTA*)malloc(sizeof(LISTA));
    novo->info = num;
    novo->prox = p;
    p = novo;
    return p;
}

int contador(LISTA *p) {
    LISTA *aux;
    aux = p;
    int count = 0;
    while (aux != NULL) {
        count++;
        aux = aux->prox;
    }
    return count;
}

int soma(LISTA *p) {
    LISTA *aux;
    aux = p;
    int soma = 0;
    while (aux != NULL) {
        soma += aux->info;
        aux = aux->prox;
    }
    return soma;
}

int main() {
    LISTA *p;
    int op, num;

    p = iniciaLista();

    do {
        printf("Entre com um numero inteiro: ");
        scanf(" %d", &num);
        p = adicionar(p, num);
        printf("Quer adicionar mais?(1/0) ");
        scanf(" %d", &op);
    } while (op == 1);

    printf("Numero de elementos da lista: %d\n", contador(p));
    printf("Soma dos elementos da lista: %d\n", soma(p));

    return 0;
}