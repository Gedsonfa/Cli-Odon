#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "structs.h"

//Funções pacientes
Dados_Paciente* tela_pesquisar_paciente(void);
Dados_Paciente* tela_cadastrar_paciente(void);
void exibePaciente(Dados_Paciente* pac);
void grava_paciente(Dados_Paciente* pac);
void tela_alterar_paciente(void);
void tela_excluir_paciente(void);
void listaPaciente(void);

//Funções Funcionarios
Dados_Funcionario* tela_cadastrar_funcionario(void);
Dados_Funcionario* tela_pesquisar_funcionario(void);
void grava_funcionario(Dados_Funcionario* fun);
void exibeFuncionario(Dados_Funcionario* fun);
void tela_alterar_funcionario(void);
void tela_excluir_funcionario(void);
void listaFuncionario(void);

//Funções Serviço
Dados_Servico* tela_pesquisar_servico(void);
Dados_Servico* tela_cadastrar_servico(void);
void grava_servico(Dados_Servico* ser);
void exibeServico(Dados_Servico* ser);
void tela_alterar_servico(void);
void tela_excluir_servico(void);
void listaServico(void);

//Funções Pagamentos
Dados_Pagamento* tela_cadastrar_pagamento(void);
Dados_Pagamento* tela_pesquisar_pagamento(void);
void grava_pagamento(Dados_Pagamento* pag);
void exibePagamento(Dados_Pagamento* pag);
void tela_alterar_pagamento(void);
void tela_excluir_pagamento(void);
void listaPagamento(void);

//Funções Agendamentos
Dados_Agendamento* tela_cadastrar_agendamento(void);
Dados_Agendamento* tela_pesquisar_agendamento(void);
void grava_agendamento(Dados_Agendamento* age);
void exibeAgendamento (Dados_Agendamento* age);
void tela_alterar_agendamento(void);
void tela_excluir_agendamento(void);
void listaAgendamento(void);

//Funções telas
void tela_pacientes();
void tela_servicos();
void tela_funcionarios();
void tela_pagamento();
void tela_agend();

void tela_progr_odont(){  
    char opcao_navegacao;
    do
    {
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
        printf("\t === 2- Modulo Serviços\n");
        printf("\t === 3- Modulo Funcionarios\n");
        printf("\t === 4- Modulo Agendamento\n");
        printf("\t === 5- Modulo Pagamento\n");
        printf("\t === 0- Voltar\n");
        printf("\t=====================================================\n");
        printf("\t=> ");
        scanf("%c", &opcao_navegacao);
        getchar();
        switch (opcao_navegacao)
        {
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
        }             
    }while(opcao_navegacao!='0');    
    printf("\tSaindo do programa...\n");
    system("cls||clear");
}

void tela_pacientes(){  
    Dados_Paciente* paciente;
    char opcao_paci;
    do
    {
        
        system("cls||clear");

        printf("\t===================================================\n");
        printf("\t===============   Modulo Paciente   ===============\n");
        printf("\t===================================================\n\n");
        printf("\t === 1- Cadastrar Paciente\n");
        printf("\t === 2- Pesquisar Paciente\n");
        printf("\t === 3- Alterar Paciente\n");
        printf("\t === 4- Excluir Paciente\n");
        printf("\t === 5- Listar Pacientes\n");
        printf("\t === 0- Voltar\n");
        printf("\n\t==================================================\n\n");
        printf("\t=> ");
        scanf("%c", &opcao_paci);
        getchar();
        switch (opcao_paci){
        case '1':
            paciente = tela_cadastrar_paciente();
            grava_paciente(paciente);
            free(paciente);
            break;
        case '2':
            paciente = tela_pesquisar_paciente();
            exibePaciente(paciente);
            free(paciente);
            break;
        case '3':
            tela_alterar_paciente();
            break;
        case '4':
            tela_excluir_paciente();
            break;
        case '5':
            listaPaciente();
            break;
        }
    }while(opcao_paci!='0');    
}

void tela_servicos(){  
    Dados_Servico* servico;
    char opcao_serv;
    do
    {
        system("cls||clear");

        printf("\t===================================================\n");
        printf("\t==============   Modulo de Servicos   =============\n");
        printf("\t===================================================\n\n");
        printf("\t === 1- Cadastrar serviço\n");
        printf("\t === 2- Pesquisar serviço\n");
        printf("\t === 3- Editar serviço\n");
        printf("\t === 4- Excluir serviço\n");
        printf("\t === 5- Listar serviços\n");
        printf("\t === 0- Voltar\n");
        printf("\n\t==================================================\n\n");
        printf("\t=> ");
        scanf("%c", &opcao_serv);
        getchar();
        switch(opcao_serv){
            case '1':
                servico = tela_cadastrar_servico();
                grava_servico(servico);
                free(servico);
                break;
            case '2':
                servico = tela_pesquisar_servico();
                exibeServico(servico);
                free(servico);
                break;
            case '3':
                tela_alterar_servico();
                break;
            case '4':
                tela_excluir_servico();
                break;
            case '5':
                listaServico();
                break;
        }
    }while(opcao_serv!='0'); 
}

void tela_funcionarios(){  
    Dados_Funcionario* funcionario;
    char opcao_funci;
    do
    {
        system("cls||clear");

        printf("\t=========================================================\n");
        printf("\t===============   Modulo de Funcionários   ==============\n");
        printf("\t=========================================================\n\n");
        printf("\t === 1- Cadastrar funcionário\n");
        printf("\t === 2- Pesquisar funcionário\n");
        printf("\t === 3- Alterar funcionário\n");
        printf("\t === 4- Excluir funcionáio\n");
        printf("\t === 5- Listar funcionáios\n");
        printf("\t === 0- Voltar\n");
        printf("\n\t======================================================\n\n");
        printf("\t=> ");
        scanf("%c", &opcao_funci);
        getchar();
        switch(opcao_funci){
            case '1':
                funcionario = tela_cadastrar_funcionario();
                grava_funcionario(funcionario);
                free(funcionario);
                break;
            case '2':
                funcionario = tela_pesquisar_funcionario();
                exibeFuncionario(funcionario);
                free(funcionario);
                break;
            case '3':
                tela_alterar_funcionario();
                break;
            case '4':
                tela_excluir_funcionario();
                break;
            case '5':
                listaFuncionario();
                break;
        }
    }while(opcao_funci!='0');  
}

void tela_pagamento(){
    Dados_Pagamento* pagamento;
    char opcao_pagamento;
    do{
        system ("cls||clear");
        printf("\t===================================================\n");
        printf("\t===============   Tela Pagamento   =============\n");
        printf("\t===================================================\n\n");
        printf("\t === 1- Efetuar pagamento\n");
        printf("\t === 2- Consultar pagamento\n");
        printf("\t === 3- Editar pagamento\n");
        printf("\t === 4- Excluir pagamento\n");
        printf("\t === 5- Listar pagamentos\n");
        printf("\t==================================================\n\n");
        printf("\t === Digite 0 para confirmar\n");
        printf("\t=>");
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
            pagamento = tela_pesquisar_pagamento();
            exibePagamento(pagamento);
            free(pagamento);  
            break;
        case '3':
            tela_alterar_pagamento();   
            break;
        case '4':
            tela_excluir_pagamento(); 
            break;
        case '5':
            listaPagamento();
            break;
        }
    }while(opcao_pagamento!='0');         
}

void tela_agend(){
    Dados_Agendamento* agendamento;
    char opcao_agend;
    do{
        system ("cls||clear");
        printf("\t===================================================\n");
        printf("\t===============   Tela Agendamento   ==============\n");
        printf("\t===================================================\n\n");
        printf("\t === 1- Novo agendamento\n");
        printf("\t === 2- Pesquisar agendamento\n");
        printf("\t === 3- Alterar agendamento\n");
        printf("\t === 4- Desagendamento\n");
        printf("\t === 5- Listar agendamentos\n");
        printf("\t==================================================\n\n");
        printf("\t === Digite 0 para confirmar\n");
        printf("\t=>");
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
            agendamento = tela_pesquisar_agendamento();
            exibeAgendamento(agendamento);
            free(agendamento);
        case '3':
            tela_alterar_agendamento();
            break;
        case '4':
            tela_excluir_agendamento(); 
            break;
        case '5':
            listaAgendamento();
            break;
        }
    }while(opcao_agend!='0');         
}

