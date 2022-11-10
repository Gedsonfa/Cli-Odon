#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

Dados_Servico* tela_cadastrar_servico(){

    Dados_Servico* ser;
    ser = (Dados_Servico*) malloc(sizeof(Dados_Servico));

    system ("cls||clear");
    printf("\t===================================================\n");
    printf("\t==============   Cadastrar Serviços   =============\n");
    printf("\t===================================================\n\n");
   
    printf("\t === Digite o codigo do serviço:\n");
    fgets(ser->codigo,6,stdin);
    
    
    printf("\t === Digite o nome do serviço:\n");
    fgets(ser->nome,51,stdin);
    
    
    printf("\t === Digite o custo do serviço:\n");
    fgets(ser->custo,7,stdin);
    
    
    printf("\t === Digite o tempo do procedimento(hh/mm):\n");
    fgets(ser->tempo,6,stdin);
    
    
    printf("\t === Digite a disponibilidade:\n");
    fgets(ser->disposto,13,stdin);
    
    ser->status = 'm';
    return ser;
    
    printf("\t==================================================\n\n");

    system("\tPause");
    system("cls | clear");         
}

void grava_servico(Dados_Servico* ser){
    FILE* fp;
    fp = fopen("servicos.dat", "ab");
    if(fp==NULL){
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possivel continuar esse programa...\n");
        exit(1);
    }
    fwrite(ser,sizeof(Dados_Servico),1,fp);
    fclose(fp);
}

void tela_pesquisar_servico(){

    Dados_Servico* ser;
    ser = (Dados_Servico*) malloc(sizeof(Dados_Servico));

    system ("cls||clear");
    printf("\t===================================================\n");
    printf("\t==============   Pesquisar Serviços   =============\n");
    printf("\t===================================================\n\n");
    
    printf("\t === Digite o código:\n");
    fgets(ser->codigo,6,stdin);
    
    
    printf("\t==================================================\n\n");

    system("\tPause");
    system("cls | clear");
}

void tela_alterar_servico(){

    Dados_Servico* ser;
    ser = (Dados_Servico*) malloc(sizeof(Dados_Servico));

    system ("cls||clear");
    printf("\t===================================================\n");
    printf("\t===============   Alterar Serviços   ==============\n");
    printf("\t===================================================\n\n");
    
    printf("\t === Digite o código:\n");
    fgets(ser->codigo,6,stdin);
    
    
    printf("\t==================================================\n\n");
    
    system("\tPause");
    system("cls | clear");
}

void tela_excluir_servico(){

    Dados_Servico* ser;
    ser = (Dados_Servico*) malloc(sizeof(Dados_Servico));

    system ("cls||clear");
    printf("\t===================================================\n");
    printf("\t===============   Excluir Serviços   ==============\n");
    printf("\t===================================================\n\n");
   
    printf("\t === Digite o código:\n");
    fgets(ser->codigo,6,stdin);
    
   
    printf("\t==================================================\n\n");
   
    system("\tPause");
    system("cls | clear");
}
//update

