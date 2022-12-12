typedef struct Dados_Pagamento Dados_Pagamento;
typedef struct Dados_Servico Dados_Servico;
typedef struct Dados_Paciente Dados_Paciente;
typedef struct Dados_Funcionario Dados_Funcionario;
typedef struct Dados_Agendamento Dados_Agendamento;
typedef struct noPac NoPac;

struct Dados_Pagamento{
char cpf[15];
char valor[30];
char data_criacao[20];
char nome_desp[20];
char meio_pagamento[30];
char banco[30];
char status;
};

struct Dados_Servico{
char codigo[11];
char nome[31];
char custo[21];
char tempo[21];
char disponi[11];
char status;
};

struct Dados_Paciente{
char cpf[15];
char nome[51];
char idade[20];
char endereco[51];
char email[51];
char numero[20];
char status;
int cod;
};

struct noPac{  //mesma de dados pacientes
char cpf[15];
char nome[51];
char idade[20];
char endereco[51];
char email[51];
char numero[20];
char status;
int cod;
NoPac* prox;
};

struct Dados_Funcionario{
char cpf[15];
char nome[51];
char idade[20];
char endereco[51];
char email[51];
char telefone[15];
char status;
};

struct Dados_Agendamento{
    char cpf[15];
    char codigo_servico[16];
    char data[20];
    char hora[20];
    char status;

};

    


void grava_paciente(Dados_Paciente* pac);

void tela_pesquisar_paciente(Dados_Paciente* pac);
void tela_alterar_paciente();
void tela_excluir_paciente();
char escAtualizarAgendamento(void);
char escAtualizarFuncionario(void);
char escAtualizarPaciente(void);
char escAtualizarPagamento(void);
char escAtualizarServico(void);

// Agendamentos
int listarAgendamentos(void);
int listarAgendamentosExc(void);
int listarAgendamentosCad(void);
char* get_nome_agendamento();
char* get_nome_full();

// Funcionários
int listarFuncionarios(void);
int listarFuncionariosExc(void);
int listarFuncionariosCad(void);

// Pacientes
void espera();
int listarPacientes(void);
int listarPacientesExc(void);
int listarPacientesCad(void);
NoPac* listaOrdenadaPac(void);
void exibeListaPac();

// Despesas
int listarDespesa(void);
int listarDespesaExc(void);
int listarDespesaCad(void);
int listarDespesaBank(void);

// Serviços
int listarServico(void);
int listarServicoExc(void);
int listarServicoCad(void);
