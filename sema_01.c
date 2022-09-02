#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Assinatura das funcoes
void tela_equi();
void tela_princi();
void tela_sobre();

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
        printf("\tInsira 0 para voltar\n");
        printf("\t=> ");

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
        printf("\t1- Modulo Cliente\n");
        printf("\t2- Modulo Funcionario\n");
        printf("\t3- Trabalhos Realizados\n");
        printf("\t4- Sobre Nos\n");
        printf("\t0- Voltar\n");
        printf("\n\t==================================================\n\n");
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
        printf("\tInsira 0 para voltar\n");
        printf("\t=> ");
        


}
//Principal
int main(void)
{
    do
    { 
    system("clear");
    setlocale(LC_ALL, "Portuguese_Brazil");
    printf("\n\t==================================================\n");
    printf("\t== Selecione uma opcao ==\n");
    printf("\t1- Tela de Equipe\n");
    printf("\t2- Tela Principal\n");
    printf("\t3- Tela de Informacao\n");
    printf("\t0- Sair\n");
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
