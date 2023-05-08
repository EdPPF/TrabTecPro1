// Por: Eduardo Ferreira (190026987)

#pragma once
//#include "./DOMINIOS.h"
#include "./ENTIDADES.h"
#include <stdexcept>
#include <string>

class TESTUNITdom {
    public:
        std::string mensagemExcept = "Sem Excecoes."; // Mensagem De Exceção.
        const static int SUCESSO =  1;
        const static int FALHA   = -1;
        int run();

    protected:
        int estado;    // Estado do teste.
        std::string valorValido;   // Dados que serão utilizados
        std::string valorInvalido; // no teste da classe.
        virtual std::string setValorValido()    = 0;
        virtual std::string setValorInvalido()  = 0;
        virtual void testeCenarioValido();
        virtual void testeCenarioInvalido();

        DOMINIOS *dominio;
        /*
            criaDominio() e destroiDominio() permitem generalizar setUp e tearDown no sentido de que
            são eles que serão sobrescritos nas classes derivadas. VALE A PENA?
        */
        virtual DOMINIOS* criaDominio() = 0;
        virtual void destroiDominio() = 0;

        void setUp();
        inline void tearDown() {
            destroiDominio();
    }
};

/******************************************************************************************/

class TesteMATRICULA : public TESTUNITdom {
    public:
        const std::string MATRInvalida = "1900269";

    private:
        const std::string MATRValida   = "1900268";
        MATRICULA *matricula;

        inline std::string setValorValido() override {
            return MATRValida;
        }
        inline std::string setValorInvalido() override {
            return MATRInvalida;
        }

        inline DOMINIOS* criaDominio()  override {
            matricula = new MATRICULA();
            return matricula;
        }
        inline void destroiDominio()    override {
            delete matricula;
        }
};

/******************************************************************************************/

class TesteRESULTADO : public TESTUNITdom {
    public:
        const std::string RESInvalido = "algumaCoisa";

    private:
        const std::string RESValido   = "APROVADO";
        RESULTADO *resultado;

        inline std::string setValorValido() override {
            return RESValido;
        }
        inline std::string setValorInvalido() override {
            return RESInvalido;
        }

        inline DOMINIOS* criaDominio()  override {
            resultado = new RESULTADO();
            return resultado;
        }
        inline void destroiDominio()    override {
            delete resultado;
        }
};

/******************************************************************************************/

class TesteCLASSE : public TESTUNITdom {
    public:
        const std::string CLASSInvalida = "Regressao";

    private:
        const std::string CLASSValida   = "REGRESSAO";
        CLASSE *classe;

        inline std::string setValorValido() override {
            return CLASSValida;
        }
        inline std::string setValorInvalido() override {
            return CLASSInvalida;
        }

        inline DOMINIOS* criaDominio()  override {
            classe = new CLASSE();
            return classe;
        }
        inline void destroiDominio()    override {
            delete classe;
        }
};

/******************************************************************************************/

class TesteTELEFONE : public TESTUNITdom {
    public:
        const std::string TELInvalido = "995557235";

    private:
        const std::string TELValido   = "+995557235";
        TELEFONE *telefone;

        inline std::string setValorValido() override {
            return TELValido;
        }
        inline std::string setValorInvalido() override {
            return TELInvalido;
        }

        inline DOMINIOS* criaDominio()  override {
            telefone = new TELEFONE();
            return telefone;
        }
        inline void destroiDominio()    override {
            delete telefone;
        }
};

/******************************************************************************************/

class TesteCODIGO : public TESTUNITdom {
    public:
        const std::string CODEInvalido = "mnm0069";

    private:
        const std::string CODEValido   = "MnM069";
        CODIGO *codigo;

        inline std::string setValorValido() override {
            return CODEValido;
        }
        inline std::string setValorInvalido() override {
            return CODEInvalido;
        }

        inline DOMINIOS* criaDominio()  override {
            codigo = new CODIGO();
            return codigo;
        }
        inline void destroiDominio()    override {
            delete codigo;
        }
};

/******************************************************************************************/

class TesteDATA : public TESTUNITdom {
    public:
        const std::string DATAInvalida = "16/05/2023";

    private:
        const std::string DATAValida   = "16/MAI/2023";
        DATA *data;

        inline std::string setValorValido() override {
            return DATAValida;
        }
        inline std::string setValorInvalido() override {
            return DATAInvalida;
        }

        inline DOMINIOS* criaDominio()  override {
            data = new DATA();
            return data;
        }
        inline void destroiDominio()    override {
            delete data;
        }
};

/******************************************************************************************/

class TesteSENHA : public TESTUNITdom {
    public:
        const std::string SENHAInvalida = "Jo@o12";

    private:
        const std::string SENHAValida   = "J@n123";
        SENHA *senha;

        inline std::string setValorValido() override {
            return SENHAValida;
        }
        inline std::string setValorInvalido() override {
            return SENHAInvalida;
        }

        inline DOMINIOS* criaDominio()  override {
            senha = new SENHA();
            return senha;
        }
        inline void destroiDominio()    override {
            delete senha;
        }
};

/******************************************************************************************/

class TesteTEXTO : public TESTUNITdom {
    public:
        const std::string TEXTOInvalido = "Não Deve Funcionar";

    private:
        const std::string TEXTOValido   = "Deve Funcionar";
        TEXTO *texto;

        inline std::string setValorValido() override {
            return TEXTOValido;
        }
        inline std::string setValorInvalido() override {
            return TEXTOInvalido;
        }

        inline DOMINIOS* criaDominio()  override {
            texto = new TEXTO();
            return texto;
        }
        inline void destroiDominio()    override {
            delete texto;
        }
};
