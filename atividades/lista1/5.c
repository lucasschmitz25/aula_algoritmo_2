#include <stdio.h>
#include <locale.h>
int main(void)
{

    float resto;
    int inteiro;

    printf("Intenger Value: \n");
    scanf("%i", &inteiro);

    resto = inteiro % 3;

    printf("%2.f\n", resto);

    return 0;
}
