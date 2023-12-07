#include <stdio.h>
#include <locale.h>
int main(void)
{
    float emprestimo, parcelas, salario, valorParcelas, calc30, calculoSalario;

    printf("Digite o valor do emprestimo: ");
    scanf("%f", &emprestimo);

    printf("Digite numero de parcelas: ");
    scanf("%f", &parcelas);

    printf("Digite numero de salario: ");
    scanf("%f", &salario);

    valorParcelas = emprestimo / parcelas;
    calc30 = (salario * 0.30);
    calculoSalario = salario - calc30;

    if ( calculoSalario > valorParcelas ) {
        printf("Emprestimo aprovado! \n");
    } else {
        printf("Emprestimo reprovado! \n");
    }

    return 0;
}
