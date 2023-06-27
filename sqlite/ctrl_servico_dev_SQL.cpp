#include "ctrl_servico_dev_SQL.h"

bool CtrlServiceDevSQL::cadastrar(Desenvolvedor dev) {
    ComandoIncluirUsuario comando(dev);

    try{
        comando.executar();
        return true;
    }
    catch (EErroPersistencia erro) {
        return false;
    }
}

bool CtrlServiceDevSQL::descadastrar(MATRICULA matr) {
    ComandoRemoverUsuario comando(matr);

    try{
        comando.executar();
        return true;
    }
    catch (EErroPersistencia erro) {
        return false;
    }
}

bool CtrlServiceDevSQL::editar(Desenvolvedor dev) {
    ComandoEditarUsuario comando(dev);

    try{
        comando.executar();
        return true;
    }
    catch (EErroPersistencia erro) {
        return false;
    }
}

bool CtrlServiceDevSQL::visualizar(MATRICULA matr, Desenvolvedor dev) {
    ComandoRecuperarUsuario comando(matr);

    try {
        comando.executar();
        dev = comando.getResultado();
        return true;
    }
    catch (EErroPersistencia erro) {
        return false;
    }
}
