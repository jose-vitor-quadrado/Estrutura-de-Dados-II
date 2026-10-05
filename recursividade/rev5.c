#include <stdio.h>

int inv(int n, int invertido) {
    if (n <= 0) {
        return invertido;
    }
    return inv(n / 10, invertido * 10 + n % 10);
}

int main() {
    int n;

    printf("Digite um valor: ");
    scanf(" %d", &n);

    printf("O numero %d sera mostrado como %d\n", n, inv(n, 0));

    return 0;
}