#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validar.h"
#include "structs.h"

Dados_Funcionario* tela_cadastrar_funcionario(void) {

    Dados_Funcionario* fun;
    fun = (Dados_Funcionario*) malloc(sizeof(Dados_Funcionario));
    
    system ("cls||clear");
    printf("\t=========================================================\n");
    printf("\t===============   Cadastrar Funcionarios   ==============\n");
    printf("\t=========================================================\n");
    
    do{
        printf("\t === Insira o CPF:    ");
        scanf("%15[^\n]",fun->cpf);
        getchar();
        
    }while(!validarCPF(fun->cpf));
    do{
    printf("\t === Insira o nome:   ");
    scanf("%30[^\n]",fun->nome);
    getchar();
    
    }while(!lerLetras(fun->nome));

    printf("\t === Insira a idade:  ");
    fgets(fun->idade,3,stdin);
    

    printf("\t === Insira o endereco:   ");
    fgets(fun->endereco,31,stdin);
    

    printf("\t === Insira o e-mail: ");
    fgets(fun->email,31,stdin);
    

    printf("\t === Insira o numero telefonico:  ");
    fgets(fun->endereco,12,stdin);
    
    fun->status = 'm';
    return fun;

    printf("\t==================================================\n\n");
    system("\tPause");
    system("cls | clear");
    
        
}

void exibeFuncionario(Dados_Funcionario* fun) {
    char situacao[20];
    if ((fun == NULL) || (fun->status == 'x')) {
        printf ("\n = Funcioanrio Inexistente = \n");
    } else {
        printf("\n = Funcionario Cadastrado = \n");
        printf("\nCPF: %s\n", fun->cpf);
        printf("\nNome: %s\n", fun->nome);
        printf("\nIdaade: %s\n", fun->idade);
        printf("\nEndereco: %s\n", fun->endereco);
        printf("\nE-mail: %s\n", fun->email);
        printf("\nTelefone: %s\n", fun->telefone);
        if (fun->status == 'm') {
            strcpy(situacao, "Cadastrado");
        } else if (fun->status == 'r') {
            strcpy(situacao, "Removido");
        } else {
            strcpy(situacao, "Nao informado");
        }
        printf("\nSituação do funcionário: %s", situacao);   
    }
} 

void grava_funcionario(Dados_Funcionario* fun) {
    FILE* fp;
    fp = fopen("funcionarios.dat", "ab");
    if(fp==NULL){
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possivel continuar esse programa...\n");
        exit(1);
    }
    fwrite(fun,sizeof(Dados_Funcionario), 1,fp);
    fclose(fp);
}

Dados_Funcionario* tela_pesquisar_funcionario(void) {
    FILE* fp;
    Dados_Funcionario* fun;
    char cpf[15];
    system ("cls||clear");
    printf("\t=========================================================\n");
    printf("\t===============   Pesquisar Funcionarios   ==============\n");
    printf("\t=========================================================\n\n");
    
    do{
    printf("\t === Insira o CPF:    ");
    scanf("%s",cpf);
    getchar();
    
    }while(!validarCPF(cpf));
    fun = (Dados_Funcionario*) malloc(sizeof(Dados_Funcionario));
    fp = fopen("funcionarios.dat", "rb");
    if(fp==NULL){
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possivel continuar esse programa...\n");
        exit(1);
    }
    while (!feof(fp)) {
        fread(fun, sizeof(Dados_Funcionario), 1, fp);
        if ((fun->cpf == cpf) && (fun->status != 'x')) {
            fclose(fp);
            return fun;
        }
    }
    fclose(fp);
    return NULL;
    printf("\t==================================================\n\n");
    
    system("\tPause");
    system("cls | clear");
    
}

void tela_excluir_funcionario(void) {
    FILE* fp;
    Dados_Funcionario* fun;
    int achou;
    char resp;
    char procurado[51];
    fp = fopen("funcionarios.dat", "r+b");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    system ("cls||clear");
    printf("\t=========================================================\n");
    printf("\t================   Excluir Funcionarios   ===============\n");
    printf("\t=========================================================\n\n");
    printf("Informe o nome do funcionario a ser excluido: ");
    scanf("%50[^\n]", procurado);
    fun = (Dados_Funcionario*) malloc(sizeof(Dados_Funcionario));
    achou = 0;
    while ((!achou) && (fread(fun, sizeof(Dados_Funcionario), 1, fp))) {
        if ((strcmp(fun->nome, procurado) == 0) && (fun->status == 'm')) {
            achou = 1;
        }
    }
    if (achou) {
        exibeFuncionario(fun);
        getchar();
        printf("Deseja realmente editar esse funcionario ? (s/n)");
        scanf("%c", &resp);
        if (resp == 's' || resp == 'S') {
            fun->status = 'x';
            fseek(fp, (-1)*sizeof(Dados_Funcionario), SEEK_CUR);
            fwrite(fun, sizeof(Dados_Funcionario), 1, fp);
            printf("\nFuncionario excluido com sucesso!!!\n");
        } else {
            printf("\nOK, os dados nao foram alterados\n");
        }
    } else {
        printf("O funcionario %s não foi encontrado...\n", procurado);
      }
    free(fun);
    fclose(fp);
    printf("\t==================================================\n\n");
    
    system("\tPause");
    system("cls | clear");

}
void tela_alterar_funcionario(void) {
    FILE* fp;
    Dados_Funcionario* fun;
    int achou;
    char resp;
    char procurado[51];
    fp = fopen("funcionarios.dat", "r+b");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    printf("\t=========================================================\n");
    printf("\t================   Alterar Funcionarios   ===============\n");
    printf("\t=========================================================\n\n");
    printf("Informe o nome do funcionario a ser alterado: ");
    scanf("%50[^\n]", procurado);
    fun = (Dados_Funcionario*) malloc(sizeof(Dados_Funcionario));
    achou = 0;
    while ((!achou) && (fread(fun, sizeof(Dados_Funcionario), 1, fp))) {
        if ((strcmp(fun->nome, procurado) == 0) && (fun->status == 'm')) {
            achou = 1;
        }
    }
    if (achou) {
        exibeFuncionario(fun);
        getchar();
        printf("Deseja realmente editar esse funcionario ? (s/n)");
        scanf("%c", &resp);
        if (resp == 's' || resp == 'S') {
            printf("\t === Insira o CPF:    ");
            scanf("%14[^\n]", fun->cpf);
            getchar();
            do{
                printf("\t === Insira o nome:   ");
                scanf("%30[^\n]",fun->nome);
                getchar();
            }while(!lerLetras(fun->nome));
            printf("\t === Insira a idade:  ");
            fgets(fun->idade,3,stdin);
            printf("\t === Insira o endereco:   ");
            fgets(fun->endereco,31,stdin);
            printf("\t === Insira o e-mail: ");
            fgets(fun->email,31,stdin);
            printf("\t === Insira o numero telefonico:  ");
            fgets(fun->endereco,12,stdin);
            fun->status = 'm';
            fseek(fp, (-1)*sizeof(Dados_Funcionario), SEEK_CUR);
            fwrite(fun, sizeof(Dados_Funcionario), 1, fp);
            printf("\nFuncionario editado com sucesso!!!\n");
        } else {
            printf("\nOK, os dados nao foram alterados\n");
        }
    } else {
        printf("O funcionario %s não foi encontrado...\n", procurado);
      }
    free(fun);
    fclose(fp);
}

void listaFuncionario(void) {
    FILE* fp;
    Dados_Funcionario* fun;
    printf("\t=========================================================\n");
    printf("\t================   Lista de Funcionarios   ===============\n");
    printf("\t=========================================================\n\n");
    fun = (Dados_Funcionario*) malloc(sizeof(Dados_Funcionario));
    fp = fopen("funcionarios.dat", "rb");
    if (fp==NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possivel continuar esse programa...\n");
        exit(1);
    }
    while (fread(fun, sizeof(Dados_Funcionario), 1, fp)) {
        if (fun->status != 'x') {
            exibeFuncionario(fun);
        }
    }
    fclose(fp);
}