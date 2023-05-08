// Por: Eduardo Ferreira (190026987)

#pragma once
#include ".\ENTIDADES.h"
#include <stdexcept>
#include <string>


class TESTUNITent {
    protected:
        virtual void setUp() = 0;
        virtual void tearDown() = 0;
        virtual void testeCenarioValido() = 0;
        int estado;
    public:
        const static int SUCESSO =  1;
        const static int FALHA   = -1;
        int run();
};

/******************************************************************************************/

class TUDesenvolvedor : public TESTUNITent {
    private:
        const std::string MATRValida  = "1900268";
        const std::string NOMEValido  = "Eduardo Ferreira";
        const std::string SENHAValida = "TecPr@";
        const std::string TELValido   = "+995567842";
        Desenvolvedor *dev;
        void setUp();
        void tearDown();
        void testeCenarioValido();
};

/******************************************************************************************/

class TUTestes : public TESTUNITent {
    private:
        const std::string CODIGOValido  = "DnD696";
        const std::string NOMEValido    = "Nome do Teste";
        const std::string CLASSEValida  = "SISTEMA";
        Testes *test;
        void setUp();
        void tearDown();
        void testeCenarioValido();
};

/******************************************************************************************/

class TUCasoTeste : public TESTUNITent {
    private:
        const std::string CODIGOValido   = "SQS112";
        const std::string NOMEValido     = "Caso de Teste";
        const std::string DATAValida     = "15/ABR/2023";
        const std::string ACAOValida     = "Uma acao qualquer";
        const std::string RESPValida     = "Resposta do teste";
        const std::string RESULTValido   = "APROVADO";
        CasoDeTeste *cdtest;
        void setUp();
        void tearDown();
        void testeCenarioValido();
};
