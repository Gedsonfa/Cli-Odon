#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validar.h"
#include "structs.h"

Dados_Pagamento Pagamento;

void tela_cadastrar_pagamento(){

    system("cls||clear");
    printf("\t===================================================\n");
    printf("\t===============   Cadastrar Pagamento   ============\n");
    printf("\t===================================================\n\n");
    
    printf("\t === CPF do funcionário:  ");
    fgets(Pagamento.id,6,stdin);
    
    
    printf("\t==================================================\n\n");
    
    system("\tPause");
    system("cls | clear");
}

void tela_pesquisar_pagamento(){

    system("cls||clear");
    printf("\t===================================================\n");
    printf("\t===============   Pesquisar Pagamento   ============\n");
    printf("\t===================================================\n\n");
      
    printf("\t==================================================\n\n");
    
    system("\tPause");
    system("cls | clear");

}

void tela_alterar_pagamento(){

    system("cls||clear");
    printf("\t===================================================\n");
    printf("\t===============   Alterar Pagamento   ============\n");
    printf("\t===================================================\n\n");
    
    printf("\t==================================================\n\n");
    
    system("\tPause");
    system("cls | clear");

}
void tela_excluir_pagamento(){

    system("cls||clear");
    printf("\t===================================================\n");
    printf("\t===============   Excluir Pagamento   ============\n");
    printf("\t===================================================\n\n");
    
    printf("\t==================================================\n\n");
    
    system("\tPause");
    system("cls | clear");

}