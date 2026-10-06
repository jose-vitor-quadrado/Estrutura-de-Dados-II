#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nome[50];
    int qtd;
    float preco;
} produto;

void cadastrar(produto *p);
void mostrar(produto *p);

int main() {
    int qtd, adicionarMais = 0, op;
    printf("Digite quantos produtos quer cadastrar: ");
    scanf(" %d", &qtd);

    produto *p = (produto*) malloc(qtd * sizeof(produto));

    if (p == NULL) {
        printf("Falha na alocacao!\n");
        return 1;
    }

    for (int i = 0; i < qtd; i++) {
        cadastrar(&p[i]);
    }

    printf("Deseja cadastrar mais produtos(1 = sim/0 = nao)? ");
    scanf(" %d", &op);

    if (op) {
        printf("Digite quantos produtos quer cadastrar: ");
        scanf(" %d", &adicionarMais);

        p = (produto*) realloc(p, (qtd + adicionarMais) * sizeof(produto));

        if (p == NULL) {
            printf("Falha na alocacao!\n");
            return 1;
        }

        for (int i = qtd; i < qtd + adicionarMais; i++) {
            cadastrar(&p[i]);
        }
    }

    for (int i = 0; i < qtd + adicionarMais; i++) {
        mostrar(&p[i]);
    }

    free(p);
    return 0;
}

void cadastrar(produto *p) {
    printf("Cadastro de produto:\n");
    printf("Digite o codigo: ");
    scanf(" %d", &p->id);
    printf("Digite o nome: ");
    scanf(" %49[^\n]", p->nome); // gets(p->nome);
    printf("Digite a quantidade no estoque: ");
    scanf(" %d", &p->qtd);
    printf("Digite o valor do produto: ");
    scanf(" %f", &p->preco);
}

void mostrar(produto *p) {
    printf("Codigo: %d\n", p->id);
    printf("Nome: %s\n", p->nome);
    printf("Quantidade em Estoque: %d\n", p->qtd);
    printf("Preco: %.2f\n", p->preco);
}
