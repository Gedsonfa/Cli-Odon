#include <stdio.h>
#include <stdlib.h>
void tela_cadastrar_funcionario(){
    char voltar;
    char cpf_funcionario[14];
    char nome_funcionario[51];
    char idade_funcionario[3];
    char endereco_funcionario[51];
    char email_funcionario[51];
    char numero_funcionario[12];
    do{
        system ("cls||clear");
        printf("\t=========================================================\n");
        printf("\t===============   Cadastrar Funcionarios   ==============\n");
        printf("\t=========================================================\n\n");
        printf("\t === Insira o CPF:    ");
        scanf("%[0-9./]", cpf_funcionario);
        getchar();
        printf("\t === Insira o nome:   ");
        scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", nome_funcionario);
        getchar();
        printf("\t === Insira a idade:  ");
        scanf("%[0-9 ]", idade_funcionario);
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
        printf("\t === Digite 0 para confirmar\n");
        printf("\t=>");
        scanf("%c", &voltar);
        getchar();
    }while(voltar!='0');         
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