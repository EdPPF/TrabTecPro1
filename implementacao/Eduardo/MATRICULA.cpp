// Por: Eduardo Ferreira
#include "../../headers/Eduardo/MATRICULA.h"
#include <stdexcept> // Para a exce��o de invalidez do construtor.
#include <string>
#include <regex> // Para manipula��o de strings.


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

void MATRICULA::Validar(std::string matric){
    if (matric.size() != 7) {
        throw std::invalid_argument("Matricula Invalida: Tamanho Invalido."); // A matr�cula possui um tamanho espec�fico;
    }
    int Hash = getHash(matric);
    int x = matric[6] - '0'; // Converte o �ltimo caractere em um n�mero;
    //return (Hash == x); // Verifica se o �ltimo caractere � igual ao hash.
    if (Hash != x) {
        throw std::invalid_argument("Matricula Invalida: Digito Verificador Invalido.");
    }
    /*
        MUDAN�A: Esse m�todo agora � void. N�o h� necessidade de reetornar um valor,
            j� que agora ele possui exce��es para caso de erro.
    */
}

void MATRICULA::setMatricula(std::string matric) {
    Validar(matric);
    /*
    if (!Validar(matric)) {
        throw std::invalid_argument("Matricula Invalida.");
    }
        MUDAN�A: se Validar lan�ar excess�o, a linha abaixo n�o sr� executada.
            Dessa forma, n�o h� necessidade de usar um "if"
    */
    nmrMatr = matric;
}

MATRICULA::MATRICULA(std::string matric) {
    /*
    if (Validar(matric)) {
        nmrMatr = matric;
    }
    else {
        throw std::invalid_argument("Matricula Invalida: Digito Verificador Nao Confere.");
    }
        MUDAN�A: Agora que Validar � void, n�o h� porque lan�ar exce��o aqui.
    */
    Validar(matric);
    nmrMatr = matric;
}


/******************************************************************************************/

void RESULTADO::Validar(std::string resultado) {
    if (resultado != "APROVADO" && resultado != "REPROVADO") {
        throw std::invalid_argument("Resultado Invalido.");
    }
}

void RESULTADO::setResult(std::string resultado) {
    Validar(resultado);
    // Se o m�todo acima n�o lancar exce��o, a linha abaixo ser� processada.
    this -> resultado = resultado;
}

/******************************************************************************************/

// Fun��o gen�rica que retorna True caso um item esteja numa lista:
/*Essa fun��o recebe o elemento alvo, a lista (supondo ambos strings) e o tamanho dela,
    percorre cada item da lista e os compara com o elemento, adicionando 1 � vari�vel
    auxiliar se elemento for igual ao item da lista. Caso a vari�vel soma seja diferente
    de 1 ao final do processo, o item n�o foi encontrado na lista (ou algo estranho aconteceu)
    e a fun��o retorna false. Caso soma == 1, retorna true.
*/
bool CLASSE::contem(std::string elemento, std::string lista[], int tamanho) {
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        if (elemento == lista[i]) {soma += 1;}
    }
    if (soma != 1) {return false;}
    return true;
}

void CLASSE::Validar(std::string tipo) {
    std::string listaNomes [6] = {"UNIDADE", "INTEGRACAO", "FUMACA", "SISTEMA", "REGRESSAO", "ACEITACAO"};
    if (!contem(tipo, listaNomes, 6)) {
        throw std::invalid_argument("Nome Invalido.");
    }
}

void CLASSE::setNome(std::string nome) {
    Validar(nome);
    this -> nome = nome;
}


/******************************************************************************************/

bool TELEFONE::comecaComMais(std::string numeroTel) {
    // Verifica se a string inicia com o d�gito "+".
    std::regex regexObj("^\\+");
    return std::regex_search(numeroTel, regexObj);
}

bool TELEFONE::digitoNumerico(std::string numeroTel) {
    // Verifica se a string iniciada por "+" possui apenas d�gitos num�ricos.
    std::regex regexObj("^\\+\\d+");
    return std::regex_search(numeroTel, regexObj);
}

bool TELEFONE::tamanhoTelefone(std::string numeroTel) {
    // Verifica se o tamanho da string iniciada por + est� correto.
    std::regex regexObj("^\\+\\d{7,15}");
    return std::regex_search(numeroTel, regexObj);
}

void TELEFONE::Validar(std::string numeroTel) {
    /*
        Aqui, a ordem das chamadas � importante: Primeiro � verificado se
           o numero inic�a com +. Se isso for satisfeito, � verificado se
           ele possui apenas n�meros. E se isso for satisfeito, � verificado
           se o tamanho est� correto.
    */
    if (!comecaComMais(numeroTel)) {
        throw std::invalid_argument("Numero de Telefone Invalido: Nao incia com +");
    }
    if (!digitoNumerico(numeroTel)) {
        throw std::invalid_argument("Numero de Telefone Invalido: O Telefone Deve Conter Apenas Numeros.");
    }
    if (!tamanhoTelefone(numeroTel)) {
        throw std::invalid_argument("Numero de Telefone Invalido: Tamanho Invalido");
    }
}

void TELEFONE::setTel(std::string numeroTel) {
    Validar(numeroTel);
    this -> numeroTel = numeroTel;
}
