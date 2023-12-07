#include <stdio.h>
#include <string.h>
int main()
{

    int tamanho = 0;
    char palavra[501];

    printf("Digite uma palavra que tenha entre 1 e 501 caracteres:");
    fgets(palavra, sizeof(palavra), stdin);

    for (int i = 0; palavra[i] != '\0'; i++)
    {
        char c = palavra[i];
        if (palavra[i] != '\n')
        {

            if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            {
                tamanho++;
            }
        }
    }

    printf("A quantidade de vogais: %d\n", tamanho);

    return 0;
}
