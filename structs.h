typedef struct Dados_Pagamento Dados_Pagamento;
typedef struct Dados_Servico Dados_Servico;
typedef struct Dados_Paciente Dados_Paciente;
typedef struct Dados_Funcionario Dados_Funcionario;
typedef struct Dados_Agendamento Dados_Agendamento;
typedef struct noPac NoPac;
typedef struct noFun NoFun;
typedef struct noPag NoPag;
typedef struct noSer NoSer;
typedef struct noAge NoAge;

//===========================================================================

struct Dados_Pagamento{
char cpf[15];
char valor[30];
char data_criacao[20];
char nome_desp[20];
char meio_pagamento[30];
char banco[30];
char status;
int cod;
};

struct noPag{
char cpf[15];
char valor[30];
char data_criacao[20];
char nome_desp[20];
char meio_pagamento[30];
char banco[30];
char status;
int cod;
NoPag* prox;
};

//===========================================================================

struct Dados_Servico{
char codigo[11];
char nome[31];
char custo[21];
char tempo[21];
char disponi[11];
char status;
int cod;
};

struct noSer{
char codigo[11];
char nome[31];
char custo[21];
char tempo[21];
char disponi[11];
char status;
int cod;
NoSer* prox;
};

//===========================================================================

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

//===========================================================================

struct Dados_Funcionario{
char cpf[15];
char nome[51];
char idade[20];
char endereco[51];
char email[51];
char telefone[15];
char status;
int cod;
};

struct noFun{
char cpf[15];
char nome[51];
char idade[20];
char endereco[51];
char email[51];
char telefone[15];
char status;
int cod;
NoFun* prox;
};

//===========================================================================

struct Dados_Agendamento{
    char cpf[15];
    char nome_ser[15];
    char codigo_agen[16];
    char codigo_ser[16];
    char data[20];
    char hora[20];
    char status;
    int cod;

};

struct noAge{
    char cpf[15];
    char codigo_servico[16];
    char data[20];
    char hora[20];
    char status;
    int cod;
    NoAge* prox;

};

    
//===========================================================================

void grava_paciente(Dados_Paciente* pac);

void tela_pesquisar_paciente(Dados_Paciente* pac);
void tela_alterar_paciente();
void tela_excluir_paciente();
char escAtualizarAgendamento(void);
char escAtualizarFuncionario(void);
char escAtualizarPaciente(void);
char escAtualizarPagamento(void);
char escAtualizarServico(void);

//===========================================================================

// Agendamentos
int listarAgendamentos(void);
int listarAgendamentosExc(void);
int listarAgendamentosCad(void);
char* get_nome_agendamento();
char* get_nome_full();
NoAge* listaOrdenadaAge(void);
void exibeListaAge();
int valida_age(char* linha);

//===========================================================================

// Funcionários
int listarFuncionarios(void);
int listarFuncionariosExc(void);
int listarFuncionariosCad(void);
NoFun* listaOrdenadaFun(void);
void exibeListaFun();
int valida_fun(char* linha);

//===========================================================================

// Pacientes
int listarPacientes(void);
int listarPacientesExc(void);
int listarPacientesCad(void);
NoPac* listaOrdenadaPac(void);
void exibeListaPac();
int valida_pac(char* linha);

//===========================================================================

// Despesas
int listarDespesa(void);
int listarDespesaExc(void);
int listarDespesaCad(void);
int listarDespesaBank(void);
NoPag* listaOrdenadaDes(void);
void exibeListaDes();
int valida_des(char* linha);

//===========================================================================

// Serviços
int listarServico(void);
int listarServicoExc(void);
int listarServicoCad(void);
NoSer* listaOrdenadaSer(void);
void exibeListaSer();
int valida_ser(char* linha);
char* get_nome_servico();
char* get_ser_full();

//===========================================================================

// Funções pacientes
void tela_pesquisar_paciente(Dados_Paciente *pac);
void grava_paciente(Dados_Paciente *pac);
Dados_Paciente *tela_cadastrar_paciente();
Dados_Paciente* buscaPaciente();
void tela_alterar_paciente();
void tela_excluir_paciente();
void exibe_pacientes();

//===========================================================================

// Funções Funcionarios
void tela_pesquisar_funcionario(Dados_Funcionario *fun);
Dados_Funcionario *tela_cadastrar_funcionario();
void grava_funcionario(Dados_Funcionario *fun);
Dados_Funcionario *buscar_funcionario();
void tela_alterar_funcionario();
void tela_excluir_funcionario();
void exibe_funcionarios();

//===========================================================================

// Funções Serviço
void tela_pesquisar_servico(Dados_Servico *ser);
Dados_Servico *tela_cadastrar_servico();
void grava_servico(Dados_Servico *ser);
Dados_Servico *buscar_servico();
void tela_alterar_servico();
void tela_excluir_servico();
void exibe_servicos();

//===========================================================================

// Funções Pagamentos
void tela_pesquisar_pagamento(Dados_Pagamento *pag);
Dados_Pagamento *tela_cadastrar_pagamento();
void grava_pagamento(Dados_Pagamento *pag);
Dados_Pagamento *buscar_pagamento();
void tela_alterar_pagamento();
void tela_excluir_pagamento();
void exibe_pagamento();

//===========================================================================

// Funções Agendamentos
void tela_pesquisar_agendamento(Dados_Agendamento* age);
Dados_Agendamento* tela_cadastrar_agendamento(void);
void grava_agendamento(Dados_Agendamento *age);
Dados_Agendamento* buscar_agendamento();
void tela_alterar_agendamento();
void tela_excluir_agendamento();
void exibe_agendamento();

//===========================================================================

// Funções Relatórios
void relatorio_agendamentos();
void relatorio_funcionario();
void relatorio_paciente();
void relatorio_servicos();
void relatorio_despesas();

//===========================================================================

// Funções telas
void tela_funcionarios();
void tela_pagamento();
void tela_pacientes();
void tela_servicos();
void tela_relatorios(void);
void tela_agend();
void sobre(void);
