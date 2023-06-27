#ifndef CTRL_SERVICO_TESTES_SQL_H
#define CTRL_SERVICO_TESTES_SQL_H

#include <list>
#include "../headers/ENTIDADES.h"
#include "../headers/interfaces.h"
#include "comandos.h"

using namespace std;

class CtrlServiceTestSQL : public InterServiceTest {
    public:
        bool cadastrarTeste(MATRICULA, Testes);
        bool descadastrarTeste(CODIGO);
        bool editarTeste(Testes);
        bool visualizarTeste(CODIGO, Testes);

        bool cadastrarCasoDeTeste(MATRICULA, CasoDeTeste);
        bool descadastrarCasoDeTeste(CODIGO);
        bool editarCasoDeTeste(CasoDeTeste);
        bool visualizarCasoDeTeste(CODIGO, CasoDeTeste);
};

#endif // CTRL_SERVICO_TESTES_SQL_H
