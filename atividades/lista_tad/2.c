#include <stdio.h>
#include <string.h>

struct Hora
{
    int hora;
    int minuto;
    int segundo;
};

int main()
{

    struct Hora hora;

    do
    {
        printf("Informe a hora: ");
        scanf("%d", &hora.hora);
    } while (hora.hora < 0 || hora.hora > 24);

    do
    {
        printf("Informe os minutos: ");
        scanf("%d", &hora.minuto);
    } while (hora.minuto < 0 || hora.minuto > 59);

    do
    {
        printf("Informe os segundos: ");
        scanf("%d", &hora.segundo);
    } while (hora.segundo < 0 || hora.segundo > 59);

    printf("Hora formatada: %d:%d:%d\n", hora.hora, hora.minuto, hora.segundo);

    return 0;
}
