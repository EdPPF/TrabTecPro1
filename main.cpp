
#include "headers/interfaces.h"
#include "headers/controladoras_apresentacao.h"
#include "stubs/stubs_servico.h"

#include "sqlite/ctrl_servico_dev_SQL.h"

#include <iostream>
#include <string>

using namespace std;

int main() {

    CtrlAprInicial ctrlAprInit;

    // Inicialização:
    InterAprAutentic *ctrlAprAutentic;
    InterAprDev *ctrlAprDev;
    InterAprTest *ctrlAprTest;

    ctrlAprAutentic = new CtrlAprAutentic();
    ctrlAprDev = new CtrlAprDev();
    ctrlAprTest = new CtrlAprTest();

    ctrlAprInit.setCtrlAprAutentic(ctrlAprAutentic);
    ctrlAprInit.setCtrlAprDev(ctrlAprDev);
    ctrlAprInit.setCtrlAprTest(ctrlAprTest);

    // Serviço:
    InterServiceAutentic *StubServiceAutentic;
    InterServiceTest *StubServiceTest;
    InterServiceDev *ctrlServiceDev;

    StubServiceAutentic = new stubServicoAutenticacao();
    StubServiceTest = new stubServicoTestes();
    ctrlServiceDev = new CtrlServiceDevSQL();

    ctrlAprAutentic->setCtrlServiceAutentic(StubServiceAutentic);
    ctrlAprTest->setCtrlServiceTest(StubServiceTest);
    ctrlAprDev->setCtrlServiceDev(ctrlServiceDev);

    ctrlAprInit.executar();

    delete ctrlAprAutentic;
    delete ctrlAprDev;
    delete ctrlAprTest;
    delete StubServiceAutentic;
    delete StubServiceTest;

    return 0;
}
