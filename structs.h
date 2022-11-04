typedef struct Dados_Pagamento Dados_Pagamento;
typedef struct Dados_Servico Dados_Servico;
typedef struct Dados_Paciente Dados_Paciente;
typedef struct Dados_Funcionario Dados_Funcionario;


struct Dados_Pagamento{
    char id[6];
    char valor[6];
    char data_criacao[11];
    char data_captura[11];
    char meio_pagamento[30];
    char numero_cartao[17];
    char banco[30];
};

struct Dados_Servico{
char codigo[6];
char nome[51];
char custo[7];
char tempo[6];
char disposto[13];
};

struct Dados_Paciente{
char cpf[14];
char nome[51];
char idade[3];
char endereco[51];
char email[51];
char numero[12];
char status;
};

struct Dados_Funcionario{
char cpf[15];
char nome[30];
char idade[3];
char endereco[31];
char email[31];
char telefone[12];
};


    
