// Por: Eduardo Ferreira (190026987)

#include "DOMINIOS.h"

// Interface Apresenta��o Autentica��o (IAA):
class InterAprAutentic {
    public:
        virtual bool autenticar(MATRICULA *) = 0;
};

// Interface Apresenta��o Desenvolvedor (IAD):
class InterAprDev {
    public:
        virtual void cadastrar() = 0;
        virtual void executar(MATRICULA) = 0;
};

// Interface Apresenta��o Testes (IAT):
class InterAprTest {
    public:
        virtual void executar(MATRICULA) = 0;
};


// Interface Servi�o Autentica��o (ISA):
class InterServiceAutentic {
    public:
        virtual bool autenticar(MATRICULA, SENHA) = 0;
};

// Interface Servi�o Desenvolvedor (ISD):
class InterServiceDev {
    public:
        virtual bool cadastrar(Desenvolvedor) = 0;
        virtual bool visualizar(Desenvolvedor) = 0;
        virtual bool editar(Desenvolvedor) = 0;
        virtual bool descadastrar(Desenvolvedor) = 0;
};

// Interface Servi�o Testes (IST):