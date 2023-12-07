#include <stdio.h>
#include <locale.h>
float calcGrauA (float nota1, float nota2, float nota3, float nota4) {
    return ( ( nota1 + nota2 + nota3 + nota4 ) / 4 );
}
int main(void)
{
    float nota1, nota2, nota3, nota4, media;

    printf("Nota 1: \n");
    scanf("%f", &nota1);

    printf("Nota 2: \n");
    scanf("%f", &nota2);

    printf("Nota 3: \n");
    scanf("%f", &nota3);

    printf("Nota 4: \n");
    scanf("%f", &nota4);

    media = calcGrauA(nota1, nota2, nota3, nota4);
    printf("Sua média foi de %2.f. \n", &media);

    if (media >= 7) {
        printf("Você está aprovado");
    } else {
       printf("Você está reprovado");
    }

    return 0;

}
