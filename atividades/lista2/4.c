#include <stdio.h>
#include <locale.h>
int main(void) {
    int valor, nota50, nota10, nota1;

    printf("Digite o valor do saque: ");
    scanf("%i", &valor);

    nota50 = valor / 50;
    valor = valor % 50;

    nota10 = valor / 10;
    valor = valor % 10;

    nota1 = valor;

    printf("50: %i\n", nota50);
    printf("10: %i\n", nota10);
    printf("1: %i\n", nota1);

    return 0;
}
