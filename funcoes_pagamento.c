#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validar.h"
#include "structs.h"

Dados_Pagamento* tela_cadastrar_pagamento(void) {

    Dados_Pagamento* pag;
    pag = (Dados_Pagamento*) malloc(sizeof(Dados_Paciente));

    system("cls||clear");
    printf("\t===================================================\n");
    printf("\t===============   Cadastrar Despesas   ============\n");
    printf("\t===================================================\n\n");
    do{
    printf("\t === ID da Despesa:  ");
    scanf("%15[^\n]", pag->cpf);
    getchar();
    }while(!((lerNumeros(pag->cpf)) && (valida_des(pag->cpf))));

    printf("\t === Insira o valor:  ");
    scanf("%15[^\n]", pag->valor);
    getchar();

    printf("\t === Insira a data de criacao '00/00/0000':    ");
    scanf("%15[^\n]", pag->data_criacao);
    getchar();

    printf("\t === Insira o nome da despesa:    ");
    scanf("%15[^\n]", pag->nome_desp);
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

Dados_Pagamento* buscar_pagamento(void) {
    FILE* fp;
    Dados_Pagamento* pag;
    char pog[15];

    printf("\n ===== Buscar Despesa ======");
    do {
        printf("\n Informe o ID: ");
        scanf("%s", pog);
        getchar();
        if (!lerNumeros(pog)) {
            printf(" | Informe um ID valido!!!\n");
        }
    } while (!lerNumeros(pog));
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
    printf("\t================   Pesquisar Despesa   ============\n");
    printf("\t===================================================\n\n");

    if((pag == NULL) || (pag->status == 'x')){
        printf("\n Pagamento nao encontrado");
    }else{
        printf(" | ============== Pagamento encontrado =============\n");
        printf(" | ID da despesa : %s\n", pag->cpf);
        printf(" | Nome da despesa: %s\n ", pag ->nome_desp);
        printf(" | Valor do pagamento: %s\n", pag->valor);
        printf(" | Data de criação: %s\n", pag->data_criacao);
        printf(" | Meio de Pagamento: %s\n", pag->meio_pagamento);
        printf(" | Banco: %s\n", pag->banco);
        printf(" | ================================================\n");
        printf(" | aperte ENTER para continuar");
        getchar();
        system(" cls| clear");
    }

}


void exibe_pagamento(Dados_Pagamento* pag) {

    printf(" | ID da despesa: %s\n", pag->cpf);
    printf(" | Nome da despesa: %s\n ", pag ->nome_desp);
    printf(" | Valor do pagamento: %s\n", pag->valor);
    printf(" | Data de criacao: %s\n", pag->data_criacao);
    printf(" | Meio de pagamento: %s\n", pag->meio_pagamento);
    printf(" | Banco: %s\n", pag->banco);
    printf(" | Status: %c\n", pag->status);
    printf("\n");

}


void tela_alterar_pagamento(void) {

    FILE* fp;
    Dados_Pagamento* pag;
    int achou;
    char esc;
    char resp;
    char procurando[20];

    fp = fopen("pagamentos.dat", "r+b");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
}
    pag = (Dados_Pagamento*) malloc(sizeof(Dados_Pagamento));
    system("cls||clear");
    printf("\t===================================================\n");
    printf("\t================   Alterar Despesa   ==============\n");
    printf("\t===================================================\n\n");
    printf("\t === ID da Despesa:  ");
    scanf("%s", procurando);
    getchar();

    achou = 0;

    while((!achou) && (fread(pag, sizeof(Dados_Pagamento), 1, fp))) {
    if ((strcmp(pag->cpf, procurando) == 0) && (pag->status == 'm')) {
    achou = 1;
    }if (achou) {
        exibe_pagamento(pag);
        printf(" Deseja realmente editar esta Despesa? [s/n] ");
        scanf("%c", &resp);
        getchar();
        if (resp == 's' || resp == 'S') {
        
        esc = escAtualizarPagamento();

        if (esc == '1'){

                printf(" | Informe o novo Valor: ");
                scanf("%30[^\n]", pag->valor);
                getchar();


                printf(" | Informe a nova data de Criacao: ");
                scanf("%20[^\n]",pag->data_criacao);
                getchar();

                printf(" | Informe o novo nome da despesa: ");
                scanf("%20[^\n]", pag->nome_desp);
                getchar();

                printf(" | Informe o novo meio de Pagamento: ");
                scanf("%[A-Z a-z]", pag->meio_pagamento);
                getchar();

                printf(" | Informe o novo Banco: ");
                scanf("%15[^\n]", pag->banco);
                getchar();


        } else if (esc == '2'){
                
                printf(" | Informe o novo Valor: ");
                scanf("%30[^\n]", pag->valor);
                getchar();

        } else if (esc == '3'){

                printf(" | Informe a nova data de Criacao: ");
                scanf("%20[^\n]",pag->data_criacao);
                getchar();

        } else if (esc == '4'){

                printf(" | Informe o novo nome da despesa: ");
                scanf("%20[^\n]", pag-> nome_desp);
                getchar();
        } else if (esc == '5'){
                printf(" | Informe o novo meio de Pagamento: ");
                scanf("%[A-Z a-z]", pag->meio_pagamento);
                getchar();

        } else if (esc == '6') {
                printf(" | Informe o novo Banco: ");
                scanf("%30[^\n]", pag->banco);
                getchar();
        }
    pag->status = 'm';
    fseek(fp, (-1)*sizeof(Dados_Pagamento), SEEK_CUR);
    fwrite(pag, sizeof(Dados_Pagamento), 1, fp);
    printf("\nDespesa editado com sucesso!!!\n");
    //grava_pagamento(pag);
    //free(pag);



    } else {
        printf("\n | Tudo bem, os dados não foram alterados!");
    }
    
    } 
    }
    printf("\n | Pressione qualquer tecla para sair...");
    getchar();
    free(pag);
    fclose(fp);

}

char escAtualizarPagamento(void) {    
    char op;
    system(" cls || clear");
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | -------------------- Atualizar Despesa ------------------ | \n");
    printf(" |                                                           | \n");
    printf(" |                 1- Editar Tudo                            | \n");
    printf(" |                 2- Editar Valor                           | \n");
    printf(" |                 3- Editar Data de criação                 | \n");
    printf(" |                 4- Editar Nome da despesa                 | \n");
    printf(" |                 5- Editar Meio de pagamento               | \n");  
    printf(" |                 6- Editar Numero do banco                 | \n");    
    printf(" |                                                           | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | Selecione uma opção do que você deseja editar: ");
    scanf("%c", &op);
    getchar();
    return op;
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
    printf("\n\n");
    system ("cls||clear");
    printf("==========================================\n");
    printf("====== Apagar registro de despesas =======\n");
    printf("========================================== \n");
    printf("Informe o ID: ");
    scanf(" %14[^\n]", procurado);
    getchar();
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
    printf("Deseja realmente apagar esta Despesa (s/n)? ");
    scanf("%c", &resp);
    getchar();
    if (resp == 's' || resp == 'S') {
        pag->status = 'x';
        fseek(fp, -1*sizeof(Dados_Pagamento), SEEK_CUR);
        fwrite(pag, sizeof(Dados_Pagamento), 1, fp);
        printf("\nDespesa excluída com sucesso!!!\n");
        printf("Aperte ENTER para continuar...");
        getchar();
        } else {
        printf("\nOk, os dados não foram alterados\n");
        printf("Aperte ENTER para continuar...");
        getchar();
        }
    } else {
    printf("A Despesa %s não foi encontrado...\n", procurado);
    printf("Aperte ENTER para continuar...");
    getchar();
    }
    fclose(fp);
    free(pag);

}
//update


int listarDespesa(void) {
    FILE* fp;
    Dados_Pagamento* pag;
    fp = fopen("pagamentos.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        return 0;
    }
    pag = (Dados_Pagamento*)malloc(sizeof(Dados_Pagamento));
    while(fread(pag, sizeof(Dados_Pagamento), 1, fp)) {
        system(" cls || clear");
        printf(" | ====================== Listar Despesas ========================= | \n");
        printf(" |                                                                  | \n");
        exibe_pagamento(pag);         
        printf(" | Pressione qualquer tecla para sair...");
        getchar();

    }

    fclose(fp);
    free(pag);
    return 0;

}

int listarDespesaExc(void) {
    FILE* fp;
    Dados_Pagamento* pag;
    fp = fopen("pagamentos.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        return 0;
    }
    pag = (Dados_Pagamento*)malloc(sizeof(Dados_Pagamento));
    while(fread(pag, sizeof(Dados_Pagamento), 1, fp)) {
        if (pag->status == 'x') {
            system(" cls || clear");
            printf(" | ====================== Listar Despesas ========================= | \n");
            printf(" |                                                                  | \n");
            exibe_pagamento(pag);         
            printf(" | Pressione qualquer tecla para sair...");
            getchar();
        }
    }

    fclose(fp);
    free(pag);
    return 0;

}

int listarDespesaCad(void) {
    
    char proc[20];
    FILE* fp;
    Dados_Pagamento* pag;
    fp = fopen("pagamentos.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        return 0;
    }
    printf("\t===================================\n");
    printf("\t Digite a data que procura: ");
    scanf("%s",proc);
    getchar();

    pag = (Dados_Pagamento*)malloc(sizeof(Dados_Pagamento));
    while(fread(pag, sizeof(Dados_Pagamento), 1, fp)) { 

        if ((strcmp(pag -> data_criacao, proc) == 0) && (pag->status != 'x')) {
            system(" cls || clear");
            printf(" | ====================== Listar Despesas ========================= | \n");
            printf(" |                                                                  | \n");
            exibe_pagamento(pag);         
            printf(" | Pressione qualquer tecla para sair...");
            getchar();
        } 
    }

    fclose(fp);
    free(pag);
    return 0;

}

int listarDespesaBank(void) {
    
    char proc[20];
    FILE* fp;
    Dados_Pagamento* pag;
    fp = fopen("pagamentos.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        return 0;
    }
    printf("\t===================================\n");
    printf("\t Digite o Banco que procura: ");
    scanf("%s",proc);
    getchar();

    pag = (Dados_Pagamento*)malloc(sizeof(Dados_Pagamento));
    while(fread(pag, sizeof(Dados_Pagamento), 1, fp)) { 
        
        if ((strcmp(pag -> banco, proc) == 0) && (pag->status != 'x')) {
            system(" cls || clear");
            printf(" | ====================== Listar Despesas ========================= | \n");
            printf(" |                                                                  | \n");
            exibe_pagamento(pag);         
            printf(" | Pressione qualquer tecla para sair...");
            getchar();
        } 
    }

    fclose(fp);
    free(pag);
    return 0;

}


NoPag* listaOrdenadaDes(void) {
  FILE* fp;
  Dados_Pagamento* des;
  NoPag* noPag;
  NoPag* lista;

  lista = NULL;
  fp = fopen("pagamentos.dat", "rb");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }

  des = (Dados_Pagamento*) malloc(sizeof(Dados_Pagamento));
  while(fread(des, sizeof(Dados_Pagamento), 1, fp)) {
    if (des->status != 'x') {
      noPag = (NoPag*) malloc(sizeof(NoPac));
      
      noPag->cod = des->cod;

      strcpy(noPag->nome_desp, des->nome_desp);

      strcpy(noPag->cpf, des->cpf);

      strcpy(noPag->valor, des->valor);

      strcpy(noPag->data_criacao, des->data_criacao);

      strcpy(noPag->meio_pagamento, des->meio_pagamento);

      strcpy(noPag->banco, des->banco);

      noPag->status = des->status;

      if (lista == NULL) {
        lista = noPag;
        noPag->prox = NULL;
      } else if (strcmp(noPag->nome_desp,lista->nome_desp) < 0) {
        noPag->prox = lista;
        lista = noPag;
      } else {
        NoPag* anter = lista;
        NoPag* atual = lista->prox;
        while ((atual != NULL) && strcmp(atual->nome_desp,noPag->nome_desp) < 0) {
          anter = atual;
          atual = atual->prox;
        }
        anter->prox = noPag;
        noPag->prox = atual;
      }
    }
  }
  fclose(fp);
  free(des);
  return lista;
}


void exibeListaDes(NoPag* lista){
    system(" cls || clear");
    while (lista != NULL) {
    printf(" | ID da despesa: %s\n", lista->cpf);
    printf(" | Nome da despesa: %s\n ", lista ->nome_desp);
    printf(" | Valor do pagamento: %s\n", lista->valor);
    printf(" | Data de criacao: %s\n", lista->data_criacao);
    printf(" | Meio de pagamento: %s\n", lista->meio_pagamento);
    printf(" | Banco: %s\n", lista->banco);
    printf(" | Status: %c\n", lista->status);
    printf("\n");
    getchar();
    system(" cls || clear");
    lista = lista->prox;
    }
}

int valida_des(char* linha)
{
    FILE* fp3;
    Dados_Pagamento* teste;

    teste = (Dados_Pagamento*)malloc(sizeof(Dados_Pagamento));
    
    fp3 = fopen("pagamentos.dat", "rt");
    
    if (fp3 == NULL)
    {
        printf("Gerando arquivo...");
        fclose(fp3);
        return 1;
    }
    while (!feof(fp3))
    {
        fread(teste, sizeof(Dados_Pagamento), 1, fp3);
        if (strcmp(linha, teste->cpf) == 0    && (teste->status != 'x'))
        {
            fclose(fp3);
            return 0;
        }
    }
    fclose(fp3);
    return 1;
}
