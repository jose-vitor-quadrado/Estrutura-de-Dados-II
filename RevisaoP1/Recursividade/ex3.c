#include <stdio.h>

float Pot(float t, int n) {
    if (n <= 0) {
        return 1;
    }
    return (1 + t) * Pot(t, n - 1);
}

float Exp(float x, float t, int n) {
    if (n <= 0) {
        return 0;
    }
    return x / Pot(t, n) + Exp(x, t, n - 1);
}

int main() {
    float x, t;
    int n;

    printf("Digite o valor de x: ");
    scanf(" %f", &x);
    printf("Digite o valor de t: ");
    scanf(" %f", &t);
    printf("Digite o valor de n: ");
    scanf(" %d", &n);

    printf("Resultado = %.2f\n", Exp(x, t, n));

    return 0;
}