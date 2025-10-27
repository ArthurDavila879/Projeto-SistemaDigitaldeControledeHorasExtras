#include <stdio.h>
#include <string.h>
#include "funcoes.h"

void limpar_buffer()
{
    int c;
    // Lê e descarta caracteres até encontrar uma nova linha ou o fim do arquivo
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void adicionarFuncionario(struct funcionario funcionarios[])
{
    int n = 0, escolha;
    while (1)
    {
        printf("\nDeseja adicionar um novo funcionario? (1 - Sim | 0 - Nao): ");
        scanf("%d", &escolha);
        limpar_buffer();
        if (escolha == 0)
            break;
        printf("Digite o nome do funcionario %d: ", n + 1);
        fgets(funcionarios[n].nome, 50, stdin);
        printf("Digite as horas extras: ");
        scanf("%f", &funcionarios[n].horas_extras);
        printf("Digite o valor da hora: ");
        scanf("%f", &funcionarios[n].valor_hora);
        limpar_buffer();
        printf("Digite a data: ");
        fgets(funcionarios[n].data, 11, stdin);
        n++;
    }
   funcionarios[n].id = n + 1;
}

void adicionarHorasExtras(struct funcionario funcionarios[], int n, int id, float horas)
{
    if (id > 0 && id <= n)
    {
        funcionarios[id - 1].horas_extras += horas;
        funcionarios[id - 1].aprovado = 0; // marca como pendente
        printf("\nHoras extras registradas com sucesso!\n");
    }
    else
    {
        printf("\nFuncionário não encontrado.\n");
    }

}
void relatorio(struct funcionario funcionarios[], int n)
{
    FILE *arquivo = fopen("dados.txt", "r+");

    for (int i = 0; i < n; i++)
    {
        float total = funcionarios[i].horas_extras * funcionarios[i].valor_hora;
        fprintf(arquivo, "ID: %d | Nome: %s | Horas Extras: %.2f | Valor Hora: R$%.2f | Total a Pagar: R$%.2f | Status: ",
               funcionarios[i].id+1,
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
}