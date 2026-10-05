#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SALTOS 4

typedef struct {
    int saltos[SALTOS];
    float media;
    float variancia;
    float desvioPadrao;
} atleta;

float potencia(float base, int expoente) {
    float resultado = 1.0;
    for (int i = 0; i < expoente; i++) {
        resultado *= base;
    }
    return resultado;
}

float media(atleta *a) {
    float sum;
    for (int i = 0; i < SALTOS; i++) {
        sum += a->saltos[i];
    }
    return sum / SALTOS;
}

float variancia(atleta *a) {
    return (
        potencia(a->saltos[0] - a->media, 2) + 
        potencia(a->saltos[1] - a->media, 2) +
        potencia(a->saltos[2] - a->media, 2) +
        potencia(a->saltos[3] - a->media, 2)
    ) / 4;
}

float desvioPadrao(atleta *a) {
    return sqrt(a->variancia);
}

int main() {
    int qtd;
    printf("Digite quantos atletas participaram: ");
    scanf(" %d", &qtd);

    atleta *a = (atleta*)malloc(qtd * sizeof(atleta));

    for (int i = 0; i < qtd; i++) {
        for (int j = 0; j < SALTOS; j++) {
            printf("Digite a distancia do salto numero %d (em Cm): ", j + 1);
            scanf(" %d", &a[i].saltos[j]);
        }
        a[i].media = media(a);
        a[i].variancia = variancia(a);
        a[i].desvioPadrao = desvioPadrao(a);
    }

    for (int i = 0; i < qtd; i++) {
        printf("Atleta %d:\n", i + 1);
        printf(
            " Media = %.2f\n Variancia = %.2f\n Desvio Padrao = %.2f\n", 
            a->media, a->variancia, a->desvioPadrao
        );
    }

    return 0;
}