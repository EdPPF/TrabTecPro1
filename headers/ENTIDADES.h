// Por: Eduardo Ferreira (190026987)

#include "./DOMINIOS.h"
#include <string>

/// Classe representativa da entidade desenvolvedor do sistema.
/** Esta classe caracteriza o usuário desenvolvedor com as seguintes características:
*       - Número de MATRICULA do usuário;
*       - Nome (TEXTO) do usuário;
*       - SENHA do usuário;
*       - TELEFONE do usuário;

*   As restrições quanto ao formato dos membros são ditadas pelos tipos desses membros,
*   como definidos em suas classes.
*/
class Desenvolvedor {
    private:
        /*<<PK>>*/ MATRICULA matricula; /*!< Respresenta a matrícula do Desenvolvedor. */
        TEXTO nome;                     /*!< Respresenta o nome do Desenvolvedor. */
        SENHA senha;                    /*!< Respresenta a senha do Desenvolvedor. */
        TELEFONE telefone;              /*!< Respresenta o telefone do Desenvolvedor. */

    public:
        //! Método inline que modifica o valor da matrícula do Desenvolvedor.
        /// -----------------------------------------------------------------
        /** Este método utiliza o método `setMatricula()` da classe MATRICULA.
        */
        /*!
            \param novaMatricula Uma *string* que representa o valor do número da Matrícula.
        */
        inline void setMatrDev(std::string novaMatricula){
            matricula.setMatricula(novaMatricula);
        }

        //! Método inline que modifica o valor do nome do Desenvolvedor.
        /// ------------------------------------------------------------
        /** Este método utiliza o método `setTexto()` da classe TEXTO.
        */
        /*!
            \param novoNome Uma *string* que representa o nome do Desenvolvedor.
        */
        inline void setNomeDev(std::string novoNome){
            nome.setTexto(novoNome);
        }

        //! Método inline que modifica a senha do Desenvolvedor.
        /// ----------------------------------------------------
        /** Este método utiliza o método `setSenha()` da classe SENHA.
        */
        /*!
            \param novaSenha Uma *string* que representa a senha do Desenvolvedor.
        */
        inline void setSenhaDev(std::string novaSenha) {
            senha.setSenha(novaSenha);
        }

        //! Método inline que modifica o telefone do Desenvolvedor.
        /// -------------------------------------------------------
        /** Este método utiliza o método `setTel()` da classe TELEFONE.
        */
        /*!
            \param novoTelefone Uma *string* que representa o telefone do Desenvolvedor.
        */
        inline void setTelDev(std::string novoTelefone) {
            telefone.setTel(novoTelefone);
        }


        //! Método inline que retorna o valor da matrícula do Desenvolvedor.
        /// ----------------------------------------------------------------
        /*!
            \return O número da matrícula.
        */
        inline std::string getMatrDev() {
            return matricula.getMatricula();
        }

        //! Método inline que retorna o nome do Desenvolvedor.
        /// --------------------------------------------------
        /*!
            \return O nome do Desenvolvedor.
        */
        inline std::string getNomeDev() {
            return nome.getTexto();
        }

        //! Método inline que retorna a senha do Desenvolvedor.
        /// ---------------------------------------------------
        /*!
            \return A senha do Desenvolvedor.
        */
        inline std::string getSenhaDev() {
            return senha.getSenha();
        }

        //! Método inline que retorna o telefone do Desenvolvedor.
        /// ------------------------------------------------------
        /*!
            \return O telefone do Desenvolvedor.
        */
        inline std::string getTelDev() {
            return telefone.getTel();
        }
};

/******************************************************************************************/

/// Classe representativa da entidade de testes das classes de DOMINIOS.
/** Esta classe caracteriza os testes com um código (CODIGO), um texto (TEXTO) e uma classe
*   (CLASSE).

*   As restrições quanto ao formato dos membros são ditadas pelos tipos desses membros,
*   como definidos em suas classes.
*/
class Testes {
    private:
        /*<<PK>>*/ CODIGO codigo; /*!< Respresenta o código do Teste. */
        TEXTO texto;              /*!< Respresenta o texto associado ao Teste. */
        CLASSE classe;            /*!< Respresenta a classe do Teste. */

    public:
        //! Método inline que modifica o valor do código do Teste.
        /// ------------------------------------------------------
        /** Este método utiliza o método `setCodigo()` da classe CODIGO.
        */
        /*!
            \param novoCodigo Uma *string* que representa o código do Teste.
        */
        inline void setCodigoTeste(std::string novoCodigo){
            codigo.setCodigo(novoCodigo);
        }

        //! Método inline que modifica o texto associado ao Teste.
        /// ------------------------------------------------------
        /** Este método utiliza o método `setTexto()` da classe TEXTO.
        */
        /*!
            \param novoTexto Uma *string* que representa o texto associado ao Teste.
        */
        inline void setTextoTeste(std::string novoTexto) {
            texto.setTexto(novoTexto);
        }

        //! Método inline que modifica a classe do Teste.
        /// ---------------------------------------------
        /** Este método utiliza o método `setNome()` da classe CLASSE.
        */
        /*!
            \param novaClasse Uma *string* que representa a classe do Teste.
        */
        inline void setClasseTeste(std::string novaClasse) {
            classe.setNome(novaClasse);
        }


        //! Método inline que retorna o código do Teste.
        /// --------------------------------------------
        /*!
            \return O código do Teste.
        */
        inline std::string getCodigoTeste() {
            return codigo.getCodigo();
        }

        //! Método inline que retorna o texto associado ao Teste.
        /// -----------------------------------------------------
        /*!
            \return O texto associado ao Teste.
        */
        inline std::string getTextoTeste() {
            return texto.getTexto();
        }

        //! Método inline que retorna a classe do Teste.
        /// --------------------------------------------
        /*!
            \return A classe do Teste.
        */
        inline std::string getClasseTeste() {
            return classe.getNome();
        }
};

/******************************************************************************************/

/// Classe representativa dos casos de teste para os DOMINIOS.
/** Esta classe caracteriza os casos de teste. Cada caso terá:
*       - Um código (CODIGO);
*       - Um nome (TEXTO);
*       - Uma data (DATA);
*       - Uma ação (TEXTO);
*       - Uma resposta (TEXTO); e
*       - Um resultado (RESULTADO).

*   As restrições quanto ao formato dos membros são ditadas pelos tipos desses membros,
*   como definidos em suas classes.
*/
class CasoDeTeste {
    private:
        /*<<PK>>*/ CODIGO codigo; /*!< Respresenta o código do Caso de Teste. */
        TEXTO nome;               /*!< Respresenta o nome do Caso de Teste. */
        DATA data;                /*!< Respresenta a data do Caso de Teste. */
        TEXTO acao;               /*!< Respresenta a ação do Caso de Teste. */
        TEXTO resposta;           /*!< Respresenta a resposta do Caso de Teste. */
        RESULTADO resultado;      /*!< Respresenta o resultado do Caso de Teste. */

    public:
        //! Método inline que modifica o código do Caso de Teste.
        /// -----------------------------------------------------
        /** Este método utiliza o método `setCodigo()` da classe CODIGO.
        */
        /*!
            \param novoCodigo Uma *string* que representa o código do Caso de Teste.
        */
        inline void setCasoCodigo(std::string novoCodigo) {
            codigo.setCodigo(novoCodigo);
        }

        //! Método inline que modifica o nome do Caso de Teste.
        /// ---------------------------------------------------
        /** Este método utiliza o método `setTexto()` da classe TEXTO.
        */
        /*!
            \param novoNome Uma *string* que representa o nome do Caso de Teste.
        */
        inline void setCasoNome(std::string novoNome) {
            nome.setTexto(novoNome);
        }

        //! Método inline que modifica a data do Caso de Teste.
        /// ---------------------------------------------------
        /** Este método utiliza o método `setData()` da classe DATA.
        */
        /*!
            \param novaData Uma *string* que representa a data do Caso de Teste.
        */
        inline void setCasoData(std::string novaData) {
            data.setData(novaData);
        }

        //! Método inline que modifica a ação do Caso de Teste.
        /// ---------------------------------------------------
        /** Este método utiliza o método `setTexto()` da classe TEXTO.
        */
        /*!
            \param novaAcao Uma *string* que representa a ação do Caso de Teste.
        */
        inline void setCasoAcao(std::string novaAcao) {
            acao.setTexto(novaAcao);
        }

        //! Método inline que modifica a respsota do Caso de Teste.
        /// -------------------------------------------------------
        /** Este método utiliza o método `setTexto()` da classe TEXTO.
        */
        /*!
            \param novaResposta Uma *string* que representa a resposta do Caso de Teste.
        */
        inline void setCasoResposta(std::string novaResposta) {
            resposta.setTexto(novaResposta);
        }

        //! Método inline que modifica o resultado do Caso de Teste.
        /// --------------------------------------------------------
        /** Este método utiliza o método `setResult()` da classe RESULTADO.
        */
        /*!
            \param novoResultado Uma *string* que representa o resultado do Caso de Teste.
        */
        inline void setCasoResult(std::string novoResultado) {
            resultado.setResult(novoResultado);
        }


        //! Método inline que retorna o código do Caso de Teste.
        /// ----------------------------------------------------
        /*!
            \return O código do Caso de Teste.
        */
        inline std::string getCasoCodigo() {
            return codigo.getCodigo();
        }

        //! Método inline que retorna o nome do Caso de Teste.
        /// --------------------------------------------------
        /*!
            \return O nome do Caso de Teste.
        */
        inline std::string getCasoNome() {
            return nome.getTexto();
        }

        //! Método inline que retorna a data do Caso de Teste.
        /// --------------------------------------------------
        /*!
            \return A data do Caso de Teste.
        */
        inline std::string getCasoData() {
            return data.getData();
        }

        //! Método inline que retorna a ação do Caso de Teste.
        /// ----------------------------------------------------
        /*!
            \return A ação do Caso de Teste.
        */
        inline std::string getCasoAcao() {
            return acao.getTexto();
        }

        //! Método inline que retorna a resposta do Caso de Teste.
        /// ------------------------------------------------------
        /*!
            \return A resposta do Caso de Teste.
        */
        inline std::string getCasoResposta() {
            return resposta.getTexto();
        }

        //! Método inline que retorna o resultado do Caso de Teste.
        /// -------------------------------------------------------
        /*!
            \return O resultado do Caso de Teste.
        */
        inline std::string getCasoResult() {
            return resultado.getResult();
        }
};
