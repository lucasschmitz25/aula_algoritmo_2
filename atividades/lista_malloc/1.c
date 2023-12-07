#include <stdio.h>
#include <stdlib.h>
int main()
{

    int quantAlunos;
    float *alunoNotas;
    float somaTotal = 0.0, media = 0.0;

    printf("Informe a quantidade de alunos que tem na turma: ");
    scanf("%d", &quantAlunos);

    alunoNotas = (float *)malloc(quantAlunos * sizeof(float));

    if (alunoNotas == NULL)
    {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    printf("Informe as notas dos alunos:\n");
    for (int i = 0; i < quantAlunos; i++)
    {
        printf("Nota do aluno %d: ", i + 1);
        scanf("%f", &alunoNotas[i]);
    }

    for (int i = 0; i < quantAlunos; i++)
    {
        somaTotal += alunoNotas[i];
    }

    media = somaTotal / quantAlunos;

    printf("Média: %.2f\n", media);

    free(alunoNotas);

    return 0; 

}
