#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Assinatura das funcoes
void tela_progr_odont();

//Funções pacientes
void tela_pacientes();
void tela_cadastrar_paciente();
void tela_pesquisar_paciente();
void tela_alterar_paciente();
void tela_excluir_paciente();

//Funções serviços
void tela_servicos();
void tela_cadastrar_servico();
void tela_pesquisar_servico();
void tela_alterar_servico();
void tela_excluir_servico();

//Funções funcionários
void tela_funcionarios();
void tela_cadastrar_funcionario();
void tela_pesquisar_funcionario();
void tela_alterar_funcionario();
void tela_excluir_funcionario();

//Funções Agendamento
void tela_agend();

//Funções Compra
void tela_compra();

//Variaveis de controle
char opcao_navegacao, opcao_inicial, opcao_paci, opcao_serv, opcao_funci, opcao_agend;
int voltar;

//principal
int main(void){
    tela_progr_odont();
    return 0;
}
//funcoes

void tela_progr_odont(){  
    do
    {
        system("cls||clear");
        printf("\n\t====================================================\n");
        printf("\t=========   Projeto Sistema SIG-Dentistry   ========\n"); 
        printf("\t====================================================\n");
        printf("\t=========   Sistema Clinica Odontologica   =========\n");
        printf("\t====================================================\n");
        printf("\t === 1- Modulo Pacientes\n");
        printf("\t === 2- Modulo Servicos\n");
        printf("\t === 3- Modulo Funcionarios\n");
        printf("\t === 4- Modulo Agendamento\n");
        printf("\t === 5- Modulo Pagamento\n");
        printf("\t === 0- Voltar\n");
        printf("\t==================================================\n");
        printf("\t=> ");
        scanf("%c", &opcao_navegacao);
        getchar();
        switch (opcao_navegacao)
        {
        case '1':
            tela_pacientes();
            break;    
        case '2':
            tela_servicos();
            break;  
        case '3':
            tela_funcionarios();
            break;
        case '4':
            tela_agend();
            break; 
        case '5':
            tela_compra();
            break;
        }             
    }while(opcao_navegacao!='0');    
    printf("\tSaindo do programa...\n");
    sleep(1);
    system("cls||clear");
}

void tela_pacientes(){  
    do
    {
        system("cls||clear");

        printf("\t===================================================\n");
        printf("\t===============   Modulo Paciente   ===============\n");
        printf("\t===================================================\n\n");
        printf("\t === 1- Cadastrar Paciente\n");
        printf("\t === 2- Pesquisar Paciente\n");
        printf("\t === 3- Alterar Paciente\n");
        printf("\t === 4- Excluir Paciente\n");
        printf("\t === 0- Voltar\n");
        printf("\n\t==================================================\n\n");
        printf("\t=> ");
        scanf("%c", &opcao_paci);
        getchar();
        switch (opcao_paci){
        case '1':
            tela_cadastrar_paciente();
            tela_pacientes();
            break;
        case '2':
            tela_pesquisar_paciente();
            tela_pacientes();
            break;
        case '3':
            tela_alterar_paciente();
            tela_pacientes();
            break;
        case '4':
            tela_excluir_paciente();
            tela_pacientes();
            break;

        }
    }while(voltar);    
}

void tela_cadastrar_paciente(){
    char cpf_paciente[14];
    char nome_paciente[51];
    char idade_paciente[3];
    char endereco_paciente[51];
    char email_paciente[51];
    char numero_paciente[12];
    do{
        system ("cls||clear");
        printf("\t===================================================\n");
        printf("\t===============   Cadastrar Paciente   ============\n");
        printf("\t===================================================\n\n");
        printf("\t === Insira o CPF:    ");
        scanf("%[0-9 .-/]", cpf_paciente);
        getchar();
        printf("\t === Insira o nome:   ");
        scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", nome_paciente);
        getchar();
        printf("\t === Insira a idade:  ");
        scanf("%s", idade_paciente);
        getchar();
        printf("\t === Insira o endereco:   ");
        scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9 -- .]", endereco_paciente);
        getchar();
        printf("\t === Insira o e-mail: ");
        scanf("%[A-Za-z0-9@._]", email_paciente);
        getchar();
        printf("\t === Insira o numero telefonico:  ");
        scanf("%[0-9]", numero_paciente);
        getchar();
        printf("\t==================================================\n\n");
        printf("\t === Digite 0 para confirmar\n");
        printf("\t=>");
        scanf("%i", &voltar);
        getchar();
    }while(voltar);         
}

void tela_pesquisar_paciente(){
    char cpf_paciente[14];
    do{
        system ("cls||clear");
        printf("\t===================================================\n");
        printf("\t===============   Pesquisar Paciente   ============\n");
        printf("\t===================================================\n\n");
        printf("\t === Digite o CPF:    ");
        scanf("%[0-9 .-/]", cpf_paciente);
        printf("\t==================================================\n\n");
        printf("\t === Digite 0 para voltar\n");
        printf("\t=>");
        scanf("%i", &voltar);
        getchar();
    }while(voltar);
}

void tela_alterar_paciente(){
    char cpf_paciente[14];
    do{
        system ("cls||clear");
        printf("\t===================================================\n");
        printf("\t================   Alterar Paciente   =============\n");
        printf("\t===================================================\n\n");
        printf("\t === Digite o CPF:    ");
        scanf("%[0-9 .-/]", cpf_paciente);
        printf("\t==================================================\n\n");
        printf("\t === Digite 0 para confirmar\n");
        printf("\t=>");
        scanf("%i", &voltar);
        getchar();
    }while(voltar);
}

void tela_excluir_paciente(){
    char cpf_paciente[14];
    do{
        system ("cls||clear");
        printf("\t===================================================\n");
        printf("\t==============   Pesquisar Paciente   =============\n");
        printf("\t===================================================\n\n");
        printf("\t === Digite o CPF:    ");
        scanf("%[0-9 .-/]", cpf_paciente);
        printf("\t==================================================\n\n");
        printf("\t=>");
        scanf("%i", &voltar);
        getchar();
    }while(voltar);
}

void tela_servicos()
{  
    do
    {
        system("cls||clear");

        printf("\t===================================================\n");
        printf("\t==============   Modulo de Servicos   =============\n");
        printf("\t===================================================\n\n");
        printf("\t === 1- Cadastrar servico\n");
        printf("\t === 2- Pesquisar servico\n");
        printf("\t === 3- Editar servico\n");
        printf("\t === 4- Excluir servico\n");
        printf("\t === 0- Voltar\n");
        printf("\n\t==================================================\n\n");
        printf("\t=> ");
        scanf("%c", &opcao_serv);
        getchar();
        switch(opcao_serv){
            case 1:
                tela_cadastrar_servico();
                tela_servicos();
                break;
            case 2:
                tela_pesquisar_servico();
                tela_servicos();
                break;
            case 3:
                tela_alterar_servico();
                tela_servicos();
                break;
            case 4:
                tela_excluir_servico();
                tela_servicos();
                break;

        }
    }while(voltar); 
}

void tela_cadastrar_servico(){
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
        scanf("%i", &voltar);
        getchar();
    }while(voltar);         
}

void tela_pesquisar_servico(){
    do{
        system ("cls||clear");
        printf("\t===================================================\n");
        printf("\t==============   Pesquisar Servicos   =============\n");
        printf("\t===================================================\n\n");
        printf("\t === EM DESENVOLVIMENTO... \n");
        printf("\t==================================================\n\n");
        printf("\t === Digite 0 para voltar\n");
        printf("\t=>");
        scanf("%i", &voltar);
        getchar();
    }while(voltar);
}

void tela_alterar_servico(){
    do{
        system ("cls||clear");
        printf("\t===================================================\n");
        printf("\t===============   Alterar Servicos   ==============\n");
        printf("\t===================================================\n\n");
        printf("\t ===  EM DESENVOLVIMENTO... \n");
        printf("\t==================================================\n\n");
        printf("\t === Digite 0 para confirmar\n");
        printf("\t=>");
        scanf("%i", &voltar);
        getchar();
    }while(voltar);
}

void tela_excluir_servico(){
    do{
        system ("cls||clear");
        printf("\t===================================================\n");
        printf("\t===============   Excluir Servicos   ==============\n");
        printf("\t===================================================\n\n");
        printf("\t === EM DESENVOLVIMENTO... \n");
        printf("\t==================================================\n\n");
        printf("\t === Digite 0 para confirmar a exclusao\n");
        printf("\t=>");
        scanf("%i", &voltar);
        getchar();
    }while(voltar);
}

void tela_funcionarios(){  
    do
    {
        system("cls||clear");

        printf("\t=========================================================\n");
        printf("\t===============   Modulo de Funcionarios   ==============\n");
        printf("\t=========================================================\n\n");
        printf("\t === 1- Cadastrar funcionario\n");
        printf("\t === 2- Pesquisar funcionario\n");
        printf("\t === 3- Alterar funcionario\n");
        printf("\t === 4- Excluir funcionaio\n");
        printf("\t === 0- Voltar\n");
        printf("\n\t======================================================\n\n");
        printf("\t=> ");
        scanf("%c", &opcao_funci);
        getchar();
        switch(opcao_funci){
            case 1:
                tela_cadastrar_funcionario();
                tela_funcionarios();
                break;
            case 2:
                tela_pesquisar_funcionario();
                tela_funcionarios();
                break;
            case 3:
                tela_alterar_funcionario();
                tela_funcionarios();
                break;
            case 4:
                tela_excluir_funcionario();
                tela_funcionarios();
                break;

        }
    }while(voltar);  
}

void tela_cadastrar_funcionario(){
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
        printf("\t === Digite 0 para confirmar\n");
        printf("\t=>");
        scanf("%i", &voltar);
        getchar();
    }while(voltar);         
}

void tela_pesquisar_funcionario(){
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
        scanf("%i", &voltar);
        getchar();
    }while(voltar);
}

void tela_alterar_funcionario(){
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
        scanf("%i", &voltar);
        getchar();
    }while(voltar);
}

void tela_excluir_funcionario(){
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
        scanf("%i", &voltar);
        getchar();
    }while(voltar);
}

void tela_compra(){
    do{
        system ("cls||clear");
        printf("\t===================================================\n");
        printf("\t===============   Efetuar pagamento   =============\n");
        printf("\t===================================================\n\n");
        printf("\t === EM DESENVOLVIMENTO...\n");
        printf("\t==================================================\n\n");
        printf("\t === Digite 0 para confirmar\n");
        printf("\t=>");
        scanf("%i", &voltar);
        getchar();
    }while(voltar);         
}

void tela_agend(){
    do{
        system ("cls||clear");
        printf("\t===================================================\n");
        printf("\t===============   Tela Agendamento   ==============\n");
        printf("\t===================================================\n\n");
        printf("\t === EM DESENVOLVIMENTO...\n");
        printf("\t==================================================\n\n");
        printf("\t === Digite 0 para confirmar\n");
        printf("\t=>");
        scanf("%i", &voltar);
        getchar();
    }while(voltar);         
}