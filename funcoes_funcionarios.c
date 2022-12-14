#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
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
    }while(!((validarCPF(fun->cpf)) && (valida_fun(fun->cpf))));


        printf("\t === Insira o nome:   ");
        scanf("%51[^\n]",fun->nome);
        getchar();

    do {
        printf("\t === Insira a idade:  ");
        scanf("%20[^\n]",fun->idade);
        getchar();
        if (!lerNumeros(fun->idade)) {
            printf("\t | Insira uma idade valida!!!(apenas numeros)\n");
        }
    } while (!lerNumeros(fun->idade));

    printf("\t === Insira o endereco:   ");
    scanf("%51[^\n]",fun->endereco);
    getchar();

    printf("\t === Insira o e-mail: ");
    scanf("%51[^\n]",fun->email);
    getchar();

    do {
        printf("\t === Insira o numero telefonico:  ");
        scanf("%15[^\n]",fun->telefone);
        getchar();
        if (!lerNumeros(fun->telefone)) {
            printf("\t | Insira um telefone valido!!!(apenas numeros)\n");
        }
    } while (!lerNumeros(fun->telefone));
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
    do {
        printf("\n Informe seu CPF: ");
        scanf("%s", fon);
        getchar();
        if (!validarCPF(fon)) {
            printf(" | Informe um CPF cadastrado");
        }
    } while (!validarCPF(fon));
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
                

                do {
                    printf(" | Informe a nova idade: ");
                    scanf("%20[^\n]",fun->idade);
                    getchar();
                } while (!lerNumeros(fun->idade));
                
                printf(" | Informe o novo email: ");
                scanf("%s", fun->email);
                getchar();

                printf(" | Informe o novo endereço: ");
                scanf("%[A-Z a-z 0-9]", fun->endereco);
                getchar();

                do {
                    printf(" | Informe o novo numero: ");
                    scanf("%15[^\n]", fun->telefone);
                    getchar();
                } while (!lerNumeros(fun->telefone));

    } else if (esc == '2'){
                
                
                    printf(" | Informe novo nome: ");
                    scanf("%[A-Z a-z]", fun->nome);
                    getchar();
                
    } else if (esc == '3'){
                do {
                    printf(" | Informe a nova idade: ");
                    scanf("%20[^\n]",fun->idade);
                    getchar();
                } while (!lerNumeros(fun->idade));
    } else if (esc == '4'){

                printf(" | Informe o novo email: ");
                scanf("%s", fun->email);
                getchar();
    } else if (esc == '5'){
                printf(" | Informe o novo endereço: ");
                scanf("%[A-Z a-z 0-9]", fun->endereco);
                getchar();

    } else if (esc == '6') {
                do {
                    printf(" | Informe o novo numero: ");
                    scanf("%20[^\n]", fun->telefone);
                    getchar();
                } while (!lerNumeros(fun->telefone));
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
    do {
        printf("Informe o CPF do Funcionario: ");
        scanf(" %14[^\n]", procurado);
        getchar();
        if (!validarCPF(procurado)) {
            printf("| Informe um CPF valido!!!\n");
        }
    } while (!validarCPF(procurado));
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
    
    FILE* fp;
    Dados_Funcionario* fun;
    int ida;
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
    while(fread(fun, sizeof(Dados_Funcionario), 1, fp)) {

        int idade = atoi(fun->idade);
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

NoFun* listaOrdenadaFun(void) {
  FILE* fp;
  Dados_Funcionario* fun;
  NoFun* noFun;
  NoFun* lista;

  lista = NULL;
  fp = fopen("funcionarios.dat", "rb");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }

  fun = (Dados_Funcionario*) malloc(sizeof(Dados_Funcionario));
  while(fread(fun, sizeof(Dados_Funcionario), 1, fp)) {
    if (fun->status != 'x') {
      noFun = (NoFun*) malloc(sizeof(NoFun));
      
      noFun->cod = fun->cod;

      strcpy(noFun->nome, fun->nome);

      strcpy(noFun->cpf, fun->cpf);

      strcpy(noFun->idade, fun->idade);

      strcpy(noFun->email, fun->email);

      strcpy(noFun->endereco, fun->endereco);

      strcpy(noFun->telefone, fun->telefone);

      noFun->status = fun->status;

      if (lista == NULL) {
        lista = noFun;
        noFun->prox = NULL;
      } else if (strcmp(noFun->nome,lista->nome) < 0) {
        noFun->prox = lista;
        lista = noFun;
      } else {
        NoFun* anter = lista;
        NoFun* atual = lista->prox;
        while ((atual != NULL) && strcmp(atual->nome,noFun->nome) < 0) {
          anter = atual;
          atual = atual->prox;
        }
        anter->prox = noFun;
        noFun->prox = atual;
      }
    }
  }
  fclose(fp);
  free(fun);
  return lista;
}

void exibeListaFun(NoFun* lista){
    system(" cls || clear");
    while (lista != NULL) {
    printf(" | CPF: %s\n", lista->cpf);
    printf(" | Nome: %s\n", lista->nome);
    printf(" | Idade: %s\n", lista->idade);
    printf(" | E-mail de contato: %s\n", lista->email);
    printf(" | Endereco: %s\n", lista->endereco);
    printf(" | Numero de contato: %s\n", lista->telefone);
    printf(" | Status: %c\n", lista->status);
    printf("\n");
    getchar();
    system(" cls || clear");
    lista = lista->prox;
    }
}

int valida_fun(char* linha)
{
    FILE* fp3;
    Dados_Funcionario* teste;

    teste = (Dados_Funcionario*)malloc(sizeof(Dados_Funcionario));
    if (access("funcionarios.dat", F_OK) != -1) {

    fp3 = fopen("funcionarios.dat", "rt");
    
    if (fp3 == NULL)
    {
        printf("Gerando arquivo...");
        fclose(fp3);
        return 1;
    }
    while (!feof(fp3))
    {
        fread(teste, sizeof(Dados_Funcionario), 1, fp3);
        if (strcmp(linha, teste->cpf) == 0    && (teste->status != 'x'))
        {
            fclose(fp3);
            return 0;
        }
    }
    fclose(fp3);
    }
    return 1;
}
