#include <stdio.h>

int naturals(int n) {
    if (n <= 50) {
        printf(" %d", n);
        naturals(n+1);
    }
}

int main() {
    int n = 1;

    naturals(n);

    return 0;
}