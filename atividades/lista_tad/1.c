#include <stdio.h>
#include <string.h>

struct Aluno
{
    char nome[80];
    int cpf;
    int matricula;
    char email[100];
    char endereco[120];
    char telefone[20];
};

int main()
{

    struct Aluno alunos[10];

    for (int i = 0; i < 10; i++)
    {
        printf("Informe as informações do aluno %d:\n", i + 1);

        printf("Nome do Aluno: ");
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);

        printf("CPF do Aluno: ");
        scanf("%d", &alunos[i].cpf);

        printf("Matrícula do Aluno:: ");
        scanf("%d", &alunos[i].matricula);

        printf("E-mail do Aluno: ");
        scanf("%s", alunos[i].email);

        printf("Endereço do Aluno: ");
        scanf("%s", alunos[i].endereco);

        printf("Telefone: ");
        scanf("%s", alunos[i].telefone);

        while (getchar() != '\n')
            ; // Limpar o buffer de entrada
    }

    printf("Todos os dados armazenados:\n");
    for (int i = 0; i < 10; i++)
    {
        // imprimirDados(&alunos[i], i);
        printf("Informações do aluno %d:\n", i + 1);
        printf("Nome do Aluno: %s", alunos[i].nome);
        printf("CPF do Aluno: %d\n", alunos[i].cpf);
        printf("Matrícula do Aluno: %d\n", alunos[i].matricula);
        printf("E-mail do Aluno: %s\n", alunos[i].email);
        printf("Endereço do Aluno: %s\n", alunos[i].endereco);
        printf("Telefone do Aluno: %s\n", alunos[i].telefone);
        printf("\n");
    }

    return 0;
}
