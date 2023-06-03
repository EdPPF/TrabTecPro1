// Por: Eduardo Ferreira (190026987)

#include "DOMINIOS.h"

// Interface Apresentação Autenticação (IAA):
class InterAprAutentic {
    public:
        virtual bool autenticar(MATRICULA *) = 0;
};

// Interface Apresentação Desenvolvedor (IAD):
class InterAprDev {
    public:
        virtual void cadastrar() = 0;
        virtual void executar(MATRICULA) = 0;
};

// Interface Apresentação Testes (IAT):
class InterAprTest {
    public:
        virtual void executar(MATRICULA) = 0;
};


// Interface Serviço Autenticação (ISA):
class InterServiceAutentic {
    public:
        virtual bool autenticar(MATRICULA, SENHA) = 0;
};

// Interface Serviço Desenvolvedor (ISD):
class InterServiceDev {
    public:
        virtual bool cadastrar(Desenvolvedor) = 0;
        virtual bool visualizar(Desenvolvedor) = 0;
        virtual bool editar(Desenvolvedor) = 0;
        virtual bool descadastrar(Desenvolvedor) = 0;
};

// Interface Serviço Testes (IST):
