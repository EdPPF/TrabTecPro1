#ifndef STUBS_SERVICO_H
#define STUBS_SERVICO_H

#include "../headers/interfaces.h"
#include "../headers/ENTIDADES.h"
#include "../headers/DOMINIOS.h"

using namespace std;

class stubServicoAutenticacao: public InterServiceAutentic {
    public:
        bool autenticar(MATRICULA, SENHA);
};

class stubServicoTestes: public InterServiceTest {
    public:
        bool cadastrarTeste(MATRICULA, Testes);
        bool descadastrarTeste(MATRICULA);
        bool editarTeste(Testes);
        bool visualizarTeste(CODIGO, Testes*);

        bool cadastrarCasoDeTeste(MATRICULA, CasoDeTeste);
        bool descadastrarCasoDeTeste(MATRICULA);
        bool editarCasoDeTeste(CasoDeTeste);
        bool visualizarCasoDeTeste(CODIGO, CasoDeTeste*);
};

#endif // STUBS_SERVICO_H
