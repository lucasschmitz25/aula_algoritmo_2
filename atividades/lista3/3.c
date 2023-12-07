#include <stdio.h>
int main() {
    int totalPessoas, idade, i;
    int maioresIdade = 0;
    float mediaIdade = 0;

    printf("Quantas pessoas deseja informar a idade? ");
    scanf("%d", &totalPessoas);

    for (i = 0; i < totalPessoas; i++) {
        printf("Digite a idade da pessoa %d: ", i + 1);
        scanf("%d", &idade);

        if (idade >= 18) {
            maioresIdade++;
            mediaIdade += idade;
        }
    }

    if (maioresIdade > 0) {
        mediaIdade /= maioresIdade;
        printf("Maiores de idade: %d\n", mediaIdade);
        printf("Média de idade: %.2f\n", mediaIdade);
    } else {
        printf("Nenhuma pessoa maior de idade foi informada.\n");
    }

    return 0;
}
