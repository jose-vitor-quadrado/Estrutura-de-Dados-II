#include <stdio.h>
#include <stdlib.h>

void vetor(int *v) {
    free(v);
}

int main() {
    int *arr;
    int n = 5;
    arr = (int*) malloc(5 * sizeof(int));
    if (arr == NULL) {
        printf("Erro de alocacao\n");
        return 1;
    }
    for (int i = 0; i < 5; i++) {
        arr[i] = 0;
    }
    arr = (int*) realloc(arr, (n + 3) * sizeof(int));
    if (arr == NULL) {
        printf("Erro de alocacao\n");
        return 1;
    }
    for (int i = 0; i < n + 3; i++) {
        arr[i] = i*2;
    }
    vetor(arr);

    return 0;
}