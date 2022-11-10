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
        scanf("%s", pac->cpf);
        getchar();
        
    } while (!validarCPF(pac->cpf));
    
    do{
        printf("\t === Insira o nome:   ");
        fgets( pac->nome, 51, stdin);
        
    }while(!lerLetras(pac->nome));

    printf("\t === Insira a idade:  ");
    fgets( pac->idade, 20,stdin);
    

    printf("\t === Insira o endereco:   ");
    fgets( pac->endereco, 51, stdin);
    

    printf("\t === Insira o e-mail: ");
    fgets(pac->email, 51, stdin);

    printf("\t === Insira o numero telefonico:  ");
    fgets( pac->numero, 15, stdin);

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
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possivel continuar esse programa...\n");
        exit(1);
    }
    fwrite(pac, sizeof(Dados_Paciente),1,fp);
    fclose(fp);
}

void tela_pesquisar_paciente(Dados_Paciente* pac)
{
    pac = (Dados_Paciente*) malloc(sizeof(Dados_Paciente));
    char cad[14];
    
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
        printf("Situacao do paciente: %s\n", cad);
        printf(" | ================================================\n");
        //getchar();
        

        system("Pause");
        system(" cls| clear");

    }

    
}

/*Dados_Paciente* buscarPaciente(){
  FILE* fp;
  Dados_Paciente* pac;
  char cad[14];
  printf("\n = Busca paciente = \n"); 
  printf("Informe matrícula: "); 
  scanf("%s", cad);
  pac = (Dados_Paciente*) malloc(sizeof(Dados_Paciente));
  fp = fopen("Pacientes.dat", "rb");
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
}*/


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
