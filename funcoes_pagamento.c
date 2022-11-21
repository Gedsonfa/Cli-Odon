#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validar.h"
#include "structs.h"

Dados_Pagamento* tela_cadastrar_pagamento(){

    Dados_Pagamento* pag;
    pag = (Dados_Pagamento*) malloc(sizeof(Dados_Paciente));

    system("cls||clear");
    printf("\t===================================================\n");
    printf("\t===============   Cadastrar Pagamento   ============\n");
    printf("\t===================================================\n\n");
    do{
        printf("\t === CPF do funcionário ou cliente:  ");
        scanf("%15[^\n]", pag->cpf);
        getchar();
    }while(!validarCPF(pag->cpf));

    printf("\t === Insira o valor:  ");
    scanf("%15[^\n]", pag->valor);
    getchar();

    printf("\t === Insira a data de criacao:    ");
    scanf("%15[^\n]", pag->data_criacao);
    getchar();

    printf("\t === Insira a data de captura:    ");
    scanf("%15[^\n]", pag->data_captura);
    getchar();

    printf("\t === Insira o meio de pagamento:  ");
    scanf("%15[^\n]", pag->meio_pagamento);
    getchar();

    printf("\t === Insira o banco:  ");
    scanf("%15[^\n]", pag->banco);
    getchar();

    pag->status = 'm';
    return pag;   

    printf("\t==================================================\n\n");
    
    system("\tPause");
    system("cls | clear");
}

void grava_pagamento(Dados_Pagamento* pag){
    FILE* fp;
    fp = fopen("pagamentos.dat", "ab");
    if(fp==NULL){
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possivel continuar esse programa...\n");
        exit(1);
    }
    fwrite(pag,sizeof(Dados_Pagamento),1,fp);
    fclose(fp);
}

Dados_Pagamento* buscar_pagamento(){
    FILE* fp;
    Dados_Pagamento* pag;
    char pog[15];

    printf("\n ===== Buscar Pagamento ======");
    printf("\n Informe seu CPF: ");
    scanf("%s", pog);
    getchar();

    pag = (Dados_Pagamento*) malloc(sizeof(Dados_Pagamento));
    fp = fopen("pagamentos.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Ocorreu  ko um erro na abertura do arquivo!\n");
        printf("Não é possível continuar este programa...\n");
        exit(1);
    }
    while(!feof(fp)){
        fread(pag, sizeof(Dados_Pagamento), 1, fp);
        if ((strcmp(pag -> cpf, pog) == 0) &&(pag->status != 'x')){
            fclose(fp);
            return pag;
        }
    }
fclose(fp);
return NULL;
}

void tela_pesquisar_pagamento(Dados_Pagamento* pag){

    system("cls||clear");
    printf("\t===================================================\n");
    printf("\t===============   Pesquisar Pagamento   ============\n");
    printf("\t===================================================\n\n");

    if((pag == NULL) || (pag->status == 'x')){
        printf("Pagamento nao encontrado");
    }else{
        printf(" | ============== Pagamento encontrado =============\n");
        printf(" | CPF : %s\n", pag->cpf);
        printf(" | Valor do pagamento: %s\n", pag->valor);
        printf(" | Data de criação: %s\n", pag->data_criacao);
        printf(" | Data de captura: %s\n", pag->data_captura);
        printf(" | Meio de Pagamento: %s\n", pag->meio_pagamento);
        printf(" | Banco: %s\n", pag->banco);
        printf(" | ================================================\n");
        printf(" | aperte ENTER para continuar");
        getchar();
        system(" cls| clear");
    }

}

void tela_alterar_pagamento(){

    Dados_Pagamento* pag;
    pag = (Dados_Pagamento*) malloc(sizeof(Dados_Paciente));

    system("cls||clear");
    printf("\t===================================================\n");
    printf("\t===============   Alterar Pagamento   ============\n");
    printf("\t===================================================\n\n");
    do{
        printf("\t === CPF do funcionário:  ");
        scanf("%15[^\n]", pag->cpf);
        getchar();
    }while(!validarCPF(pag->cpf));
    printf("\t==================================================\n\n");
    
    system("\tPause");
    system("cls | clear");

}

void exibe_pagamento(Dados_Pagamento* pag) {

    printf("CPF: %s\n", pag->cpf);
    printf("Valor do pagamento: %s\n", pag->valor);
    printf("Data de criacao: %s\n", pag->data_criacao);
    printf("Data de captura: %s\n", pag->data_captura);
    printf("Meio de pagamento: %s\n", pag->meio_pagamento);
    printf("Banco: %s\n", pag->banco);
    printf("Status: %c\n", pag->status);
    printf("\n");

}

void tela_excluir_pagamento(){


    FILE* fp;
    Dados_Pagamento* pag;
    int achou;
    char resp;
    char procurado[15];
    fp = fopen("pagamentos.dat", "r+b");
    if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
    }
    printf("\n\n");
    system ("cls||clear");
    printf("==========================================\n");
    printf("====== Apagar registro de pagamento ======\n");
    printf("========================================== \n");
    printf("Informe o CPF: ");
    scanf(" %14[^\n]", procurado);
    pag = (Dados_Pagamento*) malloc(sizeof(Dados_Pagamento));
    achou = 0;
    while((!achou) && (fread(pag, sizeof(Dados_Pagamento), 1, fp))) {
    if ((strcmp(pag->cpf, procurado) == 0) && (pag->status == 'm')) {
        achou = 1;
    }
    }

    if (achou) {
    exibe_pagamento(pag);
    getchar();
    printf("Deseja realmente apagar este Pagamento (s/n)? ");
    scanf("%c", &resp);
    getchar();
    if (resp == 's' || resp == 'S') {
        pag->status = 'x';
        fseek(fp, -1*sizeof(Dados_Pagamento), SEEK_CUR);
        fwrite(pag, sizeof(Dados_Pagamento), 1, fp);
        printf("\nPagamento excluído com sucesso!!!\n");
        printf("Aperte ENTER para continuar...");
        getchar();
        } else {
        printf("\nOk, os dados não foram alterados\n");
        printf("Aperte ENTER para continuar...");
        getchar();
        }
    } else {
    printf("O Paciente %s não foi encontrado...\n", procurado);
    printf("Aperte ENTER para continuar...");
    getchar();
    }
    fclose(fp);
    free(pag);

}
//update

