#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Declarando estrutura global
struct Produto
{
    int codigo;
    char nome[50];
    int quantidade;
    float valorUnitario;
};

void limparEstrutura(struct Produto *produto)
{
    memset(produto, 0, sizeof(struct Produto));
}

void criarProduto()
{
    system("clear");

    // Declarando variaveis locais
    char retorno;

    char separador = ';';

    // Declarando novo produto
    struct Produto produto;

    printf("|---------------------------------|\n");
    printf("|---------------------------------|\n");
    printf("|                                 |\n");
    printf("|       CADASTRO DE PRODUTO       |\n");
    printf("|                                 |\n");
    printf("|---------------------------------|\n");
    printf("|---------------------------------|\n\n");

    // Codigo do produto
    printf("Insira o Código do produto: ");
    scanf("%d", &produto.codigo);

    // Nome do Produto
    printf("Insira o Nome do Produto: ");
    while (getchar() != '\n')
        ;
    fgets(produto.nome, sizeof(produto.nome), stdin);
    produto.nome[strlen(produto.nome) - 1] = 0;

    // Quantidade do produto
    printf("Insira a Quantidade do Produto: ");
    scanf("%d", &produto.quantidade);

    // Valor unitário
    printf("Insira um Valor unitário: ");
    scanf("%f", &produto.valorUnitario);

    FILE *arquivoProdutos = fopen("produtos.csv", "a+");
    if (arquivoProdutos == NULL)
    {
        printf("Erro ao abrir os arquivos.\n");
        return;
    }

    do
    {

        printf("\nDeseja criar esse Produto? s / n \n");

        while (getchar() != '\n')
            ;

        scanf("%c", &retorno);
        retorno = tolower(retorno);

        switch (retorno)
        {
        case 's':

            fprintf(arquivoProdutos, "%d%c%s%c%d%c%f\n", produto.codigo, separador, produto.nome, separador, produto.quantidade, separador, produto.valorUnitario);

            fclose(arquivoProdutos);

            system("clear");

            printf("|---------------------------------|\n");
            printf("|       PRODUTO CADASTRADO!       |\n");
            printf("|---------------------------------|\n\n");
            break;
        case 'n':
            printf("|---------------------------------|\n");
            printf("|     PRODUTO NÃO CADASTRADO!     |\n");
            printf("|---------------------------------|\n\n");
            limparEstrutura(&produto);
            break;
        default:

            printf("|---------------------------------|\n");
            printf("|          OPÇÃO INVÁLIDA.        |\n");
            printf("|   TENTE NOVAMENTE, POR FAVOR!   |\n");
            printf("|---------------------------------|\n\n");
        }

    } while (retorno != 's' && retorno != 'n');
}

void editarProduto()
{
    system("clear");

    printf("|---------------------------------|\n");
    printf("|---------------------------------|\n");
    printf("|                                 |\n");
    printf("|    ATUALIZAR DADOS DO PRODUTO   |\n");
    printf("|                                 |\n");
    printf("|---------------------------------|\n");
    printf("|---------------------------------|\n\n");

    int codigo;
    printf("Qual o código do produto que você deseja atualizar?\n");
    printf("Código: ");
    scanf("%d", &codigo);

    FILE *arquivoLeitura = fopen("produtos.csv", "r");
    FILE *arquivoTemporario = fopen("temporario.csv", "w"); // W = Cria o arquivo se ele não existir

    if (arquivoLeitura == NULL || arquivoTemporario == NULL)
    {
        printf("Erro ao abrir os arquivos.\n");
        return;
    }

    char linha[500], retorno, separador = ';';
    int codigoEncontrado = 0;

    // Desconsiderando cabeçalho
    if (fgets(linha, sizeof(linha), arquivoLeitura) == NULL)
    {
        printf("Erro ao ler o cabeçalho do arquivo.\n");
        fclose(arquivoLeitura);
        return;
    }
    else
    {
        fprintf(arquivoTemporario, "%s%c%s%c%s%c%s\n", "codigo", separador, "nome", separador, "quantidade", separador, "valor_unitario");
    }

    // Leitura do arquivo até encontrar o código
    // Caso ele seja encontrado, tiramos ele do arquivo temporario
    while (fgets(linha, sizeof(linha), arquivoLeitura) != NULL)
    {
        char *token;
        char linhaNaoAtualizar[500];

        strcpy(linhaNaoAtualizar, linha);

        // Token
        token = strtok(linha, ";");

        // Codigo em INT
        int codigoLinha = atoi(token);

        if (codigoLinha != codigo)
        {
            fprintf(arquivoTemporario, "%s", linhaNaoAtualizar);
        }
        else
        {
            codigoEncontrado = 1;
            struct Produto produto;

            // mesma coisa que scanf, mas lê string
            // %49[^;] --> expressão: leia até 49 caracteres ou até encontrar um ponto e vírgula
            sscanf(linhaNaoAtualizar, "%d;%50[^;];%d;%f", &produto.codigo, produto.nome, &produto.quantidade, &produto.valorUnitario);

            printf("\n");
            printf("|---------------------------------|\n");
            printf("|           DADOS ATUAIS          |\n");
            printf("|---------------------------------|\n");
            printf("Código: %d\n", produto.codigo);
            printf("Nome: %s\n", produto.nome);
            printf("Quantidade: %d\n", produto.quantidade);
            printf("Valor Unitário: %.2f\n\n", produto.valorUnitario);

            // Nome
            printf("Insira um Novo Nome: ");
            while (getchar() != '\n')
                ;
            fgets(produto.nome, sizeof(produto.nome), stdin);
            produto.nome[strlen(produto.nome) - 1] = '\0';

            // Quantidade
            printf("Insira uma Nova Quantidade: ");
            scanf("%d", &produto.quantidade);

            // Valor Unitário
            printf("Insira um novo Novo Valor Unitário: ");
            scanf("%f", &produto.valorUnitario);

            // Inserindo dados no arquivo temporario
            fprintf(arquivoTemporario, "%d%c%s%c%d%c%f\n", produto.codigo, separador, produto.nome, separador, produto.quantidade, separador, produto.valorUnitario);
        }
    }

    fclose(arquivoLeitura);
    fclose(arquivoTemporario);

    if (codigoEncontrado == 0)
    {

        printf("|---------------------------------|\n");
        printf("|       CÓDIGO NÃO ENCONTRADO     |\n");
        printf("|    FAVOR REINICIAR O PROCESSO!  |\n");
        printf("|---------------------------------|\n\n");

        remove("temporario.csv");
        return;
    }
    else
    {
        do
        {

            printf("\nDeseja atualizar esse Produto? s / n \n");

            while (getchar() != '\n')
                ;

            scanf("%c", &retorno);
            retorno = tolower(retorno);

            switch (retorno)
            {
            case 's':

                // Remove o arquivo original e renomeia o temporário
                remove("produtos.csv");
                rename("temporario.csv", "produtos.csv");
                system("clear");
                printf("|---------------------------------|\n");
                printf("|         DADOS ATUALIZADOS!      |\n");
                printf("|---------------------------------|\n\n");
                break;
            case 'n':
                remove("temporario.csv");
                system("clear");
                printf("|---------------------------------|\n");
                printf("|      PRODUTO NÃO ATUALIZADO!    |\n");
                printf("|    FAVOR REINICIAR O PROCESSO!  |\n");
                printf("|---------------------------------|\n\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
            }

        } while (retorno != 's' && retorno != 'n');
    }
}

void excluirProduto()
{
    system("clear");

    printf("|---------------------------------|\n");
    printf("|---------------------------------|\n");
    printf("|                                 |\n");
    printf("|        DELETAR PRODUTO          |\n");
    printf("|                                 |\n");
    printf("|---------------------------------|\n");
    printf("|---------------------------------|\n\n");

    int codigo;
    printf("Qual o código do produto você deseja deletar?\n");
    printf("Código: ");
    scanf("%d", &codigo);

    FILE *arquivoLeitura = fopen("produtos.csv", "r");
    FILE *arquivoTemporario = fopen("temporario.csv", "w"); // W = Cria o arquivo se ele não existir

    if (arquivoLeitura == NULL || arquivoTemporario == NULL)
    {
        printf("Erro ao abrir os arquivos.\n");
        return;
    }

    char linha[500], retorno, separador = ';';
    int codigoEncontrado = 0;

    // Desconsiderando cabeçalho
    if (fgets(linha, sizeof(linha), arquivoLeitura) == NULL)
    {
        printf("Erro ao ler o cabeçalho do arquivo.\n\n");
        fclose(arquivoLeitura);
        return;
    }
    else
    {
        fprintf(arquivoTemporario, "%s%c%s%c%s%c%s\n", "codigo", separador, "nome", separador, "quantidade", separador, "valor_unitario");
    }

    // Leitura do arquivo até encontrar o código
    // Caso ele seja encontrado, tiramos ele do arquivo temporario
    while (fgets(linha, sizeof(linha), arquivoLeitura) != NULL)
    {
        char *token;
        char linhaNaoDeletar[500];

        strcpy(linhaNaoDeletar, linha);

        // Token
        token = strtok(linha, ";");

        // Codigo em INT
        int codigoLinha = atoi(token);

        if (codigoLinha != codigo)
        {
            fprintf(arquivoTemporario, "%s", linhaNaoDeletar);
        }
        else
        {
            codigoEncontrado = 1;
        }
    }

    fclose(arquivoLeitura);
    fclose(arquivoTemporario);

    if (codigoEncontrado == 0)
    {
        printf("|---------------------------------|\n");
        printf("|       CÓDIGO NÃO ENCONTRADO     |\n");
        printf("|    FAVOR REINICIAR O PROCESSO!  |\n");
        printf("|---------------------------------|\n\n");

        remove("temporario.csv");
        return;
    }
    else
    {
        do
        {

            printf("\nDeseja deletar esse Produto? s / n \n");

            while (getchar() != '\n')
                ;

            scanf("%c", &retorno);
            retorno = tolower(retorno);

            switch (retorno)
            {
            case 's':

                // Remove o arquivo original e renomeia o temporário
                remove("produtos.csv");
                rename("temporario.csv", "produtos.csv");
                system("clear");
                printf("|---------------------------------|\n");
                printf("|        PRODUTO DELETADO!        |\n");
                printf("|---------------------------------|\n\n");
                break;
            case 'n':
                remove("temporario.csv");
                system("clear");
                printf("|---------------------------------|\n");
                printf("|       PRODUTO NÃO DELETADO!     |\n");
                printf("|    FAVOR REINICIAR O PROCESSO!  |\n");
                printf("|---------------------------------|\n\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
            }

        } while (retorno != 's' && retorno != 'n');
    }
}

void listarProduto()
{
    system("clear");

    printf("|---------------------------------|\n");
    printf("|---------------------------------|\n");
    printf("|                                 |\n");
    printf("|         LISTAR PRODUTO          |\n");
    printf("|                                 |\n");
    printf("|---------------------------------|\n");
    printf("|---------------------------------|\n\n");

    // Abrindo arquivo em função de leitura
    FILE *arquivoLeitura = fopen("produtos.csv", "r");

    if (arquivoLeitura == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Array de produtos de maneira dinamica
    struct Produto *produtos = malloc(sizeof(struct Produto) * 500);

    if (produtos == NULL)
    {
        printf("Erro ao alocar memória para produtos.\n");
        fclose(arquivoLeitura);
        return;
    }

    char linha[500];
    int iLinha = 0;

    // Desconsiderando cabeçalho
    if (fgets(linha, sizeof(linha), arquivoLeitura) == NULL)
    {
        printf("Erro ao ler o cabeçalho do arquivo.\n\n");
        fclose(arquivoLeitura);
        free(produtos);
        return;
    }

    // Recuperando os produtos, e colocando dentro de uma estrutura
    while (fgets(linha, sizeof(linha), arquivoLeitura) != NULL)
    {
        int i = 0;
        float valorUnitario;
        int codigo, quantidade;
        char *token;

        token = strtok(linha, ";");

        while (token)
        {
            i++;

            if (i == 1)
            {
                codigo = atoi(token);
                produtos[iLinha].codigo = codigo;
            }
            else if (i == 2)
            {
                strcpy(produtos[iLinha].nome, token);
            }
            else if (i == 3)
            {
                quantidade = atoi(token);
                produtos[iLinha].quantidade = quantidade;
            }
            else if (i == 4)
            {
                valorUnitario = atof(token);
                produtos[iLinha].valorUnitario = valorUnitario;
            }

            token = strtok(NULL, ";");
        }

        iLinha++;
    }

    // Cabeçalho
    printf("| %-6s | %-30s | %-10s | %-16s |\n", "Código", "Nome", "Quantidade", "Valor Unitário");

    // Produtos
    for (int j = 0; j < iLinha; j++)
    {
        printf("| %-6d | %-30s | %-10d | %-15.2f | \n",
               produtos[j].codigo, produtos[j].nome, produtos[j].quantidade, produtos[j].valorUnitario);
    }

    printf("\n\n");

    fclose(arquivoLeitura);

    free(produtos);
}

int main()
{

    int tela;
    FILE *arquivoProdutos = fopen("produtos.csv", "a+");

    if (arquivoProdutos == NULL)
    {
        printf("Erro ao abrir o arquivo");
        return 1;
    }

    do
    {

        printf("|---------------------------------|\n");
        printf("|                                 |\n");
        printf("|   Selecione uma funcionalidade  |\n");
        printf("|                                 |\n");
        printf("|---------------------------------|\n");
        printf("|---------------------------------|\n");
        printf("|1 - Carregar Banco de Dados      |\n");
        printf("|2 - Cadastro do produto          |\n");
        printf("|3 - Editar/Alterar produto       |\n");
        printf("|4 - Excluir Produto              |\n");
        printf("|5 - Listar produtos              |\n");
        printf("|---------------------------------|\n");
        printf("|---------------------------------|\n\n");

        scanf("%d", &tela);

        switch (tela)
        {
        case 1:
            if (arquivoProdutos != NULL)
            {
                printf("Arquivo aberto com sucesso!\n\n");
            }
            break;
        case 2: // Cadastro do produto
            criarProduto();
            break;
        case 3: // Editar/Alterar produto
            editarProduto();
            break;
        case 4: // Excluir Produto
            excluirProduto();
            break;
        case 5:
            listarProduto();
            break;
        default:
            printf("\n");
            printf("|---------------------------------|\n");
            printf("|    INFORME UM NÚMERO CORRETO!   |\n");
            printf("|---------------------------------|\n\n");
        }

    } while (tela != 0);

    return 0;
}
