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
    do {
        printf("\t === CPF do funcionário:  ");
        scanf("%15[^\n]", pag->cpf);
        getchar();
    } while (!validarCPF(pag->cpf));
    printf("\t === Insira o valor:  ");
    fgets(pag->valor,6,stdin);
    printf("\t === Insira a data de criacao:    ");
    fgets(pag->data_criacao,11,stdin);
    printf("\t === Insira a data de captura:    ");
    fgets(pag->data_captura,11,stdin);
    printf("\t === Insira o meio de pagamento:  ");
    fgets(pag->meio_pagamento,30,stdin);
    printf("\t === Insira o banco:  ");
    fgets(pag->banco,30,stdin);
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

Dados_Pagamento* tela_pesquisar_pagamento(void) {
    FILE* fp;
    Dados_Pagamento* pag;
    char cpf[15];
    system("cls||clear");
    printf("\t===================================================\n");
    printf("\t===============   Pesquisar Pagamento   ============\n");
    printf("\t===================================================\n\n");
    printf("Informe o CPF do funcionario: ");
    scanf("%14[^\n]", cpf);
    pag = (Dados_Pagamento*) malloc(sizeof(Dados_Pagamento));
    fp = fopen("pagamentos.dat", "rb");
    if(fp==NULL){
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possivel continuar esse programa...\n");
        exit(1);
    }
    while (!feof(fp)) {
        fread(pag, sizeof(Dados_Pagamento), 1, fp);
        if ((pag->cpf == cpf) && (pag->status != 'x')) {
            fclose(fp);
            return pag;
        }
    }
    fclose(fp);
    return NULL;
    printf("\t==================================================\n\n");
    system("\tPause");
    system("cls | clear");
}

void exibePagamento(Dados_Pagamento* pag) {
    char situacao[20];
    if ((pag == NULL) || (pag->status == 'x')) {
        printf("\n = Pagamento Inexistente = \n");
    } else {
        printf("\n = Pagamento Cadastrado = \n");
        printf("CPF do funcionário: %s", pag->cpf);
        printf("Valor: %s", pag->valor);
        printf("Data de criação: %s", pag->data_criacao);
        printf("Data de captura: %s", pag->data_captura);
        printf("Meio de pagamento: %s", pag->meio_pagamento);
        printf("Banco: %s", pag->banco);       
        if (pag->status == 'm') {
            strcpy(situacao, "Cadastrado");
        } else if (pag->status == 'r') {
            strcpy(situacao, "Removido");
        } else {
            strcpy(situacao, "Não informado");
        }
        printf("\nSituação do pagamento: %s\n", situacao);
    }
}

void listaPagamento(void) {
    FILE* fp;
    Dados_Pagamento* pag;
    printf("\n = Lista de Pagamentos = \n");
    pag = (Dados_Pagamento*) malloc(sizeof(Dados_Pagamento));
    fp = fopen("pagamentos.dat", "rb");
    if (fp==NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possivel continuar esse programa...\n");
        exit(1);
    }
    while (fread(pag, sizeof(Dados_Pagamento), 1, fp)) {
        if (pag->status != 'x') {
            exibePagamento(pag);
        }
    }
    fclose(fp);
}

void tela_alterar_pagamento(void) {
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
    system("cls||clear");
    printf("\t===================================================\n");
    printf("\t===============   Alterar Pagamento   ============\n");
    printf("\t===================================================\n\n");
    printf("Informe o CPF do funcionário que tera seu pagamento alterado: ");
    scanf("%14[^\n]", procurado);
    pag = (Dados_Pagamento*) malloc(sizeof(Dados_Pagamento));
    achou = 0;
    while ((!achou) && fread(pag, sizeof(Dados_Pagamento), 1, fp)) {
        if ((strcmp(pag->cpf, procurado) == 0) && (pag->status == 'm')) {
            achou = 1;
        }
    }
    if (achou) {
        exibePagamento(pag);
        getchar();
        printf("Deseja realmente editar este pagamento ? (s/n)");
        scanf("%c", &resp);
        if (resp == 's' || resp == 'S') {
            do {
                printf("\t === CPF do funcionário:  ");
                scanf("%15[^\n]", pag->cpf);
                getchar();
            } while (!validarCPF(pag->cpf));
            printf("\t === Insira o valor:  ");
            fgets(pag->valor,6,stdin);
            printf("\t === Insira a data de criacao:    ");
            fgets(pag->data_criacao,11,stdin);
            printf("\t === Insira a data de captura:    ");
            fgets(pag->data_captura,11,stdin);
            printf("\t === Insira o meio de pagamento:  ");
            fgets(pag->meio_pagamento,30,stdin);
            printf("\t === Insira o banco:  ");
            fgets(pag->banco,30,stdin);
            pag->status = 'm';
            fseek(fp, (-1)*sizeof(Dados_Pagamento), SEEK_CUR);
            fwrite(pag, sizeof(Dados_Pagamento), 1, fp);
            printf("\nPagamento editado com sucesso!!!\n");
        } else {
            printf("\nOK, os dados não foram alterados\n");
        }
    } else {
        printf("O pagamento do funcionário de CPF %s não foi encontrado...\n", procurado);
    }
    free(pag);
    fclose(fp);
    printf("\t==================================================\n\n");
    
    system("\tPause");
    system("cls | clear");

}
void tela_excluir_pagamento(void) {
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
    system("cls||clear");
    printf("\t===================================================\n");
    printf("\t===============   Excluir Pagamento   ============\n");
    printf("\t===================================================\n\n");
    printf("Informe o CPF do funcionário que tera seu pagamento excluido: ");
    scanf("%14[^\n]", procurado);
    pag = (Dados_Pagamento*) malloc(sizeof(Dados_Pagamento));
    achou = 0;
    while ((!achou) && fread(pag, sizeof(Dados_Pagamento), 1, fp)) {
        if ((strcmp(pag->cpf, procurado) == 0) && (pag->status == 'm')) {
            achou = 1;
        }
    }
    if (achou) {
        exibePagamento(pag);
        getchar();
        printf("Deseja realmente excluir este pagamento ? (s/n)");
        scanf("%c", &resp);
        if (resp == 's' || resp == 'S') {
            pag->status = 'x';
            fseek(fp, (-1)*sizeof(Dados_Pagamento), SEEK_CUR);
            fwrite(pag, sizeof(Dados_Pagamento), 1, fp);
            printf("\nPagamento excluido com sucesso!!!\n");
        } else {
            printf("\nOK, os dados não foram alterados\n");
        }
    } else {
        printf("O pagamento do funcionário de CPF %s não foi encontrado...\n", procurado);
    }
    free(pag);
    fclose(fp);
    printf("\t==================================================\n\n");
    
    system("\tPause");
    system("cls | clear");

}