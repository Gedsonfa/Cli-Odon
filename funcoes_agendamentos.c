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
    printf("\t === Insria o codigo do agendamento: ");
    fgets(age->codigo_agendamento,6,stdin);
    do{
        printf("\t === Insira o CPF do paciente:    ");
        scanf("%15[^\n]", age->cpf_paciente);
        getchar();
    }while(!validarCPF(age->cpf_paciente));

    printf("\t === Insira o codigo do servico:  ");
    scanf("%6[^\n]", age->codigo_servico);
    getchar();

    do{
        printf("\t === Insira o CPF do funcionario: ");
        scanf("%15[^\n]", age->cpf_funcionario);
        getchar();
    }while(!validarCPF(age->cpf_funcionario));

    printf("\t === Insira a data:   ");
    fgets(age->data,11,stdin);

    printf("\t === Insira o horario:   ");
    fgets(age->hora,6,stdin);

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

Dados_Agendamento* tela_pesquisar_agendamento() {
    FILE* fp;
    Dados_Agendamento* age;
    char cpf[15];
    system ("cls||clear");
    printf("\t===================================================\n");
    printf("\t===============   Pesquisar Agendamento   ============\n");
    printf("\t===================================================\n\n");
    printf("Insira o CPF do paciente: ");
    scanf("%s", cpf);
    age = (Dados_Agendamento*) malloc(sizeof(Dados_Agendamento));
    fp = fopen("agendamentos.dat", "rb");
    if (fp==NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possivel continuar esse programa...\n");
        exit(1);
    }
    while (!feof(fp)) {
        fread(age, sizeof(Dados_Agendamento), 1, fp);
        if ((age->cpf_paciente == cpf) && (age->status != 'x')) {
            fclose(fp);
            return age;
        }
    }
    fclose(fp);
    return NULL;
    printf("\t==================================================\n\n");
    
    system("\tPause");
    system("cls | clear");

}

void exibeAgendamento (Dados_Agendamento* age) {
    char situacao[20];
    if ((age == NULL) || (age->status == 'x')) {
        printf("\n = Agendamento Inexistente = \n");
    } else {
        printf("\n = Agendamento Cadastrado =\n");
        printf("\nCodigo do agendamento: %s\n", age->codigo_agendamento);
        printf("\nCPF do paciente: %s\n", age->cpf_paciente);
        printf("\nCodigo do serviço: %s\n", age->codigo_servico);
        printf("\nCPF do funcionário: %s\n", age->cpf_funcionario);
        printf("\nData: %s\n", age->data);
        printf("\nHora: %s\n", age->hora);
        if (age->status == 'm') {
            strcpy(situacao, "Cadastrado");
        } else if (age->status == 'r') {
            strcpy(situacao, "Removido");
        } else {
            strcpy(situacao, "Não Informado");
        }
        printf("\nSituação do agendamento: %s\n", situacao);
    }
}

void tela_alterar_agendamento(void) {
    FILE* fp;
    Dados_Agendamento* age;
    int achou;
    char resp;
    char procurado[7];
    fp = fopen("agendamentos.dat", "r+b");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    system ("cls||clear");
    printf("\t===================================================\n");
    printf("\t===============   Alterar Agendamento   ============\n");
    printf("\t===================================================\n\n");
    printf("Informe o codigo do agendamento a ser alterado: ");
    scanf("%6[^\n]", procurado);
    age = (Dados_Agendamento*) malloc(sizeof(Dados_Agendamento));
    achou = 0;
    while((!achou) && (fread(age, sizeof(Dados_Agendamento), 1, fp))) {
        if ((strcmp(age->codigo_agendamento, procurado) == 0) && (age->status == 'm')) {
            achou = 1;
        }
    }
    if (achou) {
        exibeAgendamento(age);
        getchar();
        printf("Deseja realmente editar esse agendamento ? (s/n)");
        scanf("%c", &resp);
        if (resp == 's' || resp == 'S') {
            printf("\t === Insria o codigo do agendamento: ");
            fgets(age->codigo_agendamento,6,stdin);
            do {
                printf("\t === Insira o CPF do paciente:    ");
                scanf("%15[^\n]", age->cpf_paciente);
                getchar();
            } while (!validarCPF(age->cpf_paciente));
            printf("\t === Insira o codigo do servico:  ");
            scanf("%6[^\n]", age->codigo_servico);
            getchar();
            do {
                printf("\t === Insira o CPF do funcionario: ");
                scanf("%15[^\n]", age->cpf_funcionario);
                getchar();
            } while (!validarCPF(age->cpf_funcionario));
            printf("\t === Insira a data:   ");
            fgets(age->data,11,stdin);
            printf("\t === Insira o horario:   ");
            fgets(age->hora,6,stdin);
            age->status = 'm';
            fseek(fp, (-1)*sizeof(Dados_Agendamento), SEEK_CUR);
            fwrite(age, sizeof(Dados_Agendamento), 1, fp);
            printf("\nAgendamento editado com sucesso!!!\n");
        } else {
            printf("\nOK, os dados não foram alterados\n");
        }
    } else {
        printf("O agendamento %s não foi encontrado...\n", procurado);
      }
    free(age);
    fclose(fp);
    printf("\t==================================================\n\n");
    
    system("\tPause");
    system("cls | clear");

}

void listaAgendamento(void) {
    FILE* fp;
    Dados_Agendamento* age;
    system ("cls||clear");
    printf("\t===================================================\n");
    printf("\t===============   Lista de Agendamentos   ============\n");
    printf("\t===================================================\n\n");
    age = (Dados_Agendamento*) malloc(sizeof(Dados_Agendamento));
    fp = fopen("agendamentos.dat", "rb");
    if (fp==NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possivel continuar esse programa...\n");
        exit(1);
    }
    while (fread(age, sizeof(Dados_Agendamento), 1, fp)) {
        if (age->status != 'x') {
            exibeAgendamento(age);
        }
    }
}

void tela_excluir_agendamento(void) {
    FILE* fp;
    Dados_Agendamento* age;
    int achou;
    char resp;
    char procurado[7];
    fp = fopen("agendamentos.dat", "r+b");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possivel continuar esse programa...\n");
        exit(1);
    }
    system ("cls||clear");
    printf("\t===================================================\n");
    printf("\t===============   Excluir Agendamento   ============\n");
    printf("\t===================================================\n\n");
    printf("Informe o codigo do agendamento a ser apagado: ");
    scanf("%6[^\n]", procurado);
    age = (Dados_Agendamento*) malloc(sizeof(Dados_Agendamento));
    achou = 0;
    while ((!achou) && (fread(age, sizeof(Dados_Agendamento), 1, fp))) {
        if ((strcmp(age->codigo_agendamento, procurado) == 0) && (age->status == 'm')) {
            achou = 1;
        }
    }
    if (achou) {
        exibeAgendamento(age);
        getchar();
        printf("Deseja realmente apagar este agendamento ? (s/n)");
        scanf("%c", &resp);
        if (resp == 's' || resp == 'S') {
            age->status = 'x';
            fseek(fp, (-1)*sizeof(Dados_Agendamento), SEEK_CUR);
            fwrite(age, sizeof(Dados_Agendamento), 1, fp);
            printf("\nAgendamento excluído com sucesso!!!\n");
        } else {
            printf("\nOk, os dados não foram alterados\n");
        }
    } else {
        printf("O agendamento %s não foi encontado...", procurado);
      }
    free(age);
    fclose(fp);
    printf("\t==================================================\n\n");
    
    system("\tPause");
    system("cls | clear");

}