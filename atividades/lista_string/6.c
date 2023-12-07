#include <stdio.h>
#include <string.h>
int main()
{

    char palavra[31];

    printf("Digite uma palavra que tenha entre 1 e 31 caracteres: ");
    fgets(palavra, sizeof(palavra), stdin);

    for (int i = 0; palavra[i] != '\0'; i++)
    {
        if (palavra[i] >= 'A' && palavra[i] >= 'Z') {
            palavra[i] = palavra[i] - 32; // 65 até 90 menos 32 vai trazer a letra em maiusculo
        }
    }

    printf("Palavra em maiúscula: %s\n", palavra);

    return 0;
}
