#include "interfaces.h"
#include "DOMINIOS.h"

// Por: Eduardo Ferreira (190026987)

class CtrlAprAutentic: public InterAprAutentic {
    private:
        ILNAutenticacao *CtrlLNAutentic;
    public:
        bool autenticar(MATRICULA*);
        void setCtrlNAutentic(ILNAutenticacao*);
};

void inline CtrlAprAutentic::setCtrlNAutentic(ILNAutenticacao *CtrlLNAutentic){
    this->CtrlLNAutentic = CtrlLNAutentic;
}
