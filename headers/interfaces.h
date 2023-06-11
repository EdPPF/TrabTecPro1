// Por: Eduardo Ferreira (190026987)

#include <string>
#include "DOMINIOS.h"
#include "ENTIDADES.h"

//=================================================
// Declara��o de interface para servi�o de autentica��o provido pela camada de servi�o.
class ILNAutenticacao {
public:
    virtual bool autenticar(const MATRICULA&, const SENHA&) = 0;    // M�todo por meio do qual � solicitado servi�o.
    virtual ~ILNAutenticacao(){}                                    // M�todo destrutor virtual.
};

//=================================================

class InterServiceAutentic;
// Interface Apresenta��o Autentica��o (IAA):
class InterAprAutentic {
    public:
        virtual bool autenticar(MATRICULA*) = 0;
        virtual void setCtrlServiceAutentic(InterServiceAutentic*) = 0;  // Comunica��o com INterface de Servi�o;
        virtual ~InterAprAutentic(){};
};

class InterServiceDev;
// Interface Apresenta��o Desenvolvedor (IAD):
class InterAprDev {
    public:
        virtual void cadastrar() = 0;
        virtual void executar(MATRICULA*) = 0;
        virtual void setCtrlServiceDev(InterServiceDev*) = 0;  // Comunica��o com INterface de Servi�o;
        virtual ~InterAprDev(){};
};

class InterServiceTest;
// Interface Apresenta��o Testes (IAT):
class InterAprTest {
    public:
        virtual void executar(MATRICULA*) = 0;
        virtual void setCtrlServiceTest(InterServiceTest*) = 0;  // Comunica��o com INterface de Servi�o;
        virtual ~InterAprTest(){};
};


// Interface Servi�o Autentica��o (ISA):
class InterServiceAutentic {
    public:
        virtual bool autenticar(MATRICULA, SENHA) = 0;
        virtual ~InterServiceAutentic(){};
};

// Interface Servi�o Desenvolvedor (ISD):
class InterServiceDev {
    public:
        virtual bool cadastrar(Desenvolvedor) = 0;
        virtual bool descadastrar(MATRICULA) = 0;
        virtual bool editar(Desenvolvedor) = 0;
        virtual bool visualizar(MATRICULA, Desenvolvedor) = 0;
        virtual ~InterServiceDev(){};
};

// Interface Servi�o Testes (IST):
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
