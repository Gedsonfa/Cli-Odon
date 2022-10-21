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
    scanf("%s", Funcionario.nome);
    getchar();
    }while(!lerLetras(Funcionario.nome));

    printf("\t === Insira a idade:  ");
    scanf("%s", Funcionario.idade);
    getchar();

    printf("\t === Insira o endereco:   ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9 -- .]", Funcionario.endereco);
    getchar();

    printf("\t === Insira o e-mail: ");
    scanf("%[A-Za-z0-9@._]", Funcionario.email);
    getchar();

    printf("\t === Insira o numero telefonico:  ");
    scanf("%[0-9]", Funcionario.telefone);
    getchar();
    
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
