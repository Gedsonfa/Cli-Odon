#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Assinatura das funções
void tela_equi(void);
void tela_princi(void);
void tela_sobre(void);

//Variaveis de controle
int opcao_inicial;
int voltar;

//Principal
int main(void)
{
    do
    { 
    system("cls");
    setlocale(LC_ALL, "Portuguese_Brazil");
    printf("\n\t==================================================\n");
    printf("\t== Selecione uma opção ==\n");
    printf("\t1- Tela de Equipe\n");
    printf("\t2- Tela Principal\n");
    printf("\t3- Tela de Informação\n");
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
    printf("\tSaindo do programa...\n");
    return 0;
}

//Funções
void tela_sobre(void)
{  
    do
    {
        system("cls");
        printf("\n\t==================================================\n\n");
        printf("\tUniversidade Federal do Rio Grande do Norte\n");
        printf("\tCentro de Ensino Superior do Seridó\n");
        printf("\tDepartamento de Computação e Tecnologia\n");
        printf("\tBacharelado em Sistemas de Informação\n\n");
        printf("\tDisciplina DCT1106 == Programação\n");
        printf("\tProjeto Sistema SIG-Dentistry\n");
        printf("\tDeveloped by @Gedsonfa and @=== == since Ago, 2022\n\n");
        printf("\t==================================================\n\n");
        printf("\t=== Clínica Odontológica ===\n\n");
        printf("\tPrograma ultilizado para avaliação da dupla na disciplina DCT1106 == Programação,\n\tcom o objetivo de servir a uma clínica odontologica.\n");
        printf("\t==================================================\n\n");
        printf("\tInsira 0 para voltar\n");
        printf("\t=> ");
        scanf("%i", &voltar);
        break;

        return 0;
    }while(voltar != 0);
    main();
}

void tela_princi(void)
{  
    do
    {
        system("cls");
        printf("\n\t==================================================\n\n");
        printf("\tUniversidade Federal do Rio Grande do Norte\n");
        printf("\tCentro de Ensino Superior do Seridó\n");
        printf("\tDepartamento de Computação e Tecnologia\n");
        printf("\tBacharelado em Sistemas de Informação\n\n");
        printf("\tDisciplina DCT1106 == Programação\n");
        printf("\tProjeto Sistema SIG-Dentistry\n");
        printf("\tDeveloped by @Gedsonfa and @=== == since Ago, 2022\n\n");
        printf("\t==================================================\n\n");
        printf("\t === Sistema Clínica Odontológica ===\n");
        printf("\t1- Módulo Cliente\n");
        printf("\t2- Módulo Funcionario\n");
        printf("\t3- Trabalhos Realizados\n");
        printf("\t4- Sobre Nós\n");
        printf("\t0- Voltar\n");
        printf("\n\t==================================================\n\n");
        printf("\t=> ");
        scanf("%i", &voltar);
        break;

        return 0;
    }while(voltar != 0);
    main();
}

void tela_equi(void)
{
    do
    {
        system("cls");
        printf("\n\t==================================================\n\n");
        printf("\tUniversidade Federal do Rio Grande do Norte\n");
        printf("\tCentro de Ensino Superior do Seridó\n");
        printf("\tDepartamento de Computação e Tecnologia\n");
        printf("\tBacharelado em Sistemas de Informação\n\n");
        printf("\tDisciplina DCT1106 == Programação\n");
        printf("\tProjeto Sistema SIG-Dentistry\n");
        printf("\tDeveloped by @Gedsonfa and @=== == since Ago, 2022\n\n");
        printf("\t==================================================\n\n");
        printf("\t==== Sistema de Gestão de Clinica Dentaria ====\n\n");
        printf("\tEste projeto foi desenvolvido por:\n\n");
        printf("\tDisc. Gedson Fernandes\n");
        printf("\tE-mail: gedsonfda@gmail.com\n");
        printf("\tRedes sociais: @gedsonfa\n");
        printf("\tGit: https://github.com/Gedsonfa\n\n");
        printf("\tDisc. ===\n");
        printf("\tE-mail: ===@gmail.com\n");
        printf("\tRedes sociais: @===\n");
        printf("\tGit: https://github.com/===\n\n");
        printf("\t==================================================\n\n");
        printf("\tInsira 0 para voltar\n");
        printf("\t=> ");
        scanf("%i", &voltar);
        break;

        return 0;
    }while(voltar != 0);
    main();
}