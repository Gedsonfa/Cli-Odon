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
    /*struct Dados_Agendamento{
    char cpf_paciente[15];
    char codigo_servico[6];
    char cpf_funcionario[15];
    char data[11];
    char hora[6];
    char status;
};*/
    do
    {
        printf("\t === Insira o CPF So Numeros]:     ");
        scanf(" %14[^\n]", pac->cpf);
        getchar();
        
    } while (!validarCPF(pac->cpf));
    
    do{
        printf("\t === Insira o nome:   ");
        scanf(" %51[^\n]", pac->nome);
        getchar();
        
    }while(!lerLetras(pac->nome));

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

void grava_paciente(Dados_Paciente* pac){
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

Dados_Paciente* tela_pesquisar_paciente(){
    FILE* fp;
    Dados_Paciente* pac;
    char cad[14];
    
    pac = (Dados_Paciente*) malloc (sizeof(Dados_Paciente));
    system ("cls||clear");
    printf("\t===================================================\n");
    printf("\t===============   Pesquisar Paciente   ============\n");
    printf("\t===================================================\n\n");
    
    
    scanf("%s", cad);
    pac = (Dados_Paciente*) malloc(sizeof(Dados_Paciente));
    fp = fopen("pacientes.dat", "rb");
    if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar este programa...\n");
    exit(1);
  }
    while(!feof(fp)) {
    fread(pac, sizeof(Dados_Paciente), 1, fp);
    if ((pac->cpf == cad) && (pac->status != 'x')) {
      fclose(fp);
      return pac;
    }
  }
  fclose(fp);
  return NULL;
}



void tela_alterar_paciente(){

    Dados_Paciente* pac;
    pac = (Dados_Paciente*) malloc(sizeof(Dados_Paciente));

    system ("cls||clear");
    printf("\t===================================================\n");
    printf("\t================   Alterar Paciente   =============\n");
    
    printf("\t===================================================\n\n");
    do
    {
        printf("\t === Insira o CPF:    ");
        scanf("%s", pac->cpf);
        getchar();
        
    } while (!validarCPF(pac->cpf));
    
    printf("\t==================================================\n\n");
    
    system("\tPause");
    system("cls | clear");

}

void tela_excluir_paciente(){

    Dados_Paciente* pac;
    pac = (Dados_Paciente*) malloc(sizeof(Dados_Paciente));

    system ("cls||clear");
    printf("\t===================================================\n");
    printf("\t==============   Excluir Paciente   ===============\n");
    printf("\t===================================================\n\n");
   
    do
    {
        printf("\t === Insira o CPF:    ");
        scanf("%s", pac->cpf);
        getchar();
        
    } while (!validarCPF(pac->cpf));
    
    printf("\t==================================================\n\n");
    
    system("\tPause");
    system("cls | clear");
}