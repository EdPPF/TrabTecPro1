
#include "./headers/TesteDOMINIOS.h"
#include "./headers/TesteENTIDADES.h"

#include <iostream>
#include <string>

using namespace std;

int main() {

    TesteMATRICULA TUM;
    switch(TUM.run()) {
        case TesteMATRICULA::SUCESSO:
            cout << "\nTeste de Caso Valido da Matricula: Sucesso\n  " << endl;
            //break;
        case TesteMATRICULA::FALHA:
            cout << "Teste de Caso Invalido da Matricula: Sucesso.\nErro Esperado:\n" << TUM.mensagemExcept <<
            " -> " << TUM.MATRInvalida << "\n" << endl;
            break;
    }

    ////////////////////////////////

    TesteRESULTADO TUR;
    switch(TUR.run()) {
        case TesteRESULTADO::SUCESSO:
            cout << "\nTeste de Caso Valido do Resultado: Sucesso\n  " << endl;
            //break;
        case TesteRESULTADO::FALHA:
            cout << "Teste de Caso Invalido do Resultado: Sucesso.\nErro Esperado:\n" << TUR.mensagemExcept <<
            " -> " << TUR.RESInvalido << "\n" << endl;
            break;
    }

    ////////////////////////////////

    TesteCLASSE TUCl;
    switch(TUCl.run()) {
        case TesteCLASSE::SUCESSO:
            cout << "\nTeste de Caso Valido da Classe: Sucesso\n  " << endl;
            //break;
        case TesteRESULTADO::FALHA:
            cout << "Teste de Caso Invalido da Classe: Sucesso.\nErro Esperado:\n" << TUCl.mensagemExcept <<
            " -> " << TUCl.CLASSInvalida << "\n" << endl;
            break;
    }

    ////////////////////////////////

    TesteTELEFONE TUTel;
    switch(TUTel.run()) {
        case TesteTELEFONE::SUCESSO:
            cout << "\nTeste de Caso Valido do Telefone: Sucesso\n  " << endl;
            //break;
        case TesteTELEFONE::FALHA:
            cout << "Teste de Caso Invalido do Telefone: Sucesso.\nErro Esperado:\n" << TUTel.mensagemExcept <<
            " -> " << TUTel.TELInvalido << "\n" << endl;
            break;
    }

    ////////////////////////////////

    TesteCODIGO TUCo;
    switch(TUCo.run()) {
        case TesteCODIGO::SUCESSO:
            cout << "\nTeste de Caso Valido do Codigo: Sucesso\n  " << endl;
            //break;
        case TesteCODIGO::FALHA:
            cout << "Teste de Caso Invalido do Codigo: Sucesso.\nErro Esperado:\n" << TUCo.mensagemExcept <<
            " -> " << TUCo.CODEInvalido << "\n" << endl;
            break;
    }

    ////////////////////////////////

    TesteDATA TUD;
    switch(TUD.run()) {
        case TesteDATA::SUCESSO:
            cout << "\nTeste de Caso Valido da Data: Sucesso\n  " << endl;
            //break;
        case TesteDATA::FALHA:
            cout << "Teste de Caso Invalido da Data: Sucesso.\nErro Esperado:\n" << TUD.mensagemExcept <<
            " -> " << TUD.DATAInvalida << "\n" << endl;
            break;
    }

    ////////////////////////////////

    TesteSENHA TUS;
    switch(TUS.run()) {
        case TesteSENHA::SUCESSO:
            cout << "\nTeste de Caso Valido da Senha: Sucesso\n  " << endl;
            //break;
        case TesteTEXTO::FALHA:
            cout << "Teste de Caso Invalido da Senha: Sucesso.\nErro Esperado:\n" << TUS.mensagemExcept <<
            " -> " << TUS.SENHAInvalida << "\n" << endl;
            break;
    }

    ////////////////////////////////

    TesteTEXTO TUTex;
    switch(TUTex.run()) {
        case TesteTEXTO::SUCESSO:
            cout << "\nTeste de Caso Valido do Texto: Sucesso\n  " << endl;
            //break;
        case TesteTEXTO::FALHA:
            cout << "Teste de Caso Invalido do Texto: Sucesso.\nErro Esperado:\n" << TUTex.mensagemExcept <<
            " -> " << TUTex.TEXTOInvalido << "\n" << endl;
            break;
    }

/******************************************************************************************/

    TUDesenvolvedor TUDev;
    switch(TUDev.run()) {
        case TUDesenvolvedor::SUCESSO:
            cout << "\nTeste de Caso valido para os seguintes Atributos da classe Desenvolvedor:\n" <<
            "    Matricula\n    Nome\n    Senha\n    Telefone\n****SUCESSO****\n" << endl;
            break;
    }

    TUTestes TUTest;
    switch(TUTest.run()) {
        case TUTestes::SUCESSO:
            cout << "\nTeste de Caso valido para os seguintes Atributos da Classe Testes:\n" <<
            "    Codigo\n    Nome\n    Classe\n****SUCESSO****\n" << endl;
            break;
    }

    TUCasoTeste TUCDtest;
    switch(TUCDtest.run()) {
        case TUCasoTeste::SUCESSO:
            cout << "\nTeste de Caso valido para os seguintes Atributos da Classe CasoDeTestes:\n" <<
            "    Codigo\n    Nome\n    Data\n    Acao\n    Resposta\n    Resultado\n****SUCESSO****\n" << endl;
            break;
    }

    return 0;
}
