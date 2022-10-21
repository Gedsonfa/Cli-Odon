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
        scanf("%s",Paciente.cpf);
        getchar();
    } while (!validarCPF(Paciente.cpf));
    
    do{
        printf("\t === Insira o nome:   ");
        scanf("%s", Paciente.nome);
        getchar();
    }while(!lerLetras(Paciente.nome));

    printf("\t === Insira a idade:  ");
    scanf("%s", Paciente.idade);
    getchar();

    printf("\t === Insira o endereço:   ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9 -- .]", Paciente.endereco);
    getchar();

    printf("\t === Insira o e-mail: ");
    scanf("%[A-Za-z0-9@._]", Paciente.email);
    getchar();

    printf("\t === Insira o numero telefonico:  ");
    scanf("%[0-9]", Paciente.numero);
    getchar();

    printf("\t==================================================\n\n");
    system("\tPause");
    system("cls | clear");

}
void tela_pesquisar_paciente(){

    system ("cls||clear");
    printf("\t===================================================\n");
    printf("\t===============   Pesquisar Paciente   ============\n");
    printf("\t===================================================\n\n");
    printf("\t === Digite o CPF:    ");
    scanf("%[0-9 .-/]", Paciente.cpf);
    getchar();
    printf("\t==================================================\n\n");
    system("\tPause");
    system("cls | clear");

}

void tela_alterar_paciente(){

    system ("cls||clear");
    printf("\t===================================================\n");
    printf("\t================   Alterar Paciente   =============\n");
    printf("\t===================================================\n\n");
    printf("\t === Digite o CPF:    ");
    scanf("%[0-9 .-/]", Paciente.cpf);
    getchar();
    printf("\t==================================================\n\n");
    printf("\t === Digite 0 para confirmar\n");
    system("\tPause");
    system("cls | clear");

}

void tela_excluir_paciente(){

    system ("cls||clear");
    printf("\t===================================================\n");
    printf("\t==============   Pesquisar Paciente   =============\n");
    printf("\t===================================================\n\n");
    printf("\t === Digite o CPF:    ");
    scanf("%[0-9 .-/]", Paciente.cpf);
    getchar();
    printf("\t==================================================\n\n");
    system("\tPause");
    system("cls | clear");
}