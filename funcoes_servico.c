#include <stdio.h>
#include <stdlib.h>
void tela_cadastrar_servico(){
    char voltar;
    char codigo_servico[6];
    char nome_servico[51];
    char custo_servico[7];
    char tempo_servico[6];
    char disposto_servico[13];
    do{
        system ("cls||clear");
        printf("\t===================================================\n");
        printf("\t==============   Cadastrar Servicos   =============\n");
        printf("\t===================================================\n\n");
        printf("\t === Digite o codigo do servico:\n");
        scanf("%[0-9A-Z]", codigo_servico);
        getchar();
        printf("\t === Digite o nome do servico:\n");
        scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", nome_servico);
        getchar();
        printf("\t === Digite o custo do servico:\n");
        scanf("%[0-9]", custo_servico);
        getchar();
        printf("\t === Digite o tempo do procedimento(hh/mm):\n");
        scanf("%[0-9 :]", tempo_servico);
        printf("\t === Digite a disponibilidade:\n");
        scanf("%[disponivel indisponivel]", disposto_servico);
        getchar();
        printf("\t==================================================\n\n");
        printf("\t === Digite 0 para confirmar\n");
        printf("\t=>");
        scanf("%c", &voltar);
        getchar();
    }while(voltar!='0');         
}

void tela_pesquisar_servico(){
    char codigo_servico[6];
    char voltar;
    do{
        system ("cls||clear");
        printf("\t===================================================\n");
        printf("\t==============   Pesquisar Servicos   =============\n");
        printf("\t===================================================\n\n");
        printf("\t === Digite o codigo:\n");
        scanf("%[0-9A-Z]", codigo_servico);
        getchar();
        printf("\t==================================================\n\n");
        printf("\t === Digite 0 para voltar\n");
        printf("\t=>");
        scanf("%c", &voltar);
        getchar();
    }while(voltar!='0');
}

void tela_alterar_servico(){
    char codigo_servico[6];
    char voltar;
    do{
        system ("cls||clear");
        printf("\t===================================================\n");
        printf("\t===============   Alterar Servicos   ==============\n");
        printf("\t===================================================\n\n");
        printf("\t === Digite o codigo:\n");
        scanf("%[0-9A-Z]", codigo_servico);
        getchar();
        printf("\t==================================================\n\n");
        printf("\t === Digite 0 para confirmar\n");
        printf("\t=>");
        scanf("%c", &voltar);
        getchar();
    }while(voltar!='0');
}

void tela_excluir_servico(){
    char codigo_servico[6];
    char voltar;
    do{
        system ("cls||clear");
        printf("\t===================================================\n");
        printf("\t===============   Excluir Servicos   ==============\n");
        printf("\t===================================================\n\n");
        printf("\t === Digite o codigo:\n");
        scanf("%[0-9A-Z]", codigo_servico);
        getchar();
        printf("\t==================================================\n\n");
        printf("\t === Digite 0 para confirmar a exclusao\n");
        printf("\t=>");
        scanf("%c", &voltar);
        getchar();
    }while(voltar!='0');
}