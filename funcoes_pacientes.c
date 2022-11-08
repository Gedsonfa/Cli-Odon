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
        scanf(" %[A-Z a-z]", pac->nome);
        getchar();
        
    }while(!lerLetras(pac->nome));

    printf("\t === Insira a idade:  ");
    scanf(" %[0-9]", pac->idade);
    getchar();
    

    printf("\t === Insira o endereco:   ");
    scanf( "%[A-Z a-z 0-9]",pac->endereco);
    getchar();
    

    printf("\t === Insira o e-mail: ");
    scanf( "%s", pac->email);
    getchar();

    printf("\t === Insira o numero telefonico:  ");
    scanf("%[0-9]", pac->numero);
    getchar();

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
        printf(" | ================================================\n");
        system("Pause");
        system(" cls| clear");

    }

    printf("Situacao do paciente: %s\n", cad);

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
