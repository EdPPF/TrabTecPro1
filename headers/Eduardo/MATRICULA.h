// Por: Eduardo Ferreira
#include <string>


class MATRICULA {
    private:
        std::string nmrMatr;

        void Validar(std::string);
        int getHash(std::string);

    public:
        MATRICULA(std::string);
        void setMatricula(std::string);
        inline std::string getMatricula() const {
            return nmrMatr;
        }
};

/******************************************************************************************/

class RESULTADO {
    private:
        std::string resultado;
        void Validar(std::string);

    public:
        void setResult(std::string);
        inline std::string getResult() const {
            return resultado;
        }
};

/******************************************************************************************/

class CLASSE {
    private:
        std::string nome;
        bool contem(std::string ,std::string *, int); // Método auxiliar para Validar.
        void Validar(std::string);

    public:
        void setNome(std::string);
        inline std::string getNome() const {
            return nome;
        }
};

/******************************************************************************************/

class TELEFONE {
    private:
        std::string numeroTel;
        void Validar(std::string);
        // Métodos auxiliares para validação de número:
        bool comecaComMais(std::string);
        bool digitoNumerico(std::string);
        bool tamanhoTelefone(std::string);

    public:
        void setTel(std::string);
        inline std::string getTel() const {
            return numeroTel;
        }
};
