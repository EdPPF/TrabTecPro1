#include "interfaces.h"
#include "DOMINIOS.h"

// Por: Eduardo Ferreira (190026987)

// M�dulo Apresenta��o Inicial:
class CtrlAprInicial {
    public:
        void executar();
        void setCtrlAprAutentic(InterAprAutentic*);
        void setCtrlAprDev(InterAprDev*);
        void setCtrlAprTest(InterAprTest*);

    private:
        InterAprAutentic *CtrlAprAutentic;
        InterAprDev *CtrlAprDev;
        InterAprTest *CtrlAprTest;
        MATRICULA Matricula ;
        void ExecutarAutenticacao();
};

// M�dulo Apresenta��o Autentica��o:
class CtrlAprAutentic: public InterAprAutentic {
    public:
        void setCtrlServiceAutentic(InterServiceAutentic*);
        bool autenticar(MATRICULA*);

    private:
        InterServiceAutentic *CtrlServiceAutentic;
};

// M�dulo Apresenta��o Desenvolvedor:
class CtrlAprDev: public InterAprDev {
    public:
        void executar(MATRICULA*);
        void cadastrar();
        void setCtrlServiceDev(InterServiceDev*);

    private:
        InterServiceDev *CtrlServiceDev;
};

// M�dulo Apresenta��o Testes/Casos de Teste:
class CtrlAprTest: public InterAprTest {
    public:
        void executar(CODIGO*);
        void setCtrlServiceTest(InterServiceTest*);

    private:
        InterServiceTest *CtrlServiceTest;
};
