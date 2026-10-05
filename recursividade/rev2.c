#include <stdio.h>

float power(float base, int exp) {
    if (exp <= 0) {
        return 1;
    }

    return base * power(base, exp - 1);
}

int main() {
    float x;
    int n;

    printf("Digite a base: ");
    scanf(" %f", &x);
    printf("Digite o expoente: ");
    scanf(" %d", &n);

    printf("Resultado = %.2f\n", power(x, n));

    return 0;
}