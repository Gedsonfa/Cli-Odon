#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Assinatura das funcoes
void tela_desenvolvedores();
void tela_progr_odont();
void tela_especificacao();
void tela_pacientes();
void tela_servicos();
void tela_funcionarios();
void tela_entrada();
void tela_cadastrar_paciente();
void tela_pesquisar_paciente();
void tela_alterar_paciente();
void tela_excluir_paciente();
//Variaveis de controle
int opcao_navegacao, voltar, opcao_inicial, opcao_paci;

//principal
int main(void){
    tela_entrada();
    return 0;
}
//funcoes
void tela_especificacao()
{  
    do
    {
        system("cls||clear");
        printf("\n\t==================================================\n\n");
        printf("\tUniversidade Federal do Rio Grande do Norte\n");
        printf("\tCentro de Ensino Superior do Serido\n");
        printf("\tDepartamento de Computacao e Tecnologia\n");
        printf("\tBacharelado em Sistemas de Informacao\n\n");
        printf("\tDisciplina DCT1106 == Programacao\n");
        printf("\tProjeto Sistema SIG-Dentistry\n");
        printf("\tDeveloped by @Gedsonfa and @JapaGabriel since Ago, 2022\n\n");
        printf("\t==================================================\n\n");
        printf("\t=== Clinica Odontologica ===\n\n");
        printf("\tPrograma ultilizado para avaliacao da dupla na disciplina DCT1106 == Programacao,\n\tcom o objetivo de servir a uma clinica odontologica.\n");
        printf("\t==================================================\n\n");
        printf("\tTecle 0 para continuar.\n");
        scanf("%i", &voltar);
        getchar();
    }while(voltar!=0);

}

void tela_progr_odont(){  
    do
    {
        system("cls||clear");
        printf("\n\t==================================================\n\n");
        printf("\tProjeto Sistema SIG-Dentistry\n\n"); 
        printf("\t==================================================\n\n");
        printf("\t === Sistema Clinica Odontologica ===\n");
        printf("\t === 1- Modulo Pacientes\n");
        printf("\t === 2- Modulo Servicos\n");
        printf("\t === 3- Modulo Funcionarios\n");
        printf("\t === 0- Voltar\n");
        printf("\n\t==================================================\n\n");
        printf("\t=> ");
        scanf("%i", &opcao_navegacao);
        getchar();
        switch (opcao_navegacao)
        {
        case 1:
            tela_pacientes();
            break;    
        case 2:
            tela_servicos();
            break;  
        case 3:
            tela_funcionarios();
            break;  
        }             
    }while(opcao_navegacao);    
}

void tela_pacientes(){  
    do
    {
        system("cls||clear");

        printf("\t==================================================\n\n");
        printf("\t === Modulo Pacientes ===\n");
        printf("\t === 1- Cadastrar Paciente\n");
        printf("\t === 2- Pesquisar Paciente\n");
        printf("\t === 3- Alterar Paciente\n");
        printf("\t === 4- Excluir Paciente\n");
        printf("\t === 0- Voltar\n");
        printf("\n\t==================================================\n\n");
        printf("\t=> ");
        scanf("%i", &opcao_paci);
        getchar();
        switch (opcao_paci){
        case 1:
            tela_cadastrar_paciente();
            break;
        case 2:
            tela_pesquisar_paciente();
            break;
        case 3:
            tela_alterar_paciente();
            break;
        case 4:
            tela_excluir_paciente();
            break;
        }
    }while(voltar);    
}

void tela_cadastrar_paciente(){
    do
    {
        system ("cls||clear");

        printf("\n\t=== Cadastra Paciente ===\n");
        printf("\t === Insina o CPF:\n");
        scanf(";");
        getchar();
        printf("\t === Insira o nome:\n");
        scanf(";");
        getchar();
        printf("\t === Insira o genero:\n");
        scanf(";");
        getchar();
        printf("\t === Insira o endereco:\n");
        scanf(";");
        getchar();
        printf("\t === Digite 0 para confirmar\n");
        printf("\t=>");
        getchar();
        scanf("%i", &voltar);
        getchar();
    } while (voltar);       
}

void tela_pesquisar_paciente(){
    do{
        system ("cls||clear");

        printf("\t === Pesquisar Paciente ===\n");
        printf("\t === Digite o codigo a ser buscado:\n");
        scanf(";");
        printf("\t=== Aqui estaram os dados ===\n");
        printf("\t === Digite 0 para voltar\n");
        printf("\t=>");
        scanf("%i", &voltar);
        getchar();
    }while(voltar);
}

void tela_alterar_paciente(){
    do{
        system ("cls||clear");

        printf("\t === Pesquisar Paciente ===\n");
        printf("\t === Digite o codigo a ser buscado:\n");
        scanf(";");
        printf("\t === Aqui estaram os dados ===\n");
        printf("\t === Aqui estaram as opcoes para alteracao ===\n");
        printf("\t === Digite 0 para confirmar\n");
        printf("\t=>");
        scanf("%i", &voltar);
        getchar();
    }while(voltar);
}

void tela_excluir_paciente(){
    do{
        system ("cls||clear");

        printf("\t === Pesquisar Paciente ===\n");
        printf("\t === Digite o codigo a ser buscado:\n");
        scanf(";");
        printf("\t === Aqui estaram os dados ===\n");
        printf("\t === Digite 0 para confirmar a exlusao\n");
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

        printf("\t==================================================\n\n");
        printf("\t === Módulo de Serviços ===\n");
        printf("\t === 1- pesquisar serviço\n");
        printf("\t === 2- Tabela de preço\n");
        printf("\t === 3- Editar serviço\n");
        printf("\t === 4- Excluir serviço\n");
        printf("\t === 0- Voltar\n");
        printf("\n\t==================================================\n\n");
        printf("\t=> ");
        scanf("%i", &voltar);
        getchar();
    }while(voltar);
    
}

void tela_funcionarios(){  
    do
    {
        system("cls||clear");

        printf("\t==================================================\n\n");
        printf("\t === Módulo Funcionarios ===\n");
        printf("\t === 1- Cadastrar funcionário\n");
        printf("\t === 2- Pesquisar funcionário\n");
        printf("\t === 3- Editar funcionário\n");
        printf("\t === 4- Excluir funcionário\n");
        printf("\t === 0- Voltar\n");
        printf("\n\t==================================================\n\n");
        printf("\t=> ");
        scanf("%i", &voltar);
        getchar();
    }while(voltar);  
}

void tela_desenvolvedores(){
    do
    {
        system("cls||clear");
        printf("\n\t==================================================\n\n");
        printf("\tUniversidade Federal do Rio Grande do Norte\n");
        printf("\tCentro de Ensino Superior do Serido\n");
        printf("\tDepartamento de Computacao e Tecnologia\n");
        printf("\tBacharelado em Sistemas de Informacao\n\n");
        printf("\tDisciplina DCT1106 == Programacao\n");
        printf("\tProjeto Sistema SIG-Dentistry\n");
        printf("\tDeveloped by @Gedsonfa and @JapaGabriel since Ago, 2022\n\n");
        printf("\t==================================================\n\n");
        printf("\t==== Sistema de Gestao de Clinica Dentaria ====\n\n");
        printf("\tEste projeto foi desenvolvido por:\n\n");
        printf("\tDiscente: Gedson Fernandes\n");
        printf("\tE-mail: gedsonfda@gmail.com\n");
        printf("\tRedes sociais: @gedsonfa\n");
        printf("\tGit: https://github.com/Gedsonfa\n\n");
        printf("\t==================================================\n\n");
        printf("\tDiscente: Gabriel Wallace ===\n");
        printf("\tE-mail: gcanutosantos@gmail.com\n");
        printf("\tRedes sociais: @gabriel_wallace_17===\n");
        printf("\tGit: https://github.com/Japagabriel===\n\n");
        printf("\t==================================================\n\n");
        printf("\tTecle 0 para continuar.\n");
        scanf("%i", &voltar);
        getchar();
    }while(voltar!=0);      
}

void tela_entrada(){  
    do
    { 
        system("cls||clear");
        setlocale(LC_ALL, "Portuguese_Brazil");
        printf("\n\t==================================================\n");
        printf("\t == Selecione uma opcao ==\n");
        printf("\t == 1- Entrar no Programa\n");
        printf("\t == 2- Tela de Equipe\n");
        printf("\t == 3- Tela de Informacao\n");
        printf("\t == 0- Sair\n");
        printf("\t==================================================\n");
        printf("\t=> ");
        scanf("%i", &opcao_inicial);
        getchar();
        switch (opcao_inicial)
        {
            case 1:
            tela_progr_odont();
            break;
            case 2:
            tela_desenvolvedores();
            break;
            case 3:
            tela_especificacao();
            break;
        }

    }while (opcao_inicial);
    system("cls||clear");
    printf("\tSaindo do programa...\n");
}


