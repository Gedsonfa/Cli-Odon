#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validar.h"
#include "structs.h"
#include "telas.h"


Dados_Paciente* tela_cadastrar_paciente(){

    Dados_Paciente* pac;
    pac = (Dados_Paciente*) malloc(sizeof(Dados_Paciente));

    system ("cls||clear");
    printf("\t===================================================\n");
    printf("\t===============   Cadastrar Paciente   ============\n");
    printf("\t===================================================\n\n");
    do
    {
        printf("\t === Insira o CPF (So Numeros):     ");
        scanf("%15[^\n]", pac->cpf);
        getchar();
        
    } while (!((validarCPF(pac->cpf)) && (valida_pac(pac->cpf))));
    

        printf("\t === Insira o nome:   ");
        scanf(" %51[^\n]", pac->nome);
        getchar();
        


    do {
        printf("\t === Insira a idade:  ");
        scanf(" %20[^\n]", pac->idade);
        getchar();
    } while (!lerNumeros(pac->idade));

    printf("\t === Insira o endereco:   ");
    scanf( "%51[^\n]",pac->endereco);
    getchar();
    

    printf("\t === Insira o e-mail: ");
    scanf( "%51[^\n]", pac->email);
    getchar();

    do {
        printf("\t === Insira o numero telefonico:  ");
        scanf("%20[^\n]", pac->numero);
        getchar();
    } while (!lerNumeros(pac->numero));
    pac->status = 'm';
  

    printf("\t==================================================\n\n");
    system("\tPause");
    system("cls | clear");
    return pac;
    

}

void grava_paciente(Dados_Paciente* pac){
    FILE* fp;
    fp = fopen("pacientes.dat", "ab");
    if(fp==NULL){
        printf("Ops! Ocorreu  ka um erro na abertura do arquivo!\n");
        printf("Não é possivel continuar esse programa...\n");
        exit(1);
    }
    fwrite(pac, sizeof(Dados_Paciente),1,fp);
    fclose(fp);
}

Dados_Paciente* buscaPaciente(void){
    FILE* fp;
    Dados_Paciente* pac;
    char pes[15];
    do {
        printf("\n ===== Buscar Paciente ======");
        printf("\n Informe seu CPF (So Numeros): ");
        scanf("%s", pes);
        getchar();
        if (!validarCPF(pes)) {
            printf(" | Digite um CPF cadastrado!!!\n");
        }
    } while (!validarCPF(pes));
    pac = (Dados_Paciente*) malloc(sizeof(Dados_Paciente));
    fp = fopen("pacientes.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Ocorreu  ko um erro na abertura do arquivo!\n");
        printf("Não é possível continuar este programa...\n");
        exit(1);
    }
    while(!feof(fp)){
        fread(pac, sizeof(Dados_Paciente), 1, fp);
        if ((strcmp(pac -> cpf, pes) == 0) &&(pac->status != 'x')){
            fclose(fp);
            return pac;
        }
    }
fclose(fp);
return NULL;
}

void tela_pesquisar_paciente(Dados_Paciente* pac)
{ 
    system ("cls||clear");
    printf("\t===================================================\n");
    printf("\t===============   Pesquisar Paciente   ============\n");
    printf("\t===================================================\n\n");
    
    
    if((pac == NULL) || (pac->status == 'x')){
        printf("Paciente nao encontrado");
    }else{
        printf(" | ============== Paciente encontrado =============\n");
        printf(" | Nome: %s\n", pac->nome);
        printf(" | Idade: %s\n", pac->idade);
        printf(" | Email: %s\n", pac->email);
        printf(" | Endereco: %s\n", pac->endereco);
        printf(" | Numero: %s\n", pac->numero);
        printf(" | ================================================\n");
        printf(" | aperte ENTER para continuar");
        getchar();
        system(" cls| clear");

    }

}

void exibe_pacientes(Dados_Paciente* pac) {

    printf(" | CPF: %s\n", pac->cpf);
    printf(" | Nome: %s\n", pac->nome);
    printf(" | Idade: %s\n", pac->idade);
    printf(" | E-mail de contato: %s\n", pac->email);
    printf(" | Endereco: %s\n", pac->endereco);
    printf(" | Numero de contato: %s\n", pac->numero);
    printf(" | Status: %c\n", pac->status);
    printf("\n");
}


void tela_alterar_paciente(){
    FILE* fp;
    Dados_Paciente* pac;
    int achou;
    char esc;
    char resp;
    char procurando[20];


    fp = fopen("pacientes.dat", "r+b");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
}
    pac = (Dados_Paciente*) malloc(sizeof(Dados_Paciente));
    system ("cls||clear");
    printf("\t===================================================\n");
    printf("\t================   Alterar Paciente   =============\n");
    printf("\t===================================================\n\n");
    printf("\t === Insira o CPF (So Numeros):    ");
    scanf("%s", procurando);
    getchar();
    achou = 0;

    while((!achou) && (fread(pac, sizeof(Dados_Paciente), 1, fp))) {
    if ((strcmp(pac->cpf, procurando) == 0) && (pac->status == 'm')) {
    achou = 1;
    }if (achou) {
        exibe_pacientes(pac);
        printf(" Deseja realmente editar este paciente? [s/n] ");
        scanf("%c", &resp);
        getchar();
        if (resp == 's' || resp == 'S') {
        
        esc = escAtualizarPaciente();

        if (esc == '1'){

                printf(" | Informe novo nome: ");
                scanf("%[A-Z a-z]", pac->nome);
                getchar();


                printf(" | Informe a nova idade: ");
                scanf("%20[^\n]",pac->idade);
                getchar();

                printf(" | Informe o novo email: ");
                scanf("%s", pac->email);
                getchar();

                printf(" | Informe o novo endereço: ");
                scanf("%[A-Z a-z 0-9]", pac->endereco);
                getchar();

                printf(" | Informe o novo numero: ");
                scanf("%20[^\n]", pac->numero);
                getchar();


    } else if (esc == '2'){
                
                printf(" | Informe novo nome: ");
                scanf("%[A-Z a-z]", pac->nome);
                getchar();

    } else if (esc == '3'){

                printf(" | Informe a nova idade: ");
                scanf("%20[^\n]",pac->idade);
                getchar();

    } else if (esc == '4'){

                printf(" | Informe o novo email: ");
                scanf("%s", pac->email);
                getchar();
    } else if (esc == '5'){
                printf(" | Informe o novo endereço: ");
                scanf("%[A-Z a-z 0-9]", pac->endereco);
                getchar();

    } else if (esc == '6') {
                printf(" | Informe o novo numero: ");
                scanf("%20[^\n]", pac->numero);
                getchar();
    }
    pac->status = 'm';
    fseek(fp, (-1)*sizeof(Dados_Paciente), SEEK_CUR);
    fwrite(pac, sizeof(Dados_Paciente), 1, fp);
    printf("\nUsuario editado com sucesso!!!\n");



    } else {
        printf("Tudo bem, os dados não foram alterados!");
    }
    
    } 
    }
    printf(" | Pressione qualquer tecla para sair...");
    getchar();
    free(pac);
    fclose(fp);

}

char escAtualizarPaciente(void)
{    
    char op;
    system(" cls || clear");
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ------------------- Atualizar Paciente ------------------ | \n");
    printf(" |                                                           | \n");
    printf(" |                 1- Editar tudo                            | \n");
    printf(" |                 2- Editar nome                            | \n");
    printf(" |                 3- Editar idade                           | \n");
    printf(" |                 4- Editar email                           | \n");
    printf(" |                 5- Editar endereço                        | \n");  
    printf(" |                 6- Editar telefone                        | \n");    
    printf(" |                                                           | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | Selecione uma opção do que você deseja editar: ");
    scanf("%c", &op);
    getchar();

    return op;

}

void tela_excluir_paciente(){

    FILE* fp;
    Dados_Paciente* pac;
    int achou;
    char resp;
    char procurado[15];
    fp = fopen("pacientes.dat", "r+b");
    if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
    }
    printf("\n\n");
    system ("cls||clear");
    printf("=========================================\n");
    printf("====== Apagar Cadastro de Paciente ======\n");
    printf("========================================= \n");
    printf("Informe o CPF do Paciente: ");
    scanf(" %14[^\n]", procurado);
    pac = (Dados_Paciente*) malloc(sizeof(Dados_Paciente));
    achou = 0;
    while((!achou) && (fread(pac, sizeof(Dados_Paciente), 1, fp))) {
    if ((strcmp(pac->cpf, procurado) == 0) && (pac->status == 'm')) {
        achou = 1;
    }
    }

    if (achou) {
    exibe_pacientes(pac);
    getchar();
    printf("Deseja realmente apagar este Paciente (s/n)? ");
    scanf("%c", &resp);
    getchar();
    if (resp == 's' || resp == 'S') {
        pac->status = 'x';
        fseek(fp, -1*sizeof(Dados_Paciente), SEEK_CUR);
        fwrite(pac, sizeof(Dados_Paciente), 1, fp);
        printf("\nPaciente excluído com sucesso!!!\n");
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
    free(pac);
}


int listarPacientes(void) {
    FILE* fp;
    Dados_Paciente* pac;
    fp = fopen("pacientes.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        return 0;
    }
    pac = (Dados_Paciente*)malloc(sizeof(Dados_Paciente));
    while(fread(pac, sizeof(Dados_Paciente), 1, fp)) {
        system(" cls || clear");
        printf(" | ===================== Listar Pacientes ======================== | \n");
        printf(" |                                                                 | \n");
        exibe_pacientes(pac);    
        printf(" | Pressione qualquer tecla para sair...");
        getchar(); 
    }

    fclose(fp);
    free(pac);
    return 0;

}

int listarPacientesExc(void) {
    FILE* fp;
    Dados_Paciente* pac;
    fp = fopen("pacientes.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        return 0;
    }
    pac = (Dados_Paciente*)malloc(sizeof(Dados_Paciente));
    while(fread(pac, sizeof(Dados_Paciente), 1, fp)) {
        if (pac->status == 'x') {
            system(" cls || clear");
            printf(" | ===================== Listar Pacientes ======================== | \n");
            printf(" |                                                                 | \n");
            exibe_pacientes(pac);    
            printf(" | Pressione qualquer tecla para sair...");
            getchar(); 
        }
    }

    fclose(fp);
    free(pac);
    return 0;

}

int listarPacientesCad(void) {
    
    FILE* fp;
    Dados_Paciente* pac;
    int ida;
    fp = fopen("pacientes.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        return 0;
    }

    printf("\t========================================================\n");
    printf("\t Digite o limite Máximo de idade (So Numeros!):");
    scanf("%d",&ida);
    getchar();
    
    pac = (Dados_Paciente*)malloc(sizeof(Dados_Paciente));
    while(fread(pac, sizeof(Dados_Paciente), 1, fp)) {
        
        int idade = atoi(pac->idade);
        if  (idade <= ida && pac->status != 'x') {
            system(" cls || clear");
            printf(" | ===================== Listar Pacientes ======================== | \n");
            printf(" |                                                                 | \n");
            exibe_pacientes(pac);    
            printf(" | Pressione qualquer tecla para sair...");
            getchar(); 
        }
    }

    fclose(fp);
    free(pac);
    return 0;

}

NoPac* listaOrdenadaPac(void) {
  FILE* fp;
  Dados_Paciente* pac;
  NoPac* noPac;
  NoPac* lista;

  lista = NULL;
  fp = fopen("pacientes.dat", "rb");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }

  pac = (Dados_Paciente*) malloc(sizeof(Dados_Paciente));
  while(fread(pac, sizeof(Dados_Paciente), 1, fp)) {
    if (pac->status != 'x') {
      noPac = (NoPac*) malloc(sizeof(NoPac));
      
      noPac->cod = pac->cod;

      strcpy(noPac->nome, pac->nome);

      strcpy(noPac->cpf, pac->cpf);

      strcpy(noPac->idade, pac->idade);

      strcpy(noPac->email, pac->email);

      strcpy(noPac->endereco, pac->endereco);

      strcpy(noPac->numero, pac->numero);

      noPac->status = pac->status;

      if (lista == NULL) {
        lista = noPac;
        noPac->prox = NULL;
      } else if (strcmp(noPac->nome,lista->nome) < 0) {
        noPac->prox = lista;
        lista = noPac;
      } else {
        NoPac* anter = lista;
        NoPac* atual = lista->prox;
        while ((atual != NULL) && strcmp(atual->nome,noPac->nome) < 0) {
          anter = atual;
          atual = atual->prox;
        }
        anter->prox = noPac;
        noPac->prox = atual;
      }
    }
  }
  fclose(fp);
  free(pac);
  return lista;
}

void exibeListaPac(NoPac* lista){
    system(" cls || clear");
    while (lista != NULL) {
    printf(" | CPF: %s\n", lista->cpf);
    printf(" | Nome: %s\n", lista->nome);
    printf(" | Idade: %s\n", lista->idade);
    printf(" | E-mail de contato: %s\n", lista->email);
    printf(" | Endereco: %s\n", lista->endereco);
    printf(" | Numero de contato: %s\n", lista->numero);
    printf(" | Status: %c\n", lista->status);
    printf("\n");
    getchar();
    system(" cls || clear");
    lista = lista->prox;
    }
}

int valida_pac(char* linha)
{
    FILE* fp3;
    Dados_Paciente* teste;

    teste = (Dados_Paciente*)malloc(sizeof(Dados_Paciente));
    
    fp3 = fopen("pacientes.dat", "rt");
    
    if (fp3 == NULL)
    {
        printf("Gerando arquivo...");
        fclose(fp3);
        return 1;
    }
    while (!feof(fp3))
    {
        fread(teste, sizeof(Dados_Paciente), 1, fp3);
        if (strcmp(linha, teste->cpf) == 0    && (teste->status != 'x'))
        {
            fclose(fp3);
            return 0;
        }
    }
    fclose(fp3);
    return 1;
}
