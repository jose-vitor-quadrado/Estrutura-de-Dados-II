#include <stdio.h>

int digits(int n) {
    if (n <= 0) {
        return 0;
    }
    return 1 + digits(n / 10);
}

int main() {
    int n;

    printf("Digite um numero: ");
    scanf(" %d", &n);

    printf("O numero %d possui %d digitos\n", n, digits(n));

    return 0;
}