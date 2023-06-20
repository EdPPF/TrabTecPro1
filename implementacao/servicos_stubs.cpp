#include "../headers/servicos_stubs.h"

#include <iostream>

// Serviço Autenticaçao
bool StubServiceAutentic::autenticar(MATRICULA matricula, SENHA senha){
    if(matricula.getValor() == "11111112" && senha.getValor() == "abc12&"){

        cout << endl <<"autenticar"  << endl ;
        return true;
    }
    return false;
}

// Serviço Desenvolvedor
bool StubServiceDev::cadastrar(Desenvolvedor desenvolvedor){
    cout << endl <<"cadastrar Dev"  << endl ;
    return true;
}

bool StubServiceDev::descastar(MATRICULA){
    cout << endl <<"descadastrar Dev"  << endl ;
    return true;
}

bool StubServiceDev::editar(Desenvolvedor){
    cout << endl <<"editar Dev"  << endl ;
    return true;
}


bool StubServiceDev::visualizar(Desenvolvedor desenvolvedor){
    cout << endl <<"visualizar Dev"  << endl ;
    return true;
}


//Serviço Teste

bool StubServiceTest::cadastrarTeste(MATRICULA, Testes){
    cout << endl <<"cadastrar Test"  << endl ;
    return true;
}

bool StubServiceTest::descastrarTeste(CODIGO){
    cout << endl <<"descadastrar Teste"  << endl ;
    return true;
}

bool StubServiceTest::editarTeste(Testes){
    cout << endl <<"editar Teste"  << endl ;
    return true;
}

bool StubServiceTest::visualizarTeste(CODIGO, Testes*){
    cout << endl <<"visualizar Teste"  << endl ;
    return true;
}



bool StubServiceTest::cadastrarCasoDeTeste(CODIGO, CasoDeTeste){
    cout << endl <<"cadastrar Caso de teste"  << endl ;
    return true;
}

bool StubServiceTest::descadastrarCasoDeTeste(CODIGO){
    cout << endl <<"descadastra Caso de teste"  << endl ;
    return true;
}

bool StubServiceTest::editarCasoDeTeste(CasoDeTeste){
    cout << endl <<"editar Caso de teste"  << endl ;
    return true;
}

bool StubServiceTest::visualizarCasoDeTeste(CODIGO, CasoDeTeste){
    cout << endl <<"visualizar Caso de teste"  << endl ;
    return true;
}






