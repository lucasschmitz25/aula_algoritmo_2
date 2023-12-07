#include <stdio.h>
int main() {
    int i, resultado;
    for (i = 1; i <= 10; i++) {
        resultado = 5 * i;
        printf("5 x %d = %d\n", i, resultado);
    }
    return 0;
}
