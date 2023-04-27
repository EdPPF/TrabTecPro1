// Por: Eduardo Ferreira
#include "../../headers/Eduardo/MATRICULA.h"
#include <stdexcept> // Para a exceção de invalidez do construtor.
#include <string>
#include <regex> // Para manipulação de strings.


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

void MATRICULA::Validar(std::string matric){
    if (matric.size() != 7) {
        throw std::invalid_argument("Matricula Invalida: Tamanho Invalido."); // A matrícula possui um tamanho específico;
    }
    int Hash = getHash(matric);
    int x = matric[6] - '0'; // Converte o último caractere em um número;
    //return (Hash == x); // Verifica se o último caractere é igual ao hash.
    if (Hash != x) {
        throw std::invalid_argument("Matricula Invalida: Digito Verificador Invalido.");
    }
    /*
        MUDANÇA: Esse método agora é void. Não há necessidade de reetornar um valor,
            já que agora ele possui exceções para caso de erro.
    */
}

void MATRICULA::setMatricula(std::string matric) {
    Validar(matric);
    /*
    if (!Validar(matric)) {
        throw std::invalid_argument("Matricula Invalida.");
    }
        MUDANÇA: se Validar lançar excessão, a linha abaixo não srá executada.
            Dessa forma, não há necessidade de usar um "if"
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
        MUDANÇA: Agora que Validar é void, não há porque lançar exceção aqui.
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
    // Se o método acima não lancar exceção, a linha abaixo será processada.
    this -> resultado = resultado;
}

/******************************************************************************************/

// Função genérica que retorna True caso um item esteja numa lista:
/*Essa função recebe o elemento alvo, a lista (supondo ambos strings) e o tamanho dela,
    percorre cada item da lista e os compara com o elemento, adicionando 1 à variável
    auxiliar se elemento for igual ao item da lista. Caso a variável soma seja diferente
    de 1 ao final do processo, o item não foi encontrado na lista (ou algo estranho aconteceu)
    e a função retorna false. Caso soma == 1, retorna true.
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
    // Verifica se a string inicia com o dígito "+".
    std::regex regexObj("^\\+");
    return std::regex_search(numeroTel, regexObj);
}

bool TELEFONE::digitoNumerico(std::string numeroTel) {
    // Verifica se a string iniciada por "+" possui apenas dígitos numéricos.
    std::regex regexObj("^\\+\\d+");
    return std::regex_search(numeroTel, regexObj);
}

bool TELEFONE::tamanhoTelefone(std::string numeroTel) {
    // Verifica se o tamanho da string iniciada por + está correto.
    std::regex regexObj("^\\+\\d{7,15}");
    return std::regex_search(numeroTel, regexObj);
}

void TELEFONE::Validar(std::string numeroTel) {
    /*
        Aqui, a ordem das chamadas é importante: Primeiro é verificado se
           o numero inicía com +. Se isso for satisfeito, é verificado se
           ele possui apenas números. E se isso for satisfeito, é verificado
           se o tamanho está correto.
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
