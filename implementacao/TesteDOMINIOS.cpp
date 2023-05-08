// Por: Eduardo Ferreira (190026987)

#include "../headers/TesteDOMINIOS.h"

void TESTUNITdom::setUp() {
    valorValido = setValorValido();
    valorInvalido = setValorInvalido();
    dominio = criaDominio();
    estado = SUCESSO;
}

int TESTUNITdom::run() {
    setUp();
    testeCenarioValido();
    testeCenarioInvalido();
    tearDown();
    return estado;
}

void TESTUNITdom::testeCenarioValido() {
    //dominio = criaDominio();
    try{
        dominio->setValor(valorValido);
        if (dominio->getValor() != valorValido) {
            estado = FALHA;
        }
    } catch (std::invalid_argument &excecao) {
        estado = FALHA;
    }
}

void TESTUNITdom::testeCenarioInvalido() {
    try {
        dominio->setValor(valorInvalido);
        estado = FALHA;
    } catch (std::invalid_argument &excecao) {
        mensagemExcept = excecao.what();
        return;
    }
}
