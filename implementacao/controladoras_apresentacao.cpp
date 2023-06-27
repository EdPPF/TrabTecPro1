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
        system("cls"); // Limpa a tela.

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


// *****Controladora Apresentação Autenticação:
void CtrlAprAutentic::setCtrlServiceAutentic(InterServiceAutentic *ctrl) {
    CtrlServiceAutentic = ctrl;
}

bool CtrlAprAutentic::autenticar(MATRICULA* Matricula) {
    string matriculaStr, senhaStr;

    while(true) {
        system("cls");

        cout << "+-+-Sistema de Gerenciamento de Testes-+-+" << endl;
        cout << "Autenticacao de Desenvolvedor " << endl;
        cout << "Digite sua Matricula: ";
        cin >> matriculaStr;
        cout << "Digite sua Senha: ";
        cin >> senhaStr;

        MATRICULA objMatricula;
        try{
            objMatricula.setValor(matriculaStr);
        }
        catch (const invalid_argument& ex) {
            cout << "Erro => " << ex.what() << endl;
        }

        SENHA objSenha;
        try{
            objSenha.setValor(senhaStr);
        }
        catch (const invalid_argument& ex) {
            cout << "Erro => " << ex.what() << endl;
        }

        bool autenticado = CtrlServiceAutentic->autenticar(objMatricula, objSenha);
        if (autenticado) {
            Matricula->setValor(matriculaStr);
            return true;
        }
        else {
            cout << "Matricula ou Senha incorretos.\nPressione qualquer tecla para continuar ou ESC para sair." << endl;
            if (getch() == 27) return false; // 27 == ESC;
        }
    }
}


// *****Controladora Apresentação Desenvolvedor:
void CtrlAprDev::setCtrlServiceDev(InterServiceDev *ctrl) {
    CtrlServiceDev = ctrl;
}

void CtrlAprDev::executar(MATRICULA* Matricula) {
    string senhaStr;
    SENHA objSenha;
    Desenvolvedor objDev;
    char escolha;

    while(true) {
        system("cls");

        cout << "+-+-Sistema de Gerenciamento de Testes-+-+" << endl;
        cout << "Desenvolvedor: " << Matricula->getValor() << endl;
        cout << "1 - Alterar Senha" << endl;
        cout << "2 - Descadastrar Usuario" << endl;
        cout << "3 - Sair" << endl;

        switch(getch()) {
            case '1':
                system("cls");
                cout << "+-+-Sistema de Gerenciamento de Testes-+-+" << endl;
                cout << "Desenvolvedor: " << Matricula->getValor() << endl;
                cout << "Digite sua nova senha: ";
                cin >> senhaStr;

                objSenha.setValor(senhaStr);  // Necessário?

                objDev.setMatrDev(Matricula->getValor());
                objDev.setSenhaDev(senhaStr);

                if (CtrlServiceDev->editar(objDev)) {
                    cout << "Senha alterada com sucesso." << endl;
                }
                else {
                    cout << "Erro ao alterar a senha." << endl;
                }
                getch();
                break;
            case '2':
                cout << "Deseja decadastrar o usuario desta conta? (s/n)" << endl;
                escolha = getch();

                if (escolha == 's' || escolha == 'S') {
                    if (CtrlServiceDev->descadastrar(*Matricula)) {
                        cout << "Usuario descadastrado com sucesso." << endl;
                        Matricula->setValor("");
                        getch();
                        return;
                    }
                    else {
                        cout << "Erro ao descadastrar usario." << endl;
                        getch();
                    }
                }
                break;
            case '3':
                return;
            default:
                cout << "Opcao invalida." << endl;
                getch();
                break;
        }
    }
}

void CtrlAprDev::cadastrar() {
    string matriculaStr, senhaStr, nomeStr, telStr;
    MATRICULA objMatricula;
    SENHA objSenha;
    TEXTO objNome;
    TELEFONE objTel;
    Desenvolvedor objDev;

    while(true) {
        system("cls");
        cout << "+-+-Sistema de Gerenciamento de Testes-+-+" << endl;
        cout << "Cadastro de Usuario" << endl;
        cout << "Digite seu Nome: ";
        cin >> nomeStr;
        cout << "Digite sua Matricula: ";
        cin >> matriculaStr;
        cout << "Digite seu Telefone: ";
        cin >> telStr;
        cout << "Digite sua Senha: ";
        cin >> senhaStr;

        objMatricula.setValor(matriculaStr); // Necessário?
        objSenha.setValor(senhaStr);         // Necessário?
        objNome.setValor(nomeStr);         // Necessário?
        objTel.setValor(telStr);         // Necessário?

        objDev.setMatrDev(matriculaStr);
        objDev.setSenhaDev(senhaStr);
        objDev.setNomeDev(nomeStr);
        objDev.setTelDev(telStr);

        if (CtrlServiceDev->cadastrar(objDev)) {
            cout << "Usuario cadastrado com sucesso." << endl;
            getch();
            return;
        }
        else {
            cout << "Erro ao cadastrar usuario." << endl;
            cout << "Pressione qualquer tecla ou ESC para sair." << endl;
            if (getch() == 27) {
                return;
            }
        }
    }
}


// *****Controladora Apresentação Testes/Casos de Teste:
void CtrlAprTest::setCtrlServiceTest(InterServiceTest *ctrl) {
    CtrlServiceTest = ctrl;
}

void CtrlAprTest::executar(CODIGO* Code) {
    char escolha;

    string classeStr;
    CLASSE objClasse;
    string textoStr;
    TEXTO objTexto;
    string nomeStr;
    TEXTO objNome;

    Testes objTeste;
    CasoDeTeste objCasoDeTeste;

    while (true) {
        system("cls");
        cout << "+-+-Sistema de Gerenciamento de Testes-+-+" << endl;
        cout << "Teste: " << Code->getValor() << endl;
        cout << "1 - Editar Classe do Teste" << endl;
        cout << "2 - Editar Texto associado ao Teste" << endl;
        cout << "3 - Descadastrar Teste" << endl;
        cout << "4 - Editar Nome do Caso de Teste" << endl;
        cout << "5 - Descadastrar Caso de Teste" << endl;
        cout << "6 - Sair" << endl;

        switch(getch()) {
            case '1':
                system("cls");
                cout << "+-+-Sistema de Gerenciamento de Testes-+-+" << endl;
                cout << "Digite a nova Classe do Teste: ";
                cin >> classeStr;

                objTeste.setClasseTeste(classeStr);

                if (CtrlServiceTest->editarTeste(objTeste)) {
                    cout << "Classe do teste alterada com sucesso." << endl;
                }
                else {
                    cout << "Erro ao alterar a classe." << endl;
                }
                getch();
                break;

            case '2':
                system("cls");
                cout << "+-+-Sistema de Gerenciamento de Testes-+-+" << endl;
                cout << "Digite o novo Texto associado ao Teste: ";
                cin >> textoStr;

                objTeste.setTextoTeste(textoStr);

                if (CtrlServiceTest->editarTeste(objTeste)) {
                    cout << "Texto associado ao Teste alterado com sucesso." << endl;
                }
                else {
                    cout << "Erro ao alterar o Texto associado ao Teste." << endl;
                }
                getch();
                break;

            case '3':
                cout << "Deseja decadastrar o teste? (s/n)" << endl;
                escolha = getch();

                if (escolha == 's' || escolha == 'S') {
                    if (CtrlServiceTest->descadastrarTeste(*Code)) {
                        cout << "Teste descadastrado com sucesso." << endl;
                        getch();
                        return;
                    }
                    else {
                        cout << "Erro ao descadastrar teste." << endl;
                        getch();
                    }
                }
                break;

            case '4':
                system("cls");
                cout << "+-+-Sistema de Gerenciamento de Testes-+-+" << endl;
                cout << "Digite o novo nome do Caso de Teste: ";
                cin >> nomeStr;

                objCasoDeTeste.setCasoNome(nomeStr);

                if (CtrlServiceTest->editarCasoDeTeste(objCasoDeTeste)) {
                    cout << "Nome do Caso de Teste alterado com sucesso." << endl;
                }
                else {
                    cout << "Erro ao alterar o nome." << endl;
                }
                getch();
                break;

            case '5':
                cout << "Deseja decadastrar o Caso de Teste? (s/n)" << endl;
                escolha = getch();

                if (escolha == 's' || escolha == 'S') {
                    if (CtrlServiceTest->descadastrarCasoDeTeste(*Matricula)) {
                        cout << "Caso de Teste descadastrado com sucesso." << endl;
                        getch();
                        return;
                    }
                    else {
                        cout << "Erro ao descadastrar Caso de Teste." << endl;
                        getch();
                    }
                }
                break;

            case '6':
                return;
            default:
                cout << "Opcao invalida." << endl;
                getch();
                break;
        }
    }
}
