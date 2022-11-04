#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validar.h"
#include "structs.h"

Dados_Funcionario* tela_cadastrar_funcionario(){

    Dados_Funcionario* fun;
    fun = (Dados_Funcionario*) malloc(sizeof(Dados_Funcionario));
    
    system ("cls||clear");
    printf("\t=========================================================\n");
    printf("\t===============   Cadastrar Funcionarios   ==============\n");
    printf("\t=========================================================\n");
    
    do{
        printf("\t === Insira o CPF:    ");
        scanf("%15[^\n]",fun->cpf);
        getchar();
        
    }while(!validarCPF(fun->cpf));
/*struct Dados_Pagamento{
char cpf[15];
char valor[6];
char data_criacao[11];
char data_captura[11];
char meio_pagamento[30];
char banco[30];
char status;
};*/
    do{
    printf("\t === Insira o nome:   ");
    scanf("%30[^\n]",fun->nome);
    getchar();
    
    }while(!lerLetras(fun->nome));

    printf("\t === Insira a idade:  ");
    fgets(fun->idade,3,stdin);
    

    printf("\t === Insira o endereco:   ");
    fgets(fun->endereco,31,stdin);
    

    printf("\t === Insira o e-mail: ");
    fgets(fun->email,31,stdin);
    

    printf("\t === Insira o numero telefonico:  ");
    fgets(fun->endereco,12,stdin);
    
    fun->status = 'm';
    return fun;

    printf("\t==================================================\n\n");
    system("\tPause");
    system("cls | clear");
    
        
}

void grava_funcionario(Dados_Funcionario* fun){
    FILE* fp;
    fp = fopen("funcionarios.dat", "ab");
    if(fp==NULL){
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possivel continuar esse programa...\n");
        exit(1);
    }
    fwrite(fun,sizeof(Dados_Funcionario), 1,fp);
    fclose(fp);
}

void tela_pesquisar_funcionario(){

    Dados_Funcionario* fun;
    fun = (Dados_Funcionario*) malloc(sizeof(Dados_Funcionario));
    
    system ("cls||clear");
    printf("\t=========================================================\n");
    printf("\t===============   Pesquisar Funcionarios   ==============\n");
    printf("\t=========================================================\n\n");
    
    do{
    printf("\t === Insira o CPF:    ");
    scanf("%s",fun->cpf);
    getchar();
    
    }while(!validarCPF(fun->cpf));
    
    printf("\t==================================================\n\n");
    
    system("\tPause");
    system("cls | clear");
    
}

void tela_alterar_funcionario(){

    Dados_Funcionario* fun;
    fun = (Dados_Funcionario*) malloc(sizeof(Dados_Funcionario));

    system ("cls||clear");
    printf("\t=========================================================\n");
    printf("\t================   Alterar Funcionarios   ===============\n");
    printf("\t=========================================================\n\n");
    
    do{
    printf("\t === Insira o CPF:    ");
    scanf("%s",fun->cpf);
    getchar();
    
    }while(!validarCPF(fun->cpf));
    
    printf("\t==================================================\n\n");
    
    system("\tPause");
    system("cls | clear");

}

void tela_excluir_funcionario(){

    Dados_Funcionario* fun;
    fun = (Dados_Funcionario*) malloc(sizeof(Dados_Funcionario));

    system ("cls||clear");
    printf("\t=========================================================\n");
    printf("\t================   Excluir Funcionarios   ===============\n");
   
    printf("\t=========================================================\n\n");
    do{       
        printf("\t === Insira o CPF:    ");
        scanf("%s",fun->cpf);
        getchar();
    }while(!validarCPF(fun->cpf));
    
    printf("\t==================================================\n\n");
    
    system("\tPause");
    system("cls | clear");

}
