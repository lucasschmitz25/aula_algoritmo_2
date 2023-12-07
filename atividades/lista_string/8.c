#include <stdio.h>
#include <string.h>
int main()
{
    char palavra1[501], palavra2[501];
    char primeira, segunda;

    printf("Digite uma palavra 1 que tenha entre 1 e 501 caracteres: ");
    fgets(palavra1, sizeof(palavra1), stdin);

    printf("Digite uma palavra 2 que tenha entre 1 e 501 caracteres: ");
    fgets(palavra2, sizeof(palavra2), stdin);

    for (int i = 0; palavra1[i] != '\0'; i++)
    {

        if (i == 0)
        {
            primeira = palavra1[i];
        }
    }

    for (int i = 0; palavra2[i] != '\0'; i++)
    {

        if (i == 0)
        {
            segunda = palavra2[i];
        }
    }

    if (segunda > primeira) {
        printf("Palavra: %s\n", palavra1);
    } else {
        printf("Palavra: %s\n", palavra2);
    }

    return 0;

}
