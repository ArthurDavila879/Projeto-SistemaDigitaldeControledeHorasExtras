#include <stdio.h>
#include "funcoes.h"
#include <locale.h>
#include <stdlib.h>
#include <string.h>

int main() {
  setlocale(LC_ALL, "Portuguese");

    printf("\n=== Sistema de Gerenciamento de Funcionarios ===\n");    

    struct funcionario funcionarios[100];
    int opcao, escolha, opcao2;
    int total_funcionarios = 0;
    int sair = 0;

    while (!sair) {
        exibir_menu_principal();
        if (scanf("%d", &escolha) != 1) { 
            limpar_buffer(); 
            printf("\nOpção invalida! Digite apenas numeros.\n");
            continue; 
        }
        limpar_buffer();

        switch(escolha) {
            case 0: // Menu Funcionário
                exibir_menu_funcionario();
                if (scanf("%d", &opcao) != 1) { 
                    limpar_buffer(); 
                    printf("\nOpção invalida!\n");
                    break; 
                }
                limpar_buffer();

                if (opcao == 9) { 
                    sair = 1; 
                    printf("\nEncerrando programa...\n");
                    break; 
                }
                if (opcao == 0) break;

                switch (opcao) {
                    case 1:
                        total_funcionarios = adicionarFuncionario(funcionarios, total_funcionarios);
                        break;
                    case 2: {
                        int id;
                        float horas;
                        printf("\n=== REGISTRAR HORAS EXTRAS ===\n");
                        printf("Digite o ID do funcionario: ");
                        if (scanf("%d", &id) != 1) {
                            printf("\nID inválido!\n");
                            limpar_buffer();
                            break;
                        }
                        limpar_buffer();
                        printf("Digite a quantidade de horas extras: ");
                        if (scanf("%f", &horas) != 1) {
                            printf("\nQuantidade invalida!\n");
                            limpar_buffer();
                            break;
                        }
                        limpar_buffer();
                        adicionarHorasExtras(funcionarios, total_funcionarios, id, horas);
                        break;
                    }
                    default:
                        printf("\nOpção invalida!\n");
                        break;
                }
                break;

            case 1: // Menu Gestor
                if (verificargestor() == 1) {
                    printf("\nTentativas de login excedidas!\n");
                    break;
                }

                do {
                    exibir_menu_gestor();
                    if (scanf("%d", &opcao2) != 1) {
                        limpar_buffer();
                        printf("\nOpção invalida!\n");
                        continue;
                    }
                    limpar_buffer();

                    if (opcao2 == 9) {
                        sair = 1;
                        printf("\nEncerrando programa...\n");
                        break;
                    }

                    switch(opcao2) {
                        case 1:
                           
                            printf("\n============ LISTA DE REGISTROS ============\n");
                            for (int i = 0; i < total_funcionarios; i++) {
                                printf("----------------------------------------\n");
                                printf("ID: %d\n", funcionarios[i].id);
                                printf("Nome: %s\n", funcionarios[i].nome);
                                printf("Horas Extras: %.2f\n", funcionarios[i].horas_extras);
                                printf("Valor Hora: R$ %.2f\n", funcionarios[i].valor_hora);
                                printf("Status: %s\n", 
                                    funcionarios[i].aprovado == 0 ? "Pendente" :
                                    funcionarios[i].aprovado == 1 ? "Aprovado" : "Reprovado");
                            }
                            printf("========================================\n");
                            break;

                        case 2:
                            if (tentar_aprovar() == 1) break;
                          
                            break;

                        case 3:
                            relatorio(funcionarios, total_funcionarios);
                            break;

                        case 0:
                            printf("\nVoltando ao menu principal...\n");
                            break;

                        default:
                            printf("\nOpção invalida!\n");
                            break;
                    }
                } while (opcao2 != 0 && !sair);
                break;

            case 2:
                printf("\nEncerrando programa...\n");
                sair = 1;
                break;

            default:
                printf("\nOpção inválida!\n");
                break;
        }
    }
    return 0;
}