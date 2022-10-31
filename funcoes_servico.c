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
    fgets(Servico.codigo,6,stdin);
    
    
    printf("\t === Digite o nome do serviço:\n");
    fgets(Servico.nome,51,stdin);
    
    
    printf("\t === Digite o custo do serviço:\n");
    fgets(Servico.custo,7,stdin);
    
    
    printf("\t === Digite o tempo do procedimento(hh/mm):\n");
    fgets(Servico.tempo,6,stdin);
    
    
    printf("\t === Digite a disponibilidade:\n");
    fgets(Servico.disposto,13,stdin);
    
    
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
    fgets(Servico.codigo,6,stdin);
    
    
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
    fgets(Servico.codigo,6,stdin);
    
    
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
    fgets(Servico.codigo,6,stdin);
    
   
    printf("\t==================================================\n\n");
   
    system("\tPause");
    system("cls | clear");
}