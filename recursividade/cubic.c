#include <stdio.h>

int sum(int n) {
    if (n <= 0) {
        return 0;
    }
    return (n * n * n) + sum(n - 1);
}

int main() {
    int n;
    printf("Digite um valor: ");
    scanf(" %d", &n);
    printf("A soma dos valores = %d\n", sum(n));
    return 0;
}