#include "../headers/controladoras_apresentacao.h"
#include <iostream>
#include <conio.h> // getch();
#include <string>

// Por: Eduardo Ferreira (190026987)

using namespace std;

// *****Controladora Apresentação Inicial:
void CtrlAprInicial::setCtrlAprAutentic(InterAprAutentic *ctrl) {
    CtrlAprAutentic = ctrl;
}

void CtrlAprInicial::setCtrlAprDev(InterAprDev *ctrl) {
    CtrlAprDev = ctrl;
}

void CtrlAprInicial::setCtrlAprTest(InterAprTest *ctrl) {
    CtrlAprTest = ctrl;
}

void CtrlAprInicial::ExecutarAutenticacao() {
    while(true) {
        system("cls"); // Limppa a tela.

        cout << "+-+-Sistema de Gerenciamento de Testes-+-+" << endl;
        cout << "Matricula: " << Matricula.getValor() << endl;
        cout << "1 - Serviços de Desenvolvedor" << endl;
        cout << "2 - Serviços de Testes e Casos de Teste" << endl;
        cout << "3 - Sair" << endl;

        switch(getch()) {
        case '1':
            CtrlAprDev->executar(&Matricula);
            if (Matricula.getValor() == "") {
                return;
            }
            break;

        case '2':
            CtrlAprTest->executar(&Matricula);
            break;

        case '3':
            return;

        default:
            cout << "Opcao Invalida!" << endl;
            getch();
            break;
        }
    }
}

void CtrlAprInicial::executar() {
    bool esta_autenticado = false;

    while(true) {
        system("cls"); // Limpa a tela do terminal.

        cout << "+-+-Sistema de Gerenciamento de Testes-+-+" << endl;
        cout << "Bem vindo. O que deseja fazer?" << endl;
        cout << "=> Autenticar (Pressione 1)\n=> Cadastrar (2)\n=> Sair (3)" << endl;

        switch(getch()) {
            case '1':
                esta_autenticado = CtrlAprAutentic->autenticar(&Matricula);
                if (esta_autenticado) {
                        ExecutarAutenticacao();
                }
                break;
            case '2':
                CtrlAprDev->cadastrar();
                break;
            case '3':
                return;
            default:
                cout << "Opcao Invalida!" << endl;
                getch();
                break;
        }
    }
}
