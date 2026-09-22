#include <stdio.h>

int fib(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int pos;
    printf("Digite um numero: ");
    scanf(" %d", &pos);
    printf("Fib na pos %d = %d\n", pos, fib(pos));
    return 0;
}