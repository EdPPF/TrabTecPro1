#ifndef SERVICOS_STUBS_H
#define SERVICOS_STUBS_H

#include "interfaces.h"
#include "ENTIDADES.h"
#include "DOMINIOS.h"

using namespace std;

// Serviço Autenticaçao
class StubServiceAutentic: public InterServiceAutentic{
    public:
        bool autenticar(MATRICULA, SENHA);
};

// Serviço Desenvolvedor
class StubServiceDev: public InterServiceDev{
    public:
        bool cadastrar(Desenvolvedor);
        bool descadastrar(MATRICULA);
        bool editar(Desenvolvedor);
        bool visualizar(MATRICULA, Desenvolvedor);
};

//Serviço Teste
class StubServiceTest: public InterServiceTest{
    public:
        bool cadastrarTeste(MATRICULA, Testes);
        bool descadastrarTeste(CODIGO);
        bool editarTeste(Testes);
        bool visualizarTeste(CODIGO, Testes*);

        bool cadastrarCasoDeTeste(CODIGO, CasoDeTeste);
        bool descadastrarCasoDeTeste(CODIGO);
        bool editarCasoDeTeste(CasoDeTeste);
        bool visualizarCasoDeTeste(CODIGO, CasoDeTeste*);
};
#endif // SERVICOS_STUBS_H
