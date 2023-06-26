#ifndef COMANDOS_H
#define COMANDOS_H

#include <list>
#include <string>

#include "../headers/ENTIDADES.h"
#include "./ComandosSQL.h"

using namespace std;

class ComandoIncluirUsuario : public ComandoSQL {
    public:
        ComandoIncluirUsuario(Desenvolvedor dev);
};

class ComandoRemoverUsuario : public ComandoSQL {
    public:
        ComandoRemoverUsuario(MATRICULA matr);
};

class ComandoEditarUsuario : public ComandoSQL {
    public:
        ComandoEditarUsuario(Desenvolvedor dev);
};

class ComandoRecuperarUsuario : public ComandoSQL {
    public:
        ComandoRecuperarUsuario(MATRICULA matr);
        Desenvolvedor getResultado();
};

#endif // COMANDOS_H
