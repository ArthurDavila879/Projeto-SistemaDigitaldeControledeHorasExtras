#include <stdio.h>
#include <string.h>
#include "funcoes.h"

void limpar_buffer()
{
    int c;
    // Lê e descarta caracteres até encontrar uma nova linha ou o fim do arquivo
    while ((c = getchar()) != '\n' && c != EOF);
}

int adicionarFuncionario(struct funcionario funcionarios[], int total_funcionarios)
{
    int escolha;

    while (1)
    {
        printf("\nDeseja adicionar um novo funcionario? (1 - Sim | 0 - Nao): ");
        scanf("%d", &escolha);
        limpar_buffer();

        if (escolha == 0)
            break;

        int n = total_funcionarios; // começa do total atual
        funcionarios[n].id = n + 1;

        printf("Digite o nome do funcionario %d: ", funcionarios[n].id);
        fgets(funcionarios[n].nome, 50, stdin);
        funcionarios[n].nome[strcspn(funcionarios[n].nome, "\n")] = '\0';

        printf("Digite as horas extras: ");
        scanf("%f", &funcionarios[n].horas_extras);

        printf("Digite o valor da hora: ");
        scanf("%f", &funcionarios[n].valor_hora);
        limpar_buffer();

        printf("Digite a data (dd/mm/aaaa): ");
        fgets(funcionarios[n].data, 11, stdin);
        funcionarios[n].data[strcspn(funcionarios[n].data, "\n")] = '\0';

        funcionarios[n].aprovado = 0;
        total_funcionarios++;

        printf("\nFuncionario cadastrado com sucesso!\n");
    }

    return total_funcionarios; // devolve o total atualizado
}

void adicionarHorasExtras(struct funcionario funcionarios[], int n, int id, float horas)
{
    if (id > 0 && id <= n)
    {
        funcionarios[id - 1].horas_extras += horas;
        funcionarios[id - 1].aprovado = 0; 
        printf("\nHoras extras registradas com sucesso!\n");
    }
    else
    {
        printf("\nFuncionario nao encontrado.\n");
    }
}

void relatorio(struct funcionario funcionarios[], int n)
{
    FILE *arquivo = fopen("dados.txt", "w"); 
    if (arquivo == NULL)
    {
        printf("\nErro ao abrir o arquivo!\n");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        float total = funcionarios[i].horas_extras * funcionarios[i].valor_hora;

        fprintf(arquivo,
                "ID: %d | Nome: %s | Horas Extras: %.2f | Valor Hora: R$%.2f | Total a Pagar: R$%.2f | Status: ",
                funcionarios[i].id,
                funcionarios[i].nome,
                funcionarios[i].horas_extras,
                funcionarios[i].valor_hora,
                total);

        if (funcionarios[i].aprovado == 0)
            fprintf(arquivo, "Pendente\n");
        else if (funcionarios[i].aprovado == 1)
            fprintf(arquivo, "Aprovado\n");
        else
            fprintf(arquivo, "Reprovado\n");
    }

    fclose(arquivo);
    printf("\nRelatorio gerado com sucesso no arquivo 'dados.txt'!\n");
}
