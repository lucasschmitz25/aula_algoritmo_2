#include <stdio.h>
int main() {
    int i, valor;
    int maior, menor, soma = 0;
    float media;

    for (i = 1; i <= 20; i++) {
        printf("Digite o valor %d: ", i);
        scanf("%d", &valor);

        if (i == 1) {
            maior = 
            menor = valor;
        } else {
            if (valor > maior) {
                maior = valor;
            }
            if (valor < menor) {
                menor = valor;
            }
        }

        soma += valor;
    }

    media = soma / 20;

    printf("Maior valor: %d\n", maior);
    printf("Menor valor: %d\n", menor);
    printf("Média dos números: %.2f\n", media);

    return 0;
}
