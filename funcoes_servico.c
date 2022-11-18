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

void grava_servico(Dados_Servico* ser) {
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

Dados_Servico* tela_pesquisar_servico(void) {
    FILE* fp;
    Dados_Servico* ser;
    char cod[6];
    system ("cls||clear");
    printf("\t===================================================\n");
    printf("\t==============   Pesquisar Serviços   =============\n");
    printf("\t===================================================\n\n");
    printf("Informe o codigo do servico: ");
    scanf("%s", cod);
    ser = (Dados_Servico*) malloc(sizeof(Dados_Servico));
    fp = fopen("servicos.dat", "rb");
    if (fp==NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possivel continuar esse programa...\n");
        exit(1);
    }
    while (!feof(fp)) {
        fread(ser, sizeof(Dados_Servico), 1, fp);
        if ((ser->codigo == cod) && (ser->status != 'x')) {
            fclose(fp);
            return ser;
        }
    }
    fclose(fp);
    return NULL;
    printf("\t==================================================\n\n");

    system("\tPause");
    system("cls | clear");
}

void exibeServico(Dados_Servico* ser) {
    char situacao[20];
    if ((ser == NULL) || (ser->status == 'x')) {
        printf("\n = Serviço Inexistente = \n");
    } else {
        printf("\n = Cliente cadastrado = \n");
        printf("\nCodigo: %s\n", ser->codigo);
        printf("\nNome: %s\n", ser->nome);
        printf("\nCusto: %s\n", ser->custo);
        printf("\nTempo de duração: %s\n", ser->tempo);
        printf("\nDisponibilidade: %s\n", ser->disposto);
        if (ser->status == 'm') {
            strcpy(situacao, "Cadastrado");
        } else if (ser->status == 'r') {
            strcpy(situacao,"Removido");
        } else {
            strcpy(situacao, "Não Informado");
        } 
        printf("\nSituação do serviço: %s\n", situacao);
    }
}

void listaServico(void) {
    FILE* fp;
    Dados_Servico* ser;
    system ("cls||clear");
    printf("\t===================================================\n");
    printf("\t===============   Lista Serviços   ==============\n");
    printf("\t===================================================\n\n");
    ser = (Dados_Servico*) malloc(sizeof(Dados_Servico));
    fp = fopen("servicos.dat", "rb");
    if (fp==NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possivel continuar esse programa...\n");
        exit(1);
    }
    while (fread(ser, sizeof(Dados_Servico), 1, fp)) {
        if (ser->status != 'x') {
            exibeServico(ser);
        }
    }
    fclose(fp);
}

void tela_alterar_servico(){
    FILE* fp;
    Dados_Servico* ser;
    int achou;
    char resp;
    char procurado[51];
    fp = fopen("servicos.dat", "r+b");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    system ("cls||clear");
    printf("\t===================================================\n");
    printf("\t===============   Alterar Serviços   ==============\n");
    printf("\t===================================================\n\n");
    
    printf("\t === Digite o nome do serviço a ser alterado:\n");
    scanf("%50[^\n]", procurado);
    ser = (Dados_Servico*) malloc(sizeof(Dados_Servico));
    achou = 0;
    while ((!achou) && (fread(ser, sizeof(Dados_Servico), 1, fp))) {
        if ((strcmp(ser->nome, procurado) == 0) && (ser->status == 'm')) {
            achou = 1;
        }
    }
    if (achou) {
        exibeServico(ser);
        getchar();
        printf("Deseja realmente editar esse serviço ? (s/n)");
        scanf("%c", &resp);
        if (resp == 's' || resp == 'S') {
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
            fseek(fp, (-1)*sizeof(Dados_Servico), SEEK_CUR);
            fwrite(ser, sizeof(Dados_Servico), 1, fp);
            printf("\nServiço alterado com sucesso!!!\n");
        } else {
            printf("\nOK, os dados nao foram alterados\n");
        }
    } else {
        printf("O serviço %s não foi encontrado...\n", procurado);
      }
    free(ser);
    fclose(fp);
    printf("\t==================================================\n\n");
    
    system("\tPause");
    system("cls | clear");
}

void tela_excluir_servico(){
    FILE* fp;
    Dados_Servico* ser;
    int achou;
    char resp;
    char procurado[51];
    fp = fopen("servicos.dat", "r+b");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possivel continuar esse programa...\n");
        exit(1);
    }
    system ("cls||clear");
    printf("\t===================================================\n");
    printf("\t===============   Excluir Serviços   ==============\n");
    printf("\t===================================================\n\n");
    printf("Informe o nome do serviço a ser apagado: ");
    scanf("%50[^\n]", procurado);
    ser = (Dados_Servico*) malloc(sizeof(Dados_Servico));
    achou = 0;
    while ((!achou) && (fread(ser, sizeof(Dados_Servico), 1, fp))) {
        if ((strcmp(ser->nome, procurado) == 0) && (ser->status == 'm')) {
            achou = 1;
        }
    }
    if (achou) {
        exibeServico(ser);
        getchar();
        printf("Deseja realmente apagar esse serviço ? (s/n)");
        scanf("%c", &resp);
        if (resp == 's' || resp == 'S') {
            ser->status = 'x';
            fseek(fp, (-1)*sizeof(Dados_Servico), SEEK_CUR);
            fwrite(ser, sizeof(Dados_Servico), 1, fp);
            printf("Serviço excluido com sucesso!!!\n");
        } else {
            printf("\nOk, os dados não foram alterados\n");
        }
    } else {
        printf("O serviço %s não foi encontrado...\n", procurado);
    }
    free(ser);
    fclose(fp);
    printf("\t==================================================\n\n");
   
    system("\tPause");
    system("cls | clear");
}