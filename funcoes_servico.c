#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "validar.h"

Dados_Servico* tela_cadastrar_servico(){

    Dados_Servico* ser;
    ser = (Dados_Servico*) malloc(sizeof(Dados_Servico));

    system ("cls||clear");
    printf("\t===================================================\n");
    printf("\t==============   Cadastrar Serviços   =============\n");
    printf("\t===================================================\n\n");
    do {
        printf("\t === Digite o codigo do serviço: ");
        scanf("%10[^\n]",ser->codigo);
        getchar();
    } while (!((lerNumeros(ser->codigo)) && (valida_ser(ser->codigo))));

    printf("\t === Digite o nome do serviço: ");
    scanf("%30[^\n]",ser->nome);
    getchar();
    
    printf("\t === Digite o custo do serviço: ");
    scanf("%20[^\n]",ser->custo);
    getchar();
    
    printf("\t === Digite o tempo do procedimento(hh/mm): ");
    scanf("%20[^\n]",ser->tempo);
    getchar();
    
    printf("\t === Digite a disponibilidade(M/T/N): ");
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
    do {
        printf("\n Informe seu Codigo: ");
        scanf("%s", sor);
        getchar();
        if (!lerNumeros(sor)) {
            printf(" | Digite um codigo valido!!!");
        }
    } while (!lerNumeros(sor));
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
    
    }
}

void exibe_servicos(Dados_Servico* ser) {

    printf(" | Código do Servico: %s\n", ser->codigo);
    printf(" | Nome: %s\n", ser->nome);
    printf(" | Duração: %s\n", ser->tempo);
    printf(" | Preco: %s\n", ser->custo);
    printf(" | Disponibilidade: %s\n", ser->disponi);
    printf(" | Status: %c\n", ser->status);
    printf("\n");


}

void tela_alterar_servico(){
    FILE* fp;
    Dados_Servico* ser;
    int achou;
    char esc;
    char resp;
    char procurando[20];

    fp = fopen("servicos.dat", "r+b");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
}
    ser = (Dados_Servico*) malloc(sizeof(Dados_Servico));

    system ("cls||clear");
    printf("\t===================================================\n");
    printf("\t===============   Alterar Servicos   ==============\n");
    printf("\t===================================================\n\n");
    printf("\t === Digite o código:");
    scanf("%s",procurando);
    getchar();
    achou = 0;

    while((!achou) && (fread(ser, sizeof(Dados_Servico), 1, fp))) {
    if ((strcmp(ser->codigo, procurando) == 0) && (ser->status == 'm')) {
    achou = 1;
    }if (achou) {
        exibe_servicos(ser);
        printf(" Deseja realmente editar este Servico? [s/n] ");
        scanf("%c", &resp);
        getchar();
        if (resp == 's' || resp == 'S') {
        
        esc = escAtualizarServico();

        if (esc == '1'){

                printf(" | Informe o novo Nome: ");
                scanf("%30[^\n]", ser->nome);
                getchar();


                printf(" | Informe a novo Custo: ");
                scanf("%20[^\n]",ser->custo);
                getchar();

                printf(" | Informe o nova duracao do Servico: ");
                scanf("%20[^\n]", ser->tempo);
                getchar();

                printf(" | Informe a nova disponibilidade para o Servico: ");
                scanf("%[A-Z a-z]", ser->disponi);
                getchar();


    } else if (esc == '2'){
                
                printf(" | Informe o novo Nome: ");
                scanf("%30[^\n]", ser->nome);
                getchar();

    } else if (esc == '3'){

                printf(" | Informe o novo Custo: ");
                scanf("%20[^\n]",ser->custo);
                getchar();

    } else if (esc == '4'){

                printf(" | Informe a nova duracao do Servico: ");
                scanf("%20[^\n]", ser-> tempo);
                getchar();
    } else if (esc == '5'){
                printf(" | Informe a nova disponibilidade para o Servico: ");
                scanf("%[A-Z a-z]", ser->disponi);
                getchar();

    } 
    ser->status = 'm';
    fseek(fp, (-1)*sizeof(Dados_Servico), SEEK_CUR);
    fwrite(ser, sizeof(Dados_Servico), 1, fp);
    printf("\nservico editado com sucesso!!!\n");
    //grava_servico(ser);
    //free(ser);



    } else {
        printf("Tudo bem, os dados não foram alterados!");
    }
    
    } 
    }
    printf(" | Pressione qualquer tecla para sair...");
    getchar();
    free(ser);
    fclose(fp);

}


char escAtualizarServico(void)
{    
    char op;
    system(" cls || clear");
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | -------------------- Atualizar Servico ------------------ | \n");
    printf(" |                                                           | \n");
    printf(" |                 1- Editar tudo                            | \n");
    printf(" |                 2- Editar o Nome                          | \n");
    printf(" |                 3- Editar o Custo                         | \n");
    printf(" |                 4- Editar a duracao do Servico            | \n");
    printf(" |                 5- Editar disponibilidade de servico      | \n");      
    printf(" |                                                           | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | Selecione uma opção do que você deseja editar: ");
    scanf("%c", &op);
    getchar();

    return op;

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

int listarServico(void) {
    FILE* fp;
    Dados_Servico* ser;
    fp = fopen("servicos.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        return 0;
    }
    ser = (Dados_Servico*)malloc(sizeof(Dados_Servico));
    while(fread(ser, sizeof(Dados_Servico), 1, fp)) {
        system(" cls || clear");
        printf(" | ===================== Listar Serviços ========================== | \n");
        printf(" |                                                                  | \n");
        exibe_servicos(ser);     
        printf(" | Pressione qualquer tecla para sair...");
        getchar();
    }

    fclose(fp);
    free(ser);
    return 0;

}

int listarServicoExc(void) {
    FILE* fp;
    Dados_Servico* ser;
    fp = fopen("servicos.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        return 0;
    }
    ser = (Dados_Servico*)malloc(sizeof(Dados_Servico));
    while(fread(ser, sizeof(Dados_Servico), 1, fp)) {
        if (ser->status == 'x') {
            system(" cls || clear");
            printf(" | ===================== Listar Serviços ========================== | \n");
            printf(" |                                                                  | \n");
            exibe_servicos(ser);     
            printf(" | Pressione qualquer tecla para sair...");
            getchar();
        } 
    }

    fclose(fp);
    free(ser);
    return 0;

}

int listarServicoCad(void) {
    int val;
    FILE* fp;
    Dados_Servico* ser;
    fp = fopen("servicos.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        return 0;
    }
    printf("\t========================================================\n");
    printf("\t Digite o limite Máximo de Custo (So Numeros!):");
    scanf("%d",&val);
    getchar();

    ser = (Dados_Servico*)malloc(sizeof(Dados_Servico));
    while(fread(ser, sizeof(Dados_Servico), 1, fp)) {
        
        int custo = atoi(ser->custo);
        if  (custo <= val && ser->status != 'x') {
            system(" cls || clear");
            printf(" | ===================== Listar Serviços ========================== | \n");
            printf(" |                                                                  | \n");
            exibe_servicos(ser);     
            printf(" | Pressione qualquer tecla para sair...");
            getchar();
        } 
    }

    fclose(fp);
    free(ser);
    return 0;

}

NoSer* listaOrdenadaSer(void) {
  FILE* fp;
  Dados_Servico* ser;
  NoSer* noSer;
  NoSer* lista;

  lista = NULL;
  fp = fopen("servicos.dat", "rb");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }

  ser = (Dados_Servico*) malloc(sizeof(Dados_Servico));
  while(fread(ser, sizeof(Dados_Servico), 1, fp)) {
    if (ser->status != 'x') {
      noSer = (NoSer*) malloc(sizeof(NoSer));
      
      noSer->cod = ser->cod;

      strcpy(noSer->codigo, ser->codigo);

      strcpy(noSer->nome, ser->nome);

      strcpy(noSer->custo, ser->custo);

      strcpy(noSer->tempo, ser->tempo);

      strcpy(noSer->disponi, ser->disponi);

      noSer->status = ser->status;

      if (lista == NULL) {
        lista = noSer;
        noSer->prox = NULL;
      } else if (strcmp(noSer->nome,lista->nome) < 0) {
        noSer->prox = lista;
        lista = noSer;
      } else {
        NoSer* anter = lista;
        NoSer* atual = lista->prox;
        while ((atual != NULL) && strcmp(atual->nome,noSer->nome) < 0) {
          anter = atual;
          atual = atual->prox;
        }
        anter->prox = noSer;
        noSer->prox = atual;
      }
    }
  }
  fclose(fp);
  free(ser);
  return lista;
}

void exibeListaSer(NoSer* lista){
    system(" cls || clear");
    while (lista != NULL) {
    printf(" | Código do Servico: %s\n", lista->codigo);
    printf(" | Nome: %s\n", lista->nome);
    printf(" | Duração: %s\n", lista->tempo);
    printf(" | Preco: %s\n", lista->custo);
    printf(" | Disponibilidade: %s\n", lista->disponi);
    printf(" | Status: %c\n", lista->status);
    printf("\n");
    getchar();
    system(" cls || clear");
    lista = lista->prox;
    }

}

int valida_ser(char* linha)
{
    FILE* fp3;
    Dados_Servico* teste;

    teste = (Dados_Servico*)malloc(sizeof(Dados_Servico));
    
    fp3 = fopen("servicos.dat", "rt");
    
    if (fp3 == NULL)
    {
        printf("Gerando arquivo...");
        fclose(fp3);
        return 1;
    }
    while (!feof(fp3))
    {
        fread(teste, sizeof(Dados_Servico), 1, fp3);
        if (strcmp(linha, teste->codigo) == 0   && (teste->status != 'x'))
        {
            fclose(fp3);
            return 0;
        }
    }
    fclose(fp3);
    return 1;
}

