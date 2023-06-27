#include "ctrl_servico_testes_SQL.h"

bool CtrlServiceTestSQL::cadastrarTeste(MATRICULA matr, Testes test) {
    ComandoIncluirTeste comando(test);

    try {
        comando.executar();
        return true;
    }
    catch (EErroPersistencia erro) {
        return false;
    }
}

bool CtrlServiceTestSQL::descadastrarTeste(CODIGO code) {
    ComandoRemoverTeste comando(code);

    try{
        comando.executar();
        return true;
    }
    catch (EErroPersistencia erro) {
        return false;
    }
}

bool CtrlServiceTestSQL::editarTeste(Testes test) {
    ComandoEditarTeste comando(test);

    try{
        comando.executar();
        return true;
    }
    catch (EErroPersistencia erro) {
        return false;
    }
}

bool CtrlServiceTestSQL::visualizarTeste(CODIGO code, Testes test) {
    ComandoRecuperarTeste comando(code);

    try{
        comando.executar();
        test = comando.getResultado();
        return true;
    }
    catch (EErroPersistencia erro) {
        return false;
    }
}


bool CtrlServiceTestSQL::cadastrarCasoDeTeste(MATRICULA matr, CasoDeTeste ctest); {
    ComandoIncluirCasoDeTeste comando(ctest);

    try {
        comando.executar();
        return true;
    }
    catch (EErroPersistencia erro) {
        return false;
    }
}

bool CtrlServiceTestSQL::descadastrarCasoDeTeste(CODIGO code) {
    ComandoRemoverCasoDeTeste comando(code);

    try{
        comando.executar();
        return true;
    }
    catch (EErroPersistencia erro) {
        return false;
    }
}

bool CtrlServiceTestSQL::editarCasoDeTeste(CasoDeTeste ctest) {
    ComandoEditarCasoDeTeste comando(ctest);

    try{
        comando.executar();
        return true;
    }
    catch (EErroPersistencia erro) {
        return false;
    }
}

bool CtrlServiceTestSQL::visualizarCasoDeTeste(CODIGO code, CasoDeTeste ctest) {
    ComandoRecuperarCasoDeTeste comando(code);

    try{
        comando.executar();
        ctest = comando.getResultado();
        return true;
    }
    catch (EErroPersistencia erro) {
        return false;
    }
}
