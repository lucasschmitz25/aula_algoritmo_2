#include <stdio.h>
#include <string.h>

void copiarInvertido(const char palavra[], char invertida[])
{
    int tamanho = strlen(palavra);

    // Inverte e copia a string
    for (int i = 0; i < tamanho; i++)
    {
        invertida[i] = palavra[tamanho - 1 - i];
    }

    // Adiciona o caractere nulo ao final
    invertida[tamanho] = '\0';
}

int main()
{

    char palavra[501];
    char palavra_invertida[501];

    printf("Digite uma palavra que tenha entre 1 e 501 caracteres: ");
    fgets(palavra, sizeof(palavra), stdin);

    copiarInvertido(palavra, palavra_invertida);

    printf("==================== \n");

    printf("Original: %s\n", palavra);
    printf("Invertida: %s\n", palavra_invertida);

    return 0;
}
