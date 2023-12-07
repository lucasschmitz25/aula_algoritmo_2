#include <stdio.h>
#include <locale.h>
int main(void)
{

    float totalSalary, netSalary, discount;

    printf("How much do you make? \n");
    scanf("%f", &totalSalary);

    discount = totalSalary * 0.10;

    netSalary = totalSalary - discount;

    printf("Your total salary is %2.f and your net salary is %2.f. \n", totalSalary, netSalary);

    return 0;

}
