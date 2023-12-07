#include <stdio.h>
#include <locale.h>
int main(void) {
    int idade;

    printf("Idade: ");
    scanf("%i", &idade);

    if (idade >= 18)
        printf("Maior de idade.\n");
    else
        printf("Menor de idade.\n");

    return 0;
}
