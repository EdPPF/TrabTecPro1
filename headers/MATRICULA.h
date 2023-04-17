// Por: Eduardo Ferreira
#include <string>


class MATRICULA {
    private:
        std::string nmrMatr;

        bool Validar(std::string);
        int getHash(std::string);

    public:
        MATRICULA(std::string);
        void setMatricula(std::string);
        std::string getMatricula() const { // inline.
            return nmrMatr;
        }
};
