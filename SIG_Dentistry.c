#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Assinatura das funcoes
void tela_equi();
void tela_princi();
void tela_sobre();
void tela_pacientes();
void tela_servicos();
void tela_funcio();
void tela_adm();
void tela_d_entrada();
void cadast_paciente();

//Variaveis de controle
int opcao_navegacao, voltar, opcao_inicial, opcao_paci;

//funcoes
void tela_sobre()
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
    }while(voltar!=0);

}

void tela_princi()
{  
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
        printf("\t === 4- Modulo Administrativo\n");
        printf("\t === 0- Voltar\n");
        printf("\n\t==================================================\n\n");
        printf("\t=> ");
        scanf("%i", &opcao_navegacao);
        switch (opcao_navegacao)
        {
        case 1:
            tela_pacientes();
            break;    
        case 2:
            tela_servicos();
            break;  
        case 3:
            tela_funcio();
            break;  
        case 4:
            tela_adm();
            break;
        }
               
    }while(opcao_navegacao != 0);
    
}

void tela_pacientes()
{  
    do
    {
        system("cls||clear");

        printf("\t==================================================\n\n");
        printf("\t === Módulo Pacientes ===\n");
        printf("\t === 1- Cadastrar Paciente\n");
        printf("\t === 2- Pesquisar Paciente\n");
        printf("\t === 3- Editar Paciente\n");
        printf("\t === 4- Excluir Paciente\n");
        printf("\t === 0- Voltar\n");
        printf("\n\t==================================================\n\n");
        printf("\t=> ");
        scanf("%i", &opcao_paci);
        switch (opcao_paci)
        {
        case 0:
            voltar = 0;
            break;
        case 1:
            cadast_paciente();
            break;
        case 2:
            ;
            break;
        case 3:
            ;
            break;
        case 4:
            ;
            break;
        }
        break;

    }while(voltar != 0);
    
}

void cadast_paciente()
{
    do
    {
        system ("cls||clear");

        printf("\n\t=== Cadastra Paciente ===\n");
        printf("\t === Insina o CPF:\n");
        printf("\t === Insira o nome:\n");
        printf("\t === Insira o genero:\n");
        printf("\t === Insira o endereco:\n");
        printf("\t === Digite 0 para confirmar\n");
        printf("\t=>");
        scanf("%i", &voltar);
    } while (voltar != 0);
    
    
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
        break;

        
    }while(voltar != 0);
    
}

void tela_funcio()
{  
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
        break;

        
    }while(voltar != 0);
    
}

void tela_adm()
{  
    do
    {
        system("cls||clear");

        printf("\t==========================================\n\n");
        printf("\t === Módulo Admnistrativo ===\n");
        printf("\t === 1- ADM serviços\n");
        printf("\t === 2- ADM clientes\n");
        printf("\t === 3- ADM funcionários\n");
        printf("\t === 0- Voltar\n");
        printf("\n\t=========================================\n\n");
        printf("\t=> ");
        scanf("%i", &voltar);
        break;

        
    }while(voltar != 0);
    
}



void tela_equi()
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
    }while(voltar!=0);
        


}
void tela_d_entrada()
{  
    do
    { 
        system("cls||clear");
        setlocale(LC_ALL, "Portuguese_Brazil");
        printf("\n\t==================================================\n");
        printf("\t == Selecione uma opcao ==\n");
        printf("\t == 1- Tela de Equipe\n");
        printf("\t == 2- Entrar no Programa\n");
        printf("\t == 3- Tela de Informacao\n");
        printf("\t == 0- Sair\n");
        printf("\t==================================================\n");
        printf("\t=> ");
        scanf("%i", &opcao_inicial);
        switch (opcao_inicial)
        {
            case 1:
            tela_equi();
            break;
            case 2:
            tela_princi();
            break;
            case 3:
            tela_sobre();
            break;
        }
    }while (opcao_inicial != 0);
    system("cls||clear");
    printf("\tSaindo do programa...\n");
}

//Principal
int main(void)
{
    tela_d_entrada();
    return 0;
}