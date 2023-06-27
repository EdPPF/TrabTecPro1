
#ifndef CTRL_SERVICO_DEV_SQL_H
#define CTRL_SERVICO_DEV_SQL_H

#include <list>
#include "../headers/ENTIDADES.h"
#include "../headers/interfaces.h"
#include "comandos.h"

using namespace std;

class CtrlServiceDevSQL : public InterServiceDev {
    public:
        bool cadastrar(Desenvolvedor);
        bool descadastrar(MATRICULA);
        bool editar(Desenvolvedor);
        bool visualizar(MATRICULA, Desenvolvedor);
};

#endif // CTRL_SERVICO_DEV_SQL_H
