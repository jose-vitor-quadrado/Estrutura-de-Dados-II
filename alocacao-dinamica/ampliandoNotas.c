#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[50];
    float intermediaria;
    float semestral;
    float trabalho;
    float media;
    int resultado;
} aluno;

void main()
{
    aluno *sala;
    int tam, novoTam;

    printf("Digite quantos alunos a sala possui: ");
    scanf(" %d", &tam);

    sala = (aluno *)malloc(tam * sizeof(aluno));

    for (int i = 0; i < tam; i++)
    {
        printf("Digite o nome do aluno: ");
        scanf(" %50[^\n]", &sala[i].nome);
        printf("Digite a nota da prova intermediaria: ");
        scanf(" %f", &sala[i].intermediaria);
        printf("Digite a nota da prova semestral: ");
        scanf(" %f", &sala[i].semestral);
        printf("Digite a nota da trabalho: ");
        scanf(" %f", &sala[i].trabalho);
        sala[i].media = ((sala[i].intermediaria + sala[i].semestral) * 2 + sala[i].trabalho) / 3;
        sala[i].resultado = (sala[i].media >= 7.0) ? 1 : 0;
    }

    printf("Houve aumento ou reducao de alunos?  ");
    scanf(" %d", &novoTam);

    if (tam + novoTam <= 0)
    {
        free(sala);
        exit(1);
    }

    if (novoTam > 0)
    {
        sala = (aluno *)realloc(sala, (tam + novoTam) * sizeof(aluno));

        for (int i = tam; i < (tam + novoTam); i++)
        {
            printf("Digite o nome do aluno: ");
            scanf(" %50[^\n]", &sala[i].nome);
            printf("Digite a nota da prova intermediaria: ");
            scanf(" %f", &sala[i].intermediaria);
            printf("Digite a nota da prova semestral: ");
            scanf(" %f", &sala[i].semestral);
            printf("Digite a nota da trabalho: ");
            scanf(" %f", &sala[i].trabalho);
            sala[i].media = ((sala[i].intermediaria + sala[i].semestral) * 2 + sala[i].trabalho) / 3;
            sala[i].resultado = (sala[i].media >= 7.0) ? 1 : 0;
        }
    }
    else
    {
        sala = (aluno *)realloc(sala, (tam + novoTam) * sizeof(aluno));
    }

    tam += novoTam;
    for (int i = 0; i < tam; i++)
    {
        printf("Nome: %s\nMedia: %.2f\nResultado: ", sala[i].nome, sala[i].media);
        if (sala[i].resultado)
        {
            printf("Aprovado\n");
        }
        else
        {
            printf("Reprovado\n");
        }
    }

    free(sala);
}
