#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validar.h"
#include "structs.h"

Dados_Paciente* tela_cadastrar_paciente(void) {

    Dados_Paciente* pac;
    pac = (Dados_Paciente*) malloc(sizeof(Dados_Paciente));

    system ("cls||clear");
    printf("\t===================================================\n");
    printf("\t===============   Cadastrar Paciente   ============\n");
    printf("\t===================================================\n\n");
    do {
        printf("\t === Insira o CPF (apenas digitos):     ");
        scanf(" %14[^\n]", pac->cpf);
        getchar();
    } while (!validarCPF(pac->cpf));
    do {
        printf("\t === Insira o nome:   ");
        scanf(" %51[^\n]", pac->nome);
        getchar();
    } while (!lerLetras(pac->nome));
    printf("\t === Insira a idade:  ");
    scanf(" %20[^\n]", pac->idade);
    getchar();
    printf("\t === Insira o endereco:   ");
    scanf( "%51[^\n]",pac->endereco);
    getchar();
    printf("\t === Insira o e-mail: ");
    scanf( "%51[^\n]", pac->email);
    getchar();
    printf("\t === Insira o numero telefonico:  ");
    scanf("%[0-9]", pac->numero);
    getchar();
    pac->status = 'm';
    return pac;

    printf("\t==================================================\n\n");
    system("\tPause");
    system("cls | clear");

}

void grava_paciente(Dados_Paciente* pac) {
    FILE* fp;
    fp = fopen("pacientes.dat", "ab");
    if(fp==NULL){
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possivel continuar esse programa...\n");
        exit(1);
    }
    fwrite(pac, sizeof(Dados_Paciente),1,fp);
    fclose(fp);
}

Dados_Paciente* tela_pesquisar_paciente(void) {
    FILE* fp;
    Dados_Paciente* pac;
    char nome[51];
    system ("cls||clear");
    printf("\t===================================================\n");
    printf("\t===============   Pesquisar Paciente   ============\n");
    printf("\t===================================================\n\n");
    printf("Informe o nome do paciente: ");
    scanf("%50[^\n]", nome);
    pac = (Dados_Paciente*) malloc(sizeof(Dados_Paciente));
    fp = fopen("pacientes.dat", "rb");
    if(fp==NULL){
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possivel continuar esse programa...\n");
        exit(1);
    }
    while (!feof(fp)) {
        fread(pac, sizeof(Dados_Paciente), 1, fp);
        if ((pac->nome == nome) && (pac->status != 'x')) {
            fclose(fp);
            return pac;
        }
    }
    fclose(fp);
    return NULL;
    printf("\t==================================================\n\n");
    system("\tPause");
    system("cls | clear");
}

void exibePaciente(Dados_Paciente* pac) {
    char situacao[20];
    if ((pac == NULL) || (pac->status == 'x')) {
        printf("\n = Paciente Inexistente = \n");
    } else {
        printf("\n = Paciente Cadastrado = \n");
        printf("\nCPF: %s\n", pac->cpf);
        printf("\nNome: %s\n", pac->nome);
        printf("\nIdade: %s\n", pac->idade);
        printf("\nEndereço: %s\n", pac->endereco);
        printf("\nE-mail: %s\n", pac->email);
        printf("\nNúmero: %s\n", pac->numero);  
        if (pac->status == 'm') {
            strcpy(situacao, "Cadastrado");
        } else if (pac->status == 'r') {
            strcpy(situacao, "Removido");
        } else {
            strcpy(situacao, "Não informado");
        }
        printf("\nSituação do paciente: %s\n", situacao);     
    }
}

void listaPaciente(void) {
    FILE* fp;
    Dados_Paciente* pac;
    printf("\n = Lista de Pacientes =\n");
    pac = (Dados_Paciente*) malloc(sizeof(Dados_Paciente));
    fp = fopen("pacientes.dat", "rb");
    if (fp==NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possivel continuar esse programa...\n");
        exit(1);
    }
    while (fread(pac, sizeof(Dados_Paciente), 1, fp)) {
        if (pac->status != 'x') {
            exibePaciente(pac);
        }
    }
    fclose(fp);
}

void tela_alterar_paciente(void) {
    FILE* fp;
    Dados_Paciente* paciente;
    int achou;
    char resp;
    char procurado[51];
    fp = fopen("pacientes.dat", "r+b");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    system ("cls||clear");
    printf("\t===================================================\n");
    printf("\t================   Alterar Paciente   =============\n");
    printf("\t===================================================\n\n");
    printf("Informe o nome do paciente a ser alterado: ");
    scanf("%50[^\n]", procurado);
    paciente = (Dados_Paciente*) malloc(sizeof(Dados_Paciente));
    achou = 0;
    while ((!achou) && fread(paciente, sizeof(Dados_Paciente), 1, fp)) {
        if ((strcmp(paciente->nome, procurado) == 0) && (paciente->status == 'm')) {
            achou = 1;
        }
    }
    if (achou) {
        exibePaciente(paciente);
        getchar();
        printf("Deseja realmente editar esse paciente ? (s/n)");
        scanf("%c", &resp);
        if (resp == 's' || resp == 'S') {
            do {
                printf("\t === Insira o CPF (apenas digitos):     ");
                scanf(" %14[^\n]", paciente->cpf);
                getchar();
            } while (!validarCPF(paciente->cpf));
            do {
                printf("\t === Insira o nome:   ");
                scanf(" %51[^\n]", paciente->nome);
                getchar();
            } while (!lerLetras(paciente->nome));
            printf("\t === Insira a idade:  ");
            scanf(" %20[^\n]", paciente->idade);
            getchar();
            printf("\t === Insira o endereco:   ");
            scanf( "%51[^\n]",paciente->endereco);
            getchar();
            printf("\t === Insira o e-mail: ");
            scanf( "%51[^\n]", paciente->email);
            getchar();
            printf("\t === Insira o numero telefonico:  ");
            scanf("%[0-9]", paciente->numero);
            getchar();
            paciente->status = 'm';
            fseek(fp, (-1)*sizeof(Dados_Paciente), SEEK_CUR);
            fwrite(paciente, sizeof(Dados_Paciente), 1, fp);
            printf("\nPaciente editado com sucesso!!!\n");
        } else {
                printf("\nOK, os dados não foram alterados\n");
          }      
    } else {
                printf("O paciente %s não foi encontrado...\n", procurado);
      }
    free(paciente);
    fclose(fp);
    printf("\t==================================================\n\n");
    system("\tPause");
    system("cls | clear");
}

void tela_excluir_paciente(void) {
    FILE* fp;
    Dados_Paciente* pac;
    int achou;
    char resp;
    char procurado[51];
    fp = fopen("pacientes.dat", "r+b");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possivel continuar esse programa...\n");
        exit(1);
    }
    system ("cls||clear");
    printf("\t===================================================\n");
    printf("\t==============   Excluir Paciente   ===============\n");
    printf("\t===================================================\n\n");
    printf("Informe o nome do paciente a ser apagado: ");
    scanf("%50[^\n]", procurado);
    pac = (Dados_Paciente*) malloc(sizeof(Dados_Paciente));
    achou = 0;
    while ((!achou) && (fread(pac, sizeof(Dados_Paciente), 1, fp))) {
        if ((strcmp(pac->nome, procurado) == 0) && (pac->status == 'm')) {
            achou = 1;
        }
    }
    if (achou) {
        exibePaciente(pac);
        getchar();
        printf("Deseja realmente apagar este paciente ? (s/n)");
        scanf("%c", &resp);
        if (resp == 's' || resp == 'S') {
            pac->status = 'x';
            fseek(fp, (-1)*sizeof(Dados_Paciente), SEEK_CUR);
            fwrite(pac, sizeof(Dados_Paciente), 1, fp);
            printf("\nPaciente excluído com sucesso!!!\n");
        } else {
            printf("\nOk, os dados não foram alterados\n");
          }
    } else {
        printf("O paciente %s não foi encontrado...\n", procurado);
      }
    free(pac);
    fclose(fp);
    printf("\t==================================================\n\n");
    system("\tPause");
    system("cls | clear");
}