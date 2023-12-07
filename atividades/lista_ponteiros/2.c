#include <stdio.h>
#include <stdlib.h>

int main() {
	int vet[5];
	int *ponteiro;

    printf("Digite 5 números inteiros:\n");

    // Leitura dos valores e armazenamento no vetor
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &vet[i]);
    }
    	
	ponteiro = vet;
	printf("O primeiro valor é %d\n", (*ponteiro) * 2);
	ponteiro++;
	printf("O segundo valor é %d\n", (*ponteiro) * 2);
	ponteiro++;
	printf("O terceiro valor é %d\n", (*ponteiro) * 2);
  ponteiro++;
  printf("O quarto valor é %d\n", (*ponteiro) * 2);
  ponteiro++;
  printf("O quinto valor é %d\n", (*ponteiro) * 2);
  ponteiro++;
	return 0;

}
