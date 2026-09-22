#include <stdio.h>

float power(float n, int pow) {
    if (pow == 1) return n;
    return n * power(n, pow - 1);
}

int main() {
    int pow;
    float val;
    printf("Digite o valor a ser elevado: ");
    scanf(" %f", &val);
    printf("Digite o numero que vai elevar %.2f: ", val);
    scanf(" %d", &pow);
    printf("%.2f elevado a %d = %.2f\n", val, pow, power(val, pow));

    return 0;
}