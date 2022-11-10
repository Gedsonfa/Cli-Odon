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
    scanf("%20[^\n]",fun->idade);
    

    printf("\t === Insira o endereco:   ");
    scanf("%31[^\n]",fun->endereco);
    getchar();
    

    printf("\t === Insira o e-mail: ");
    scanf("%31[^\n]",fun->email);
    getchar();

    printf("\t === Insira o numero telefonico:  ");
    scanf("%21[^\n]",fun->telefone);
    getchar();
    
    fun->status = 'm';
    
    printf("\t==================================================\n\n");
    system("\tPause");
    system("cls | clear");
    return fun;
        
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

void tela_pesquisar_funcionario(Dados_Funcionario* fun){

    /*fun = (Dados_Funcionario*) malloc(sizeof(Dados_Funcionario));*/
    char dm[14];
    
    system ("cls||clear");
    printf("\t=========================================================\n");
    printf("\t===============   Pesquisar Funcionarios   ==============\n");
    printf("\t=========================================================\n\n");
    
    if((fun == NULL) || (fun->status == 'x')){
        printf("Paciente nao encontrado");
    }else{
        printf(" | ============== Paciente encontrado =============\n");
        printf(" | Nome: %s\n", fun->nome);
        printf(" | Idade: %s\n", fun->idade);
        printf(" | Email: %s\n", fun->email);
        printf(" | Endereco: %s\n", fun->endereco);
        printf(" | Numero: %s\n", fun->telefone);
        printf(" | ================================================\n");
        system("Pause");
        system(" cls| clear");

    }

    printf("Situacao do paciente: %s\n", dm);

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

//update
