#include "stubs_servico.h"

// Stub Serviço de Autenticação
bool stubServicoAutenticacao::autenticar(MATRICULA Matr, SENHA Senha) {
    if (Matr.getValor() == "1900268" && Senha.getValor() == "abc123") {
        return true;
    }
    return false;
}

// Stub Serviço de Testes
bool stubServicoTestes::cadastrarTeste(MATRICULA Matr, Testes Test) {
    return true;
}

bool stubServicoTestes::descadastrarTeste(MATRICULA Matr){
    return true;
}

bool stubServicoTestes::editarTeste(Testes Test){
    return true;
}

bool stubServicoTestes::visualizarTeste(CODIGO Code, Testes* Test){
    if (Code.getValor() != "INTEGRACAO") {
        return false;
    }

    Test->setClasseTeste("INTEGRACAO");
    Test->setCodigoTeste("DnD321");
    Test->setTextoTeste("Texto do teste.");

    return true;
}

bool stubServicoTestes::cadastrarCasoDeTeste(MATRICULA Matr, CasoDeTeste Ctest){
    return true;
}

bool stubServicoTestes::descadastrarCasoDeTeste(MATRICULA Matr){
    return true;
}

bool stubServicoTestes::editarCasoDeTeste(CasoDeTeste Ctest){
    return true;
}

bool stubServicoTestes::visualizarCasoDeTeste(CODIGO Code, CasoDeTeste* Ctest) {
    if (Code.getValor() != "ABC123") {
        return false;
    }

    Ctest->setCasoAcao("Acao do Caso de Teste.");
    Ctest->setCasoCodigo("ABC123");
    Ctest->setCasoData("19/JUN/2023");
    Ctest->setCasoNome("Nome do Caso.");
    Ctest->setCasoResposta("Resposta do Caso.");
    Ctest->setCasoResult("APROVADO");

    return true;
}
