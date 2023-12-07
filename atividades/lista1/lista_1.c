#include <stdio.h>
#include <locale.h>
// 1 )
/*int main(void)
{

    float totalSalary, netSalary, discount;

    printf("How much do you make? \n");
    scanf("%f", &totalSalary);

    discount = totalSalary * 0.10;

    netSalary = totalSalary - discount;

    printf("Your total salary is %2.f and your net salary is %2.f. \n", totalSalary, netSalary);

    return 0;

}*/
// 2 )
/*int main(void)
{

    float base, height, area;

    printf("Base Value: \n");
    scanf("%f", &base);

    printf("Height Value: \n");
    scanf("%f", &height);

    area = (base * height) / 2;

    printf("Your area is %2.f \n", area);

    return 0;
}*/

/*int main(void)
{

    float celcius, calc;

    printf("Celcius Value: \n");
    scanf("%f", &celcius);

    calc = 1.8 * celcius + 32;

    printf("Your temperature in Fahrenheit is %2.f \n", calc);

    return 0;
}*/
/*int main(void)
{

    float quociente;
    int inteiro;

    printf("Intenger Value: \n");
    scanf("%i", &inteiro);

    quociente = inteiro / 3;

    printf("%2.f\n", quociente);

    return 0;
}*/
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
