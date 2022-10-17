#include <stdio.h>
#include <stdlib.h>
void tela_cadastrar_pagamento(){
    char voltar;
    char cpf_funcionario[14];
    do
    {
        system("cls||clear");
        printf("\t===================================================\n");
        printf("\t===============   Cadastrar Pagamento   ============\n");
        printf("\t===================================================\n\n");
        printf("\t === CPF do funcionário:  ");
        scanf("%[0-9 .-/]", cpf_funcionario);
        getchar();
        //implementar um gerador
        printf("\t === codigo unico vinculado ao pagamento: ");
        printf("\t==================================================\n\n");
        printf("\t === Digite 0 para confirmar\n");
        printf("\t=>");
        scanf("%c", &voltar);
        getchar();
    }while(voltar != '0');
}
void tela_pesquisar_pagamento(){
    char voltar;
    do
    {
        system("cls||clear");
        printf("\t===================================================\n");
        printf("\t===============   Pesquisar Pagamento   ============\n");
        printf("\t===================================================\n\n");
        //implementar um gerador
        printf("\t === digite o codigo unico vinculado ao pagamento: ");
        printf("\t==================================================\n\n");
        printf("\t === Digite 0 para confirmar\n");
        printf("\t=>");
        scanf("%c", &voltar);
        getchar();
    }while(voltar != '0');
}
void tela_alterar_pagamento(){
    char voltar;
    do
    {
        system("cls||clear");
        printf("\t===================================================\n");
        printf("\t===============   Alterar Pagamento   ============\n");
        printf("\t===================================================\n\n");
        //implementar um gerador
        printf("\t === digite o codigo unico vinculado ao pagamento: ");
        printf("\t==================================================\n\n");
        printf("\t === Digite 0 para confirmar\n");
        printf("\t=>");
        scanf("%c", &voltar);
        getchar();
    }while(voltar != '0');

}
void tela_excluir_pagamento(){
    char voltar;
    do
    {
        system("cls||clear");
        printf("\t===================================================\n");
        printf("\t===============   Excluir Pagamento   ============\n");
        printf("\t===================================================\n\n");
        //implementar um gerador
        printf("\t === digite o codigo unico vinculado ao pagamento: ");
        printf("\t==================================================\n\n");
        printf("\t === Digite 0 para confirmar\n");
        printf("\t=>");
        scanf("%c", &voltar);
        getchar();
    }while(voltar != '0');

}