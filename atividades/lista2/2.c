#include <stdio.h>
#include <locale.h>
int main(void)
{

    float lado1, lado2, lado3;

    printf("Lado 1: \n");
    scanf("%f", &lado1);

    printf("Lado 2: \n");
    scanf("%f", &lado2);

    printf("Lado 3: \n");
    scanf("%f", &lado3);

    if (lado1 == lado2 && lado1 == lado3 && lado2 == lado3)
    {
        printf("Equilátero");
    }
    else if (lado1 == lado2 || lado2 == lado3 || lado1 == lado1 == lado3)
    {
        printf("Isósceles");
    }
    else
    {
        printf("Escaleno");
    }

    return 0;
}
