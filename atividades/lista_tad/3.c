#include <stdio.h>
#include <string.h>

struct Dia
{
    int dia;
    int mes;
    int ano;
};

int validar(int verificacao, int inferior, int superior)
{
    return (verificacao < inferior || verificacao > superior);
}

int main()
{

    struct Dia dia;

    do
    {
        printf("Informe um dia: ");
        scanf("%d", &dia.dia);
    } while (validar(dia.dia, 0, 31));

    do
    {
        printf("Informe os mês: ");
        scanf("%d", &dia.mes);
    } while (validar(dia.mes, 0, 12));

    printf("Informe os ano: ");
    scanf("%d", &dia.ano);

    printf("Hora formatada: %02d/%02d/%04d\n", dia.dia, dia.mes, dia.ano);
}
