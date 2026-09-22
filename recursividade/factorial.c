#include <stdio.h>

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int n;
    printf("Digite um numero: ");
    scanf(" %d", &n);   
    if (n < 0) {
        printf("Valor invalido!\n");
        return 0;
    }
    printf("%d! = %d\n", n, factorial(n));
    return 0;
}