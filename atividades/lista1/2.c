#include <stdio.h>
#include <locale.h>
int main(void)
{

    float base, height, area;

    printf("Base Value: \n");
    scanf("%f", &base);

    printf("Height Value: \n");
    scanf("%f", &height);

    area = (base * height) / 2;

    printf("Your area is %2.f \n", area);

    return 0;
}
