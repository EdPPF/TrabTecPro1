#include "./headers/MATRICULA.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    MATRICULA fulano("1900268");
    cout << "Testando o metodo setMatricula():\nA matricula atual eh " << fulano.getMatricula() << endl;
    fulano.setMatricula("1234561");
    cout << "Nova matricula:\n" << fulano.getMatricula() << endl;

    MATRICULA edppf("1900268");
    cout << "\nEste numero de matricula eh valido de acordo com o construtor: " << edppf.getMatricula() << endl;
    cout << "Entretanto, 1900267 não eh. Veja a excessao sendo lancada:\n";
    MATRICULA dois("1900267");

    return 0;
}
