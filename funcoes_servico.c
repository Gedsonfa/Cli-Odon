#include <stdio.h>
#include <stdlib.h>
void tela_cadastrar_servico(){
    char voltar;
    do{
        system ("cls||clear");
        printf("\t===================================================\n");
        printf("\t==============   Cadastrar Servicos   =============\n");
        printf("\t===================================================\n\n");
        printf("\t === Digite o nome do servico:\n");
        printf("\t === Digite o custo do servico:\n");
        printf("\t === Digite o tempo do procedimento:\n");
        printf("\t === Digite a disponibilidade:\n");
        printf("\t==================================================\n\n");
        printf("\t === Digite 0 para confirmar\n");
        printf("\t=>");
        scanf("%c", &voltar);
        getchar();
    }while(voltar!='0');         
}

void tela_pesquisar_servico(){
    char voltar;
    do{
        system ("cls||clear");
        printf("\t===================================================\n");
        printf("\t==============   Pesquisar Servicos   =============\n");
        printf("\t===================================================\n\n");
        printf("\t === EM DESENVOLVIMENTO... \n");
        printf("\t==================================================\n\n");
        printf("\t === Digite 0 para voltar\n");
        printf("\t=>");
        scanf("%c", &voltar);
        getchar();
    }while(voltar!='0');
}

void tela_alterar_servico(){
    char voltar;
    do{
        system ("cls||clear");
        printf("\t===================================================\n");
        printf("\t===============   Alterar Servicos   ==============\n");
        printf("\t===================================================\n\n");
        printf("\t ===  EM DESENVOLVIMENTO... \n");
        printf("\t==================================================\n\n");
        printf("\t === Digite 0 para confirmar\n");
        printf("\t=>");
        scanf("%c", &voltar);
        getchar();
    }while(voltar!='0');
}

void tela_excluir_servico(){
    char voltar;
    do{
        system ("cls||clear");
        printf("\t===================================================\n");
        printf("\t===============   Excluir Servicos   ==============\n");
        printf("\t===================================================\n\n");
        printf("\t === EM DESENVOLVIMENTO... \n");
        printf("\t==================================================\n\n");
        printf("\t === Digite 0 para confirmar a exclusao\n");
        printf("\t=>");
        scanf("%c", &voltar);
        getchar();
    }while(voltar!='0');
}