#include <stdio.h>
#ifndef FUNCOES_H
#define FUNCOES_H

struct funcionario
{
    int id;
    char nome[50];
    float horas_extras;
    float valor_hora;
    char data[12];
    int aprovado; // 1 aprovado 2 reprovado
};

void limpar_buffer();
int adicionarFuncionario(struct funcionario funcionarios[], int total_funcionarios);
void adicionarHorasExtras(struct funcionario funcionarios[], int n, int id, float horas);
void relatorio(struct funcionario funcionarios[], int n);
int verificargestor();
int tentar_aprovar();
void exibir_menu_gestor();
void exibir_menu_funcionario();
void exibir_menu_principal();
#endif
