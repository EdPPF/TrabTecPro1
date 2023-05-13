// Por: Eduardo Ferreira (190026987)

#pragma once
#include <string>

/// Classe base das quais herdam todos os Dom�nios.
/** Esta classe possui apenas o m�todo virtual puro `Validar()` e o m�todo gen�rico `contem()`,
*    herdados pelas classes derivadas.
*/
class DOMINIOS {
    public:
        //! Fun��o auxiliar para m�todos de classes derivadas.
        /// -----------------------------------------------------
        /** Fun��o gen�rica que retorna *true* caso um item esteja numa lista.

        *   Essa fun��o recebe o elemento alvo, a lista (supondo ambos strings) e o tamanho dela,
        *   percorre cada item da lista e os compara com o elemento, adicionando 1 � vari�vel
        *   auxiliar se elemento for igual ao item da lista. Caso a vari�vel soma seja diferente
        *   de 1 ao final do processo, o item n�o foi encontrado na lista (ou algo estranho aconteceu)
        *   e a fun��o retorna false. Caso *soma == 1*, retorna true.

        *   Essa fun��o auxiliar � utilizada pelas classes `CLASSE` e `DATA`.
        */
        /*!
            \param elemento O elemento que ser� verificado se pertence � lista.
            \param lista A lista alvo.
            \param tamanho O tamanho da lista.
            \return *true* caso o elemento pertenca � lista e *false* caso contr�rio.
        */
        bool contem(std::string ,std::string *, int);

        //! M�todo virtual puro, sem implementa��o.
        /// -----------------------------------------
        virtual void Validar(std::string) = 0;

        //! M�todo virtual destrutor.
        /// -------------------------
        virtual ~DOMINIOS() {}

        //! M�todo virtual puro de retorno de valor.
        /// -----------------------------------
        /** Este m�todo � redefinido nas classes derivadas, de modo a retornar o atributo adequado
        *   para cada classe.
        */
        virtual std::string getValor() = 0;

        //! M�todo virtual puro de atribui��o de valor.
        /// --------------------------------------
        /** Este m�todo � redefinido nas classes derivadas, de modo a atribuir para o devido
        *   atributo da classe um valor adequado.
        */
        virtual void setValor(std::string) = 0;
};

/******************************************************************************************/

/// Classe representativa do n�mero de matr�cula do usu�rio.
/** Esta classe permite alterar e obter o n�mero de matr�cula do usu�rio.

*   As restri��es quanto ao formato est�o implementadas de acordo:

*     - Formato: DDDDDDX, onde D � d�gito num�rico e X o d�gito verificador.
*/
class MATRICULA : public DOMINIOS {
    private:
        std::string nmrMatr; /*!< Respresenta o n�mero de matr�cula. */

        //! M�todo de valida��o do n�mero de matr�cula.
        ///--------------------------------------------
        /** Verifica se a string passada como argumento est� de acordo com as restri��es
        *   de formato.

        *   Caso n�o esteja, lan�a exce��o.

        *   Este m�todo utiliza a fun��o auxiliar `getHash()` para o c�lculo do d�gito verificador
        *   e � chamado pelo m�todo `setMatricula()`.
        */
        /*!
            \param matric N�mero de matr�cula cujo formato ser� verificado.
            \throw std::invalid_argument Caso o tamanho seja inv�lido.
            \throw std::invalid_argument Caso o d�gito verificador seja inv�lido.
        */
        void Validar(std::string);

        //! Fun��o auxiliar para o m�todo Validar().
        /// ----------------------------------------
        /** Calcula o hash do n�mero de matr�cula. Essa fun��o trata exclusivamente do formato da
        *   matr�cula especificado, ou seja, um n�mero de 7 d�gitos, onde o d�gito verificador � o �ltimo.

        *   O d�gito verificador � calculado como a divis�o por *10* da soma dos d�gitos anteriores.
        */
        /*!
            \param s Uma *string* formada por sete d�gitos num�ricos.
            \return O d�gito verificador.
        */
        int getHash(std::string);

    public:
        //! M�todo que modifica o valor da Matr�cula.
        /// -----------------------------------------
        /** Este m�todo utiliza a fun��o auxiliar `Validar()`.
        */
        /*!
            \param nmrMatr Uma *string* que representa o valor do n�mero da Matr�cula.
        */
        //void setMatricula(std::string);
        void setValor(std::string nmrMatr);

        //! M�todo inline que retorna o valor da Matr�cula.
        /// -----------------------------------------------
        /*!
            \return O n�mero da Matr�cula.
        */
        inline std::string getValor() {return nmrMatr;}
//        inline std::string getMatricula() const {
//            return nmrMatr;
//        }
};

/******************************************************************************************/

/// Classe representativa dos resultados dos casos de teste.
/** Esta classe permite alterar e obter o resultado dos casos de teste.

*   Os resultados poss�veis s�o "APROVADO" e "REPROVADO".

*/
class RESULTADO : public DOMINIOS {
    private:
        std::string resultado; /*!< Respresenta o resultado do caso de teste. */

        //! M�todo de valida��o do resultado do caso de teste.
        ///---------------------------------------------------
        /** Verifica se a string passada como argumento � igual a um dos dois resultados poss�veis.

        *   Caso n�o seja, lan�a exce��o.

        *   Este m�todo � chamado pelo m�todo `setResult()`.
        */
        /*!
            \param resultado Resultado do caso de teste.
            \throw std::invalid_argument Caso o resultado seja inv�lido.
        */
        void Validar(std::string);

    public:
        //! M�todo que modifica o valor do resultado.
        /// -----------------------------------------
        /** Este m�todo utiliza a fun��o auxiliar `Validar()`.
        */
        /*!
            \param resultado Uma *string* que representa o resultado do teste.
        */
        //void setResult(std::string);
        void setValor(std::string);

        //! M�todo inline que retorna o valor do resultado.
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

*   Os nomes poss�veis s�o: "UNIDADE", "INTEGRACAO", "FUMACA", "SISTEMA", "REGRESSAO", "ACEITACAO"

*/
class CLASSE : public DOMINIOS {
    private:
        std::string nome; /*!< Representa o nome do teste. */

        //! M�todo de valida��o do nome do tipo de teste.
        ///---------------------------------------------------
        /** Verifica se o nome do teste � um dos nomes poss�veis, armazenados numa lista (*array*).

        *   Caso n�o seja, lan�a exce��o.

        *   Esse m�todo utiliza a fun��o auxiliar `contem()` da classe base `DOMINIOS`.

        *   Este m�todo � chamado pelo m�todo `setNome()`.
        */
        /*!
            \param tipo O nome do teste.
            \throw std::invalid_argument Caso o nome n�o fa�a parte da lista de nomes v�lidos.
        */
        void Validar(std::string);

    public:
        //! M�todo que modifica o nome do teste.
        /// ------------------------------------
        /** Este m�todo utiliza a fun��o auxiliar `Validar()`.
        */
        /*!
            \param nome Uma *string* que representa o nome do teste.
        */
        //void setNome(std::string);
        void setValor(std::string);

        //! M�todo inline que retorna o tipo de teste realizado.
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

/// Classe representativa do n�mero de telefone do usu�rio.
/** Esta classe permite modificar e obter o n�mero de telefone de um usu�rio, de acordo com
*   as regras de formata��o abaixo:.

*   Formato: +XXXXXXX (7 d�gitos) a +XXXXXXXXXXXXXXX (15 d�gitos), onde X � d�gito num�rico de 0 a 9.
*/
class TELEFONE : public DOMINIOS {
    private:
        std::string numeroTel; /*!< Respresenta o n�mero de telefone. */

        //! Fun��o auxiliar para o m�todo Validar().
        ///-----------------------------------------
        /** Esta fun��o verifica se a string inicia com o d�gito "+".

        *   Para isso, faz uso da biblioteca padr�o *<regex>* para manipula��o de strings.
        */
        /*!
            \param numeroTel O n�mero de telefone.
            \return *true* se *numeroTel* come�a com "+" e *false* caso contr�rio.
        */
        bool comecaComMais(std::string);

        //! Fun��o auxiliar para o m�todo Validar().
        /// ----------------------------------------
        /** Esta fun��o verifica se a string iniciada por "+" possui apenas d�gitos num�ricos.

        *   � chamada pelo m�todo `Validar()` **ap�s** a fun��o �comecaComMais()�. Por isso,
        *   sup�e que o argumento j� inicia com "+".
        */
        /*!
            \param numeroTel O n�mero de telefone.
            \return *true* se *numeroTel* possui apenas d�gitos num�ricos e *false* caso contr�rio.
        */
        bool digitoNumerico(std::string);

        //! Fun��o auxiliar para o m�todo Validar().
        /// ----------------------------------------
        /** Esta fun��o verifica se o tamanho da string iniciada por + est� correto.

        *   � chamaado pelo m�todo `Validar()` **ap�s** as fun��es auxiliares `comecaComMais()`
        *   e `digitoNumerico()`, por isso sup�e que o formato que essas fun��es verifica � correspondido
        *   pela string passada no argumento.
        */
        /**
            \param numeroTel O n�mero de telefone.
            \return *true* se o tamanho est� correto e *false* caso contr�rio.
        */
        bool tamanhoTelefone(std::string);

        //! M�todo de valida��o do n�mero de telefone.
        ///-------------------------------------------
        /** Verifica se o n�mero de telefone est� formatado corretamente.

        *   Caso n�o esteja, lan�a exce��o de acordo com as fun��es auxiliares.

        *   Esse m�todo utiliza as fun��es auxiliares `comecaComMais()`, `digitoNumerico` e
        *  `tamanhoTelefone()`.

        *   Este m�todo � chamado pelo m�todo `setTel()`.
        */
        /*!
            \param numeroTel O n�mero de telefone.
            \throw std::invalid_argument Caso o n�mero n�o inicie com "+".
            \throw std::invalid_argument Caso o n�mero n�o contenha apenas n�meros.
            \throw std::invalid_argument Caso o n�mero n�o tenha tamanho v�lido.
        */
        void Validar(std::string);

    public:
        //! M�todo que modifica o valor do n�mero de telefone.
        /// --------------------------------------------------
        /** Esse m�todo utiliza a fun��o auxiliar `Validar()`.
        */
        /*!
            \param numeroTel Uma *string* que representa o n�mero de telefone do usu�rio.
        */
        //void setTel(std::string);
        void setValor(std::string);

        //! M�todo inline que retorna o n�mero de telefone.
        /// -----------------------------------------------
        /*!
            \return O n�mero de telefone.
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

/// Classe representativa dos c�digos dos testes e casos de teste.
/** Esta classe permite alterar e obter os c�digos dos testes e dos casos de teste.

*   As restri��es quanto ao formato dos c�digos s�o:
*       - Formato: LLLDDD, onde L � letra (A - Z, a - z) e D � d�gito (0 - 9).
*/
class CODIGO : public DOMINIOS {
    private:
        std::string codigo; /*!< Representa o valor do c�digo. */

        //! M�todo de valida��o do formato do c�digo.
        /// -----------------------------------------
        /** Verifica se a string passada como argumento est� de acordo com as regras
        *   de formato.

        *   Caso n�o esteja, lan�a exce��o.

        *   Este m�todo utiliza as fun��es auxiliares `letra()` e `digito()`.
        */
        /*!
            \param cod O c�digo cujo formato ser� verificado.
            \throw std::invalid_argument Se o tamanho for inv�lido.
            \throw std::invalid_argument Se os tr�s primeiros d�gitos n�o forem letras.
            \throw std::invalid_argument Se os tr�s �ltimos d�gitos n�o forem num�ricos.
        */
        void Validar(std::string);

        //! Fun��o auxiliar para o m�todo Validar().
        /// ------------------------------------------
        /** Verifica se os todos os tr�s primeiros d�gitos da string s�o letras.
        */
        /*!
            \param let A string alvo, de pelo menos tr�s d�gitos.
            \return *true* se os tr�s primeiros d�gitos forem letras; *false* do contr�rio.
        */
        bool letra(std::string);

        //! Fun��o auxiliar para o m�todo Validar().
        /// ------------------------------------------
        /** Verifica se todos os tr�s d�gitos da string a partir do �ndice 3 s�o num�ricos.
        */
        /*!
            \param dig A string alvo, de pelo quatro tr�s d�gitos.
            \return *true* se os tr�s d�gitos do ind�ce 3 em diante forem n�meros; *false* do contr�rio.
        */
        bool digito(std::string);

    public:
        //! M�todo que modifica o valor do c�digo.
        /// --------------------------------------
        /** Este m�todo utiliza a fun��o `Validar()`.
        */
        /*!
            \param codigo Uma *string* que representa o c�digo.
        */
        //void setCodigo(std::string);
        void setValor(std::string);

        //! M�todo inline que retorna o valor do c�digo.
        /// --------------------------------------------
        /*!
            \return O valor do c�digo.
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
*       - *MES* � abrevia��o dos nomes dos meses, com tr�s letras;
*       - *ANO* � um ano de 2000 a 2999.
*/
class DATA : public DOMINIOS {
    private:
        std::string data; /*!< Representa a data do caso de teste. */

        //! Fun��o auxiliar para o m�todo Validar().
        /// ----------------------------------------
        /** Esta fun��o verifica se um ano, passado como *string*, � bissexto.
        */
        /*!
            \param data O ano a ser verificado, do tipo *string*.
            \return *true* se o ano for bissexto; *false* do contr�rio.
        */
        bool anoBissexto(std::string);

        //! Fun��o auxiliar para o m�todo auxiliar verificaDia().
        /// ----------------------------------------
        /** Esta fun��o verifica a validade do dia em uma data, em conformidade com as regras usuais.

        *   Para isso, faz uma s�rie de verifica��es, como verificar se o dia � no m�ximo 31 para os
        *   m�ses que possuem essa quantidade de dias ou se � 30 para os outros. Tamb�m leva em considera��o
        *   o m�s de Fevereiro e anos bissextos.
        */
        /*!
            \param data Uma *string* formatada de acordo com o permitido pela classe.
            \return *true* se o dia � v�lido para o m�s e ano da data e *false* do contr�rio.
        */
        bool verificaDia(std::string);

        //! Fun��o auxiliar para o m�todo Validar().
        /// ----------------------------------------
        /** Esta fun��o verifica se o m�s da data  passada como argumento � um dos 12 m�ses do ano,
        *   considerando apenas a formata��o permitida pela classe, i.e., uma abrevia��o mai�scula
        *   de tr�s d�gitos.

        *   Para isso, � usada a fun��o auxiliar `contem()` da classe base DOMINIOS.
        */
        /*!
            \param data Uma *string* formatada de acordo com o permitido pela classe.
            \return *true* e m�s � valido; *false* do contr�rio.
        */
        bool verificaMes(std::string); // Verifica se o m�s � um dos 12 poss�veis (formatados corretamente);

        //! Fun��o auxiliar para o m�todo Validar().
        /// ----------------------------------------
        /** Esta fun��o verifica se o ano da string passada como argumento � v�lido, considerando que
        *   o ano deve ser formado por quatro d�gitos num�ricos e estar entre *2000* e *2999*.
        */
        /*!
            \param data Uma *string* formatada de acordo com o permitido pela classe.
            \return *true* se o ano est� no intervalo permitido; *false* do contr�rio.
        */
        bool verificaAno(std::string);

        //! Fun��o auxiliar para o m�todo Validar().
        /// ----------------------------------------
        /** Esta fun��o verifica se o formato geral da string passada como argumento � o permitido pela
        *   classe, ou seja, � do tipo *DD\MMM\ANOX*.

        *   No m�todo `Validar()`, est� � a primeira fun��o chamada. Isso garante que o formato da string
        *   usada como argumento para as outras fun��es auxiliares, `verificaDia()`, `verificaMes()` e `verificaAno()`,
        *   est� correta para o funcionamento delas.
        */
        /*!
            \param data Uma *string* cujo formato ser� verificado.
            \return *true* caso o formato esteja de acordo com o permitido pela classe; *false* do contr�rio.
        */
        bool verificaFormato(std::string);

        //! M�todo de valida��o do formato da data.
        /// ---------------------------------------
        /** Verifica se a string passada como argumento est� de acordo com as regras
        *   de formato da classe.

        *   Caso n�o esteja, lan�a exce��o.

        *   Este m�todo utiliza as fun��es auxiliares `verificaFormato()`, `verificaDia()`, `verificaMes()`
        *   e `verificaAno()`.
        */
        /*!
            \param data A data cujo formato ser� verificado.
            \throw std::invalid_argument Se o formato for inv�lido.
            \throw std::invalid_argument Se o dia for inv�lido.
            \throw std::invalid_argument Se m�s for inv�lido.
            \throw std::invalid_argument Se o ano for inv�lido.
        */
        void Validar(std::string);

    public:
        //! M�todo que modifica a data.
        /// ---------------------------
        /** Este m�todo utiliza a fun��o `Validar()`.
        */
        /*!
            \param data Uma *string* que representa a data.
        */
        //void setData(std::string);
        void setValor(std::string);

        //! M�todo inline que retorna a data.
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

/// Classe representativa da senha de usu�rios (desenvolvedores).
/** Esta classe permite alterar e obter a senha de usu�rios.

*   As restri��es quanto ao formato das senhas s�o:
*       - Formato XXXXXX, onde X � um dos seguintes caracteres: letra (A - Z, a - z),
*         d�gito (0 - 9), @ , #, *$* , *%* ou *&*;
*       - N�o pode haver caractere duplicado;
*/
class SENHA : public DOMINIOS {
    private:
        std::string senha; /*!< Representa a senha inserida pelo usu�rio. */

        //! Fun��o auxiliar para o m�todo Validar().
        /// ----------------------------------------
        /** Esta fun��o verifica se os caracteres presentes na string argumento fazem parte dos
        *   permitidos pelas restri��es de formato da classe.
        */
        /*!
            \param senha A *string* que representa a senha.
            \return *true* se os caracteres s�o permitidos pela classe; *false* caso contr�rio.
        */
        bool formatacao(std::string);

        //! Fun��o auxiliar para o m�todo Validar().
        /// ----------------------------------------
        /** Esta fun��o verifica se existe no m�nimo uma dupla ocorr�ncia de algum caractere
        *   integrante da string argumento.
        */
        /*!
            \param senha A *string* que representa a senha.
            \return *true* se a string possui algum caractere duplicado; *false* do contr�rio.
        */
        bool caractereDuplicado(std::string);

        //! M�todo de valida��o do formato da senha.
        /// ----------------------------------------
        /** Verifica se a string passada como argumento est� de acordo com as regras
        *   de formato da classe.

        *   Caso n�o esteja, lan�a exce��o.

        *   Este m�todo utiliza as fun��es auxiliares `caractereDuplicado()` e `formatacao()`.
        */
        /*!
            \param senha A senha cujo formato ser� verificado.
            \throw std::invalid_argument Se o tamanho da string for diferente de 6.
            \throw std::invalid_argument Se a string possui caractere duplicado.
            \throw std::invalid_argument Se a string possui algum caractere n�o permitido pela classe.
        */
        void Validar(std::string);

    public:
        //! M�todo que modifica a senha.
        /// ----------------------------
        /** Esse m�todo utiliza a fun��o `Validar()`, definida como abaixo:
        */
        /*!
            \param senha Uma *string* que representa a senha do usu�rio.
        */
        //void setSenha(std::string);
        void setValor(std::string);

        //! M�todo inline que retorna a senha.
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
/** Esta classe permite modificar e obter textos com a seguinte formata��o:
*       - 10 a 20 caracteres;
*       - N�o h� acentua��o;
*       - N�o h� espa�os em branco em sequ�ncia; e
*       - Cada caractere X � letra, d�gito (0-9), sinal de pontua��o ( . , ; ? ! : - ), @ , #, *$* , *%* ou *&*.
*/
class TEXTO : public DOMINIOS {
    private:
        std::string texto; /*!< Representa o texto, que pode ter diferentes significados. */

        //! Fun��o auxiliar para o m�todo Validar().
        /// ----------------------------------------
        /** Esta fun��o verifica se o texto possui caracteres acentuados, de acordo com os presentes na tabela
        *   ASCII.
        */
        /*!
            \param texto A *string* que representa o texto.
            \return *true* se a string possui algum caractere acentuado; *false* do contr�rio.
        */
        bool contemAcento(std::string);

        //! Fun��o auxiliar para o m�todo Validar().
        /// ----------------------------------------
        /** Esta fun��o verifica se a string argumento possui espa�os (' ') em sequ�ncia.
        */
        /*!
            \param texto A *string* que representa o texto.
            \return *true* se a string possui espa�os em sequ�ncia; *false* do contr�rio.
        */
        bool sequenciaDeEspaco(std::string);

        //! Fun��o auxiliar para o m�todo Validar().
        /// ----------------------------------------
        /** Esta fun��o verifica se o argumento possui apenas caracteres permitidos pela classe.
        */
        /*!
            \param texto A *string* que representa o texto.
            \return *true* se a string possui apenas caracteres permitidos; *false* do contr�rio.
        */
        bool formatacao(std::string);

        //! M�todo de valida��o do formato do texto.
        /// ----------------------------------------
        /** Verifica se a string passada como argumento est� de acordo com as regras
        *   de formato da classe.

        *   Caso n�o esteja, lan�a exce��o.

        *   Este m�todo utiliza as fun��es auxiliares `contemAcento()` e `formatacao()`.
        */
        /*!
            \param texto O texto cujo formato ser� verificado.
            \throw std::invalid_argument Se o tamanho da string n�o estiver no intervalo de 10 a 20.
            \throw std::invalid_argument Se a string possui caractere duplicado.
            \throw std::invalid_argument Se a string possui espa�os em sequ�ncia.
            \throw std::invalid_argument Se a string possui caractere n�o permitido pela classe.
        */
        void Validar(std::string);

    public:
        //! M�todo que modifica o texto escrito.
        /// ------------------------------------
        /** Esse m�todo utiliza a fun��o `Validar()`.
        */
        /*!
            \param texto Uma *string* que representa o texto escrito.
        */
        //void setTexto(std::string);
        void setValor(std::string);

        //! M�todo inline que retorna o texto.
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

