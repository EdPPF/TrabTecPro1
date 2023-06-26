#include "comandos.h"

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
