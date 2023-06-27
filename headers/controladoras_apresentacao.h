#include "interfaces.h"
#include "DOMINIOS.h"

// Por: Eduardo Ferreira (190026987)

// Módulo Apresentação Inicial:
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

// Módulo Apresentação Autenticação:
class CtrlAprAutentic: public InterAprAutentic {
    public:
        void setCtrlServiceAutentic(InterServiceAutentic*);
        bool autenticar(MATRICULA*);

    private:
        InterServiceAutentic *CtrlServiceAutentic;
};

// Módulo Apresentação Desenvolvedor:
class CtrlAprDev: public InterAprDev {
    public:
        void executar(MATRICULA*);
        void cadastrar();
        void setCtrlServiceDev(InterServiceDev*);

    private:
        InterServiceDev *CtrlServiceDev;
};

// Módulo Apresentação Testes/Casos de Teste:
class CtrlAprTest: public InterAprTest {
    public:
        void executar(CODIGO*);
        void setCtrlServiceTest(InterServiceTest*);

    private:
        InterServiceTest *CtrlServiceTest;
};
