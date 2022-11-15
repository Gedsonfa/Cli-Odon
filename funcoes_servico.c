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
   
    printf("\t === Digite o codigo do serviço: ");
    scanf("%10[^\n]",ser->codigo);
    getchar();
    
    printf("\t === Digite o nome do serviço: ");
    scanf("%30[^\n]",ser->nome);
    getchar();
    
    printf("\t === Digite o custo do serviço: ");
    scanf("%20[^\n]",ser->custo);
    getchar();
    
    printf("\t === Digite o tempo do procedimento(hh/mm): ");
    scanf("%6[^\n]",ser->tempo);
    getchar();
    
    printf("\t === Digite a disponibilidade: ");
    scanf("%10[^\n]",ser->disponi);
    getchar();

    ser->status = 'm';
    
    
    printf("\t==================================================\n\n");

    system("\tPause");
    system("cls | clear");  
    
    return ser;       
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

Dados_Servico* buscar_servico(){
    FILE* fp;
    Dados_Servico* ser;
    char sor[15];

    printf("\n ===== Buscar Serviço ======");
    printf("\n Informe seu Codigo: ");
    scanf("%s", sor);
    getchar();
    
    ser = (Dados_Servico*) malloc(sizeof(Dados_Servico));
    fp = fopen("servicos.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Ocorreu  ko um erro na abertura do arquivo!\n");
        printf("Não é possível continuar este programa...\n");
        exit(1);
    }
    while(!feof(fp)){
        fread(ser, sizeof(Dados_Servico), 1, fp);
        if ((strcmp(ser -> codigo, sor) == 0) &&(ser->status != 'x')){
            fclose(fp);
            return ser;
        }
    }
fclose(fp);
return NULL;

}

void tela_pesquisar_servico(Dados_Servico* ser){

    system ("cls||clear");
    printf("\t===================================================\n");
    printf("\t==============   Pesquisar Serviços   =============\n");
    printf("\t===================================================\n\n");
    
    if(( ser == NULL) || (ser->status == 'x')){
        printf("Servico nao encontrado");
    }else{
        printf(" | ============== Servico Cadastrado =============\n");
        printf(" | Nome: %s\n", ser->nome);
        printf(" | Codigo: %s\n", ser->codigo);
        printf(" | Custo: %s\n", ser->custo);
        printf(" | Tempo: %s\n", ser->tempo);
        printf(" | Disponibilidade: %s\n", ser->disponi);
        printf(" | ================================================\n");
        printf(" | aperte ENTER para continuar");
        getchar();
        system(" cls| clear");
    
    printf("\t==================================================\n\n");

    system("\tPause");
    system("cls | clear");
    }
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

void exibe_servicos(Dados_Servico* ser) {

    printf("CPF: %s\n", ser->codigo);
    printf("Nome: %s\n", ser->nome);
    printf("Idade: %s\n", ser->tempo);
    printf("E-mail de contato: %s\n", ser->custo);
    printf("Endereco: %s\n", ser->disponi);
    printf("Status: %c\n", ser->status);
    printf("\n");

}

void tela_excluir_servico(){

    FILE* fp;
    Dados_Servico* ser;
    int achou;
    char resp;
    char procurado[15];
    fp = fopen("servicos.dat", "r+b");
    if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
    }
    printf("\n\n");
    system ("cls||clear");
    printf("=========================================\n");
    printf("============= Apagar servico ============\n");
    printf("========================================= \n");
    printf("Informe o codigo do Servico: ");
    scanf(" %14[^\n]", procurado);
    ser = (Dados_Servico*) malloc(sizeof(Dados_Servico));
    achou = 0;
    while((!achou) && (fread(ser, sizeof(Dados_Servico), 1, fp))) {
    if ((strcmp(ser->codigo, procurado) == 0) && (ser->status == 'm')) {
        achou = 1;
    }
    }

    if (achou) {
    exibe_servicos(ser);
    getchar();
    printf("Deseja realmente apagar este servico (s/n)? ");
    scanf("%c", &resp);
    getchar();
    if (resp == 's' || resp == 'S') {
        ser->status = 'x';
        fseek(fp, -1*sizeof(Dados_Servico), SEEK_CUR);
        fwrite(ser, sizeof(Dados_Servico), 1, fp);
        printf("\nServico excluído com sucesso!!!\n");
        printf("Aperte ENTER para continuar...");
        getchar();
        } else {
        printf("\nOk, os dados não foram alterados\n");
        printf("Aperte ENTER para continuar...");
        getchar();
        }
    } else {
    printf("O Servico %s não foi encontrado...\n", procurado);
    printf("Aperte ENTER para continuar...");
    getchar();
    }
    fclose(fp);
    free(ser);
}
//update

