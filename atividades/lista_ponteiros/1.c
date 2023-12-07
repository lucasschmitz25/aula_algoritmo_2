#include <stdio.h>
#include <stdlib.h>
int main()
{

    int inteiro;
    float real;
    char string = 'A';

    inteiro = 1;
    real = 1.12;

    int *ponteiro_inteiro;
    float *ponteiro_float;
    char *ponteiro_char;

    ponteiro_inteiro = &inteiro;
    ponteiro_float = &real;
    ponteiro_char = &string;

    printf("Antes: /n");
    printf("Inteiro: %d \n", inteiro);
    printf("Real: %.2f \n", real);
    printf("Char: %c \n", string);

    *ponteiro_inteiro = 20;
    *ponteiro_float = 10.7;
    *ponteiro_char = 'B';

    printf("\nDepois: \n");
    printf("Inteiro: %d \n", inteiro);
    printf("Real: %.2f \n", real);
    printf("Char: %c \n", string);

    return 0;

}
