// Por: Eduardo Ferreira (190026987)

#include "./DOMINIOS.h"
#include <string>

/// Classe representativa da entidade desenvolvedor do sistema.
/** Esta classe caracteriza o usu�rio desenvolvedor com as seguintes caracter�sticas:
*       - N�mero de MATRICULA do usu�rio;
*       - Nome (TEXTO) do usu�rio;
*       - SENHA do usu�rio;
*       - TELEFONE do usu�rio;

*   As restri��es quanto ao formato dos membros s�o ditadas pelos tipos desses membros,
*   como definidos em suas classes.
*/
class Desenvolvedor {
    private:
        /*<<PK>>*/ MATRICULA matricula; /*!< Respresenta a matr�cula do Desenvolvedor. */
        TEXTO nome;                     /*!< Respresenta o nome do Desenvolvedor. */
        SENHA senha;                    /*!< Respresenta a senha do Desenvolvedor. */
        TELEFONE telefone;              /*!< Respresenta o telefone do Desenvolvedor. */

    public:
        //! M�todo inline que modifica o valor da matr�cula do Desenvolvedor.
        /// -----------------------------------------------------------------
        /** Este m�todo utiliza o m�todo `setMatricula()` da classe MATRICULA.
        */
        /*!
            \param novaMatricula Uma *string* que representa o valor do n�mero da Matr�cula.
        */
        inline void setMatrDev(std::string novaMatricula){
            matricula.setMatricula(novaMatricula);
        }

        //! M�todo inline que modifica o valor do nome do Desenvolvedor.
        /// ------------------------------------------------------------
        /** Este m�todo utiliza o m�todo `setTexto()` da classe TEXTO.
        */
        /*!
            \param novoNome Uma *string* que representa o nome do Desenvolvedor.
        */
        inline void setNomeDev(std::string novoNome){
            nome.setTexto(novoNome);
        }

        //! M�todo inline que modifica a senha do Desenvolvedor.
        /// ----------------------------------------------------
        /** Este m�todo utiliza o m�todo `setSenha()` da classe SENHA.
        */
        /*!
            \param novaSenha Uma *string* que representa a senha do Desenvolvedor.
        */
        inline void setSenhaDev(std::string novaSenha) {
            senha.setSenha(novaSenha);
        }

        //! M�todo inline que modifica o telefone do Desenvolvedor.
        /// -------------------------------------------------------
        /** Este m�todo utiliza o m�todo `setTel()` da classe TELEFONE.
        */
        /*!
            \param novoTelefone Uma *string* que representa o telefone do Desenvolvedor.
        */
        inline void setTelDev(std::string novoTelefone) {
            telefone.setTel(novoTelefone);
        }


        //! M�todo inline que retorna o valor da matr�cula do Desenvolvedor.
        /// ----------------------------------------------------------------
        /*!
            \return O n�mero da matr�cula.
        */
        inline std::string getMatrDev() {
            return matricula.getMatricula();
        }

        //! M�todo inline que retorna o nome do Desenvolvedor.
        /// --------------------------------------------------
        /*!
            \return O nome do Desenvolvedor.
        */
        inline std::string getNomeDev() {
            return nome.getTexto();
        }

        //! M�todo inline que retorna a senha do Desenvolvedor.
        /// ---------------------------------------------------
        /*!
            \return A senha do Desenvolvedor.
        */
        inline std::string getSenhaDev() {
            return senha.getSenha();
        }

        //! M�todo inline que retorna o telefone do Desenvolvedor.
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
/** Esta classe caracteriza os testes com um c�digo (CODIGO), um texto (TEXTO) e uma classe
*   (CLASSE).

*   As restri��es quanto ao formato dos membros s�o ditadas pelos tipos desses membros,
*   como definidos em suas classes.
*/
class Testes {
    private:
        /*<<PK>>*/ CODIGO codigo; /*!< Respresenta o c�digo do Teste. */
        TEXTO texto;              /*!< Respresenta o texto associado ao Teste. */
        CLASSE classe;            /*!< Respresenta a classe do Teste. */

    public:
        //! M�todo inline que modifica o valor do c�digo do Teste.
        /// ------------------------------------------------------
        /** Este m�todo utiliza o m�todo `setCodigo()` da classe CODIGO.
        */
        /*!
            \param novoCodigo Uma *string* que representa o c�digo do Teste.
        */
        inline void setCodigoTeste(std::string novoCodigo){
            codigo.setCodigo(novoCodigo);
        }

        //! M�todo inline que modifica o texto associado ao Teste.
        /// ------------------------------------------------------
        /** Este m�todo utiliza o m�todo `setTexto()` da classe TEXTO.
        */
        /*!
            \param novoTexto Uma *string* que representa o texto associado ao Teste.
        */
        inline void setTextoTeste(std::string novoTexto) {
            texto.setTexto(novoTexto);
        }

        //! M�todo inline que modifica a classe do Teste.
        /// ---------------------------------------------
        /** Este m�todo utiliza o m�todo `setNome()` da classe CLASSE.
        */
        /*!
            \param novaClasse Uma *string* que representa a classe do Teste.
        */
        inline void setClasseTeste(std::string novaClasse) {
            classe.setNome(novaClasse);
        }


        //! M�todo inline que retorna o c�digo do Teste.
        /// --------------------------------------------
        /*!
            \return O c�digo do Teste.
        */
        inline std::string getCodigoTeste() {
            return codigo.getCodigo();
        }

        //! M�todo inline que retorna o texto associado ao Teste.
        /// -----------------------------------------------------
        /*!
            \return O texto associado ao Teste.
        */
        inline std::string getTextoTeste() {
            return texto.getTexto();
        }

        //! M�todo inline que retorna a classe do Teste.
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
/** Esta classe caracteriza os casos de teste. Cada caso ter�:
*       - Um c�digo (CODIGO);
*       - Um nome (TEXTO);
*       - Uma data (DATA);
*       - Uma a��o (TEXTO);
*       - Uma resposta (TEXTO); e
*       - Um resultado (RESULTADO).

*   As restri��es quanto ao formato dos membros s�o ditadas pelos tipos desses membros,
*   como definidos em suas classes.
*/
class CasoDeTeste {
    private:
        /*<<PK>>*/ CODIGO codigo; /*!< Respresenta o c�digo do Caso de Teste. */
        TEXTO nome;               /*!< Respresenta o nome do Caso de Teste. */
        DATA data;                /*!< Respresenta a data do Caso de Teste. */
        TEXTO acao;               /*!< Respresenta a a��o do Caso de Teste. */
        TEXTO resposta;           /*!< Respresenta a resposta do Caso de Teste. */
        RESULTADO resultado;      /*!< Respresenta o resultado do Caso de Teste. */

    public:
        //! M�todo inline que modifica o c�digo do Caso de Teste.
        /// -----------------------------------------------------
        /** Este m�todo utiliza o m�todo `setCodigo()` da classe CODIGO.
        */
        /*!
            \param novoCodigo Uma *string* que representa o c�digo do Caso de Teste.
        */
        inline void setCasoCodigo(std::string novoCodigo) {
            codigo.setCodigo(novoCodigo);
        }

        //! M�todo inline que modifica o nome do Caso de Teste.
        /// ---------------------------------------------------
        /** Este m�todo utiliza o m�todo `setTexto()` da classe TEXTO.
        */
        /*!
            \param novoNome Uma *string* que representa o nome do Caso de Teste.
        */
        inline void setCasoNome(std::string novoNome) {
            nome.setTexto(novoNome);
        }

        //! M�todo inline que modifica a data do Caso de Teste.
        /// ---------------------------------------------------
        /** Este m�todo utiliza o m�todo `setData()` da classe DATA.
        */
        /*!
            \param novaData Uma *string* que representa a data do Caso de Teste.
        */
        inline void setCasoData(std::string novaData) {
            data.setData(novaData);
        }

        //! M�todo inline que modifica a a��o do Caso de Teste.
        /// ---------------------------------------------------
        /** Este m�todo utiliza o m�todo `setTexto()` da classe TEXTO.
        */
        /*!
            \param novaAcao Uma *string* que representa a a��o do Caso de Teste.
        */
        inline void setCasoAcao(std::string novaAcao) {
            acao.setTexto(novaAcao);
        }

        //! M�todo inline que modifica a respsota do Caso de Teste.
        /// -------------------------------------------------------
        /** Este m�todo utiliza o m�todo `setTexto()` da classe TEXTO.
        */
        /*!
            \param novaResposta Uma *string* que representa a resposta do Caso de Teste.
        */
        inline void setCasoResposta(std::string novaResposta) {
            resposta.setTexto(novaResposta);
        }

        //! M�todo inline que modifica o resultado do Caso de Teste.
        /// --------------------------------------------------------
        /** Este m�todo utiliza o m�todo `setResult()` da classe RESULTADO.
        */
        /*!
            \param novoResultado Uma *string* que representa o resultado do Caso de Teste.
        */
        inline void setCasoResult(std::string novoResultado) {
            resultado.setResult(novoResultado);
        }


        //! M�todo inline que retorna o c�digo do Caso de Teste.
        /// ----------------------------------------------------
        /*!
            \return O c�digo do Caso de Teste.
        */
        inline std::string getCasoCodigo() {
            return codigo.getCodigo();
        }

        //! M�todo inline que retorna o nome do Caso de Teste.
        /// --------------------------------------------------
        /*!
            \return O nome do Caso de Teste.
        */
        inline std::string getCasoNome() {
            return nome.getTexto();
        }

        //! M�todo inline que retorna a data do Caso de Teste.
        /// --------------------------------------------------
        /*!
            \return A data do Caso de Teste.
        */
        inline std::string getCasoData() {
            return data.getData();
        }

        //! M�todo inline que retorna a a��o do Caso de Teste.
        /// ----------------------------------------------------
        /*!
            \return A a��o do Caso de Teste.
        */
        inline std::string getCasoAcao() {
            return acao.getTexto();
        }

        //! M�todo inline que retorna a resposta do Caso de Teste.
        /// ------------------------------------------------------
        /*!
            \return A resposta do Caso de Teste.
        */
        inline std::string getCasoResposta() {
            return resposta.getTexto();
        }

        //! M�todo inline que retorna o resultado do Caso de Teste.
        /// -------------------------------------------------------
        /*!
            \return O resultado do Caso de Teste.
        */
        inline std::string getCasoResult() {
            return resultado.getResult();
        }
};
