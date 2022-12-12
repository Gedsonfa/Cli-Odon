#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validar.h"
#include "structs.h"

Dados_Funcionario* tela_cadastrar_funcionario(){

    Dados_Funcionario* fun;
    fun = (Dados_Funcionario*) malloc(sizeof(Dados_Funcionario));
    
    system ("cls||clear");
    printf("\t=========================================================\n");
    printf("\t===============   Cadastrar Funcionarios   ==============\n");
    printf("\t=========================================================\n");
    
    do{
        printf("\t === Insira o CPF (So Numeros):    ");
        scanf("%15[^\n]",fun->cpf);
        getchar();
        
    }while(!validarCPF(fun->cpf));

    do{
    printf("\t === Insira o nome:   ");
    scanf("%51[^\n]",fun->nome);
    getchar();
    
    }while(!lerLetras(fun->nome));

    printf("\t === Insira a idade:  ");
    scanf("%20[^\n]",fun->idade);
    getchar();

    printf("\t === Insira o endereco:   ");
    scanf("%51[^\n]",fun->endereco);
    getchar();

    printf("\t === Insira o e-mail: ");
    scanf("%51[^\n]",fun->email);
    getchar();

    printf("\t === Insira o numero telefonico:  ");
    scanf("%15[^\n]",fun->telefone);
    getchar();

    fun->status = 'm';
    return fun;

    printf("\t==================================================\n\n");
    system("\tPause");
    system("cls | clear");
    
        
}

void grava_funcionario(Dados_Funcionario* fun){
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

Dados_Funcionario* buscar_funcionario() {
    FILE* fp;
    Dados_Funcionario* fun;
    char fon[15];

    printf("\n ===== Buscar Paciente ======");
    printf("\n Informe seu CPF: ");
    scanf("%s", fon);
    getchar();
    
    fun = (Dados_Funcionario*) malloc(sizeof(Dados_Funcionario));
    fp = fopen("funcionarios.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Ocorreu  ko um erro na abertura do arquivo!\n");
        printf("Não é possível continuar este programa...\n");
        exit(1);
    }
    while(!feof(fp)){
        fread(fun, sizeof(Dados_Funcionario), 1, fp);
        if ((strcmp(fun -> cpf, fon) == 0) &&(fun->status != 'x')){
            fclose(fp);
            return fun;
        }
    }
fclose(fp);
return NULL;

}
void tela_pesquisar_funcionario(Dados_Funcionario* fun){
  
    system ("cls||clear");
    printf("\t=========================================================\n");
    printf("\t===============   Pesquisar Funcionarios   ==============\n");
    printf("\t=========================================================\n\n");
    
    if((fun == NULL) || (fun->status == 'x')){
        printf("Funcionario nao encontrado");
    }else{
        printf(" | ============== Funcionario encontrado =============\n");
        printf(" | Nome: %s\n", fun->nome);
        printf(" | Idade: %s\n", fun->idade);
        printf(" | Email: %s\n", fun->email);
        printf(" | Endereco: %s\n", fun->endereco);
        printf(" | Numero: %s\n", fun->telefone);
        printf(" | ================================================\n");
        printf(" | aperte ENTER para continuar");
        getchar();
        system(" cls| clear");
    }
    
}


void exibe_funcionarios(Dados_Funcionario* fun) {

    printf(" | CPF: %s\n", fun->cpf);
    printf(" | Nome: %s\n", fun->nome);
    printf(" | Idade: %s\n", fun->idade);
    printf(" | E-mail de contato: %s\n", fun->email);
    printf(" | Endereco: %s\n", fun->endereco);
    printf(" | Numero de contato: %s\n", fun->telefone);
    printf(" | Status: %c\n", fun->status);
    printf("\n");


}

void tela_alterar_funcionario(){

    FILE* fp;
    Dados_Funcionario* fun;
    int achou;
    char esc;
    char resp;
    char procurando [20];


    fp = fopen("funcionarios.dat", "r+b");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
}
    fun = (Dados_Funcionario*) malloc(sizeof(Dados_Funcionario));
    system ("cls||clear");
    printf("\t=========================================================\n");
    printf("\t================   Alterar Funcionarios   ===============\n");
    printf("\t=========================================================\n\n");
    printf("\t === Insira o CPF (So Numeros):    ");
    scanf("%s",procurando);
    getchar();

    achou = 0;

    while((!achou) && (fread(fun, sizeof(Dados_Funcionario), 1, fp))) {
    if ((strcmp(fun->cpf, procurando) == 0) && (fun->status == 'm')) {
    achou = 1;
    }if (achou) {
        exibe_funcionarios(fun);
        printf(" Deseja realmente editar este funcionario? [s/n] ");
        scanf("%c", &resp);
        getchar();
        if (resp == 's' || resp == 'S') {
        
        esc = escAtualizarFuncionario();

        if (esc == '1'){

                printf(" | Informe novo nome: ");
                scanf("%[A-Z a-z]", fun->nome);
                getchar();


                printf(" | Informe a nova idade: ");
                scanf("%20[^\n]",fun->idade);
                getchar();

                printf(" | Informe o novo email: ");
                scanf("%s", fun->email);
                getchar();

                printf(" | Informe o novo endereço: ");
                scanf("%[A-Z a-z 0-9]", fun->endereco);
                getchar();

                printf(" | Informe o novo numero: ");
                scanf("%15[^\n]", fun->telefone);
                getchar();


    } else if (esc == '2'){
                
                printf(" | Informe novo nome: ");
                scanf("%[A-Z a-z]", fun->nome);
                getchar();

    } else if (esc == '3'){

                printf(" | Informe a nova idade: ");
                scanf("%20[^\n]",fun->idade);
                getchar();

    } else if (esc == '4'){

                printf(" | Informe o novo email: ");
                scanf("%s", fun->email);
                getchar();
    } else if (esc == '5'){
                printf(" | Informe o novo endereço: ");
                scanf("%[A-Z a-z 0-9]", fun->endereco);
                getchar();

    } else if (esc == '6') {
                printf(" | Informe o novo numero: ");
                scanf("%20[^\n]", fun->telefone);
                getchar();
    }
    fun->status = 'm';
    fseek(fp, (-1)*sizeof(Dados_Funcionario), SEEK_CUR);
    fwrite(fun, sizeof(Dados_Funcionario), 1, fp);
    printf("\nUsuario editado com sucesso!!!\n");



    } else {
        printf("Tudo bem, os dados não foram alterados!");
    }
    
    } 
    }
    printf(" | Pressione qualquer tecla para sair...");
    getchar();
    free(fun);
    fclose(fp);

}



char escAtualizarFuncionario(void)
{    
    char op;
    system(" cls || clear");
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ----------- ------ Atualizar Funcionario ---------------- | \n");
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



void tela_excluir_funcionario(){

    FILE* fp;
    Dados_Funcionario* fun;
    int achou;
    char resp;
    char procurado[15];
    fp = fopen("funcionarios.dat", "r+b");
    if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
    }
    printf("\n\n");
    system ("cls||clear");
    printf("=========================================\n");
    printf("==== Apagar Cadastro de Funcionario =====\n");
    printf("========================================= \n");
    printf("Informe o CPF do Funcionario: ");
    scanf(" %14[^\n]", procurado);
    fun = (Dados_Funcionario*) malloc(sizeof(Dados_Funcionario));
    achou = 0;
    while((!achou) && (fread(fun, sizeof(Dados_Funcionario), 1, fp))) {
    if ((strcmp(fun->cpf, procurado) == 0) && (fun->status == 'm')) {
        achou = 1;
    }
    }

    if (achou) {
    exibe_funcionarios(fun);
    getchar();
    printf("Deseja realmente apagar este Funcionario (s/n)? ");
    scanf("%c", &resp);
    getchar();
    if (resp == 's' || resp == 'S') {
        fun->status = 'x';
        fseek(fp, -1*sizeof(Dados_Funcionario), SEEK_CUR);
        fwrite(fun, sizeof(Dados_Funcionario), 1, fp);
        printf("\nFuncionario excluído com sucesso!!!\n");
        printf("Aperte ENTER para continuar...");
        getchar();
        } else {
        printf("\nOk, os dados não foram alterados\n");
        printf("Aperte ENTER para continuar...");
        getchar();
        }
    } else {
    printf("O Funcionario %s não foi encontrado...\n", procurado);
    printf("Aperte ENTER para continuar...");
    getchar();
    }
    fclose(fp);
    free(fun);

}

//update


int listarFuncionarios(void)
{
    FILE* fp;
    Dados_Funcionario* fun;
    fp = fopen("funcionarios.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        return 0;
    }
    fun = (Dados_Funcionario*)malloc(sizeof(Dados_Funcionario));
    while(fread(fun, sizeof(Dados_Funcionario), 1, fp)) {
        system(" cls || clear");
        printf(" | ===================== Listar Funcionarios ======================== | \n");
        printf(" |                                                                    | \n");
        exibe_funcionarios(fun);    
        printf(" | Pressione qualquer tecla para sair...");
        getchar();
    }

    fclose(fp);
    free(fun);
    return 0;

}

int listarFuncionariosExc(void)
{
    FILE* fp;
    Dados_Funcionario* fun;
    fp = fopen("funcionarios.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        return 0;
    }
    fun = (Dados_Funcionario*)malloc(sizeof(Dados_Funcionario));
    while(fread(fun, sizeof(Dados_Funcionario), 1, fp)) {
        if (fun->status == 'x') {
            system(" cls || clear");
            printf(" | ===================== Listar Funcionarios ======================== | \n");
            printf(" |                                                                    | \n");
            exibe_funcionarios(fun);    
            printf(" | Pressione qualquer tecla para sair...");
            getchar();
        }
    }

    fclose(fp);
    free(fun);
    return 0;

}

int listarFuncionariosCad(void)
{
    int ida;
    FILE* fp;
    Dados_Funcionario* fun;
    fp = fopen("funcionarios.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        return 0;
    }
    printf("\t========================================================\n");
    printf("\t Digite o limite Máximo de idade (So Numeros!):");
    scanf("%d",&ida);
    getchar();

    fun = (Dados_Funcionario*)malloc(sizeof(Dados_Funcionario));
    int idade = atoi(fun->idade);
    while(fread(fun, sizeof(Dados_Funcionario), 1, fp)) {
        if (idade <= ida && fun->status != 'x') {
            system(" cls || clear");
            printf(" | ===================== Listar Funcionarios ======================== | \n");
            printf(" |                                                                    | \n");
            exibe_funcionarios(fun);    
            printf(" | Pressione qualquer tecla para sair...");
            getchar();
        }
    }

    fclose(fp);
    free(fun);
    return 0;

}
