// Por: Eduardo Ferreira (190026987)

#pragma once
#include <string>

/// Classe base das quais herdam todos os Domínios.
/** Esta classe possui apenas o método virtual puro `Validar()` e o método genérico `contem()`,
*    herdados pelas classes derivadas.
*/
class DOMINIOS {
    public:
        //! Função auxiliar para métodos de classes derivadas.
        /// -----------------------------------------------------
        /** Função genérica que retorna *true* caso um item esteja numa lista.

        *   Essa função recebe o elemento alvo, a lista (supondo ambos strings) e o tamanho dela,
        *   percorre cada item da lista e os compara com o elemento, adicionando 1 à variável
        *   auxiliar se elemento for igual ao item da lista. Caso a variável soma seja diferente
        *   de 1 ao final do processo, o item não foi encontrado na lista (ou algo estranho aconteceu)
        *   e a função retorna false. Caso *soma == 1*, retorna true.

        *   Essa função auxiliar é utilizada pelas classes `CLASSE` e `DATA`.
        */
        /*!
            \param elemento O elemento que será verificado se pertence à lista.
            \param lista A lista alvo.
            \param tamanho O tamanho da lista.
            \return *true* caso o elemento pertenca à lista e *false* caso contrário.
        */
        bool contem(std::string ,std::string *, int);

        //! Método virtual puro, sem implementação.
        /// -----------------------------------------
        virtual void Validar(std::string) = 0;

        //! Método virtual destrutor.
        /// -------------------------
        virtual ~DOMINIOS() {}

        //! Método virtual puro de retorno de valor.
        /// -----------------------------------
        /** Este método é redefinido nas classes derivadas, de modo a retornar o atributo adequado
        *   para cada classe.
        */
        virtual std::string getValor() = 0;

        //! Método virtual puro de atribuição de valor.
        /// --------------------------------------
        /** Este método é redefinido nas classes derivadas, de modo a atribuir para o devido
        *   atributo da classe um valor adequado.
        */
        virtual void setValor(std::string) = 0;
};

/******************************************************************************************/

/// Classe representativa do número de matrícula do usuário.
/** Esta classe permite alterar e obter o número de matrícula do usuário.

*   As restrições quanto ao formato estão implementadas de acordo:

*     - Formato: DDDDDDX, onde D é dígito numérico e X o dígito verificador.
*/
class MATRICULA : public DOMINIOS {
    private:
        std::string nmrMatr; /*!< Respresenta o número de matrícula. */

        //! Método de validação do número de matrícula.
        ///--------------------------------------------
        /** Verifica se a string passada como argumento está de acordo com as restrições
        *   de formato.

        *   Caso não esteja, lança exceção.

        *   Este método utiliza a função auxiliar `getHash()` para o cálculo do dígito verificador
        *   e é chamado pelo método `setMatricula()`.
        */
        /*!
            \param matric Número de matrícula cujo formato será verificado.
            \throw std::invalid_argument Caso o tamanho seja inválido.
            \throw std::invalid_argument Caso o dígito verificador seja inválido.
        */
        void Validar(std::string);

        //! Função auxiliar para o método Validar().
        /// ----------------------------------------
        /** Calcula o hash do número de matrícula. Essa função trata exclusivamente do formato da
        *   matrícula especificado, ou seja, um número de 7 dígitos, onde o dígito verificador é o último.

        *   O dígito verificador é calculado como a divisão por *10* da soma dos dígitos anteriores.
        */
        /*!
            \param s Uma *string* formada por sete dígitos numéricos.
            \return O dígito verificador.
        */
        int getHash(std::string);

    public:
        //! Método que modifica o valor da Matrícula.
        /// -----------------------------------------
        /** Este método utiliza a função auxiliar `Validar()`.
        */
        /*!
            \param nmrMatr Uma *string* que representa o valor do número da Matrícula.
        */
        //void setMatricula(std::string);
        void setValor(std::string nmrMatr);

        //! Método inline que retorna o valor da Matrícula.
        /// -----------------------------------------------
        /*!
            \return O número da Matrícula.
        */
        inline std::string getValor() {return nmrMatr;}
//        inline std::string getMatricula() const {
//            return nmrMatr;
//        }
};

/******************************************************************************************/

/// Classe representativa dos resultados dos casos de teste.
/** Esta classe permite alterar e obter o resultado dos casos de teste.

*   Os resultados possíveis são "APROVADO" e "REPROVADO".

*/
class RESULTADO : public DOMINIOS {
    private:
        std::string resultado; /*!< Respresenta o resultado do caso de teste. */

        //! Método de validação do resultado do caso de teste.
        ///---------------------------------------------------
        /** Verifica se a string passada como argumento é igual a um dos dois resultados possíveis.

        *   Caso não seja, lança exceção.

        *   Este método é chamado pelo método `setResult()`.
        */
        /*!
            \param resultado Resultado do caso de teste.
            \throw std::invalid_argument Caso o resultado seja inválido.
        */
        void Validar(std::string);

    public:
        //! Método que modifica o valor do resultado.
        /// -----------------------------------------
        /** Este método utiliza a função auxiliar `Validar()`.
        */
        /*!
            \param resultado Uma *string* que representa o resultado do teste.
        */
        //void setResult(std::string);
        void setValor(std::string);

        //! Método inline que retorna o valor do resultado.
        /// -----------------------------------------------
        /*!
            \return O valor do resultado.
        */
        inline std::string getValor() {
            return resultado;
        }
//        inline std::string getResult() const {
//            return resultado;
//        }
};

/******************************************************************************************/

/// Clsse representativa dos tipos de teste.
/** Esta classe permite modificar e obter os nomes dos testes realizados.

*   Os nomes possíveis são: "UNIDADE", "INTEGRACAO", "FUMACA", "SISTEMA", "REGRESSAO", "ACEITACAO"

*/
class CLASSE : public DOMINIOS {
    private:
        std::string nome; /*!< Representa o nome do teste. */

        //! Método de validação do nome do tipo de teste.
        ///---------------------------------------------------
        /** Verifica se o nome do teste é um dos nomes possíveis, armazenados numa lista (*array*).

        *   Caso não seja, lança exceção.

        *   Esse método utiliza a função auxiliar `contem()` da classe base `DOMINIOS`.

        *   Este método é chamado pelo método `setNome()`.
        */
        /*!
            \param tipo O nome do teste.
            \throw std::invalid_argument Caso o nome não faça parte da lista de nomes válidos.
        */
        void Validar(std::string);

    public:
        //! Método que modifica o nome do teste.
        /// ------------------------------------
        /** Este método utiliza a função auxiliar `Validar()`.
        */
        /*!
            \param nome Uma *string* que representa o nome do teste.
        */
        //void setNome(std::string);
        void setValor(std::string);

        //! Método inline que retorna o tipo de teste realizado.
        /// ----------------------------------------------------
        /*!
            \return O nome do teste.
        */
        inline std::string getValor() {
            return nome;
        }
//        inline std::string getNome() const {
//            return nome;
//        }
};

/******************************************************************************************/

/// Classe representativa do número de telefone do usuário.
/** Esta classe permite modificar e obter o número de telefone de um usuário, de acordo com
*   as regras de formatação abaixo:.

*   Formato: +XXXXXXX (7 dígitos) a +XXXXXXXXXXXXXXX (15 dígitos), onde X é dígito numérico de 0 a 9.
*/
class TELEFONE : public DOMINIOS {
    private:
        std::string numeroTel; /*!< Respresenta o número de telefone. */

        //! Função auxiliar para o método Validar().
        ///-----------------------------------------
        /** Esta função verifica se a string inicia com o dígito "+".

        *   Para isso, faz uso da biblioteca padrão *<regex>* para manipulação de strings.
        */
        /*!
            \param numeroTel O número de telefone.
            \return *true* se *numeroTel* começa com "+" e *false* caso contrário.
        */
        bool comecaComMais(std::string);

        //! Função auxiliar para o método Validar().
        /// ----------------------------------------
        /** Esta função verifica se a string iniciada por "+" possui apenas dígitos numéricos.

        *   É chamada pelo método `Validar()` **após** a função ´comecaComMais()´. Por isso,
        *   supõe que o argumento já inicia com "+".
        */
        /*!
            \param numeroTel O número de telefone.
            \return *true* se *numeroTel* possui apenas dígitos numéricos e *false* caso contrário.
        */
        bool digitoNumerico(std::string);

        //! Função auxiliar para o método Validar().
        /// ----------------------------------------
        /** Esta função verifica se o tamanho da string iniciada por + está correto.

        *   É chamaado pelo método `Validar()` **após** as funções auxiliares `comecaComMais()`
        *   e `digitoNumerico()`, por isso supõe que o formato que essas funções verifica é correspondido
        *   pela string passada no argumento.
        */
        /**
            \param numeroTel O número de telefone.
            \return *true* se o tamanho está correto e *false* caso contrário.
        */
        bool tamanhoTelefone(std::string);

        //! Método de validação do número de telefone.
        ///-------------------------------------------
        /** Verifica se o número de telefone está formatado corretamente.

        *   Caso não esteja, lança exceção de acordo com as funções auxiliares.

        *   Esse método utiliza as funções auxiliares `comecaComMais()`, `digitoNumerico` e
        *  `tamanhoTelefone()`.

        *   Este método é chamado pelo método `setTel()`.
        */
        /*!
            \param numeroTel O número de telefone.
            \throw std::invalid_argument Caso o número não inicie com "+".
            \throw std::invalid_argument Caso o número não contenha apenas números.
            \throw std::invalid_argument Caso o número não tenha tamanho válido.
        */
        void Validar(std::string);

    public:
        //! Método que modifica o valor do número de telefone.
        /// --------------------------------------------------
        /** Esse método utiliza a função auxiliar `Validar()`.
        */
        /*!
            \param numeroTel Uma *string* que representa o número de telefone do usuário.
        */
        //void setTel(std::string);
        void setValor(std::string);

        //! Método inline que retorna o número de telefone.
        /// -----------------------------------------------
        /*!
            \return O número de telefone.
        */
        inline std::string getValor() {
            return numeroTel;
        }
//        inline std::string getTel() const {
//            return numeroTel;
//        }
};


// ====================================================================================================================


// Por: Renan Santos

/// Classe representativa dos códigos dos testes e casos de teste.
/** Esta classe permite alterar e obter os códigos dos testes e dos casos de teste.

*   As restrições quanto ao formato dos códigos são:
*       - Formato: LLLDDD, onde L é letra (A - Z, a - z) e D é dígito (0 - 9).
*/
class CODIGO : public DOMINIOS {
    private:
        std::string codigo; /*!< Representa o valor do código. */

        //! Método de validação do formato do código.
        /// -----------------------------------------
        /** Verifica se a string passada como argumento está de acordo com as regras
        *   de formato.

        *   Caso não esteja, lança exceção.

        *   Este método utiliza as funções auxiliares `letra()` e `digito()`.
        */
        /*!
            \param cod O código cujo formato será verificado.
            \throw std::invalid_argument Se o tamanho for inválido.
            \throw std::invalid_argument Se os três primeiros dígitos não forem letras.
            \throw std::invalid_argument Se os três últimos dígitos não forem numéricos.
        */
        void Validar(std::string);

        //! Função auxiliar para o método Validar().
        /// ------------------------------------------
        /** Verifica se os todos os três primeiros dígitos da string são letras.
        */
        /*!
            \param let A string alvo, de pelo menos três dígitos.
            \return *true* se os três primeiros dígitos forem letras; *false* do contrário.
        */
        bool letra(std::string);

        //! Função auxiliar para o método Validar().
        /// ------------------------------------------
        /** Verifica se todos os três dígitos da string a partir do índice 3 são numéricos.
        */
        /*!
            \param dig A string alvo, de pelo quatro três dígitos.
            \return *true* se os três dígitos do indíce 3 em diante forem números; *false* do contrário.
        */
        bool digito(std::string);

    public:
        //! Método que modifica o valor do código.
        /// --------------------------------------
        /** Este método utiliza a função `Validar()`.
        */
        /*!
            \param codigo Uma *string* que representa o código.
        */
        //void setCodigo(std::string);
        void setValor(std::string);

        //! Método inline que retorna o valor do código.
        /// --------------------------------------------
        /*!
            \return O valor do código.
        */
        inline std::string getValor() {
            return codigo;
        }
//        inline std::string getCodigo() const {
//            return codigo;
//        }
};

/******************************************************************************************/

/// Classe representativa da data dos casos de teste.
/** Esta classe permite modificar e obter as datas dos casos de teste, de acordo com o
*   formato *DD/MES/ANO*, sendo que:
*       - *MES* é abreviação dos nomes dos meses, com três letras;
*       - *ANO* é um ano de 2000 a 2999.
*/
class DATA : public DOMINIOS {
    private:
        std::string data; /*!< Representa a data do caso de teste. */

        //! Função auxiliar para o método Validar().
        /// ----------------------------------------
        /** Esta função verifica se um ano, passado como *string*, é bissexto.
        */
        /*!
            \param data O ano a ser verificado, do tipo *string*.
            \return *true* se o ano for bissexto; *false* do contrário.
        */
        bool anoBissexto(std::string);

        //! Função auxiliar para o método auxiliar verificaDia().
        /// ----------------------------------------
        /** Esta função verifica a validade do dia em uma data, em conformidade com as regras usuais.

        *   Para isso, faz uma série de verificações, como verificar se o dia é no máximo 31 para os
        *   mêses que possuem essa quantidade de dias ou se é 30 para os outros. Também leva em consideração
        *   o mês de Fevereiro e anos bissextos.
        */
        /*!
            \param data Uma *string* formatada de acordo com o permitido pela classe.
            \return *true* se o dia é válido para o mês e ano da data e *false* do contrário.
        */
        bool verificaDia(std::string);

        //! Função auxiliar para o método Validar().
        /// ----------------------------------------
        /** Esta função verifica se o mês da data  passada como argumento é um dos 12 mêses do ano,
        *   considerando apenas a formatação permitida pela classe, i.e., uma abreviação maiúscula
        *   de três dígitos.

        *   Para isso, é usada a função auxiliar `contem()` da classe base DOMINIOS.
        */
        /*!
            \param data Uma *string* formatada de acordo com o permitido pela classe.
            \return *true* e mês é valido; *false* do contrário.
        */
        bool verificaMes(std::string); // Verifica se o mês é um dos 12 possíveis (formatados corretamente);

        //! Função auxiliar para o método Validar().
        /// ----------------------------------------
        /** Esta função verifica se o ano da string passada como argumento é válido, considerando que
        *   o ano deve ser formado por quatro dígitos numéricos e estar entre *2000* e *2999*.
        */
        /*!
            \param data Uma *string* formatada de acordo com o permitido pela classe.
            \return *true* se o ano está no intervalo permitido; *false* do contrário.
        */
        bool verificaAno(std::string);

        //! Função auxiliar para o método Validar().
        /// ----------------------------------------
        /** Esta função verifica se o formato geral da string passada como argumento é o permitido pela
        *   classe, ou seja, é do tipo *DD\MMM\ANOX*.

        *   No método `Validar()`, está é a primeira função chamada. Isso garante que o formato da string
        *   usada como argumento para as outras funções auxiliares, `verificaDia()`, `verificaMes()` e `verificaAno()`,
        *   está correta para o funcionamento delas.
        */
        /*!
            \param data Uma *string* cujo formato será verificado.
            \return *true* caso o formato esteja de acordo com o permitido pela classe; *false* do contrário.
        */
        bool verificaFormato(std::string);

        //! Método de validação do formato da data.
        /// ---------------------------------------
        /** Verifica se a string passada como argumento está de acordo com as regras
        *   de formato da classe.

        *   Caso não esteja, lança exceção.

        *   Este método utiliza as funções auxiliares `verificaFormato()`, `verificaDia()`, `verificaMes()`
        *   e `verificaAno()`.
        */
        /*!
            \param data A data cujo formato será verificado.
            \throw std::invalid_argument Se o formato for inválido.
            \throw std::invalid_argument Se o dia for inválido.
            \throw std::invalid_argument Se mês for inválido.
            \throw std::invalid_argument Se o ano for inválido.
        */
        void Validar(std::string);

    public:
        //! Método que modifica a data.
        /// ---------------------------
        /** Este método utiliza a função `Validar()`.
        */
        /*!
            \param data Uma *string* que representa a data.
        */
        //void setData(std::string);
        void setValor(std::string);

        //! Método inline que retorna a data.
        /// ---------------------------------
        /*!
            \return A data.
        */
        inline std::string getValor() {
            return data;
        }
//        inline std::string getData() const {
//            return data;
//        }


};

/******************************************************************************************/

/// Classe representativa da senha de usuários (desenvolvedores).
/** Esta classe permite alterar e obter a senha de usuários.

*   As restrições quanto ao formato das senhas são:
*       - Formato XXXXXX, onde X é um dos seguintes caracteres: letra (A - Z, a - z),
*         dígito (0 - 9), @ , #, *$* , *%* ou *&*;
*       - Não pode haver caractere duplicado;
*/
class SENHA : public DOMINIOS {
    private:
        std::string senha; /*!< Representa a senha inserida pelo usuário. */

        //! Função auxiliar para o método Validar().
        /// ----------------------------------------
        /** Esta função verifica se os caracteres presentes na string argumento fazem parte dos
        *   permitidos pelas restrições de formato da classe.
        */
        /*!
            \param senha A *string* que representa a senha.
            \return *true* se os caracteres são permitidos pela classe; *false* caso contrário.
        */
        bool formatacao(std::string);

        //! Função auxiliar para o método Validar().
        /// ----------------------------------------
        /** Esta função verifica se existe no mínimo uma dupla ocorrência de algum caractere
        *   integrante da string argumento.
        */
        /*!
            \param senha A *string* que representa a senha.
            \return *true* se a string possui algum caractere duplicado; *false* do contrário.
        */
        bool caractereDuplicado(std::string);

        //! Método de validação do formato da senha.
        /// ----------------------------------------
        /** Verifica se a string passada como argumento está de acordo com as regras
        *   de formato da classe.

        *   Caso não esteja, lança exceção.

        *   Este método utiliza as funções auxiliares `caractereDuplicado()` e `formatacao()`.
        */
        /*!
            \param senha A senha cujo formato será verificado.
            \throw std::invalid_argument Se o tamanho da string for diferente de 6.
            \throw std::invalid_argument Se a string possui caractere duplicado.
            \throw std::invalid_argument Se a string possui algum caractere não permitido pela classe.
        */
        void Validar(std::string);

    public:
        //! Método que modifica a senha.
        /// ----------------------------
        /** Esse método utiliza a função `Validar()`, definida como abaixo:
        */
        /*!
            \param senha Uma *string* que representa a senha do usuário.
        */
        //void setSenha(std::string);
        void setValor(std::string);

        //! Método inline que retorna a senha.
        /// ----------------------------------
        /*!
            \return A senha.
        */
        inline std::string getValor() {
            return senha;
        }
//        inline std::string getSenha() const {
//            return senha;
//        }
};

/******************************************************************************************/

/// Classe representativa de textos variados usados pelas entidades do sistema.
/** Esta classe permite modificar e obter textos com a seguinte formatação:
*       - 10 a 20 caracteres;
*       - Não há acentuação;
*       - Não há espaços em branco em sequência; e
*       - Cada caractere X é letra, dígito (0-9), sinal de pontuação ( . , ; ? ! : - ), @ , #, *$* , *%* ou *&*.
*/
class TEXTO : public DOMINIOS {
    private:
        std::string texto; /*!< Representa o texto, que pode ter diferentes significados. */

        //! Função auxiliar para o método Validar().
        /// ----------------------------------------
        /** Esta função verifica se o texto possui caracteres acentuados, de acordo com os presentes na tabela
        *   ASCII.
        */
        /*!
            \param texto A *string* que representa o texto.
            \return *true* se a string possui algum caractere acentuado; *false* do contrário.
        */
        bool contemAcento(std::string);

        //! Função auxiliar para o método Validar().
        /// ----------------------------------------
        /** Esta função verifica se a string argumento possui espaços (' ') em sequência.
        */
        /*!
            \param texto A *string* que representa o texto.
            \return *true* se a string possui espaços em sequência; *false* do contrário.
        */
        bool sequenciaDeEspaco(std::string);

        //! Função auxiliar para o método Validar().
        /// ----------------------------------------
        /** Esta função verifica se o argumento possui apenas caracteres permitidos pela classe.
        */
        /*!
            \param texto A *string* que representa o texto.
            \return *true* se a string possui apenas caracteres permitidos; *false* do contrário.
        */
        bool formatacao(std::string);

        //! Método de validação do formato do texto.
        /// ----------------------------------------
        /** Verifica se a string passada como argumento está de acordo com as regras
        *   de formato da classe.

        *   Caso não esteja, lança exceção.

        *   Este método utiliza as funções auxiliares `contemAcento()` e `formatacao()`.
        */
        /*!
            \param texto O texto cujo formato será verificado.
            \throw std::invalid_argument Se o tamanho da string não estiver no intervalo de 10 a 20.
            \throw std::invalid_argument Se a string possui caractere duplicado.
            \throw std::invalid_argument Se a string possui espaços em sequência.
            \throw std::invalid_argument Se a string possui caractere não permitido pela classe.
        */
        void Validar(std::string);

    public:
        //! Método que modifica o texto escrito.
        /// ------------------------------------
        /** Esse método utiliza a função `Validar()`.
        */
        /*!
            \param texto Uma *string* que representa o texto escrito.
        */
        //void setTexto(std::string);
        void setValor(std::string);

        //! Método inline que retorna o texto.
        /// ----------------------------------
        /*!
            \return O texto.
        */
        inline std::string getValor() {
            return texto;
        }
//        inline std::string getTexto() const {
//            return texto;
//        }
};

