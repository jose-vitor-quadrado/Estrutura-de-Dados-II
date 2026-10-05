#include <stdio.h>

float sum(float vect[], int n) {
    if (n <= -1) {
        return 0;
    }
    return vect[n] + sum(vect, n - 1);
}

int main() {
    float vect[5] = {2.5, 2.5, 2.5, 2.5, 2.5};

    printf("Resultado = %.2f\n", sum(vect, 5));

    return 0;
}