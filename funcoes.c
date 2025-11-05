#include <stdio.h>
#include <string.h>
#include "funcoes.h"
#include <time.h>
#include <stdlib.h>
void limpar_buffer()
{
    int c;
    // Lê e descarta caracteres até encontrar uma nova linha ou o fim do arquivo
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int adicionarFuncionario(struct funcionario funcionarios[], int total_funcionarios)
{
    int escolha;

    while (escolha != 0)
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

    return total_funcionarios; // devolve o total
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
int verificargestor()
{
    char nome[100];
    char senha[20];
    char nomelogin[100] = {"gestor"};
    char senhalogin[20] = {"gestor"};
    printf("Insira o nome do gestor: ");
    fgets(nome, sizeof(nome), stdin);
    printf("Insira a senha: ");
    fgets(senha, sizeof(senha), stdin);
    int verific1 = strcmp(senha, senhalogin);
    int verific2 = strcmp(nome, nomelogin);

    if (verific1 >= 0 && verific2 >= 0)
    {
        printf("Login correto");
        return 0;
    }
    else
    {
        printf("Login incorreto, tente novamente");
        return 1;
    }
}
#define HORA_LIMITE 14

// Função que verifica se a aprovação pode ocorrer com base na hora atual.
int tentar_aprovar()
{
    time_t tempo_atual;
    // Obtém o timestamp atual
    time(&tempo_atual);

    // Converte para estrutura tm com a hora local
    struct tm *info_tempo = localtime(&tempo_atual);
    if (info_tempo == NULL)
    {
        perror("Erro ao obter a hora local");
    }

    // Ajusta a hora caso haja valores fora do intervalo por alguma razão.
    int hora_atual = (info_tempo->tm_hour);
    // Recupera os minutos atuais (0..59)
    int minuto_atual = info_tempo->tm_min;

    // Compara a hora atual com o limite definido por HORA_LIMITE
    if (hora_atual < HORA_LIMITE)
    {
        // Antes do limite: aprovação permitida
        printf("\n\n--- VERIFICACAO DE HORA ---\n");
        printf("Hora atual (ajustada): %02d:%02d\n", hora_atual, minuto_atual);
        printf("Aprovacao permitida. O limite de %02d:00 ainda nao foi atingido.\n", HORA_LIMITE);
        printf("\nRotina de aprovacao sendo executada...\n");
        return 0;
    }
    else
    {
        // Igual ou após o limite: aprovação negada
        printf("--- VERIFICACAO DE HORA ---\n");
        printf("Hora atual (ajustada): %02d:%02d\n", hora_atual, minuto_atual);
        printf("Aprovacao negada. O horario limite de %02d:00 foi ultrapassado.\n", HORA_LIMITE);
        return 1;
    }
}

// Função para exibir o menu do gestor
void exibir_menu_gestor() {
    printf("\n====== MENU DO GESTOR ======\n");
    printf("[ 1 ] Listar registros\n");
    printf("[ 2 ] Aprovar/Reprovar horas extras\n");
    printf("[ 3 ] Gerar relatorio final\n");
    printf("[ 0 ] Voltar ao menu inicial\n");
    printf("[ 9 ] Encerrar programa\n");
    printf("--------------------------\n");
    printf("Escolha uma oocao: ");
}
// Função para exibir o menu do funcionário
void exibir_menu_funcionario() {
    printf("\n=== MENU DO FUNCIONARIO ===\n");
    printf("[ 1 ] Cadastrar funcionario\n");
    printf("[ 2 ] Registrar horas extras\n");
    printf("[ 0 ] Voltar ao menu inicial\n");
    printf("[ 9 ] Encerrar programa\n");
    printf("-------------------------\n");
    printf("Escolha uma opcao: ");
}

// Função para exibir o menu principal
void exibir_menu_principal() {
    printf("\n=======================================\n");
    printf("  SISTEMA DE CONTROLE DE HORAS EXTRAS  \n");
    printf("=======================================\n");
    printf("[ 0 ] Entrar como Funcionario\n");
    printf("[ 1 ] Entrar como Gestor\n");
    printf("[ 2 ] Encerrar Programa\n");
    printf("---------------------------------------\n");
    printf("Escolha uma opcao: ");
}