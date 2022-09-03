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

//Variaveis de controle
int opcao_inicial;
int voltar;


//funcoes
void tela_sobre()
{  

        system("clear");
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
        printf("\tTecle ENTER para continuar.\n");
        getchar();

}

void tela_princi()
{  
    do
    {
        system("clear");
        printf("\n\t==================================================\n\n");
        printf("\tUniversidade Federal do Rio Grande do Norte\n");
        printf("\tCentro de Ensino Superior do Serido\n");
        printf("\tDepartamento de Computacao e Tecnologia\n");
        printf("\tBacharelado em Sistemas de Informacao\n\n");
        printf("\tDisciplina DCT1106 == Programacao\n");
        printf("\tProjeto Sistema SIG-Dentistry\n");
        printf("\tDeveloped by @Gedsonfa and @=== == since Ago, 2022\n\n");
        printf("\t==================================================\n\n");
        printf("\t === Sistema Clinica Odontologica ===\n");
        printf("\t === 1- Modulo Cliente\n");
        printf("\t === 2- Modulo Funcionario\n");
        printf("\t === 3- Trabalhos Realizados\n");
        printf("\t === 4- Sobre Nos\n");
        printf("\t === 0- Voltar\n");
        printf("\n\t==================================================\n\n");
        printf("\t=> ");
        scanf("%i", &voltar);
        break;

        
    }while(voltar != 0);
    
}

void tela_pacientes()
{  
    do
    {
        system("clear");

        printf("\t==================================================\n\n");
        printf("\t === Módulo Pacientes ===\n");
        printf("\t === 1- Cadastrar Paciente\n");
        printf("\t === 2- Pesquisar Paciente\n");
        printf("\t === 3- Editar Paciente\n");
        printf("\t === 4- Excluir Paciente\n");
        printf("\t === 0- Voltar\n");
        printf("\n\t==================================================\n\n");
        printf("\t=> ");
        scanf("%i", &voltar);
        break;

        
    }while(voltar != 0);
    
}

void tela_servicos()
{  
    do
    {
        system("clear");

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
        system("clear");

        printf("\t==================================================\n\n");
        printf("\t === Módulo Pacientes ===\n");
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
        system("clear");

        printf("\t==========================================\n\n");
        printf("\t === Módulo Funcionários ===\n");
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

        system("clear");
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
        printf("\tTecle ENTER para continuar.\n");
        getchar();
        


}
//Principal
int main(void)
{
    do
    { 
    system("clear");
    setlocale(LC_ALL, "Portuguese_Brazil");
    printf("\n\t==================================================\n");
    printf("\t == Selecione uma opcao ==\n");
    printf("\t == 1- Tela de Equipe\n");
    printf("\t == 2- Tela Principal\n");
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
    system("clear");
    printf("\tSaindo do programa...\n");
    return 0;
}