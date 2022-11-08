#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validar.h"
#include "structs.h"

Dados_Agendamento* tela_cadastrar_agendamento(){

    Dados_Agendamento* age;
    age = (Dados_Agendamento*) malloc(sizeof(Dados_Agendamento));

    system ("cls||clear");
    printf("\t===================================================\n");
    printf("\t===============   Cadastrar Agendamento   ============\n");
    printf("\t===================================================\n\n");
    
    do{
        printf("\t === Insira o CPF do paciente:    ");
        scanf("%15[^\n]", age->cpf_paciente);
        getchar();
    }while(!validarCPF(age->cpf_paciente));

    printf("\t === Insira o codigo do servico:  ");
    scanf("%6[^\n]", age->codigo_servico);
    getchar();

    do{
        printf("\t === Insira o CPF do funcionario: ");
        scanf("%15[^\n]", age->cpf_funcionario);
        getchar();
    }while(!validarCPF(age->cpf_funcionario));

    printf("\t === Insira a data:   ");
    fgets(age->data,11,stdin);

    printf("\t === Insira o horario:   ");
    fgets(age->hora,6,stdin);

    age->status = 'm';
    return age;

    printf("\t==================================================\n\n");
    system("\tPause");
    system("cls | clear");
}

void grava_agendamento(Dados_Agendamento* age){
    FILE* fp;
    fp = fopen("agendamentos.dat", "ab");
    if(fp==NULL){
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possivel continuar esse programa...\n");
        exit(1);
    }
    fwrite(age,sizeof(Dados_Agendamento),1,fp);
    fclose(fp);
}

void tela_pesquisar_agendamento(){

    Dados_Agendamento* age;
    age = (Dados_Agendamento*) malloc(sizeof(Dados_Agendamento));

    system ("cls||clear");
    printf("\t===================================================\n");
    printf("\t===============   Pesquisar Agendamento   ============\n");
    printf("\t===================================================\n\n");
    
    do
    {
        printf("\t === Insira o CPF:    ");
        scanf("%s", age->cpf_paciente);
        getchar();
        
    } while (!validarCPF(age->cpf_paciente));
    
    printf("\t==================================================\n\n");
    
    system("\tPause");
    system("cls | clear");

}

void tela_alterar_agendamento(){

    Dados_Agendamento* age;
    age = (Dados_Agendamento*) malloc(sizeof(Dados_Agendamento));

    system ("cls||clear");
    printf("\t===================================================\n");
    printf("\t===============   Alterar Agendamento   ============\n");
    printf("\t===================================================\n\n");
    
    do
    {
        printf("\t === Insira o CPF:    ");
        scanf("%s", age->cpf_paciente);
        getchar();
        
    } while (!validarCPF(age->cpf_paciente));
    
    printf("\t==================================================\n\n");
    
    system("\tPause");
    system("cls | clear");

}

void tela_excluir_agendamento(){

    Dados_Agendamento* age;
    age = (Dados_Agendamento*) malloc(sizeof(Dados_Agendamento));

    system ("cls||clear");
    printf("\t===================================================\n");
    printf("\t===============   Excluir Agendamento   ============\n");
    printf("\t===================================================\n\n");
    
    do
    {
        printf("\t === Insira o CPF:    ");
        scanf("%s", age->cpf_paciente);
        getchar();
        
    } while (!validarCPF(age->cpf_paciente));
    
    printf("\t==================================================\n\n");
    
    system("\tPause");
    system("cls | clear");

}