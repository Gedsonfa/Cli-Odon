#include <stdio.h>
#include <stdlib.h>
#include "validar.h"

void tela_cadastrar_funcionario(void){
    
    char cpf_funcionario[15];
    char nome_funcionario[30];
    char idade_funcionario[3];
    char endereco_funcionario[31];
    char email_funcionario[31];
    char numero_funcionario[12];
    
    system ("cls||clear");
    printf("\t=========================================================\n");
    printf("\t===============   Cadastrar Funcionarios   ==============\n");
    printf("\t=========================================================\n");
    do{
        printf("\t === Insira o CPF:    ");
        scanf("%s", cpf_funcionario);
        getchar();
    }while(!validarCPF(cpf_funcionario));

    do{
    printf("\t === Insira o nome:   ");
    scanf("%s", nome_funcionario);
    getchar();
    }while(!lerLetras(nome_funcionario));

    printf("\t === Insira a idade:  ");
    scanf("%s", idade_funcionario);
    getchar();
    printf("\t === Insira o endereco:   ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9 -- .]", endereco_funcionario);
    getchar();
    printf("\t === Insira o e-mail: ");
    scanf("%[A-Za-z0-9@._]", email_funcionario);
    getchar();
    printf("\t === Insira o numero telefonico:  ");
    scanf("%[0-9]", numero_funcionario);
    getchar();
    printf("\t==================================================\n\n");
    system("\tPause");
    system("cls | clear");
    
        
}

void tela_pesquisar_funcionario(){
    char voltar;
    char cpf_funcionario[14];
    do{
        system ("cls||clear");
        printf("\t=========================================================\n");
        printf("\t===============   Pesquisar Funcionarios   ==============\n");
        printf("\t=========================================================\n\n");
        printf("\t === Digite o CPF:    ");
        scanf("%[0-9 .-/]", cpf_funcionario);
        printf("\t==================================================\n\n");
        printf("\t === Digite 0 para voltar\n");
        printf("\t=>");
        scanf("%c", &voltar);
        getchar();
    }while(voltar!='0');
}

void tela_alterar_funcionario(){
    char voltar;
    char cpf_funcionario[14];
    do{
        system ("cls||clear");
        printf("\t=========================================================\n");
        printf("\t================   Alterar Funcionarios   ===============\n");
        printf("\t=========================================================\n\n");
        printf("\t === Digite o CPF:    ");
        scanf("%[0-9 .-/]", cpf_funcionario);
        printf("\t==================================================\n\n");
        printf("\t === Digite 0 para confirmar\n");
        printf("\t=>");
        scanf("%c", &voltar);
        getchar();
    }while(voltar!='0');
}

void tela_excluir_funcionario(){
    char voltar;
    char cpf_funcionario[14];
    do{
        system ("cls||clear");
        printf("\t=========================================================\n");
        printf("\t================   Excluir Funcionarios   ===============\n");
        printf("\t=========================================================\n\n");
        printf("\t === Digite o CPF:    ");
        scanf("%[0-9 .-/]", cpf_funcionario);
        printf("\t==================================================\n\n");
        printf("\t === Digite 0 para confirmar a exclusao\n");
        printf("\t=>");
        scanf("%c", &voltar);
        getchar();
    }while(voltar!='0');
}
