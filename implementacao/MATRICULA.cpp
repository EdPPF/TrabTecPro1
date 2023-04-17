// Por: Eduardo Ferreira
#include "../headers/MATRICULA.h"
#include <stdexcept> // Para a exce��o de invalidez do construtor.
#include <string>


/* Fun��o auxiliar para Validar. Calcula o hash do n�mero de matr�cula.
Essa fun��o trata especificamente do formato da matr�cula especificado,
ou seja, um n�mero de 7 d�gitos, onde o d�gito verificador � o �ltimo.
*/
int MATRICULA::getHash(std::string s) {
    int Hash = 0;
    for (int i=0; i<6; i++) { // Percorre a matr�cula at� o pen�ltimo n�mero para preencher o Hash;
        Hash += (s[i] - '0'); // Transforma o caractere em inteiro e soma ao Hash;
    }
    return Hash % 10; // O Hash em si � o resultado dessa divis�o.
}

bool MATRICULA::Validar(std::string matric){
    if (matric.size() != 7) {
        throw std::invalid_argument("Matricula Invalida: Tamanho Invalido."); // A matr�cula possui um tamanho espec�fico;
    }
    int Hash = getHash(matric);
    int x = matric[6] - '0'; // Converte o �ltimo caractere em um n�mero;
    return (Hash == x); // Verifica se o �ltimo caractere � igual ao hash.
}

void MATRICULA::setMatricula(std::string matric) {
    if (!Validar(matric)) {
        throw std::invalid_argument("Matricula Invalida.");
    }
    nmrMatr = matric;
}

MATRICULA::MATRICULA(std::string matric) {
    if (Validar(matric)) {
        nmrMatr = matric;
    }
    else {
        throw std::invalid_argument("Matricula Invalida: Digito Verificador Nao Confere.");
    }
}
