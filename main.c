#include <stdio.h>
#include "funcoes.h"
#include <locale.h>
#include <stdlib.h>

int main(){
    printf("=== Sistema de Gerenciamento de Funcionarios ===\n");    
    struct funcionario funcionarios[100];
      int opcao;
    do {
        printf("\n===== SISTEMA DE CONTROLE DE HORAS EXTRAS =====\n");
        printf("1. Cadastrar funcionario\n");
        printf("2. Registrar horas extras\n");
        printf("3. Listar registros\n");
        printf("4. Aprovar/Reprovar horas extras\n");
        printf("5. Gerar relatorio final\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limpar_buffer();

        int total_funcionarios = 0;
        
        switch (opcao) {
            case 1: {
                adicionarFuncionario(funcionarios);
                total_funcionarios++;
                break;
                }
            
            

            case 2: {
                int id;
                float horas;
                printf("\n===== REGISTRAR HORAS EXTRAS =====\n");
                printf("\nDigite o ID do funcionário: ");
                scanf("%d", &id);
                limpar_buffer();
                printf("Digite a quantidade de horas extras: ");
                scanf("%f", &horas);
                adicionarHorasExtras(funcionarios, total_funcionarios, id, horas);
                break;
            }

            case 3: {
                printf("\n===== LISTA DE REGISTROS =====\n");
                for (int i = 0; i < total_funcionarios; i++) {
                    printf("ID: %d | Nome: %s | Horas Extras: %.2f | Valor Hora: R$%.2f | Status: ",
                        funcionarios[i].id,
                        funcionarios[i].nome,
                        funcionarios[i].horas_extras,
                        funcionarios[i].valor_hora);
                    if (funcionarios[i].aprovado == 0) printf("Pendente\n");
                    else if (funcionarios[i].aprovado == 1) printf("Aprovado\n");
                    else printf("Reprovado\n");
                }
                break;
            }

            case 4: {
                int id, decisao;
                printf("\nDigite o ID do funcionário: ");
                scanf("%d", &id);
                if (id > 0 && id <= total_funcionarios) {
                    printf("1 - Aprovar | 2 - Reprovar: ");
                    scanf("%d", &decisao);
                    if (decisao == 1) funcionarios[id - 1].aprovado = 1;
                    else { funcionarios[id - 1].aprovado = 2; }
                    printf("\nDecisão registrada com sucesso!\n");
                } else {
                    printf("\nFuncionário não encontrado.\n");
                }
                break;
            }

            case 5: {
                relatorio(funcionarios, total_funcionarios);
                break;
            }
            case 0:{
                printf("\nSaindo do sistema...\n");
                break;

            }
            default:
                printf("\nOpção inválida. Tente novamente.\n");
                break;
        }

        }while (opcao != 0);
    return 0;
}

