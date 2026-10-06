#include <stdio.h>

int calcular(int n) {
    if (n == 0) return 2;
    return 2 * calcular(n - 1) + n;
}

int main() {
    printf("%d\n", calcular(4));

    return 0;
}