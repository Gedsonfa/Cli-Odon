#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validar.h"
#include "structs.h"

Dados_Funcionario Funcionario;

void tela_cadastrar_funcionario(void){
    
    system ("cls||clear");
    printf("\t=========================================================\n");
    printf("\t===============   Cadastrar Funcionarios   ==============\n");
    printf("\t=========================================================\n");
    
    do{
        printf("\t === Insira o CPF:    ");
        scanf("%s",Funcionario.cpf);
        getchar();
        
    }while(!validarCPF(Funcionario.cpf));

    do{
    printf("\t === Insira o nome:   ");
    scanf("%s",Funcionario.nome);
    getchar();
    
    }while(!lerLetras(Funcionario.nome));

    printf("\t === Insira a idade:  ");
    fgets(Funcionario.idade,3,stdin);
    

    printf("\t === Insira o endereco:   ");
    fgets(Funcionario.endereco,31,stdin);
    

    printf("\t === Insira o e-mail: ");
    fgets(Funcionario.email,31,stdin);
    

    printf("\t === Insira o numero telefonico:  ");
    fgets(Funcionario.endereco,12,stdin);
    
    
    printf("\t==================================================\n\n");
    system("\tPause");
    system("cls | clear");
    
        
}

void tela_pesquisar_funcionario(){

    system ("cls||clear");
    printf("\t=========================================================\n");
    printf("\t===============   Pesquisar Funcionarios   ==============\n");
    printf("\t=========================================================\n\n");
    
    do{
    printf("\t === Insira o CPF:    ");
    scanf("%s",Funcionario.cpf);
    getchar();
    
    }while(!validarCPF(Funcionario.cpf));
    
    printf("\t==================================================\n\n");
    
    system("\tPause");
    system("cls | clear");
    
}

void tela_alterar_funcionario(){

    system ("cls||clear");
    printf("\t=========================================================\n");
    printf("\t================   Alterar Funcionarios   ===============\n");
    printf("\t=========================================================\n\n");
    
    do{
    printf("\t === Insira o CPF:    ");
    scanf("%s",Funcionario.cpf);
    getchar();
    
    }while(!validarCPF(Funcionario.cpf));
    
    printf("\t==================================================\n\n");
    
    system("\tPause");
    system("cls | clear");

}

void tela_excluir_funcionario(){

    system ("cls||clear");
    printf("\t=========================================================\n");
    printf("\t================   Excluir Funcionarios   ===============\n");
   
    printf("\t=========================================================\n\n");
    do{       
        printf("\t === Insira o CPF:    ");
        scanf("%s",Funcionario.cpf);
        getchar();
    }while(!validarCPF(Funcionario.cpf));
    
    printf("\t==================================================\n\n");
    
    system("\tPause");
    system("cls | clear");

}
