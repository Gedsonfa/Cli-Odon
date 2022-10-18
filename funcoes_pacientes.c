#include <stdio.h>
#include <stdlib.h>
#include "validar.h"
void tela_cadastrar_paciente(){
    char voltar;
    char cpf_paciente[14];
    char nome_paciente[51];
    char idade_paciente[3];
    char endereco_paciente[51];
    char email_paciente[51];
    char numero_paciente[12];
    do{
        system ("cls||clear");
        printf("\t===================================================\n");
        printf("\t===============   Cadastrar Paciente   ============\n");
        printf("\t===================================================\n\n");
        printf("\t === Insira o CPF:    ");
        scanf("%[0-9 .-/]", cpf_paciente);
        getchar();
        printf("\t === Insira o nome:   ");
        scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", nome_paciente);
        getchar();
        printf("\t === Insira a idade:  ");
        scanf("%s", idade_paciente);
        getchar();
        printf("\t === Insira o endereço:   ");
        scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9 -- .]", endereco_paciente);
        getchar();
        printf("\t === Insira o e-mail: ");
        scanf("%[A-Za-z0-9@._]", email_paciente);
        getchar();
        printf("\t === Insira o numero telefonico:  ");
        scanf("%[0-9]", numero_paciente);
        getchar();
        printf("\t==================================================\n\n");
        printf("\t === Digite 0 para confirmar\n");
        printf("\t=>");
        scanf("%c", &voltar);
        getchar();
    }while(voltar!='0');         
}
void tela_pesquisar_paciente(){
    char voltar;
    char cpf_paciente[14];
    do{
        system ("cls||clear");
        printf("\t===================================================\n");
        printf("\t===============   Pesquisar Paciente   ============\n");
        printf("\t===================================================\n\n");
        printf("\t === Digite o CPF:    ");
        scanf("%[0-9 .-/]", cpf_paciente);
        getchar();
        printf("\t==================================================\n\n");
        printf("\t === Digite 0 para voltar\n");
        printf("\t=>");
        scanf("%c", &voltar);
        getchar();
    }while(voltar!='0');
}

void tela_alterar_paciente(){
    char voltar;
    char cpf_paciente[14];
    do{
        system ("cls||clear");
        printf("\t===================================================\n");
        printf("\t================   Alterar Paciente   =============\n");
        printf("\t===================================================\n\n");
        printf("\t === Digite o CPF:    ");
        scanf("%[0-9 .-/]", cpf_paciente);
        getchar();
        printf("\t==================================================\n\n");
        printf("\t === Digite 0 para confirmar\n");
        printf("\t=>");
        scanf("%c", &voltar);
        getchar();
    }while(voltar!='0');
}

void tela_excluir_paciente(){
    char voltar;
    char cpf_paciente[14];
    do{
        system ("cls||clear");
        printf("\t===================================================\n");
        printf("\t==============   Pesquisar Paciente   =============\n");
        printf("\t===================================================\n\n");
        printf("\t === Digite o CPF:    ");
        scanf("%[0-9 .-/]", cpf_paciente);
        getchar();
        printf("\t==================================================\n\n");
        printf("\t=>");
        scanf("%c", &voltar);
        getchar();
    }while(voltar!='0');
}