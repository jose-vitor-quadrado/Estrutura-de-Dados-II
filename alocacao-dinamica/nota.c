#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    float n1;
    float n2;
    float nt;
    float media;
    int status;
} aluno;

float media(float n1, float n2, float nt) {
    float p1 = ((n1 + n2) / 2) * 0.7;
    float p2 = nt * 0.3;
    return p1 + p2;
}

int main() {
    int qtA;
    printf("Digite a quantidade de alunos: ");
    scanf(" %d", &qtA);

    aluno *alunos = (aluno*) malloc(qtA * sizeof(aluno));
    if (alunos == NULL) {
        printf("Erro de alocacao!\n");
        exit(1);
    }

    for (int i = 0; i < qtA; i++) {
        printf("Digite o nome do aluno: ");
        scanf(" %50[^\n]", &alunos[i].nome);
        printf("Digite a nota 1: ");
        scanf(" %f", &alunos[i].n1);
        printf("Digite a nota 2: ");
        scanf(" %f", &alunos[i].n2);
        printf("Digite a nota do trabalho: ");
        scanf(" %f", &alunos[i].nt);
        alunos[i].media = media(alunos[i].n1, alunos[i].n2, alunos[i].nt);
        if (alunos[i].media < 7.0) alunos[i].status = 0;
        else alunos[i].status = 1;
    }

    printf("Aprovados:\n");
    for (int i = 0; i < qtA; i++) {
        if (alunos[i].status)
            printf(" Nome: %s\n Media: %.2f\n", alunos[i].nome, alunos[i].media);
    }

    printf("Reprovados:\n");
    for (int i = 0; i < qtA; i++) {
        if (!alunos[i].status) 
            printf(" Nome: %s\n Media: %.2f\n", alunos[i].nome, alunos[i].media);
    }

    free(alunos);
    return 0;
}