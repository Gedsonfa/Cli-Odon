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
        getchar();
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

