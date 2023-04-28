// Por: Eduardo Ferreira

#include <string>

/// Classe representativa do número de matrícula do usuário.
/** Esta classe permite alterar e obter o número de matrícula do usuário.

*   As restrições quanto ao formato estão implementadas de acordo:

*     - Formato: DDDDDDX, onde D é dígito numérico e X o dígito verificador.
*/
class MATRICULA {
    private:
        std::string nmrMatr;

        void Validar(std::string);
        int getHash(std::string);

    public:
        //! Método que modifica o valor da Matrícula.
        /// -----------------------------------------
        /** Este método utiliza a função auxiliar `Validar()`, definida como abaixo:
        *   - `Validar(std::string)`:

        *       Verifica se a string passada como argumento
        *       está de acordo com as restrições de formato.

        *       Caso não esteja, lança exceção.

        *       O dígito verificador é calculado em base 10 como a média aritmética
        *       dos dígitos anteriores.
        */
        /*!
            \param matric Uma *string* que representa o valor do número da Matrícula.
        */
        void setMatricula(std::string);

        //! Método inline que retorna o valor da Matrícula.
        /// -----------------------------------------------
        /*!
            \return O número da Matrícula.
        */
        inline std::string getMatricula() const {
            return nmrMatr;
        }
};

/******************************************************************************************/

/// Classe representativa dos resultados dos casos de teste.
/** Esta classe permite alterar e obter o resultado dos casos de teste.

*   Os resultados possíveis são "APROVADO" e "REPROVADO".

*/
class RESULTADO {
    private:
        std::string resultado;
        void Validar(std::string);

    public:
        //! Método que modifica o valor do resultado.
        /// -----------------------------------------
        /** Este método utiliza a função auxiliar `Validar()`, definida como abaixo:
        *   - `Validar(std::string)`:

        *       Verifica se o argumento passado é um dos resultados possíveis.

        *       Caso não seja, lança exceção.
        */
        /*!
            \param resultado Uma *string* que representa o resultado do teste.
        */
        void setResult(std::string);

        //! Método inline que retorna o valor do resultado.
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

* Os nomes possíveis são: "UNIDADE", "INTEGRACAO", "FUMACA", "SISTEMA", "REGRESSAO", "ACEITACAO"

*/
class CLASSE {
    private:
        std::string nome;
        bool contem(std::string ,std::string *, int); // Método auxiliar para Validar.
        void Validar(std::string);

    public:
        //! Método que modifica o nome do teste.
        /// ------------------------------------
        /** Este método utiliza a função auxiliar `Validar()`, definida como abaixo:
        *   - `Validar(std::string):`

        *       Verifica se o nome do teste é um dos nomes possíveis, armazenados numa lista (*array*).

        *       Caso não seja, lança exceção.

        *       Essa função utiliza outro método auxiliar:

        *       - `contem(std::string ,std::string *, int)`:
        *          Retorna *true* caso a string passada como argumento faça parte da lista passada e
        *          *false* caso não faça. Para isso, utiliza o tamanho da lista, também fornecido como argumento.
        */
        /*!
            \param nome Uma *string* que representa o nome do teste.
        */
        void setNome(std::string);

        //! Método inline que retorna o tipo de teste realizado.
        /// ----------------------------------------------------
        /*!
            \return O nome do teste.
        */
        inline std::string getNome() const {
            return nome;
        }
};

/******************************************************************************************/

/// Classe representativa do número de telefone do usuário.
/** Esta classe permite modificar e obter o número de telefone de um usuário, de acordo com
*   as regras de formatação abaixo:.

*   Formato: +XXXXXXX (7 dígitos) a +XXXXXXXXXXXXXXX (15 dígitos), onde X é dígito numérico de 0 a 9.
*/
class TELEFONE {
    private:
        std::string numeroTel;
        void Validar(std::string);
        // Métodos auxiliares para validação de número:
        bool comecaComMais(std::string);
        bool digitoNumerico(std::string);
        bool tamanhoTelefone(std::string);

    public:
        //! Método que modifica o valor do número de telefone.
        /// --------------------------------------------------
        /** Esse método utiliza a função auxiliar `Validar()`, definida como abaixo:
        *    - `Validar(std::string)`:

        *       Verifica se o argumento está de acordo com as regras de formatação.

        *       Lança exceção caso não esteja.

        *       Essa função utiliza uma série de outros métodos auxiliares que, cada um, verifica uma
        *       condição das regras de formatação do número, utilizando a biblioteca padrão *regex*:
        *       - `comecaComMais(std::string)`: Verifia se o argumento passado inicia om "+";
        *       - `digitoNumerico(std::string)`: Verifica se a string iniciada por "+" possui apenas dígitos numéricos;
        *       - `tamanhoTelefone(std::string)`: Verifica se o tamanho da string iniciada por + está entre 7 e 15 dígitos.
        */
        /*!
            \param numeroTel Uma *string* que representa o número de telefone do usuário.
        */
        void setTel(std::string);

        //! Método inline que retorna o número de telefone.
        /// -----------------------------------------------
        /*!
            \return O número de telefone.
        */
        inline std::string getTel() const {
            return numeroTel;
        }
};
