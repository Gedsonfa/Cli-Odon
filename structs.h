typedef struct Dados_Pagamento Dados_Pagamento;
typedef struct Dados_Servico Dados_Servico;
typedef struct Dados_Paciente Dados_Paciente;
typedef struct Dados_Funcionario Dados_Funcionario;
typedef struct Dados_Agendamento Dados_Agendamento;

struct Dados_Pagamento{
char cpf[15];
char valor[6];
char data_criacao[11];
char data_captura[11];
char meio_pagamento[30];
char banco[30];
char status;
};

struct Dados_Servico{
char codigo[6];
char nome[51];
char custo[7];
char tempo[6];
char disposto[13];
char status;
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
char status;
};

struct Dados_Agendamento{
    char cpf_paciente[15];
    char codigo_servico[6];
    char cpf_funcionario[15];
    char data[11];
    char hora[6];
    char status;
};

    
