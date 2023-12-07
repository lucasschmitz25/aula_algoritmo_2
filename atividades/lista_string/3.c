#include <stdio.h>
#include <string.h>
int main()
{

    int tamanho = 0;
    char palavra[501];
    char caractere;

    printf("Digite uma palavra que tenha entre 1 e 501 caracteres: ");
    fgets(palavra, sizeof(palavra), stdin);

    printf("Digite um caractere: ");
    scanf(" %c", &caractere); // Utilizando " %c" para ignorar espaços em branco (VI no GOOGLE)

    for (int i = 0; palavra[i] != '\0'; i++)
    {
        if (palavra[i] != '\n')
        {

            if (palavra[i] == caractere)
            {
                tamanho++;
            }
        }
    }

    printf("Numero de caracteres: %d\n", tamanho);

    return 0;
}
