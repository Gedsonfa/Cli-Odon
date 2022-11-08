#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "structs.h"


//Funções pacientes
Dados_Paciente* tela_pesquisar_paciente( );
void tela_alterar_paciente();
void tela_excluir_paciente();
void grava_paciente(Dados_Paciente* pac);
Dados_Paciente* tela_cadastrar_paciente();

//Funções Funcionarios
Dados_Funcionario* tela_cadastrar_funcionario();
void grava_funcionario(Dados_Funcionario* fun);
void tela_pesquisar_funcionario();
void tela_alterar_funcionario();
void tela_excluir_funcionario();

//Funções Serviço
Dados_Servico* tela_cadastrar_servico();
void grava_servico(Dados_Servico* ser);
void tela_pesquisar_servico();
void tela_alterar_servico();
void tela_excluir_servico();

//Funções Pagamentos
Dados_Pagamento* tela_cadastrar_pagamento();
void grava_pagamento(Dados_Pagamento* pag);
void tela_pesquisar_pagamento();
void tela_alterar_pagamento();
void tela_excluir_pagamento();

//Funções Agendamentos
Dados_Agendamento* tela_cadastrar_agendamento();
void grava_agendamento(Dados_Agendamento* age);
void tela_pesquisar_agendamento();
void tela_alterar_agendamento();
void tela_excluir_agendamento();

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
        printf("\t === 0- Voltar\n");
        printf("\n\t==================================================\n\n");
        printf("\t=> ");
        scanf("%c", &opcao_paci);
        getchar();
        switch (opcao_paci){
        case '1':
            paciente = tela_cadastrar_paciente();
            grava_paciente(paciente);
            tela_pacientes();
            free(paciente);
            break;
        case '2':
            tela_pesquisar_paciente();
            tela_pacientes();
            break;
        case '3':
            tela_alterar_paciente();
            tela_pacientes();
            break;
        case '4':
            tela_excluir_paciente();
            tela_pacientes();
            break;

        }
    }while(opcao_paci!='0');   
    free(paciente); 
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
        printf("\t === 0- Voltar\n");
        printf("\n\t==================================================\n\n");
        printf("\t=> ");
        scanf("%c", &opcao_serv);
        getchar();
        switch(opcao_serv){
            case '1':
                servico = tela_cadastrar_servico();
                grava_servico(servico);
                tela_servicos();
                break;
            case '2':
                tela_pesquisar_servico();
                tela_servicos();
                break;
            case '3':
                tela_alterar_servico();
                tela_servicos();
                break;
            case '4':
                tela_excluir_servico();
                tela_servicos();
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
        printf("\t === 0- Voltar\n");
        printf("\n\t======================================================\n\n");
        printf("\t=> ");
        scanf("%c", &opcao_funci);
        getchar();
        switch(opcao_funci){
            case '1':
                funcionario = tela_cadastrar_funcionario();
                grava_funcionario(funcionario);
                tela_funcionarios();
                break;
            case '2':
                tela_pesquisar_funcionario();
                tela_funcionarios();
                break;
            case '3':
                tela_alterar_funcionario();
                tela_funcionarios();
                break;
            case '4':
                tela_excluir_funcionario();
                tela_funcionarios();
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
            tela_pagamento();            
            break;       
        case '2':
            tela_pesquisar_pagamento();
            tela_pagamento();   
            break;
        case '3':
            tela_alterar_pagamento();
            tela_pagamento();   
            break;
        case '4':
            tela_excluir_pagamento();
            tela_pagamento();   
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
        printf("\t === 2- Exibir agendamento\n");
        printf("\t === 3- Alterar agendamento\n");
        printf("\t === 4- Desagendamento\n");
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
            tela_agend();
            break;
        case '2':
            tela_pesquisar_agendamento();
            tela_agend();
            break;
        case '3':
            tela_alterar_agendamento();
            tela_agend();
            break;
        case '4':
            tela_excluir_agendamento(); 
            tela_agend();
            break;
        }
    }while(opcao_agend!='0');         
}

