#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

Dados_Servico Servico;

void tela_cadastrar_servico(){

    system ("cls||clear");
    printf("\t===================================================\n");
    printf("\t==============   Cadastrar Serviços   =============\n");
    printf("\t===================================================\n\n");
   
    printf("\t === Digite o codigo do serviço:\n");
    scanf("%[0-9A-Z]", Servico.codigo);
    getchar();
    
    printf("\t === Digite o nome do serviço:\n");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", Servico.nome);
    getchar();
    
    printf("\t === Digite o custo do serviço:\n");
    scanf("%[0-9]", Servico.custo);
    getchar();
    
    printf("\t === Digite o tempo do procedimento(hh/mm):\n");
    scanf("%[0-9 :]", Servico.tempo);
    getchar();
    
    printf("\t === Digite a disponibilidade:\n");
    scanf("%[disponivel indisponivel]", Servico.disposto);
    getchar();
    
    printf("\t==================================================\n\n");

    system("\tPause");
    system("cls | clear");         
}

void tela_pesquisar_servico(){

    system ("cls||clear");
    printf("\t===================================================\n");
    printf("\t==============   Pesquisar Serviços   =============\n");
    printf("\t===================================================\n\n");
    
    printf("\t === Digite o código:\n");
    scanf("%[0-9A-Z]", Servico.codigo);
    getchar();
    
    printf("\t==================================================\n\n");

    system("\tPause");
    system("cls | clear");
}

void tela_alterar_servico(){

    system ("cls||clear");
    printf("\t===================================================\n");
    printf("\t===============   Alterar Serviços   ==============\n");
    printf("\t===================================================\n\n");
    
    printf("\t === Digite o código:\n");
    scanf("%[0-9A-Z]", Servico.codigo);
    getchar();
    
    printf("\t==================================================\n\n");
    
    system("\tPause");
    system("cls | clear");
}

void tela_excluir_servico(){

    system ("cls||clear");
    printf("\t===================================================\n");
    printf("\t===============   Excluir Serviços   ==============\n");
    printf("\t===================================================\n\n");
   
    printf("\t === Digite o código:\n");
    scanf("%[0-9A-Z]", Servico.codigo);
    getchar();
   
    printf("\t==================================================\n\n");
   
    system("\tPause");
    system("cls | clear");
}