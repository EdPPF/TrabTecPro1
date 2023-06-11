// Por: Eduardo Ferreira (190026987)

#include <string>
#include "DOMINIOS.h"
#include "ENTIDADES.h"

//=================================================
// Declaração de interface para serviço de autenticação provido pela camada de serviço.
class ILNAutenticacao {
public:
    virtual bool autenticar(const MATRICULA&, const SENHA&) = 0;    // Método por meio do qual é solicitado serviço.
    virtual ~ILNAutenticacao(){}                                    // Método destrutor virtual.
};

//=================================================

class InterServiceAutentic;
// Interface Apresentação Autenticação (IAA):
class InterAprAutentic {
    public:
        virtual bool autenticar(MATRICULA*) = 0;
        virtual void setCtrlServiceAutentic(InterServiceAutentic*) = 0;  // Comunicação com INterface de Serviço;
        virtual ~InterAprAutentic(){};
};

class InterServiceDev;
// Interface Apresentação Desenvolvedor (IAD):
class InterAprDev {
    public:
        virtual void cadastrar() = 0;
        virtual void executar(MATRICULA*) = 0;
        virtual void setCtrlServiceDev(InterServiceDev*) = 0;  // Comunicação com INterface de Serviço;
        virtual ~InterAprDev(){};
};

class InterServiceTest;
// Interface Apresentação Testes (IAT):
class InterAprTest {
    public:
        virtual void executar(MATRICULA*) = 0;
        virtual void setCtrlServiceTest(InterServiceTest*) = 0;  // Comunicação com INterface de Serviço;
        virtual ~InterAprTest(){};
};


// Interface Serviço Autenticação (ISA):
class InterServiceAutentic {
    public:
        virtual bool autenticar(MATRICULA, SENHA) = 0;
        virtual ~InterServiceAutentic(){};
};

// Interface Serviço Desenvolvedor (ISD):
class InterServiceDev {
    public:
        virtual bool cadastrar(Desenvolvedor) = 0;
        virtual bool descadastrar(MATRICULA) = 0;
        virtual bool editar(Desenvolvedor) = 0;
        virtual bool visualizar(MATRICULA, Desenvolvedor) = 0;
        virtual ~InterServiceDev(){};
};

// Interface Serviço Testes (IST):
class InterServiceTest {
    public:
        virtual bool cadastrarTeste(MATRICULA, Testes) = 0;
        virtual bool descadastrarTeste(CODIGO) = 0;
        virtual bool editarTeste(Testes) = 0;
        virtual bool visualizarTeste(CODIGO, Testes*) = 0;

        virtual bool cadastrarCasoDeTeste(CODIGO, CasoDeTeste) = 0;
        virtual bool descadastrarCasoDeTeste(CODIGO) = 0;
        virtual bool editarCasoDeTeste(CasoDeTeste) = 0;
        virtual bool visualizarCasoDeTeste(CODIGO, CasoDeTeste*) = 0;

        ~InterServiceTest(){};
};
