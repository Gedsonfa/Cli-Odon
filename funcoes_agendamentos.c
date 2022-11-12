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

    printf("\t === Insira a data:   ");
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

void tela_alterar_agendamento(){

    Dados_Agendamento* age;
    age = (Dados_Agendamento*) malloc(sizeof(Dados_Agendamento));

    system ("cls||clear");
    printf("\t===================================================\n");
    printf("\t===============   Alterar Agendamento   ============\n");
    printf("\t===================================================\n\n");
    
    do
    {
        printf("\t === Insira o CPF:    ");
        scanf("%s", age->cpf);
        getchar();
        
    } while (!validarCPF(age->cpf));
    
    printf("\t==================================================\n\n");
    
    system("\tPause");
    system("cls | clear");

}

void tela_excluir_agendamento(){

    Dados_Agendamento* age;
    age = (Dados_Agendamento*) malloc(sizeof(Dados_Agendamento));

    system ("cls||clear");
    printf("\t===================================================\n");
    printf("\t===============   Excluir Agendamento   ============\n");
    printf("\t===================================================\n\n");
    
    do
    {
        printf("\t === Insira o CPF:    ");
        scanf("%s", age->cpf);
        getchar();
        
    } while (!validarCPF(age->cpf));
    
    printf("\t==================================================\n\n");
    
    system("\tPause");
    system("cls | clear");

}
//update

