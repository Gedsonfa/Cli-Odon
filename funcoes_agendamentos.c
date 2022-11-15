#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validar.h"
#include "structs.h"

Dados_Agendamento* tela_cadastrar_agendamento(){

    Dados_Agendamento* age;
    age = (Dados_Agendamento*) malloc(sizeof(Dados_Agendamento));

    system ("cls||clear");
    printf("\t===================================================\n");
    printf("\t===============   Cadastrar Agendamento   ============\n");
    printf("\t===================================================\n\n");
    
    do{
        printf("\t === Insira o CPF do paciente:    ");
        scanf("%15[^\n]", age->cpf);
        getchar();
    }while(!validarCPF(age->cpf));

    printf("\t === Insira o codigo do servico:  ");
    scanf("%10[^\n]", age->codigo_servico);
    getchar();

    printf("\t === Insira a data de agendamento:   ");
    scanf("%15[^\n]", age->data);
    getchar();

    printf("\t === Insira o horario:   ");
    scanf("%15[^\n]", age->hora);
    getchar();

    age->status = 'm';
    return age;

    printf("\t==================================================\n\n");
    system("\tPause");
    system("cls | clear");
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
    printf("\n Informe o codigo de servico: ");
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

    system ("cls||clear");
    printf("\t===================================================\n");
    printf("\t============   Pesquisar Agendamento   ============\n");
    printf("\t===================================================\n\n");
    if((age == NULL) || (age->status == 'x')){
        printf("Agendamento nao encontrado");
    }else{
        printf(" | ============== Agendamento encontrado ========\n");
        printf(" | CPF : %s\n", age->cpf);
        printf(" | Codigo do agendamento: %s\n", age->codigo_servico);
        printf(" | Data do agendamento: %s\n", age->data);
        printf(" | Horario: %s\n", age->hora);
        printf(" | ==============================================\n");
        printf(" | aperte ENTER para continuar");
        getchar();
        system(" cls| clear");
    }

}

void exibe_agendamento(Dados_Agendamento* age) {
    printf("Codigo do Agendamento: %s\n", age->codigo_servico);
    printf("CPF: %s\n", age->cpf);
    printf("Data do Agendamento: %s\n", age->data);
    printf("Horario do Agendamento: %s\n", age->hora);
    printf("Status: %c\n", age->status);
    printf("\n");

}

void tela_alterar_agendamento(){
//    FILE* fp;
//    Dados_Agendamento* age;
//    int achou;
//    char resp;
    char procurando[20];
//    age = (Dados_Agendamento*) malloc(sizeof(Dados_Agendamento));
//    achou = 0;
//
//    fp = fopen("agendamento.dat", "r+b");
//    if (fp == NULL) {
//        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
//        printf("Não é possível continuar o programa...\n");
//        exit(1);
//  }

    system ("cls||clear");
    printf("\t===================================================\n");
    printf("\t===============   Alterar Agendamento   ===========\n");
    printf("\t===================================================\n");
    printf("\t Digite o CPF do Cliente: \n");
    scanf("%s", procurando);
    getchar();
    
//    while((!achou) && (fread(age, sizeof(Dados_Agendamento), 1, fp))) {
//    if ((strcmp(age->cpf, procurando) == 0) && (age->status == '1')) {
//     achou = 1;
//   }if (achou) {
//        exibe_agendamento(age);
//        printf(" Deseja realmente editar este usuario? [s/n] ");
//        scanf("%c", &resp);
//        getchar();
//        if (resp == 's' || resp == 'S') {
//    
//
//        printf(" | Informe o novo nome: ");
//        scanf("%10[^\n]", age->codigo_servico);
//        getchar();
//
//
//        printf(" | Informe o nova data 00/00/0000: ");
//        scanf("%15[^\n]",&age->data);
//        getchar();
//
//        printf(" | Escolha seu novo Horário: ");
//        scanf("%15[^\n]", age->hora);
//        getchar();
//
//
//        age->status = '1';
//        fseek(fp, (-1)*sizeof(Dados_Agendamento), SEEK_CUR);
//        fwrite(age, sizeof(Dados_Agendamento), 1, fp);
//        printf("\nUsuario editado com sucesso!!!\n");
//        grava_agendamento(age);
//        printf(" Pressione qualquer tecla para sair... ");
//        getchar();
//
//    } else {
//        printf("Tudo bem, os dados não foram alterados!");
//    }
//  
//   } 
//  
//}
//free(age);
//fclose(fp);
//
}

void tela_excluir_agendamento(){

    
    FILE* fp;
    Dados_Agendamento* age;
    int achou;
    char resp;
    char procurado[15];
    fp = fopen("agendamentos.dat", "r+b");
    if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
    }
    printf("\n\n");
    system ("cls||clear");
    printf("=============================\n");
    printf("==== Apagar Agendamento =====\n");
    printf("============================= \n");
    printf("Informe o agendamento a ser apagado: ");
    scanf(" %14[^\n]", procurado);
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

