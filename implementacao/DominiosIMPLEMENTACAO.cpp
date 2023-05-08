// Por: Eduardo Ferreira (190026987)

#include "../headers/DOMINIOS.h"
#include <stdexcept> // Para a exceção de invalidez do construtor.
#include <string>
#include <regex> // Para manipulação de strings.


bool DOMINIOS::contem(std::string elemento, std::string lista[], int tamanho) {
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        if (elemento == lista[i]) {soma += 1;}
    }
    if (soma != 1) {return false;}
    return true;
}


/******************************************************************************************/

int MATRICULA::getHash(std::string s) {
    int Hash = 0;
    for (int i=0; i<6; i++) { // Percorre a matrícula até o penúltimo número para preencher o Hash;
        Hash += (s[i] - '0'); // Transforma o caractere em inteiro e soma ao Hash;
    }
    return Hash % 10;         // O Hash em si é o resultado dessa divisão.
}

void MATRICULA::Validar(std::string matric) {
    if (matric.size() != 7) {
        throw std::invalid_argument("Matricula Invalida: Tamanho Invalido.");
    }
    int Hash = getHash(matric);
    int x = matric[6] - '0'; // Converte o último caractere em um número;
    if (Hash != x) {
        throw std::invalid_argument("Matricula Invalida: Digito Verificador Invalido.");
    }
}

//void MATRICULA::setMatricula(std::string nmrMatr) {
//    Validar(nmrMatr);
//    this -> nmrMatr = nmrMatr;
//}
void MATRICULA::setValor(std::string nmrMatr) {
    Validar(nmrMatr);
    this -> nmrMatr = nmrMatr;
}


/******************************************************************************************/

void RESULTADO::Validar(std::string resultado) {
    if (resultado != "APROVADO" && resultado != "REPROVADO") {
        throw std::invalid_argument("Resultado Invalido.");
    }
}

//void RESULTADO::setResult(std::string resultado) {
//    Validar(resultado);
//    this -> resultado = resultado;
//}
void RESULTADO::setValor(std::string resultado) {
    Validar(resultado);
    this -> resultado = resultado;
}


/******************************************************************************************/

void CLASSE::Validar(std::string tipo) {
    std::string listaNomes [6] = {"UNIDADE", "INTEGRACAO", "FUMACA", "SISTEMA", "REGRESSAO", "ACEITACAO"};
    if (!contem(tipo, listaNomes, 6)) {
        throw std::invalid_argument("Nome Invalido.");
    }
}

//void CLASSE::setNome(std::string nome) {
//    Validar(nome);
//    this -> nome = nome;
//}
void CLASSE::setValor(std::string nome) {
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
    return std::regex_match(numeroTel, regexObj);
}

bool TELEFONE::tamanhoTelefone(std::string numeroTel) {
    // Verifica se o tamanho da string iniciada por + está correto.
    std::regex regexObj("^\\+\\d{7,15}");
    return std::regex_match(numeroTel, regexObj);
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

//void TELEFONE::setTel(std::string numeroTel) {
//    Validar(numeroTel);
//    this -> numeroTel = numeroTel;
//}
void TELEFONE::setValor(std::string numeroTel) {
    Validar(numeroTel);
    this -> numeroTel = numeroTel;
}


// ====================================================================================================================


// Por: Renan Santos

bool CODIGO::letra(std::string let){
    for (int i = 0; i < 3; i++) {
        if(!isalpha(let[i])){// retorna false se o caracter nao for alfabetico
            return false;
        }
    }
    return true;
}

bool CODIGO::digito(std::string dig){
    // retorna false se o caracter nao for um numero
    std::string copia = dig.substr(3, 3); // Copia 3 char da pos 3 pra frente.
    std::regex regObj("\\d\\d\\d");
    return std::regex_match(copia, regObj);
}

void CODIGO::Validar(std::string cod){
    if(cod.size() != 6){
        throw std::invalid_argument("Codigo Invalido: Tamnho Invalido.");
    }
    if(!letra(cod)){
        throw std::invalid_argument("Codigo Invalido: Letras Invalidas.");
    }
    if(!digito(cod)){
         throw std::invalid_argument("Codigo Invalido: Numeros Invalidos.");
    }
}

//void CODIGO::setCodigo(std::string codigo){
//    Validar(codigo);
//    this -> codigo = codigo;
//}
void CODIGO::setValor(std::string codigo){
    Validar(codigo);
    this -> codigo = codigo;
}


/******************************************************************************************/

bool DATA::anoBissexto(std::string data) {
    int ano = std::stoi(data);
    // Retorna true se o ano for bissexto:
    return ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0);
}

bool DATA::verificaDia(std::string data){
    // Pega a parte que contem os dias;
    std::string diaStr = data.substr(0, 2);
    // Retorna false se o dia não for um número poxa vida:
    std::regex regObj("[0-9]+");
    if (!(std::regex_search(diaStr, regObj))) {
        return false;
    }

    int dia = std::stoi(diaStr);            // Converte em int o dia;
    std::string mes = data.substr(3, 3);   // Pega a parte de contem o mês;
    std::string ano = data.substr(7, 4);  // Pega a parte que contem o ano.

    // Verifica se o dia está entre 01 e 31 para os meses: JAN, MAR, MAI, JUL, AGO, OUT, DEZ
    if (mes == "JAN" || mes == "MAR" || mes == "MAI" || mes == "JUL" || mes == "AGO" || mes == "OUT" || mes == "DEZ") {
        if (!(dia > 0 && dia <= 31)) {
            return false;
        }
    }
    // Verifica se o dia está entre 01 e 30 para os meses: ABR, JUN, SET, NOV
    if (mes == "ABR" || mes == "JUN" || mes == "SET" || mes == "NOV") {
        if (!(dia > 0 && dia <= 30)) {return false;}
    }
    // Se o mês for fevereiro->Se ano bissexto: Verifica se o dia está entre 01 e 29
    //                       ->Se não for bissexto: Verifica se está entre 01 e 28
    if (mes == "FEV") {
        if (anoBissexto(ano)) {
            if ((dia > 0 && dia <= 29)) {return true;}
        }
        if (!(dia > 0 && dia <= 28)) {return false;}
    }
    return true;
}

bool DATA::verificaMes(std::string data){
    std::string listaMes [12] = {"JAN","FEV","MAR","ABR","MAI","JUN","JUL","AGO","SET","OUT","NOV","DEZ"};
    std::string mes = data.substr(3, 3);
    if (!(contem(mes, listaMes, 12))) {
        return false;
    }
    return true;
}

bool DATA::verificaAno(std::string data){
    // Pega a parte que contem o ano;
    std::string anoStr = data.substr(7, 4);
    // Retorna falso se o ano não for um número poxa vida:
    std::regex regObj("[0-9]+");
    if (!(std::regex_search(anoStr, regObj))) {
        return false;
    }

    int ano = std::stoi(anoStr);
    // Verificar se o ano está entre 2000 e 2999:
    if (!(ano >= 2000 && ano <= 2999)) {
        return false;
    }
    return true;
}

bool DATA::verificaFormato(std::string data) {
    // Verificar se o formato é DD/MMM/ANOX
    std::regex regObj("\\d\\d/\\w\\w\\w/\\d\\d\\d\\d");
    return std::regex_match(data, regObj);
}

void DATA::Validar(std::string data){
    if (!verificaFormato(data)) {
        throw std::invalid_argument("Data Invalida: Formato Invalido.");
    }
    if (!verificaDia(data)) {
        throw std::invalid_argument("Data Invalida: Dia Invalido.");
    }
    if (!verificaMes(data)) {
        throw std::invalid_argument("Data Invalida: Mes Invalido.");
    }
    if (!verificaAno(data)) {
        throw std::invalid_argument("Data Invalida: Ano Invalido.");
    }
}

//void DATA::setData(std::string data){
//    Validar(data);
//    this -> data = data;
//}
void DATA::setValor(std::string data){
    Validar(data);
    this -> data = data;
}


/******************************************************************************************/

bool SENHA::formatacao(std::string senha) {
    // Retorna true se texto possui um ou mais dos caracteres na expressão.
    std::regex regObj("[A-Za-z\\d\\@\\#\\$\\%\\&]+");
    return std::regex_search(senha, regObj);
}

bool SENHA::caractereDuplicado(std::string senha) {
    int tamanho = senha.length();
    std::string copia = senha;
    std::string letra;
    // CONSIDERANDO QUE minusculo != maiusculo, OU SEJA, T != t:
    for (int i = 0; i < tamanho; i++) {
        letra = senha[i]; // Letra que será verificada a dupla ocorrência;
        copia.erase(copia.begin()); // Apaga o inicio da palavra copiada para remover a letra alvo;
        if (copia.find(letra) != std::string::npos) {
            // Retorna true se encontrar um caractere mais de uma vez.
            return true;
        }
    }
    return false;
}

void SENHA::Validar(std::string senha){
    if (senha.length() != 6){ // Verifica o tamaho da senha.
        throw std::invalid_argument("Senha Invalida: Tamanho de Senha Invalido.");
    }
    if (caractereDuplicado(senha)) {
        throw std::invalid_argument("Senha Invalida: Caractere Repetido.");
    }
    if (!formatacao(senha)) {
        throw std::invalid_argument("Senha Invalida.");
    }
}

//void SENHA::setSenha(std::string senha){
//    Validar(senha);
//    this->senha = senha;
//}
void SENHA::setValor(std::string senha){
    Validar(senha);
    this->senha = senha;
}


/******************************************************************************************/

bool TEXTO::contemAcento(std::string texto){
    // Retorna true se texto CONTEM acentuação;
    std::regex regObj("[\\x80-\\x105]"); // Posições x80 a x105 na tabela ASCII;
    return std::regex_search(texto, regObj);
}

bool TEXTO::sequenciaDeEspaco(std::string texto) {
    // Retorna true se texto CONTÉM espaços seguidos.
    std::regex regObj("\\s{2,}");
    return std::regex_search(texto, regObj);
}

bool TEXTO::formatacao(std::string texto) {
    // Retorna true se texto possui um ou mais dos caracteres na expressão.
    std::regex regObj("[A-Za-z\\d\\.\\,\\;\\?\\!\\:\\-\\@\\#\\$\\%\\&]+");
    return std::regex_search(texto, regObj);
}

void TEXTO::Validar(std::string texto){
    // Verifica o tamanho:
    if (!(texto.length() >= 10 && texto.length() <= 20)){
        throw std::invalid_argument("Texto Invalido: Tamanho Invalido.");
    }
    //Verifica se contém acentuação:
    if (contemAcento(texto)) {
        throw std::invalid_argument("Texto Invalido: Acentuacao Nao Permitida.");
    }
    // Verifica se possui espaços em sequência:
    if (sequenciaDeEspaco(texto)) {
        throw std::invalid_argument("Texto Invalido: Sequencia de Espacos Encontrada.");
    }
    // Verifica o restante da formatação:
    if (!formatacao(texto)) {
        throw std::invalid_argument("Texto Invalido.");
    }
}

//void TEXTO::setTexto(std::string texto){
//    Validar(texto);
//    this -> texto = texto;
//}
void TEXTO::setValor(std::string texto){
    Validar(texto);
    this -> texto = texto;
}
