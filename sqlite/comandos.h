#ifndef COMANDOS_H
#define COMANDOS_H

#include <list>
#include <string>

#include "../headers/ENTIDADES.h"
#include "./ComandosSQL.h"

using namespace std;

// Desenvolvedor:
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

// Testes:
class ComandoIncluirTeste : public ComandoSQL {
    public:
        ComandoIncluirTeste(Testes test);
};

class ComandoRemoverTeste : public ComandoSQL {
    public:
        ComandoRemoverTeste(CODIGO code);
};

class ComandoEditarTeste: public ComandoSQL {
    public:
        ComandoEditarTeste(Testes test);
};

class ComandoRecuperarTeste : public ComandoSQL {
    public:
        ComandoRecuperarTeste(CODIGO code);
        Testes getResultado();
};

class ComandoIncluirCasoDeTeste : public ComandoSQL {
    public:
        ComandoIncluirCasoDeTeste(CasoDeTeste ctest);
};

class ComandoRemoverCasoDeTeste : public ComandoSQL {
    public:
        ComandoRemoverCasoDeTeste(CODIGO code);
};

class ComandoEditarCasoDeTeste: public ComandoSQL {
    public:
        ComandoEditarCasoDeTeste(CasoDeTeste ctest);
};

class ComandoRecuperarCasoDeTeste : public ComandoSQL {
    public:
        ComandoRecuperarCasoDeTeste(CODIGO code);
        CasoDeTeste getResultado();
};


#endif // COMANDOS_H
