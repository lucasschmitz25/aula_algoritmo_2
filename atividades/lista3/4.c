    #include <stdio.h>
    int main() {
        int voto;
        int candidato1 = 0, candidato2 = 0, candidato3 = 0, candidato4 = 0;
        int nulo = 0, branco = 0;

        while (1) {
            printf("Digite o código do voto (1, 2, 3, 4, 5, 6, ou 0 para sair): ");
            scanf("%d", &voto);

            if (voto == 0) {
                break;
            }

            switch (voto) {
                case 1:
                    candidato1++;
                    break;
                case 2:
                    candidato2++;
                    break;
                case 3:
                    candidato3++;
                    break;
                case 4:
                    candidato4++;
                    break;
                case 5:
                    nulo++;
                    break;
                case 6:
                    branco++;
                    break;
                default:
                    printf("Código de voto inválido.\n");
            }
        }

        printf("Resultado da votação:\n");
        printf("Candidato 1: %d votos\n", candidato1);
        printf("Candidato 2: %d votos\n", candidato2);
        printf("Candidato 3: %d votos\n", candidato3);
        printf("Candidato 4: %d votos\n", candidato4);
        printf("Voto Nulo: %d votos\n", nulo);
        printf("Voto em Branco: %d votos\n", branco);

        printf("Encerrando a contagem de votos.\n");

        return 0;
    }
