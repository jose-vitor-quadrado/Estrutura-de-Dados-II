#include <stdio.h>

int mdc(int a, int b) {
    if (b == 0) return a;
    return mdc(b, a % b);
}

int main() {
    printf("%d\n", mdc(27, 4));

    return 0;
}