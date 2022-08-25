#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Assinatura das funções
void tela_equi(void);
void tela_princi(void);
void tela_sobre(void);

//Variaveis de controle
int op;
int cont;

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
    scanf("%i", &op);
    switch (op)
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
    }while (op != 0);
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
        scanf("%i", &cont);
        break;

        return 0;
    }while(cont != 0);
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
        printf("\tInsira 0 para voltar\n");
        printf("\t=> ");
        scanf("%i", &cont);
        break;

        return 0;
    }while(cont != 0);
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
        scanf("%i", &cont);
        break;

        return 0;
    }while(cont != 0);
    main();
}