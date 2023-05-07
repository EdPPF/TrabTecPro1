
#include "./headers/DOMINIOS.h"

#include <iostream>
#include <string>
#include <cctype>
#include <regex>

using namespace std;

int main() {

//    DATA data;
//    data.setData("02/FEV/2023");
//    cout << "A data atual eh: " << data.getData() << endl;

    ////////////////////////////////

//    SENHA senha;
//    senha.setSenha("J@n123");
//    cout << "Senha colocada: " << senha.getSenha() << endl;

//    int tamanho = senha.length();
//    std::string copia = senha;
//    std::string letra;
//    for (int i = 0; i < tamanho; i++) {
//        letra = senha[i];
//        copia.erase(copia.begin());
//        if (copia.find(letra) != std::string::npos) {
//            cout << letra << " ->Duplicada: " << copia << endl;
//        }
//    }

    ////////////////////////////////

//    TEXTO texto;
//    texto.setTexto("Joaozin123");
//    cout << "Texto do texto testo: " << texto.getTexto() << endl;

    ////////////////////////////////

//    CODIGO code;
//    code.setCodigo("MnM069");
//    cout << "O codigo eh: " << code.getCodigo() << endl;

//    regex reg("[A-Za-z\\d\\.\\,\\;\\?\\!\\:\\-\\@\\#\\$\\%\\&]+"); // XXXXXX
//    string pal = "MnM0069).,;?!:-@#$%&";
//    cout << regex_search(pal, reg);

    ////////////////////////////////

//    MATRICULA fulano("1900268");
//    cout << "Testando o metodo setMatricula():\nA matricula atual eh " << fulano.getMatricula() << endl;
//    fulano.setMatricula("1234561");
//    cout << "Nova matricula:\n" << fulano.getMatricula() << endl;
//
//    MATRICULA edppf("1900268");
//    cout << "\nEste numero de matricula eh valido de acordo com o construtor: " << edppf.getMatricula() << endl;
//    cout << "Entretanto, 1900267 não eh. Veja a excessao sendo lancada:\n";
//    MATRICULA dois("1900267");

    ////////////////////////////////

//    TELEFONE tel;
//    tel.setTel("+456789abc");
//
//    string numero = "+123654abc";
//    regex obj("^\\+");
//    regex obj2("^\\+\\d+");
//    regex obj3("^\\+\\d{7,15}");
//
//    cout<<"Inicia com +: "<<regex_search(numero, obj);
//    cout<<"\nInicia com + e possui somente digitos: "<<regex_search(numero, obj2);
//    cout<<"\nInicia com + e possui de 7 a 15 chars: "<<regex_search(numero, obj3);
    std::regex regexObj("^\\+\\d{7,15}");
    string pal = "+45566128910131517";
    cout << std::regex_search(pal, regexObj) << endl;
    cout << std::regex_match(pal, regexObj);

    ////////////////////////////////

//    RESULTADO resu;
//    resu.setResult("APROVADO");
//
//    CLASSE noome;
//    noome.setNome("UNIDADE");
//
//    cout << "Nome RESULTADO: " << resu.getResult();
//    cout << "\nNome CLASSE: " << noome.getNome() << endl;

    ////////////////////////////////

//    Desenvolvedor Edu;
//    Edu.setMatrDev("1900268");
//    Edu.setTelDev("+99625049");
//
//    cout << "\nNumero de matricula do desenvolvedor Edu: " << Edu.getMatrDev();
//    cout << "\nNumero de telefone do desenvolvedor Edu: " << Edu.getTelDev() << endl;
//
//    Testes Batata;
//    Batata.setClasseTeste("FUMACA");
//
//    cout << "Tipo de teste do teste Batat: " << Batata.getClasseTeste() << endl;
//
//    CasoDeTeste Batat;
//    Batat.setCasoResult("APROVADO");
//
//    cout << "Resultado do teste Batat: " << Batat.getCasoResult() << endl;

    ////////////////////////////////

    return 0;
}
