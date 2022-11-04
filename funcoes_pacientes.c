#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validar.h"
#include "structs.h"

Dados_Paciente* tela_cadastrar_paciente(){

    Dados_Paciente* pac;
    pac = (Dados_Paciente*) malloc(sizeof(Dados_Paciente));

    system ("cls||clear");
    printf("\t===================================================\n");
    printf("\t===============   Cadastrar Paciente   ============\n");
    printf("\t===================================================\n\n");
    
    do
    {
        printf("\t === Insira o CPF:    ");
        scanf("%14[^\n]", pac->cpf);
        getchar();
        
    } while (!validarCPF(pac->cpf));
    
    do{
        printf("\t === Insira o nome:   ");
        scanf("%51[^\n]", pac->nome);
        getchar();
        
    }while(!lerLetras(pac->nome));

    printf("\t === Insira a idade:  ");
    fgets(pac->idade,3,stdin);
    

    printf("\t === Insira o endereço:   ");
    fgets(pac->endereco,51,stdin);
    

    printf("\t === Insira o e-mail: ");
    fgets(pac->email,51,stdin);
    

    printf("\t === Insira o numero telefonico:  ");
    fgets(pac->numero,12,stdin);

    pac->status = 'm';
    return pac;

    printf("\t==================================================\n\n");
    system("\tPause");
    system("cls | clear");

}

void grava_paciente(Dados_Paciente* pac){
    FILE* fp;
    fp = fopen("pacientes.dat", "ab");
    if(fp==NULL){
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possivel continuar esse programa...\n");
        exit(1);
    }
    fwrite(pac, sizeof(Dados_Paciente),1,fp);
    fclose(fp);
}

void tela_pesquisar_paciente(){

    Dados_Paciente* pac;
    pac = (Dados_Paciente*) malloc(sizeof(Dados_Paciente));

    system ("cls||clear");
    printf("\t===================================================\n");
    printf("\t===============   Pesquisar Paciente   ============\n");
    printf("\t===================================================\n\n");
    
    do
    {
        printf("\t === Insira o CPF:    ");
        scanf("%s", pac->cpf);
        getchar();
        
    } while (!validarCPF(pac->cpf));
    
    printf("\t==================================================\n\n");
    
    system("\tPause");
    system("cls | clear");

}

void tela_alterar_paciente(){

    Dados_Paciente* pac;
    pac = (Dados_Paciente*) malloc(sizeof(Dados_Paciente));

    system ("cls||clear");
    printf("\t===================================================\n");
    printf("\t================   Alterar Paciente   =============\n");
    
    printf("\t===================================================\n\n");
    do
    {
        printf("\t === Insira o CPF:    ");
        scanf("%s", pac->cpf);
        getchar();
        
    } while (!validarCPF(pac->cpf));
    
    printf("\t==================================================\n\n");
    
    system("\tPause");
    system("cls | clear");

}

void tela_excluir_paciente(){

    Dados_Paciente* pac;
    pac = (Dados_Paciente*) malloc(sizeof(Dados_Paciente));

    system ("cls||clear");
    printf("\t===================================================\n");
    printf("\t==============   Pesquisar Paciente   =============\n");
    printf("\t===================================================\n\n");
   
    do
    {
        printf("\t === Insira o CPF:    ");
        scanf("%s", pac->cpf);
        getchar();
        
    } while (!validarCPF(pac->cpf));
    
    printf("\t==================================================\n\n");
    
    system("\tPause");
    system("cls | clear");
}