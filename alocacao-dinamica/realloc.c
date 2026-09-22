#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p;
    int tam, novoTam, num;

    printf("Quantos numeros inteiros deseja armazenar no vetor? ");
    scanf(" %d", &tam);

    // Este apenas aponta para a primeira posicao (preferencialmente usar este)
    p = (int*)malloc(tam * sizeof(int));

    // Este comeca com 0 nos espacos
    // p = (int*)calloc(tam, sizeof(int));

    for (int i = 0; i < tam; i++) {
        printf("Digite um numero inteiro: ");
        scanf(" %d", &p[i]);
    }

    printf("Deseja alterar o tamanho do vetor?\n");
    printf("(positivo para aumentar, 0 para manter, negativo para diminuir)\n");
    printf("--> ");
    scanf(" %d", &novoTam);

    if (tam + novoTam <= 0)
    {
        free(p);
        exit(1);
    }

    if (novoTam < 0) {
        for (int i = novoTam; i < 0; i++) {
            printf("Qual numero deseja retirar do vetor? ");
            scanf(" %d", &num);

            for (int j = 0; j < tam; j++) {
                if (p[j] != num) {
                    continue;
                }
                for (int k = j; k < tam; k++) {
                    p[k] = p[k + 1];
                }
                p = (int*)realloc(p, (tam - 1) * sizeof(int));
            }
        }
    }
    else
    {
        p = (int *)realloc(p, (tam + novoTam) * sizeof(int));

        for (int i = tam; i < (tam + novoTam); i++)
        {
            printf("Digite um numero inteiro: ");
            scanf(" %d", &p[i]);
        }
    }

    tam += novoTam;
    printf("Vetor pos realocacao!\n");
    for (int i = 0; i < tam; i++)
    {
        printf(" %d", p[i]);
    }
    printf("\n");

    free(p);

    return 0;
}