// Por: Eduardo Ferreira
#include "../headers/MATRICULA.h"
#include <stdexcept> // Para a exceção de invalidez do construtor.
#include <string>


/* Função auxiliar para Validar. Calcula o hash do número de matrícula.
Essa função trata especificamente do formato da matrícula especificado,
ou seja, um número de 7 dígitos, onde o dígito verificador é o último.
*/
int MATRICULA::getHash(std::string s) {
    int Hash = 0;
    for (int i=0; i<6; i++) { // Percorre a matrícula até o penúltimo número para preencher o Hash;
        Hash += (s[i] - '0'); // Transforma o caractere em inteiro e soma ao Hash;
    }
    return Hash % 10; // O Hash em si é o resultado dessa divisão.
}

bool MATRICULA::Validar(std::string matric){
    if (matric.size() != 7) {
        throw std::invalid_argument("Matricula Invalida: Tamanho Invalido."); // A matrícula possui um tamanho específico;
    }
    int Hash = getHash(matric);
    int x = matric[6] - '0'; // Converte o último caractere em um número;
    return (Hash == x); // Verifica se o último caractere é igual ao hash.
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
