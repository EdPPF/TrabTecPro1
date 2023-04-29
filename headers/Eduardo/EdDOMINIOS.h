// Por: Eduardo Ferreira

#include <string>

/// Classe representativa do n�mero de matr�cula do usu�rio.
/** Esta classe permite alterar e obter o n�mero de matr�cula do usu�rio.

*   As restri��es quanto ao formato est�o implementadas de acordo:

*     - Formato: DDDDDDX, onde D � d�gito num�rico e X o d�gito verificador.
*/
class MATRICULA {
    private:
        std::string nmrMatr;

        void Validar(std::string);
        int getHash(std::string);

    public:
        //! M�todo que modifica o valor da Matr�cula.
        /// -----------------------------------------
        /** Este m�todo utiliza a fun��o auxiliar `Validar()`, definida como abaixo:
        *   - `Validar(std::string)`:

        *       Verifica se a string passada como argumento
        *       est� de acordo com as restri��es de formato.

        *       Caso n�o esteja, lan�a exce��o.

        *       O d�gito verificador � calculado em base 10 como a m�dia aritm�tica
        *       dos d�gitos anteriores.
        */
        /*!
            \param matric Uma *string* que representa o valor do n�mero da Matr�cula.
        */
        void setMatricula(std::string);

        //! M�todo inline que retorna o valor da Matr�cula.
        /// -----------------------------------------------
        /*!
            \return O n�mero da Matr�cula.
        */
        inline std::string getMatricula() const {
            return nmrMatr;
        }
};

/******************************************************************************************/

/// Classe representativa dos resultados dos casos de teste.
/** Esta classe permite alterar e obter o resultado dos casos de teste.

*   Os resultados poss�veis s�o "APROVADO" e "REPROVADO".

*/
class RESULTADO {
    private:
        std::string resultado;
        void Validar(std::string);

    public:
        //! M�todo que modifica o valor do resultado.
        /// -----------------------------------------
        /** Este m�todo utiliza a fun��o auxiliar `Validar()`, definida como abaixo:
        *   - `Validar(std::string)`:

        *       Verifica se o argumento passado � um dos resultados poss�veis.

        *       Caso n�o seja, lan�a exce��o.
        */
        /*!
            \param resultado Uma *string* que representa o resultado do teste.
        */
        void setResult(std::string);

        //! M�todo inline que retorna o valor do resultado.
        /// -----------------------------------------------
        /*!
            \return O valor do resultado.
        */
        inline std::string getResult() const {
            return resultado;
        }
};

/******************************************************************************************/

/// Clsse representativa dos tipos de teste.
/** Esta classe permite modificar e obter os nomes dos testes realizados.

* Os nomes poss�veis s�o: "UNIDADE", "INTEGRACAO", "FUMACA", "SISTEMA", "REGRESSAO", "ACEITACAO"

*/
class CLASSE {
    private:
        std::string nome;
        bool contem(std::string ,std::string *, int); // M�todo auxiliar para Validar.
        void Validar(std::string);

    public:
        //! M�todo que modifica o nome do teste.
        /// ------------------------------------
        /** Este m�todo utiliza a fun��o auxiliar `Validar()`, definida como abaixo:
        *   - `Validar(std::string):`

        *       Verifica se o nome do teste � um dos nomes poss�veis, armazenados numa lista (*array*).

        *       Caso n�o seja, lan�a exce��o.

        *       Essa fun��o utiliza outro m�todo auxiliar:

        *       - `contem(std::string ,std::string *, int)`:
        *          Retorna *true* caso a string passada como argumento fa�a parte da lista passada e
        *          *false* caso n�o fa�a. Para isso, utiliza o tamanho da lista, tamb�m fornecido como argumento.
        */
        /*!
            \param nome Uma *string* que representa o nome do teste.
        */
        void setNome(std::string);

        //! M�todo inline que retorna o tipo de teste realizado.
        /// ----------------------------------------------------
        /*!
            \return O nome do teste.
        */
        inline std::string getNome() const {
            return nome;
        }
};

/******************************************************************************************/

/// Classe representativa do n�mero de telefone do usu�rio.
/** Esta classe permite modificar e obter o n�mero de telefone de um usu�rio, de acordo com
*   as regras de formata��o abaixo:.

*   Formato: +XXXXXXX (7 d�gitos) a +XXXXXXXXXXXXXXX (15 d�gitos), onde X � d�gito num�rico de 0 a 9.
*/
class TELEFONE {
    private:
        std::string numeroTel;
        void Validar(std::string);
        // M�todos auxiliares para valida��o de n�mero:
        bool comecaComMais(std::string);
        bool digitoNumerico(std::string);
        bool tamanhoTelefone(std::string);

    public:
        //! M�todo que modifica o valor do n�mero de telefone.
        /// --------------------------------------------------
        /** Esse m�todo utiliza a fun��o auxiliar `Validar()`, definida como abaixo:
        *    - `Validar(std::string)`:

        *       Verifica se o argumento est� de acordo com as regras de formata��o.

        *       Lan�a exce��o caso n�o esteja.

        *       Essa fun��o utiliza uma s�rie de outros m�todos auxiliares que, cada um, verifica uma
        *       condi��o das regras de formata��o do n�mero, utilizando a biblioteca padr�o *regex*:
        *       - `comecaComMais(std::string)`: Verifia se o argumento passado inicia om "+";
        *       - `digitoNumerico(std::string)`: Verifica se a string iniciada por "+" possui apenas d�gitos num�ricos;
        *       - `tamanhoTelefone(std::string)`: Verifica se o tamanho da string iniciada por + est� entre 7 e 15 d�gitos.
        */
        /*!
            \param numeroTel Uma *string* que representa o n�mero de telefone do usu�rio.
        */
        void setTel(std::string);

        //! M�todo inline que retorna o n�mero de telefone.
        /// -----------------------------------------------
        /*!
            \return O n�mero de telefone.
        */
        inline std::string getTel() const {
            return numeroTel;
        }
};
