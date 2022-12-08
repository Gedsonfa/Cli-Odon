#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "structs.h"

// Funções pacientes
void tela_pesquisar_paciente(Dados_Paciente *pac);
void grava_paciente(Dados_Paciente *pac);
Dados_Paciente *tela_cadastrar_paciente();
Dados_Paciente* buscaPaciente();
void tela_alterar_paciente();
void tela_excluir_paciente();
void exibe_pacientes();

// Funções Funcionarios
void tela_pesquisar_funcionario(Dados_Funcionario *fun);
Dados_Funcionario *tela_cadastrar_funcionario();
void grava_funcionario(Dados_Funcionario *fun);
Dados_Funcionario *buscar_funcionario();
void tela_alterar_funcionario();
void tela_excluir_funcionario();
void exibe_funcionarios();

// Funções Serviço
void tela_pesquisar_servico(Dados_Servico *ser);
Dados_Servico *tela_cadastrar_servico();
void grava_servico(Dados_Servico *ser);
Dados_Servico *buscar_servico();
void tela_alterar_servico();
void tela_excluir_servico();
void exibe_servicos();

// Funções Pagamentos
void tela_pesquisar_pagamento(Dados_Pagamento *pag);
Dados_Pagamento *tela_cadastrar_pagamento();
void grava_pagamento(Dados_Pagamento *pag);
Dados_Pagamento *buscar_pagamento();
void tela_alterar_pagamento();
void tela_excluir_pagamento();
void exibe_pagamento();

// Funções Agendamentos
void tela_pesquisar_agendamento(Dados_Agendamento* age);
Dados_Agendamento* tela_cadastrar_agendamento(void);
void grava_agendamento(Dados_Agendamento *age);
Dados_Agendamento* buscar_agendamento();
void tela_alterar_agendamento();
void tela_excluir_agendamento();
void exibe_agendamento();

// Funções Relatórios
void relatorio_agendamentos();
void relatorio_funcionario();
void relatorio_paciente();
void relatorio_servicos();
void relatorio_despesas();

// Funções telas
void tela_funcionarios();
void tela_pagamento();
void tela_pacientes();
void tela_servicos();
void tela_relatorios(void);
void tela_agend();
void sobre(void);

void tela_progr_odont() {
    char opcao_navegacao;
    do {
        system("cls||clear");
        printf("\n\t=======================================================\n");
        printf("\t=========   Projeto Sistema SIG-Dentistry      ========\n");
        printf("\t=========   Discentes:                         ========\n");
        printf("\t=========   Gabriel Wallace Canuto dos Santos  ========\n");
        printf("\t=========   Gedson Fernandes de Araújo        ========\n");
        printf("\t=======================================================\n");
        printf("\t=========   Sistema Clinica Odontologica   ============\n");
        printf("\t=======================================================\n");
        printf("\t === 1- Modulo Pacientes\n");
        printf("\t === 2- Modulo Servicos\n");
        printf("\t === 3- Modulo Funcionarios\n");
        printf("\t === 4- Modulo Agendamento\n");
        printf("\t === 5- Modulo Despesas\n");
        printf("\t === 6- Modulo Relatórios\n");
        printf("\t === 7- Tela Sobre\n");
        printf("\t === 0- Voltar\n");
        printf("\t=====================================================\n");
        printf("\t=> ");
        scanf("%c", &opcao_navegacao);
        getchar();
        switch (opcao_navegacao) {
        case '1':
            tela_pacientes();
            break;
        case '2':
            tela_servicos();
            break;
        case '3':
            tela_funcionarios();
            break;
        case '4':
            tela_agend();
            break;
        case '5':
            tela_pagamento();
            break;
        case '6':
            tela_relatorios();
            break;
        case '7':
            sobre();
            break;
        }
    } while (opcao_navegacao != '0');
    printf("\tSaindo do programa...\n");
    system("cls||clear");
}

void tela_pacientes() {
    Dados_Paciente *paciente;
    int opcao_paci;
    do {

        system("cls||clear");

        printf("\t===================================================\n");
        printf("\t===============   Modulo Paciente   ===============\n");
        printf("\t===================================================\n\n");
        printf("\t === 1- Cadastrar Paciente\n");
        printf("\t === 2- Pesquisar Paciente\n");
        printf("\t === 3- Alterar Paciente\n");
        printf("\t === 4- Excluir Paciente\n");
        printf("\t === 0- Voltar\n");
        printf("\n\t==================================================\n\n");
        printf("\t=> ");
        scanf("%d", &opcao_paci);
        getchar();
        switch (opcao_paci)
        {
        case 1:
            paciente = tela_cadastrar_paciente();
            grava_paciente(paciente);

            free(paciente);
            break;
        case 2:
            paciente = buscaPaciente();
            tela_pesquisar_paciente(paciente);

            free(paciente);
            break;
        case 3:
            tela_alterar_paciente();

            break;
        case 4:
            tela_excluir_paciente();

            break;
        default:
            printf("Opção inválida");
            break;
        }
    } while (opcao_paci);
}

void tela_servicos()
{
    Dados_Servico *servico;
    char opcao_serv;
    do
    {
        system("cls||clear");

        printf("\t===================================================\n");
        printf("\t==============   Modulo de Servicos   =============\n");
        printf("\t===================================================\n\n");
        printf("\t === 1- Cadastrar servico\n");
        printf("\t === 2- Pesquisar servico\n");
        printf("\t === 3- Editar serviço\n");
        printf("\t === 4- Excluir servico\n");
        printf("\t === 0- Voltar\n");
        printf("\n\t==================================================\n\n");
        printf("\t=> ");
        scanf("%c", &opcao_serv);
        getchar();
        switch (opcao_serv)
        {
        case '1':
            servico = tela_cadastrar_servico();
            grava_servico(servico);

            free(servico);
            break;
        case '2':
            servico = buscar_servico();
            tela_pesquisar_servico(servico);

            free(servico);
            break;
        case '3':
            tela_alterar_servico();

            break;
        case '4':
            tela_excluir_servico();

            break;
        default:
            printf("Opção inválida!");
            break;
        }
    } while (opcao_serv != '0');
}

void tela_funcionarios()
{
    Dados_Funcionario *funcionario;
    char opcao_funci;
    do
    {
        system("cls||clear");

        printf("\t=========================================================\n");
        printf("\t===============   Modulo de Funcionários   ==============\n");
        printf("\t=========================================================\n\n");
        printf("\t === 1- Cadastrar funcionario\n");
        printf("\t === 2- Pesquisar funcionario\n");
        printf("\t === 3- Alterar funcionario\n");
        printf("\t === 4- Excluir funcionaio\n");
        printf("\t === 0- Voltar\n");
        printf("\n\t======================================================\n\n");
        printf("\t=> ");
        scanf("%c", &opcao_funci);
        getchar();
        switch (opcao_funci)
        {
        case '1':
            funcionario = tela_cadastrar_funcionario();
            grava_funcionario(funcionario);

            free(funcionario);
            break;
        case '2':
            funcionario = buscar_funcionario();
            tela_pesquisar_funcionario(funcionario);

            free(funcionario);
            break;
        case '3':
            tela_alterar_funcionario();

            break;
        case '4':
            tela_excluir_funcionario();

            break;
        default:
            printf("Opção inválida!");
            break;
        }
    } while (opcao_funci != '0');
}

void tela_pagamento()
{
    Dados_Pagamento *pagamento;
    char opcao_pagamento;
    do
    {
        system("cls||clear");
        printf("\t===================================================\n");
        printf("\t===============   Tela Despesas   =================\n");
        printf("\t===================================================\n\n");
        printf("\t === 1- Cadastrar Despesa\n");
        printf("\t === 2- Consultar Despesa\n");
        printf("\t === 3- Editar Despesa\n");
        printf("\t === 4- Excluir Despesa\n");
        printf("\t === 0- Voltar\n");
        printf("\t==================================================\n\n");
        printf("\t=> ");
        scanf("%c", &opcao_pagamento);
        getchar();
        switch (opcao_pagamento)
        {
        case '1':
            pagamento = tela_cadastrar_pagamento();
            grava_pagamento(pagamento);

            free(pagamento);
            break;
        case '2':
            pagamento = buscar_pagamento();
            tela_pesquisar_pagamento(pagamento);

            free(pagamento);
            break;
        case '3':
            tela_alterar_pagamento();

            break;
        case '4':
            tela_excluir_pagamento();

            break;
        default:
            printf("Opção inválida!");
            break;
        }
        
    } while (opcao_pagamento != '0');
}

void tela_agend()
{
    Dados_Agendamento *agendamento;
    char opcao_agend;
    do
    {
        system("cls||clear");
        printf("\t===================================================\n");
        printf("\t===============   Tela Agendamento   ==============\n");
        printf("\t===================================================\n\n");
        printf("\t === 1- Cadastrar Agendamento\n");
        printf("\t === 2- Exibir Agendamento\n");
        printf("\t === 3- Alterar Agendamento\n");
        printf("\t === 4- Desagendamento\n");
        printf("\t === 5- Listar Agendamentos\n");
        printf("\t === 0- Voltar\n");
        printf("\t==================================================\n\n");
        printf("\t=> ");
        scanf("%c", &opcao_agend);
        getchar();
        switch (opcao_agend)
        {
        case '1':
            agendamento = tela_cadastrar_agendamento();
            grava_agendamento(agendamento);

            free(agendamento);
            break;
        case '2':
            agendamento = buscar_agendamento();
            tela_pesquisar_agendamento(agendamento);

            free(agendamento);
            break;
        case '3':
            tela_alterar_agendamento();

            break;
        case '4':
            //agendamento = buscar_agendamento();
            tela_excluir_agendamento();

            //free(agendamento);
            break;
        case '5':
            listarAgendamentos();
            break;
        default:
            printf("Opção inválida!");
            break;
        }
        
    } while (opcao_agend != '0');
}

void tela_relatorios(void) {
    char opcao;
    do {
        system("cls||clear");
        printf("\t===================================================\n");
        printf("\t===============   Tela de Relatórios   ============\n");
        printf("\t===================================================\n\n");
        printf("\t === 1- Relatório Pacientes\n");
        printf("\t === 2- Relatório Funcionários\n");
        printf("\t === 3- Relatório Serviços\n");
        printf("\t === 4- Relatório Despesas\n");
        printf("\t === 5- Relatório Agendamentos\n");
        printf("\t === 0- Voltar\n");
        printf("\t==================================================\n\n");
        printf("\t=> ");
        scanf("%c", &opcao);
        getchar();
        switch (opcao) {
            case '1':
                relatorio_paciente();
                break;
            case '2':
                relatorio_funcionario();
                break;
            case '3':
                relatorio_servicos();
                break;
            case '4':
                relatorio_despesas();
                break;
            case '5':
                relatorio_agendamentos();
                break;
            default:
                break;
        }
    } while (opcao != '0');
}

void relatorio_paciente() {
    char opcao;
    do {
        system("cls||clear");
        printf("\t===================================================\n");
        printf("\t=============== Relatórios de Pacientes ===========\n");
        printf("\t===================================================\n\n");
        printf("\t === 1- Todos os pacientes\n");
        printf("\t === 2- Pacientes excluidos\n");
        printf("\t === 0- Voltar\n");
        printf("\t==================================================\n\n");
        printf("\t=> ");
        scanf("%c", &opcao);
        getchar();
        switch (opcao)
        {
        case '1':
            listarPacientes();
            break;
        case '2':
            listarPacientesExc();
            break;
        default:
            break;
        }
    } while (opcao != '0');
}

void relatorio_funcionario() {
    char opcao;
    do {
        system("cls||clear");
        printf("\t===================================================\n");
        printf("\t============ Relatórios de Funcionários ===========\n");
        printf("\t===================================================\n\n");
        printf("\t === 1- Todos os funcionários\n");
        printf("\t === 0- Voltar\n");
        printf("\t==================================================\n\n");
        printf("\t=> ");
        scanf("%c", &opcao);
        getchar();
        switch (opcao) {
            case '1':
                listarFuncionarios();
                break;
            default:
                break;
        }
    } while (opcao != '0');
}
void relatorio_servicos() {
    char opcao;
    do {
        system("cls||clear");
        printf("\t===================================================\n");
        printf("\t============== Relatórios de Serviços =============\n");
        printf("\t===================================================\n\n");
        printf("\t === 1- Todos os serviços\n");
        printf("\t === 2- Serviços excluidos\n");
        printf("\t === 3- Serviços ativos\n");
        printf("\t === 0- Voltar\n");
        printf("\t==================================================\n\n");
        printf("\t=> ");
        scanf("%c", &opcao);
        getchar();
        switch (opcao) {
            case '1':
                listarServico();
                break;
            case '2':
                listarServicoExc();
                break;
            case '3':
                listarServicoCad();
                break;
            default:
                break;
        }
    } while (opcao != '0');
}

void relatorio_despesas() {
    char opcao;
    do {
        system("cls||clear");
        printf("\t===================================================\n");
        printf("\t============== Relatórios de Despesas =============\n");
        printf("\t===================================================\n\n");
        printf("\t === 1- Todas as despesas\n");
        printf("\t === 2- Despesas excluidas\n");
        printf("\t === 3- Despesas ativas\n");
        printf("\t === 0- Voltar\n");
        printf("\t==================================================\n\n");
        printf("\t=> ");
        scanf("%c", &opcao);
        getchar();
        switch (opcao) {
            case '1':
                listarPagamentos();
                break;
            case '2':
                listarPagamentosExc();
                break;
            case '3':
                listarPagamentosCad();
                break;
            default:
                break;
        }
    } while (opcao != '0');
}

void relatorio_agendamentos() {
    char opcao;
    do {
        system("cls||clear");
        printf("\t===================================================\n");
        printf("\t============== Relatórios de Agendamentos =============\n");
        printf("\t===================================================\n\n");
        printf("\t === 1- Todos os agendamentos\n");
        printf("\t === 0- Voltar\n");
        printf("\t==================================================\n\n");
        printf("\t=> ");
        scanf("%c", &opcao);
        getchar();
        switch (opcao) {
            case '1':
                listarAgendamentos();
                break;
            default:
                break;
        }
    } while (opcao != '0');
}

void sobre(void) {
    system("cls||clear");
    printf("\t ===================================================== \n ");
    printf("\t ==== Sistema de Gestão de Clínica Odontológica ==== \n ");
    printf("\t Este projeto foi desenvolvido por: \n ");
    printf("\t Discente: Gedson Fernandes \n ");
    printf("\t E-mail: gedsonfda@gmail.com \n ");
    printf("\t Redes Sociais: @gedsonfa \n ");
    printf("\t Git : https://github.com/Gedsonfa \n");
    printf("\t ===================================================== \n");
    printf("\t Discente: Gabriel Wallace  \n ");
    printf("\t E-mail: gcanutosantos@gmail.com \n ");
    printf("\t Redes Sociais: @gabriel_wallace_17 \n ");
    printf("\t Git : https://github.com/Japagabriel \n ");
    printf("\t ===================================================== \n ");
    printf("\t Programa ultilizado para avaliacao da dupla na disciplina DCT1106 == Programacao, com o objetivo de servir a uma clinica odontologica fictícia, NÃO NOS RESPONSABILIZAMOS POR QUAISQUER TRANSTORNOS SOFRIDOS POR USO NÃO AUTORIZADO DE TERCEIROS de partes ou de todo o codigo.\n " );
    printf("\t ======================================================== \n");
    printf("\t Agradecemos a todos que contribuiram com o projeto direta ou indiretamente: \n");
    printf("\t https://github.com/italo-mauricio \n");
    printf("\t https://github.com/FlaviusGorgonio \n");
    printf("\t https://github.com/DayXL \n");
    printf("\t Perdão caso tenhamos esquecido sua menção\n");
    printf("\t ======================================================== \n");
    printf("\tTecle ENTER para prosseguir...\n");
    getchar();
}