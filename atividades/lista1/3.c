#include <stdio.h>
#include <locale.h>
int main(void)
{

    float celcius, calc;

    printf("Celcius Value: \n");
    scanf("%f", &celcius);

    calc = 1.8 * celcius + 32;

    printf("Your temperature in Fahrenheit is %2.f \n", calc);

    return 0;
}
