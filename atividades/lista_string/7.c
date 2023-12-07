#include <stdio.h>
#include <string.h>
int main()
{
    int j = 0;
    char palavra[501];
    char noSpace[501];

    printf("Digite uma palavra que tenha entre 1 e 501 caracteres: ");
    fgets(palavra, sizeof(palavra), stdin);

    for (int i = 0; palavra[i] != '\0'; i++)
    {
        if (palavra[i] != ' ' && palavra[i] != '\t' && palavra[i] != '\n')
        {
            noSpace[j] = palavra[i];
            j++;
        }
    }

    noSpace[j] = '\0';

    printf("Frase em branco: %s\n", noSpace);

    return 0;
}
