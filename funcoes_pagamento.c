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
        printf("\t === CPF do funcionário:  ");
        scanf("%15[^\n]", pag->cpf);
        getchar();
    }while(!validarCPF(pag->cpf));

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

void tela_pesquisar_pagamento(){

    Dados_Pagamento* pag;
    pag = (Dados_Pagamento*) malloc(sizeof(Dados_Paciente));

    system("cls||clear");
    printf("\t===================================================\n");
    printf("\t===============   Pesquisar Pagamento   ============\n");
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
void tela_excluir_pagamento(){

    Dados_Pagamento* pag;
    pag = (Dados_Pagamento*) malloc(sizeof(Dados_Paciente));

    system("cls||clear");
    printf("\t===================================================\n");
    printf("\t===============   Excluir Pagamento   ============\n");
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
//update
