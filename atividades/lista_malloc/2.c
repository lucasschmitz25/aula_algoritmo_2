#include <stdio.h>
#include <stdlib.h>

int *uniao(int *vetor1, int *vetor2, int tam1, int tam2)
{

    int *vetor3;

    vetor3 = (int *)malloc((tam1 + tam2) * sizeof(int));

    if (vetor3 == NULL)
    {
        printf("Erro ao alocar memória.\n");
        return 0;
    }

    // vetor1 para vetor3
    for (int i = 0; i < tam1; i++)
    {
        vetor3[i] = vetor1[i];
    }

    // vetor1 para vetor2
    for (int i = 0; i < tam2; i++)
    {
        vetor3[tam1 + i] = vetor2[i];
    }

    return vetor3;
}

int main()
{

    int tam1, tam2;
    int *vetor1;
    int *vetor2;
    int *vetor3;

    printf("Digite a quantidade do primeiro vetor: ");
    scanf("%d", &tam1);

    printf("Digite a quantidade do primeiro vetor: ");
    scanf("%d", &tam2);

    // Alocar dinamicamente
    vetor1 = (int *)malloc(tam1 * sizeof(int));
    vetor2 = (int *)malloc(tam2 * sizeof(int));

    if (vetor1 == NULL || vetor2 == NULL)
    {
        printf("Erro ao alocar memória.\n");
        free(vetor1);
        free(vetor2);
        return 1;
    }

    // Preencher o vetor
    printf("Digite os números do primeiro vetor:\n");
    for (int i = 0; i < tam1; i++)
    {
        printf("Número %d: ", i + 1);
        scanf("%d", &vetor1[i]);
    }

    printf("Digite os números do segundo vetor:\n");
    for (int i = 0; i < tam2; i++)
    {
        printf("Número %d: ", i + 1);
        scanf("%d", &vetor2[i]);
    }

    vetor3 = uniao(vetor1, vetor2, tam1, tam2);

    printf("União dos vetores\n");
    for (int i = 0; i < tam1 + tam2; i++)
    {
        printf("%d ", vetor3[i]);
    }

    printf("\n");

    free(vetor1);
    free(vetor2);
    free(vetor3);

    return 0;
}
