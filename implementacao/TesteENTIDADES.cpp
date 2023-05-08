// Por: Eduardo Ferreira (190026987)

#include "../headers/TesteENTIDADES.h"

int TESTUNITent::run() {
    setUp();
    testeCenarioValido();
    tearDown();
    return estado;
}

/******************************************************************************************/

void TUDesenvolvedor::setUp() {
    dev = new Desenvolvedor();
    estado = SUCESSO;
}

void TUDesenvolvedor::tearDown() {
    delete dev;
}

void TUDesenvolvedor::testeCenarioValido() {
    MATRICULA matricula;
    matricula.setValor(MATRValida);
    dev -> setMatrDev(MATRValida);
    if(dev->getMatrDev() != MATRValida) {
        estado = FALHA;
    }

    TEXTO nome;
    nome.setValor(NOMEValido);
    dev -> setNomeDev(NOMEValido);
    if(dev->getNomeDev() != NOMEValido) {
        estado = FALHA;
    }

    SENHA senha;
    senha.setValor(SENHAValida);
    dev -> setSenhaDev(SENHAValida);
    if(dev->getSenhaDev() != SENHAValida) {
        estado = FALHA;
    }

    TELEFONE telefone;
    telefone.setValor(TELValido);
    dev -> setTelDev(TELValido);
    if(dev->getTelDev() != TELValido) {
        estado = FALHA;
    }
}

/******************************************************************************************/

void TUTestes::setUp() {
    test = new Testes();
    estado = SUCESSO;
}

void TUTestes::tearDown() {
    delete test;
}

void TUTestes::testeCenarioValido() {
    CODIGO codigo;
    codigo.setValor(CODIGOValido);
    test -> setCodigoTeste(CODIGOValido);
    if(test->getCodigoTeste() != CODIGOValido) {
        estado = FALHA;
    }

    TEXTO nome;
    nome.setValor(NOMEValido);
    test -> setTextoTeste(NOMEValido);
    if(test->getTextoTeste() != NOMEValido) {
        estado = FALHA;
    }

    CLASSE classe;
    classe.setValor(CLASSEValida);
    test -> setClasseTeste(CLASSEValida);
    if(test->getClasseTeste() != CLASSEValida) {
        estado = FALHA;
    }
}

/******************************************************************************************/

void TUCasoTeste::setUp() {
    cdtest = new CasoDeTeste();
    estado = SUCESSO;
}

void TUCasoTeste::tearDown() {
    delete cdtest;
}

void TUCasoTeste::testeCenarioValido() {
    CODIGO codigo;
    codigo.setValor(CODIGOValido);
    cdtest -> setCasoCodigo(CODIGOValido);
    if(cdtest->getCasoCodigo() != CODIGOValido) {
        estado = FALHA;
    }

    TEXTO nome;
    nome.setValor(NOMEValido);
    cdtest -> setCasoNome(NOMEValido);
    if(cdtest->getCasoNome() != NOMEValido) {
        estado = FALHA;
    }

    DATA data;
    data.setValor(DATAValida);
    cdtest -> setCasoData(DATAValida);
    if(cdtest->getCasoData() != DATAValida) {
        estado = FALHA;
    }

    TEXTO acao;
    acao.setValor(ACAOValida);
    cdtest -> setCasoAcao(ACAOValida);
    if(cdtest->getCasoAcao() != ACAOValida) {
        estado = FALHA;
    }

    TEXTO resposta;
    resposta.setValor(RESPValida);
    cdtest -> setCasoResposta(RESPValida);
    if(cdtest->getCasoResposta() != RESPValida) {
        estado = FALHA;
    }

    RESULTADO resultado;
    resultado.setValor(RESULTValido);
    cdtest -> setCasoResult(RESULTValido);
    if(cdtest->getCasoResult() != RESULTValido) {
        estado = FALHA;
    }
}
