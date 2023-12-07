// Nome: Lucas Schmitz e Bernardo do Santos
// Objetivo: CRUD de estoque de Produto
// Analista Funcional: Gildomiro Bairros
// Data de Desenvolvimento: 06//12/2023
// Observação: O arquivo ".csv" está no output e está denominado como "produtos.csv"
//             Qualquer dúvida, entrar em contato.

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

void clearScreen()
{
    system("printf \"\\033c\"");
}

void criarProduto()
{
    clearScreen();
    system("clear");

    // Declarando variaveis locais
    char retorno;
    char separador = ';';
    char term;

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
    do
    {

        printf("Insira o Código do produto: ");

        if (scanf("%d%c", &produto.codigo, &term) != 2 || term != '\n')
        { // 1 = entrada bem sucedida
            printf("Erro: Código deve ser um número inteiro.\n");
            while (getchar() != '\n')
                ; // Limpar o buffer de entrada
        }
        else
        {
            break; // Sai do loop se a entrada for válida
        }

    } while (2);

    // Nome do Produto
    // printf("Insira o Nome do Produto: ");
    // fgets(produto.nome, sizeof(produto.nome), stdin);
    // produto.nome[strlen(produto.nome) - 1] = 0;

    do
    {
        printf("Insira o Nome do Produto: ");

        fgets(produto.nome, sizeof(produto.nome), stdin);

        // Remover de nova linha
        // size_t --> armazena os tamanhos de objetos no C. É o tipo retornado das funções (size_of e strlen)
        size_t len = strlen(produto.nome);
        if (len > 0 && produto.nome[len - 1] == '\n')
        {
            produto.nome[len - 1] = '\0';
        }

        if (isspace(produto.nome[0]))
        {
            printf("Erro: Nome do Produto não deve ter espaços em branco.\n");
        }
        else if (produto.nome[0] == '\0')
        {
            printf("Erro: Nome do Produto não deve ser nulo.\n");
        }
        else
        {
            break;
        }

        // fgets(produto.nome, sizeof(produto.nome), stdin);

    } while (1);

    // Quantidade do produto
    do
    {

        printf("Insira a Quantidade do Produto: ");

        // if (scanf("%d", &produto.quantidade) != 1)
        if (scanf("%d%c", &produto.quantidade, &term) != 2 || term != '\n')
        { // 1 = entrada bem sucedida
            printf("Erro: Quantidade deve ser um número inteiro.\n");
            while (getchar() != '\n')
                ; // Limpar o buffer de entrada
        }
        else
        {
            break; // Sai do loop se a entrada for válida
        }

    } while (2);

    // Valor unitário
    do
    {

        printf("Insira um Valor unitário: ");

        if (scanf("%f", &produto.valorUnitario) != 1)
        { // 1 = entrada bem sucedida
            printf("Erro: Valor Unitário deve ser um valor.\n");
            while (getchar() != '\n')
                ; // Limpar o buffer de entrada
            printf("\n");
        }
        else
        {
            break; // Sai do loop se a entrada for válida
        }

    } while (1);

    // printf("Insira um Valor unitário: ");
    // scanf("%f", &produto.valorUnitario);
    FILE *arquivoValidacao = fopen("produtos.csv", "r");
    if (arquivoValidacao == NULL)
    {
        printf("Erro ao abrir os arquivos.\n");
        return;
    }

    FILE *arquivoProdutos = fopen("produtos.csv", "a");
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

            fprintf(arquivoProdutos, "%d%c%s%c%d%c%.2f\n", produto.codigo, separador, produto.nome, separador, produto.quantidade, separador, produto.valorUnitario);

            fclose(arquivoProdutos);

            system("clear");

            printf("|---------------------------------|\n");
            printf("|       PRODUTO CADASTRADO!       |\n");
            printf("|---------------------------------|\n\n");
            break;
        case 'n':
            system("clear");
            printf("|---------------------------------|\n");
            printf("|     PRODUTO NÃO CADASTRADO!     |\n");
            printf("|---------------------------------|\n\n");
            limparEstrutura(&produto);
            break;
        default:
            system("clear");
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
    clearScreen();

    printf("|---------------------------------|\n");
    printf("|---------------------------------|\n");
    printf("|                                 |\n");
    printf("|    ATUALIZAR DADOS DO PRODUTO   |\n");
    printf("|                                 |\n");
    printf("|---------------------------------|\n");
    printf("|---------------------------------|\n\n");

    int codigo;
    char term;

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

            while (getchar() != '\n')
                ; // Limpar o buffer de entrada

            // Nome
            do
            {

                printf("Insira um Novo Nome: ");

                fgets(produto.nome, sizeof(produto.nome), stdin);

                // Remover de nova linha
                size_t len = strlen(produto.nome);
                if (len > 0 && produto.nome[len - 1] == '\n')
                {
                    produto.nome[len - 1] = '\0';
                }

                if (isspace(produto.nome[0]))
                {
                    printf("Erro: Nome do Produto não deve ter espaços em branco.\n");
                }
                else if (produto.nome[0] == '\0')
                {
                    printf("Erro: Nome do Produto não deve ser nulo.\n");
                }
                else
                {
                    break;
                }

                // fgets(produto.nome, sizeof(produto.nome), stdin);

            } while (1);

            /*printf("Insira um Novo Nome: ");
            while (getchar() != '\n')
                ;
            fgets(produto.nome, sizeof(produto.nome), stdin);
            produto.nome[strlen(produto.nome) - 1] = '\0';*/

            do
            {

                printf("Insira uma Nova Quantidade: ");

                // if (scanf("%d", &produto.quantidade) != 1)
                if (scanf("%d%c", &produto.quantidade, &term) != 2 || term != '\n')
                { // 1 = entrada bem sucedida
                    printf("Erro: Quantidade deve ser um número inteiro.\n");
                    while (getchar() != '\n')
                        ; // Limpar o buffer de entrada
                }
                else
                {
                    break; // Sai do loop se a entrada for válida
                }

            } while (2);

            // Valor unitário
            do
            {

                printf("Insira um Novo Valor unitário: ");

                if (scanf("%f", &produto.valorUnitario) != 1)
                { // 1 = entrada bem sucedida
                    printf("Erro: Valor Unitário deve ser um valor.");
                    while (getchar() != '\n')
                        ; // Limpar o buffer de entrada
                    printf("\n");
                }
                else
                {
                    break; // Sai do loop se a entrada for válida
                }

            } while (1);

            // Inserindo dados no arquivo temporario
            fprintf(arquivoTemporario, "%d%c%s%c%d%c%.2f\n", produto.codigo, separador, produto.nome, separador, produto.quantidade, separador, produto.valorUnitario);
        }
    }

    fclose(arquivoLeitura);
    fclose(arquivoTemporario);

    if (codigoEncontrado == 0)
    {
        system("clear");
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
                system("clear");
                printf("|---------------------------------|\n");
                printf("|          OPÇÃO INVÁLIDA.        |\n");
                printf("|   TENTE NOVAMENTE, POR FAVOR!   |\n");
                printf("|---------------------------------|\n\n");
            }

        } while (retorno != 's' && retorno != 'n');
    }
}

void excluirProduto()
{
    system("clear");
    clearScreen();

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
        system("clear");
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
                system("clear");
                printf("|---------------------------------|\n");
                printf("|          OPÇÃO INVÁLIDA.        |\n");
                printf("|   TENTE NOVAMENTE, POR FAVOR!   |\n");
                printf("|---------------------------------|\n\n");
            }

        } while (retorno != 's' && retorno != 'n');
    }
}

void listarProduto()
{
    system("clear");
    clearScreen();

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
    FILE *arquivoProdutos = fopen("produtos.csv", "r");

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
                printf("\nArquivo aberto com sucesso!\n\n");
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
