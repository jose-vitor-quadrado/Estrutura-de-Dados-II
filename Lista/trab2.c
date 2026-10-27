#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct no {
    int id;
    char titulo[50];
    char nome[50];
    struct no *prox;
};
typedef struct no LISTA;

