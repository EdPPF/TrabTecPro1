#include "comandos.h"

// Desenvolvedor:
ComandoIncluirUsuario::ComandoIncluirUsuario(Desenvolvedor dev) {
    comandoSQL = "INSERT INTO DESENVOLVEDOR (matricula, nome, senha, telefone) VALUES ('";
    comandoSQL += dev.getMatrDev();
    comandoSQL += "', '";
    comandoSQL += dev.getNomeDev();
    comandoSQL += "', '";
    comandoSQL += dev.getSenhaDev();
    comandoSQL += "', '";
    comandoSQL += dev.getTelDev();
    comandoSQL += "');";
}

ComandoRemoverUsuario::ComandoRemoverUsuario(MATRICULA matr) {
    comandoSQL = "DELETE FROM DESENVOLVEDOR WHERE matricula = '";
    comandoSQL += matr.getValor();
    comandoSQL += "';";
}

ComandoEditarUsuario::ComandoEditarUsuario(Desenvolvedor dev) {
    comandoSQL = "UPDATE DESENVOLVEDOR SET nome = '";
    comandoSQL += dev.getNomeDev();
    comandoSQL += "', senha = '";
    comandoSQL += dev.getSenhaDev();
    comandoSQL += "', telefone = '";
    comandoSQL += dev.getTelDev();
    comandoSQL += "' WHERE matricula = '";
    comandoSQL += dev.getMatrDev();
    comandoSQL += "';";
}

ComandoRecuperarUsuario::ComandoRecuperarUsuario(MATRICULA matr) {
    comandoSQL = "SELECT * FROM DESENVOLVEDOR WHERE matricula = '";
    comandoSQL += matr.getValor();
    comandoSQL += "';";
}

Desenvolvedor ComandoRecuperarUsuario::getResultado() {
    Desenvolvedor dev;
    ElementoResultado elemento;

    // Matricula
    if (listaResultado.empty()) {
        throw EErroPersistencia("Lista de resultados vazia");
    }
    elemento = listaResultado.back();
    listaResultado.pop_back();

    dev.setMatrDev(elemento.getValorColuna());

    // Nome
    if (listaResultado.empty()) {
        throw EErroPersistencia("Lista de resultados vazia");
    }
    elemento = listaResultado.back();
    listaResultado.pop_back();

    dev.setNomeDev(elemento.getValorColuna());

    // Senha
    if (listaResultado.empty()) {
        throw EErroPersistencia("Lista de resultados vazia");
    }
    elemento = listaResultado.back();
    listaResultado.pop_back();

    dev.setSenhaDev(elemento.getValorColuna());

    // Telefone
    if (listaResultado.empty()) {
        throw EErroPersistencia("Lista de resultados vazia");
    }
    elemento = listaResultado.back();
    listaResultado.pop_back();

    dev.setTelDev(elemento.getValorColuna());

    return dev;
}

// Testes:
ComandoIncluirTeste::ComandoIncluirTeste(Testes test) {
    comandoSQL = "INSERT INTO TESTES (codigo, nome, classe) VALUES ('";
    comandoSQL += test.getCodigoTeste();
    comandoSQL += "', '";
    comandoSQL += test.getTextoTeste();
    comandoSQL += "', '";
    comandoSQL += test.getClasseTeste();
    comandoSQL += "');";
}

ComandoRemoverTeste::ComandoRemoverTeste(CODIGO code) {
    comandoSQL = "DELETE FROM TESTES WHERE codigo = '";
    comandoSQL += code.getValor();
    comandoSQL += "';";
}

ComandoEditarTeste::ComandoEditarTeste(Testes test) {
    comandoSQL = "UPDATE TESTES SET nome = '";
    comandoSQL += test.getTextoTeste();
    comandoSQL += "', classe = '";
    comandoSQL += test.getClasseTeste();
    comandoSQL += "' WHERE codigo = '";
    comandoSQL += test.getCodigoTeste();
    comandoSQL += "';";
}

ComandoRecuperarTeste::ComandoRecuperarTeste(CODIGO code) {
    comandoSQL = "SELECT * FROM TESTES WHERE codigo = '";
    comandoSQL += code.getValor();
    comandoSQL += "';";
}

Testes ComandoRecuperarTeste::getResultado() {
    Testes test;
    ElementoResultado elemento;

    // Codigo
    if (listaResultado.empty()) {
        throw EErroPersistencia("Lista de resultados vazia");
    }
    elemento = listaResultado.back();
    listaResultado.pop_back();

    test.setCodigoTeste(elemento.getValorColuna());

    // Nome
    if (listaResultado.empty()) {
        throw EErroPersistencia("Lista de resultados vazia");
    }
    elemento = listaResultado.back();
    listaResultado.pop_back();

    test.setTextoTeste(elemento.getValorColuna());

    // Classe
    if (listaResultado.empty()) {
        throw EErroPersistencia("Lista de resultados vazia");
    }
    elemento = listaResultado.back();
    listaResultado.pop_back();

    test.setClasseTeste(elemento.getValorColuna());

    return test;
}

// Casos de Teste:
ComandoIncluirCasoDeTeste::ComandoIncluirCasoDeTeste(CasoDeTeste ctest) {
    comandoSQL = "INSERT INTO CASO-DE-TESTE (codigo, nome, data, acao, resposta, resultado) VALUES ('";
    comandoSQL += ctest.getCasoCodigo();
    comandoSQL += "', '";
    comandoSQL += ctest.getCasoNome();
    comandoSQL += "', '";
    comandoSQL += ctest.getCasoData();
    comandoSQL += "', '";
    comandoSQL += ctest.getCasoAcao();
    comandoSQL += "', '";
    comandoSQL += ctest.getCasoResposta();
    comandoSQL += "', '";
    comandoSQL += ctest.getCasoResult();
    comandoSQL += "');";
}

ComandoRemoverCasoDeTeste::ComandoRemoverCasoDeTeste(CODIGO code) {
    comandoSQL = "DELETE FROM CASO-DE-TESTE WHERE codigo = '";
    comandoSQL += code.getValor();
    comandoSQL += "';";
}

ComandoEditarCasoDeTeste::ComandoEditarCasoDeTeste(CasoDeTeste ctest) {
    comandoSQL = "UPDATE CASO-DE-TESTE SET nome = '";
    comandoSQL += ctest.getCasoNome();
    comandoSQL += "', data = '";
    comandoSQL += ctest.getCasoData();
    comandoSQL += "', acao = '";
    comandoSQL += ctest.getCasoAcao();
    comandoSQL += "', resposta = '";
    comandoSQL += ctest.getCasoResposta();
    comandoSQL += "', resultado = '";
    comandoSQL += ctest.getCasoResult();
    comandoSQL += "' WHERE codigo = '";
    comandoSQL += ctest.getCasoCodigo();
    comandoSQL += "';";
}

ComandoRecuperarCasoDeTeste::ComandoRecuperarCasoDeTeste(CODIGO code) {
    comandoSQL = "SELECT * FROM CASO-DE-TESTE WHERE codigo = '";
    comandoSQL += code.getValor();
    comandoSQL += "';";
}

CasoDeTeste ComandoRecuperarCasoDeTeste::getResultado() {
    CasoDeTeste ctest;
    ElementoResultado elemento;

    // Codigo
    if (listaResultado.empty()) {
        throw EErroPersistencia("Lista de resultados vazia");
    }
    elemento = listaResultado.back();
    listaResultado.pop_back();

    ctest.setCasoCodigo(elemento.getValorColuna());

    // Nome
    if (listaResultado.empty()) {
        throw EErroPersistencia("Lista de resultados vazia");
    }
    elemento = listaResultado.back();
    listaResultado.pop_back();

    ctest.setCasoNome(elemento.getValorColuna());

    // Data
    if (listaResultado.empty()) {
        throw EErroPersistencia("Lista de resultados vazia");
    }
    elemento = listaResultado.back();
    listaResultado.pop_back();

    ctest.setCasoData(elemento.getValorColuna());

    // Ação
    if (listaResultado.empty()) {
        throw EErroPersistencia("Lista de resultados vazia");
    }
    elemento = listaResultado.back();
    listaResultado.pop_back();

    ctest.setCasoAcao(elemento.getValorColuna());

    // Resposta
    if (listaResultado.empty()) {
        throw EErroPersistencia("Lista de resultados vazia");
    }
    elemento = listaResultado.back();
    listaResultado.pop_back();

    ctest.setCasoResposta(elemento.getValorColuna());

    // Resultado
    if (listaResultado.empty()) {
        throw EErroPersistencia("Lista de resultados vazia");
    }
    elemento = listaResultado.back();
    listaResultado.pop_back();

    ctest.setCasoResult(elemento.getValorColuna());

    return ctest;
}
