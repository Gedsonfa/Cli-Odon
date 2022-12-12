#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validar.h"
#include "structs.h"


char* get_nome_agendamento(char* cpf) 
{

  Dados_Paciente* pac;
  FILE* fp;
  char* nome;

  nome = (char*) malloc(81*sizeof(char));

  pac = (Dados_Paciente*)malloc(sizeof(Dados_Paciente));
  fp = fopen("pacientes.dat", "rb");

    if (fp == NULL)
    {
        printf("Ocorreu um erro na abertura do arquivo, não é possivel continuar o programa");
        exit(1);
    }

    while (!feof(fp))
    { // Busca até o final do arquivo
        fread(pac, sizeof(Dados_Paciente), 1, fp);
        if (strcmp(pac->cpf, cpf) == 0 && (pac->status != 'x'))
        { /*Verifica se o código é igual e o status*/
            fclose(fp);
            strcpy(nome, pac->nome);
            free(pac);
            return nome;
        }
    }

    fclose(fp);
    free(pac);
    return NULL;

}

char* get_nome_full(char* cpf) 
{
  Dados_Paciente* pac;
  FILE* fp;
  char* nome;

  nome = (char*) malloc(81*sizeof(char));

  pac = (Dados_Paciente*)malloc(sizeof(Dados_Paciente));
  fp = fopen("pacientes.dat", "rb");

    if (fp == NULL)
    {
        printf("Ocorreu um erro na abertura do arquivo, não é possivel continuar o programa");
        exit(1);
    }

    while (!feof(fp))
    { // Busca até o final do arquivo
        fread(pac, sizeof(Dados_Paciente), 1, fp);
        if (strcmp(pac->cpf, cpf) == 0)
        { /*Verifica se o código é igual e o status*/
            fclose(fp);
            strcpy(nome, pac->nome);
            free(pac);
            return nome;
        }
    }

    fclose(fp);
    free(pac);
    return NULL;

}



Dados_Agendamento* tela_cadastrar_agendamento(void){

    Dados_Agendamento* age;
    age = (Dados_Agendamento*) malloc(sizeof(Dados_Agendamento));
    char* nome_pac;
    system ("cls||clear");
    printf("\t=====================================================\n");
    printf("\t===============   Cadastrar Agendamento   ===========\n");
    printf("\t=====================================================\n\n");
    
    do{
        printf("\t === Insira o CPF do paciente (So Numeros):    ");
        scanf("%s", age->cpf);
        getchar();
    }while(!validarCPF(age->cpf));


    nome_pac = get_nome_agendamento(age->cpf);
    if (nome_pac != NULL) 
    {
        printf("\t ================================= \n");
        printf("\t Paciente encontrado com sucesso!\n");
        printf("\t Nome do Paciente: %s\n", nome_pac);
        printf("\t ================================= \n");
        free(nome_pac);

        printf("\t === Insira o codigo do Agendamento:  ");
        scanf("%10[^\n]", age->codigo_servico);
        getchar();

        printf("\t === Insira a data de agendamento '00/00/0000':   ");
        scanf("%s", age->data);
        getchar();

        printf("\t === Insira o horario:   ");
        scanf("%s", age->hora);
        getchar();

        age->status = 'm';
        return age;
        printf("\t==================================================\n\n");
        system("\tPause");
        system("cls | clear");
        printf(" Aperte ENTER para continuar...");
        getchar();
   
    } else {
        printf("\t ================================= \n");
        printf("\t Ops, Paciente não encontrado!\n");
        printf("\t Verifique se esse cadastro existe ou está ativo!\n");
        printf("\t ================================= \n\n");
        printf("\t==================================================\n\n");
        system("\tPause");
        system("cls | clear");
        return NULL;
    }


}



void grava_agendamento(Dados_Agendamento* age){
    FILE* fp;
    fp = fopen("agendamentos.dat", "ab");
    if(fp==NULL){
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possivel continuar esse programa...\n");
        exit(1);
    }
    fwrite(age,sizeof(Dados_Agendamento),1,fp);
    fclose(fp);
}

Dados_Agendamento* buscar_agendamento(){
    FILE* fp;
    Dados_Agendamento* age;
    char men[15];

    printf("\n ===== Buscar Agendamento ======");
    printf("\n Informe o Codigo do agendamento: ");
    scanf("%s", men);
    getchar();
    
    age = (Dados_Agendamento*) malloc(sizeof(Dados_Agendamento));
    fp = fopen("agendamentos.dat", "rb");

    if (fp == NULL) {
        printf("Ops! Ocorreu  ko um erro na abertura do arquivo!\n");
        printf("Não é possível continuar este programa...\n");
        exit(1);
    }
    while(!feof(fp)){
        fread(age, sizeof(Dados_Agendamento), 1, fp);
        if ((strcmp(age -> codigo_servico, men) == 0) &&(age->status != 'x')){
            fclose(fp);
            return age;
        }
    }
fclose(fp);
return NULL;
}


void tela_pesquisar_agendamento(Dados_Agendamento* age){

    char* nome_pac;
    system ("cls||clear");
    printf("\t===================================================\n");
    printf("\t============   Pesquisar Agendamento   ============\n");
    printf("\t===================================================\n\n");
    if((age == NULL) || (age->status == 'x')){
        printf("Agendamento nao encontrado");
    }else{
        
        nome_pac = get_nome_full(age->cpf);
        printf(" | ============== Agendamento encontrado ========\n");
        printf(" | Nome do Paciente: %s\n", nome_pac);
        printf(" | CPF : %s\n", age->cpf);
        printf(" | Codigo do agendamento: %s\n", age->codigo_servico);
        printf(" | Data do agendamento: %s\n", age->data);
        printf(" | Horario: %s\n", age->hora);
        printf(" | ==============================================\n");
        printf(" | aperte ENTER para continuar");
        getchar();
        system(" cls| clear");
        free(nome_pac);
    }

}

void exibe_agendamento(Dados_Agendamento* age) {
    char* nome_pac;
    nome_pac = get_nome_full(age->cpf);
    printf(" | Nome do Paciente: %s\n", nome_pac);
    printf(" | Codigo do Agendamento: %s\n", age->codigo_servico);
    printf(" | CPF: %s\n", age->cpf);
    printf(" | Data do Agendamento: %s\n", age->data);
    printf(" | Horario do Agendamento: %s\n", age->hora);
    printf(" | Status: %c\n", age->status);
    printf("\n");


}

int listarAgendamentos(void)
{
    FILE* fp;
    Dados_Agendamento* age;
    fp = fopen("agendamentos.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        return 0;
    }
    age = (Dados_Agendamento*)malloc(sizeof(Dados_Agendamento));
    while(fread(age, sizeof(Dados_Agendamento), 1, fp)) {
        system(" cls || clear");
        printf(" | ===================== Lista Agendamentos ======================== | \n");
        printf(" |                                                                   | \n");
        exibe_agendamento(age);    
        printf(" | Pressione qualquer tecla para sair...");
        getchar();
    }

    fclose(fp);
    free(age);
    return 0;

}

int listarAgendamentosExc(void)
{
    FILE* fp;
    Dados_Agendamento* age;
    fp = fopen("agendamentos.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        return 0;
    }
    age = (Dados_Agendamento*)malloc(sizeof(Dados_Agendamento));
    while(fread(age, sizeof(Dados_Agendamento), 1, fp)) {
        if (age->status == 'x') {
            system(" cls || clear");
            printf(" | ===================== Lista Agendamentos ======================== | \n");
            printf(" |                                                                   | \n");
            exibe_agendamento(age);    
            printf(" | Pressione qualquer tecla para sair...");
            getchar();
        }
    } 
    fclose(fp);
    free(age);
    return 0;

}

int listarAgendamentosCad(void)
{
    char proc [20];
    FILE* fp;
    Dados_Agendamento* age;
    fp = fopen("agendamentos.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        return 0;
    }
    printf("\t===================================\n");
    printf("\t Digite a data que procura '00/00/000': ");
    scanf("%s",proc);
    getchar();

    age = (Dados_Agendamento*)malloc(sizeof(Dados_Agendamento));// &&
    while(fread(age, sizeof(Dados_Agendamento), 1, fp)) {
        if ((strcmp(age -> data, proc) == 0) && (age->status != 'x'))  {
            system(" cls || clear");
            printf(" | ===================== Lista Agendamentos ======================== | \n");
            printf(" |                                                                   | \n");
            exibe_agendamento(age);    
            printf(" | Pressione qualquer tecla para sair...");
            getchar();
        }
    }

    fclose(fp);
    free(age);
    return 0;

}

void tela_alterar_agendamento(){
    FILE* fp;
    Dados_Agendamento* age;
    int achou;
    char resp;
    char esc;
    char procurando[20];



    fp = fopen("agendamentos.dat", "r+b");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
}
    age = (Dados_Agendamento*) malloc(sizeof(Dados_Agendamento));
    system ("cls||clear");
    printf("\t===================================================\n");
    printf("\t===============   Alterar Agendamento   ===========\n");
    printf("\t===================================================\n");
    printf("\t Digite o CPF do Cliente: ");
    scanf("%s", procurando);
    getchar();
    achou = 0;
    
    while((!achou) && (fread(age, sizeof(Dados_Agendamento), 1, fp))) {
    if ((strcmp(age->cpf, procurando) == 0) && (age->status == 'm')) {
    achou = 1;
    }if (achou) {
        exibe_agendamento(age);
        printf(" Deseja realmente editar este usuario? [s/n] ");
        scanf("%c", &resp);
        getchar();
        if (resp == 's' || resp == 'S') {
        
        esc = escAtualizarAgendamento();

        if (esc == '1'){

                printf(" | Informe novo CPF (So Numeros): ");
                scanf("%[0-9]", age->cpf);
                getchar();


                printf(" | Informe o nova data '00/00/0000': ");
                scanf("%20[^\n]",age->data);
                getchar();

                printf(" | Escolha seu novo Horário: ");
                scanf("%20[^\n]", age->hora);
                getchar();


    } else if (esc == '2'){
                printf(" | Informe novo CPF: ");
                scanf("%[0-9]", age->cpf);
                printf(" | Novo nome alterado com sucesso!");
                getchar();
    } else if (esc == '3'){
                printf(" | Informe o nova data '00/00/0000': ");
                scanf("%20[^\n]",age->data);
                printf(" | Nova data alterada com sucesso!");
                getchar();
    } else if (esc == '4'){
                printf(" | Escolha seu novo Horário: ");
                scanf("%20[^\n]", age->hora);
                printf(" | Novo horário alterado com sucesso!");
                getchar();
    }
    age->status = 'm';
    fseek(fp, (-1)*sizeof(Dados_Agendamento), SEEK_CUR);
    fwrite(age, sizeof(Dados_Agendamento), 1, fp);
    printf("\nUsuario editado com sucesso!!!\n");



    } else {
        printf("Tudo bem, os dados não foram alterados!");
    }
    
    } 
    }
    printf(" | Pressione qualquer tecla para sair...");
    getchar();
    free(age);
    fclose(fp);

}


char escAtualizarAgendamento(void)
{    
    char op;
    system(" cls || clear");
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ----------- ------ Atualizar Agendamento ---------------- | \n");
    printf(" |                                                           | \n");
    printf(" |                 1- Editar tudo                            | \n");
    printf(" |                 2- Editar CPF                             | \n");
    printf(" |                 3- Editar data                            | \n");
    printf(" |                 4- Editar horário                         | \n");  
    printf(" |                                                           | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | Selecione uma opção do que você deseja editar: ");
    scanf("%c", &op);
    getchar();

    return op;

}



void tela_excluir_agendamento(){

    
    FILE* fp;
    Dados_Agendamento* age;
    int achou;
    char resp;
    char procurado[20];
    fp = fopen("agendamentos.dat", "r+b");
    if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
    }
    printf("\n\n");
    system ("cls||clear");
    printf("==================================================\n");
    printf("============== Apagar Agendamento ================\n");
    printf("==================================================\n");
    printf("Informe o codigo do agendamento a ser apagado: ");
    scanf(" %19[^\n]", procurado);
    age = (Dados_Agendamento*) malloc(sizeof(Dados_Agendamento));
    achou = 0;
    while((!achou) && (fread(age, sizeof(Dados_Agendamento), 1, fp))) {
    if ((strcmp(age->codigo_servico, procurado) == 0) && (age->status == 'm')) {
        achou = 1;
    }
    }

    if (achou) {
    exibe_agendamento(age);
    getchar();
    printf("Deseja realmente apagar este Agendamento (s/n)? ");
    scanf("%c", &resp);
    getchar();
    if (resp == 's' || resp == 'S') {
        age->status = 'x';
        fseek(fp, -1*sizeof(Dados_Agendamento), SEEK_CUR);
        fwrite(age, sizeof(Dados_Agendamento), 1, fp);
        printf("\nAgendamento excluído com sucesso!!!\n");
        printf("Aperte ENTER para continuar...");
        getchar();
        } else {
        printf("\nOk, os dados não foram alterados\n");
        printf("Aperte ENTER para continuar...");
        getchar();
        }
    } else {
    printf("O animal %s não foi encontrado...\n", procurado);
    printf("Aperte ENTER para continuar...");
    getchar();
    }
    fclose(fp);
    free(age);
}



//update

