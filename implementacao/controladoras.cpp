#include "../headers/controladoras.h"
#include <iostream>

// Por: Eduardo Ferreira (190026987)

using namespace std;
bool CtrlAprAutentic::autenticar(MATRICULA *matricula) {
    SENHA senha;
    std::string entrada;

    while (true) {
        cout << endl << "-+-+-+Autenticação de Usuário+-+-+-" << endl;

        try {
            cout << "Digite a matrícula: ";
            cin >> entrada;
            matricula->setValor(entrada);

            cout << "Digite a senha: ";
            cin >> entrada;
            senha.setValor(entrada);
            break;
        }
        catch (const invalid_argument &exp) {
            cout << endl << "Dado em formato incorreto." << endl;
        }
    }

    bool resultado = CtrlLNAutentic->autenticar(*matricula, senha);

    return resultado;
}
