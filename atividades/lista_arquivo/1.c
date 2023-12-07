#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *numeros;

    FILE *arquivo = fopen("arquivo.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int inicial = 10; // Capacidade inicial do vetor
    numeros = (int *)malloc(inicial * sizeof(int));

    if (numeros == NULL)
    {
        printf("Erro ao alocar memória.\n");
        fclose(arquivo);
        return 1;
    }

    int tamanhoArquivo = 0;

    while (fscanf(arquivo, "%d", &numeros[tamanhoArquivo]) == 1)
    {
        int *temporario;
        tamanhoArquivo++;

        // Realocando mais espaço
        if (tamanhoArquivo == inicial)
        {
            inicial *= 2;
            temporario = (int *)realloc(numeros, inicial * sizeof(int));

            if (temporario == NULL)
            {
                printf("Erro ao realocar memória.\n");
                free(numeros);
                fclose(arquivo);
                return 1;
            }

            numeros = temporario;
        }
    }

    fclose(arquivo);

    // pega ao contrario da quantidade do array
    // i-- = decremento, ou seja, vai até o ultimo dado dentro do array
    for (int i = tamanhoArquivo - 1; i >= 0; i--) 
    {
        printf("%d\n", numeros[i]);
    }

    free(numeros);

    return 0;
}
