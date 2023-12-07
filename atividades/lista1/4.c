#include <stdio.h>
#include <locale.h>
int main(void)
{

    float quociente;
    int inteiro;

    printf("Intenger Value: \n");
    scanf("%i", &inteiro);

    quociente = inteiro / 3;

    printf("%2.f\n", quociente);

    return 0;
}
