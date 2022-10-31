#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validar.h"
#include "structs.h"

Dados_Paciente Paciente;

void tela_cadastrar_paciente(){

    system ("cls||clear");
    printf("\t===================================================\n");
    printf("\t===============   Cadastrar Paciente   ============\n");
    printf("\t===================================================\n\n");
    
    do
    {
        printf("\t === Insira o CPF:    ");
        scanf("%s", Paciente.cpf);
        getchar();
        
    } while (!validarCPF(Paciente.cpf));
    
    do{
        printf("\t === Insira o nome:   ");
        scanf("%s", Paciente.nome);
        getchar();
        
    }while(!lerLetras(Paciente.nome));

    printf("\t === Insira a idade:  ");
    fgets(Paciente.idade,3,stdin);
    

    printf("\t === Insira o endereço:   ");
    fgets(Paciente.endereco,51,stdin);
    

    printf("\t === Insira o e-mail: ");
    fgets(Paciente.email,51,stdin);
    

    printf("\t === Insira o numero telefonico:  ");
    fgets(Paciente.numero,12,stdin);
    

    printf("\t==================================================\n\n");
    system("\tPause");
    system("cls | clear");

}
void tela_pesquisar_paciente(){

    system ("cls||clear");
    printf("\t===================================================\n");
    printf("\t===============   Pesquisar Paciente   ============\n");
    printf("\t===================================================\n\n");
    
    do
    {
        printf("\t === Insira o CPF:    ");
        scanf("%s", Paciente.cpf);
        getchar();
        
    } while (!validarCPF(Paciente.cpf));
    
    printf("\t==================================================\n\n");
    
    system("\tPause");
    system("cls | clear");

}

void tela_alterar_paciente(){

    system ("cls||clear");
    printf("\t===================================================\n");
    printf("\t================   Alterar Paciente   =============\n");
    
    printf("\t===================================================\n\n");
    do
    {
        printf("\t === Insira o CPF:    ");
        scanf("%s", Paciente.cpf);
        getchar();
        
    } while (!validarCPF(Paciente.cpf));
    
    printf("\t==================================================\n\n");
    
    system("\tPause");
    system("cls | clear");

}

void tela_excluir_paciente(){

    system ("cls||clear");
    printf("\t===================================================\n");
    printf("\t==============   Pesquisar Paciente   =============\n");
    printf("\t===================================================\n\n");
   
    do
    {
        printf("\t === Insira o CPF:    ");
        scanf("%s", Paciente.cpf);
        getchar();
        
    } while (!validarCPF(Paciente.cpf));
    
    printf("\t==================================================\n\n");
    
    system("\tPause");
    system("cls | clear");
}