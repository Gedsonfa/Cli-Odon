#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "validar.h"
#include "structs.h"


char* get_nome_agendamento(char* cpf) //Devolve um apontador, recebe um aportador pra cpf
{

  Dados_Paciente* pac;
  FILE* fp;
  char* nome;

  nome = (char*) malloc(81*sizeof(char)); //Aloca o tamanho 

  pac = (Dados_Paciente*)malloc(sizeof(Dados_Paciente)); //Alocar tamanho de acordo com o struct
  fp = fopen("pacientes.dat", "rb");

    if (fp == NULL) //Se o arquivo for nulo
    {
        printf("Ocorreu um erro na abertura do arquivo, não é possivel continuar o programa");
        exit(1);
    }

    while (!feof(fp)) // Busca até o final do arquivo
    { 
        fread(pac, sizeof(Dados_Paciente), 1, fp);
        if (strcmp(pac->cpf, cpf) == 0 && (pac->status != 'x'))/*Verifica se o código é igual e o status*/
        { 
            fclose(fp);
            strcpy(nome, pac->nome);//Realiza a cópia do conteúdo de uma variável a outra
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

    while (!feof(fp)) // Busca até o final do arquivo
    {
        fread(pac, sizeof(Dados_Paciente), 1, fp);
        if (strcmp(pac->cpf, cpf) == 0)/*Verifica se o código é igual e o status*/
        { 
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

char* get_nome_servico(char* codigo_ser) //Devolve um apontador, recebe um aportador pra cpf
{

  Dados_Servico* ser;
  FILE* fp;
  char* nome;

  nome = (char*) malloc(81*sizeof(char)); //Aloca o tamanho 

  ser = (Dados_Servico*)malloc(sizeof(Dados_Servico)); //Alocar tamanho de acordo com o struct
  fp = fopen("servicos.dat", "rb");

    if (fp == NULL) //Se o arquivo for nulo
    {
        printf("Ocorreu um erro na abertura do arquivo, não é possivel continuar o programa");
        exit(1);
    }

    while (!feof(fp)) // Busca até o final do arquivo
    { 
        fread(ser, sizeof(Dados_Servico), 1, fp);
        if (strcmp(ser->codigo, codigo_ser) == 0 && (ser->status != 'x'))/*Verifica se o código é igual e o status*/
        { 
            fclose(fp);
            strcpy(nome, ser->nome);//Realiza a cópia do conteúdo de uma variável a outra
            free(ser);
            return nome;
        }
    }

    fclose(fp);
    free(ser);
    return NULL;

}

char* get_ser_full(char* codigo_ser) 
{
    Dados_Servico* ser;
    FILE* fp;
    char* nome;

    nome = (char*) malloc(81*sizeof(char));

    ser = (Dados_Servico*)malloc(sizeof(Dados_Servico));
    fp = fopen("servicos.dat", "rb");

    if (fp == NULL)
    {
        printf("Ocorreu um erro na abertura do arquivo, não é possivel continuar o programa");
        exit(1);
    }

    while (!feof(fp)) // Busca até o final do arquivo
    {
        fread(ser, sizeof(Dados_Servico), 1, fp);
        if (strcmp(ser->codigo, codigo_ser) == 0)/*Verifica se o código é igual e o status*/
        { 
            fclose(fp);
            strcpy(nome, ser->nome);
            free(ser);
            return nome;
        }
    }

    fclose(fp);
    free(ser);
    return NULL;

}

Dados_Agendamento* tela_cadastrar_agendamento(void){

    Dados_Agendamento* age;
    age = (Dados_Agendamento*) malloc(sizeof(Dados_Agendamento));
    char* nome_ser;
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
        
        do{
        printf("\t === Insira o codigo do Agendamento:  ");
        scanf("%15[^\n]", age->codigo_agen);
        getchar();

        }while(!valida_age(age->codigo_agen));

        printf("\t === Insira o codigo do Serviço:  ");
        scanf("%15[^\n]", age->codigo_ser);
        getchar();

        nome_ser = get_nome_servico(age->codigo_ser);
        if (nome_ser != NULL) {

        printf("\t ================================= \n");
        printf("\t Serviço encontrado com sucesso!\n");
        printf("\t Nome do Serviço: %s\n", nome_ser);
        printf("\t ================================= \n");
        free(nome_ser);

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

        }else{
            printf("\t ================================= \n");
            printf("\t Ops, Serviço não encontrado!\n");
            printf("\t Verifique se esse serviço existe ou está ativo!\n");
            printf("\t ================================= \n\n");
            printf("\t==================================================\n\n");
            getchar();
            system("\tPause");
            system("cls | clear");
            return NULL;
        }

    } else {
        printf("\t ================================= \n");
        printf("\t Ops, Paciente não encontrado!\n");
        printf("\t Verifique se esse cadastro existe ou está ativo!\n");
        printf("\t ================================= \n\n");
        printf("\t==================================================\n\n");
        getchar();
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
    fwrite(age,sizeof(Dados_Agendamento),1,fp);/* o endereço da variável cujo conteúdo será escrito no arquivo; – 
    o tamanho do dado que será escrito; – a quantidade de dados que serão escritos; – o ponteiro para o arquivo onde os 
    dados serão escritos*/
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
        fread(age, sizeof(Dados_Agendamento), 1, fp);//A função retorna o número de unidades efetivamente lidas
        if ((strcmp(age -> codigo_agen, men) == 0) &&(age->status != 'x')){
            fclose(fp);
            return age;
        }
    }
fclose(fp);
return NULL;
}


void tela_pesquisar_agendamento(Dados_Agendamento* age){

    char* nome_pac;
    char* nome_ser;
    system ("cls||clear");
    printf("\t===================================================\n");
    printf("\t============   Pesquisar Agendamento   ============\n");
    printf("\t===================================================\n\n");
    if((age == NULL) || (age->status == 'x')){
        printf("Agendamento nao encontrado");
    }else{
        
        nome_pac = get_nome_full(age->cpf);
        nome_ser = get_ser_full(age -> codigo_ser);
        printf(" | ============== Agendamento encontrado ========\n");
        printf(" | Nome do Paciente: %s\n", nome_pac);
        printf(" | CPF : %s\n", age->cpf);
        printf(" | Nome do do Serviço: %s\n", nome_ser);
        printf(" | Codigo do agendamento: %s\n", age->codigo_agen);
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
    char* nome_ser;
    nome_pac = get_nome_full(age->cpf);
    nome_ser = get_ser_full(age -> codigo_ser);
    printf("\n | ============== Agendamento encontrado ========\n");
    printf(" | Nome do Paciente: %s\n", nome_pac);
    printf(" | CPF: %s\n", age->cpf);
    printf(" | Nome do do Serviço: %s\n", nome_ser);
    printf(" | Codigo do Agendamento: %s\n", age->codigo_agen);
    printf(" | Data do Agendamento: %s\n", age->data);
    printf(" | Horario do Agendamento: %s\n", age->hora);
    printf(" | Status: %c\n", age->status);
    printf(" | ==============================================\n");
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
    do {
        printf("\t Digite o CPF do Cliente: ");
        scanf("%s", procurando);
        getchar();
    } while (!validarCPF(procurando));
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
                do {
                    printf(" | Informe novo CPF (So Numeros): ");
                    scanf("%[0-9]", age->cpf);
                    getchar();
                } while(!validarCPF(age->cpf));

                do{
                    printf(" | Informe o nova data '00/00/0000': ");
                    scanf("%20[^\n]",age->data);
                    getchar();
                } while (!lerData(age->data));
                
                do {
                    printf(" | Escolha seu novo Horário: ");
                    scanf("%20[^\n]", age->hora);
                    getchar();
                    if (!lerHora(age->hora)) {
                        printf(" | Informe um horario valido!!!\n");
                    }
                } while (!lerHora(age->hora));

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
    fseek(fp, (-1)*sizeof(Dados_Agendamento), SEEK_CUR); /*move a posição corrente de leitura ou escrita no arquivo de 
    um valor especificado, a partir de um ponto especificado*/ //SEEK_CUR: Ponto corrente no arquivo
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
    getchar();
    age = (Dados_Agendamento*) malloc(sizeof(Dados_Agendamento));
    achou = 0;
    while((!achou) && (fread(age, sizeof(Dados_Agendamento), 1, fp))) {
    if ((strcmp(age->codigo_agen, procurado) == 0) && (age->status == 'm')) {
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



NoAge* listaOrdenadaAge(void) {
  FILE* fp;
  Dados_Agendamento* age;
  NoAge* noAge;
  NoAge* lista;

  lista = NULL;
  fp = fopen("agendamentos.dat", "rb");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }

  age = (Dados_Agendamento*) malloc(sizeof(Dados_Agendamento));
  while(fread(age, sizeof(Dados_Agendamento), 1, fp)) {
    if (age->status != 'x') {
      noAge = (NoAge*) malloc(sizeof(NoAge));
      
      noAge->cod = age->cod;

      strcpy(noAge->cpf, age->cpf);

      strcpy(noAge->codigo_servico, age->codigo_agen);

      strcpy(noAge->data, age->data);

      strcpy(noAge->hora, age->hora);

      noAge->status = age->status;

      if (lista == NULL) {
        lista = noAge;
        noAge->prox = NULL;
      } else if (strcmp(noAge->cpf,lista->cpf) < 0) {
        noAge->prox = lista;
        lista = noAge;
      } else {
        NoAge* anter = lista;
        NoAge* atual = lista->prox;
        while ((atual != NULL) && strcmp(atual->cpf,noAge->cpf) < 0) {
          anter = atual;
          atual = atual->prox;
        }
        anter->prox = noAge;
        noAge->prox = atual;
      }
    }
  }
  fclose(fp);
  free(age);
  return lista;
}
//update
void exibeListaAge(NoAge* lista){
    system(" cls || clear");
    char* nome_pac;
    while (lista != NULL) {    
    nome_pac = get_nome_full(lista->cpf);    
    printf(" | Nome do Paciente: %s\n", nome_pac);
    printf(" | Codigo do Agendamento: %s\n", lista->codigo_servico);
    printf(" | CPF: %s\n", lista->cpf);
    printf(" | Data do Agendamento: %s\n", lista->data);
    printf(" | Horario do Agendamento: %s\n", lista->hora);
    printf(" | Status: %c\n", lista->status);
    printf("\n");
    getchar();
    system(" cls || clear");
    lista = lista->prox;
    }

}

int valida_age(char* linha)
{
    FILE* fp3;
    Dados_Agendamento* teste;

    teste = (Dados_Agendamento*)malloc(sizeof(Dados_Agendamento));
    if (access("agendamentos.dat", F_OK) != -1) {
        fp3 = fopen("agendamentos.dat", "rt");
        
        if (fp3 == NULL)
        {
            printf("Gerando arquivo...");
            fclose(fp3);
            return 1;
        }

        while (!feof(fp3))
        {
            fread(teste, sizeof(Dados_Agendamento), 1, fp3);
            if (strcmp(linha, teste->codigo_agen) == 0    && (teste->status != 'x'))
            {
                fclose(fp3);
                return 0;
            }
        }
        fclose(fp3);
    }
    return 1;
}

