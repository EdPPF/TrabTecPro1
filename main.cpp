#include "./headers/Eduardo/EdDOMINIOS.h"
#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
    /*
    MATRICULA fulano("1900268");
    cout << "Testando o metodo setMatricula():\nA matricula atual eh " << fulano.getMatricula() << endl;
    fulano.setMatricula("1234561");
    cout << "Nova matricula:\n" << fulano.getMatricula() << endl;

    MATRICULA edppf("1900268");
    cout << "\nEste numero de matricula eh valido de acordo com o construtor: " << edppf.getMatricula() << endl;
    cout << "Entretanto, 1900267 não eh. Veja a excessao sendo lancada:\n";
    MATRICULA dois("1900267");
    */

    ////////////////////////////////

    /*
    TELEFONE tel;
    tel.setTel("+456789abc");

    string numero = "+123654abc";
    regex obj("^\\+");
    regex obj2("^\\+\\d+");
    regex obj3("^\\+\\d{7,15}");

    cout<<"Inicia com +: "<<regex_search(numero, obj);
    cout<<"\nInicia com + e possui somente digitos: "<<regex_search(numero, obj2);
    cout<<"\nInicia com + e possui de 7 a 15 chars: "<<regex_search(numero, obj3);
    */

    ////////////////////////////////

    RESULTADO resu;
    resu.setResult("APROVADO");

    CLASSE noome;
    noome.setNome("UNIDADE");

    cout << "Nome RESULTADO: " << resu.getResult();
    cout << "\nNome CLASSE: " << noome.getNome();

    return 0;
}
