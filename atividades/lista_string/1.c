#include <stdio.h>
#include <string.h>
// 1)

int main()
{

    int tamanho = 0;
    char palavra[501];

    printf("Digite uma palavra que tenha entre 1 e 501 caracteres: ");
    fgets(palavra, sizeof(palavra), stdin);

    for (int i = 0; palavra[i] != '\0'; i++)
    {
        if (palavra[i] != '\n')
        {
            tamanho++;
        }
    }

    printf("O tamanho da string é: %d\n", tamanho);

    return 0;
}
