#include <stdio.h>
#include <locale.h>
int main() {
    int num1, num2, num3, maior;

    printf("Digite 3 numeros diferentes: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    maior = num1;

    if (num2 > maior) {
        maior = num2;
    } else if (num3 > maior) {
        maior = num3;
    }
            
    printf("O maior numero e: %i\n", maior);

    return 0;
}
