#ifndef MULTI_IMPRESSORA_H_
#define MULTI_IMPRESSORA_H_

#include "Impressora.h"
#include "Scan.h"

class Multi : public Impressora, Scan {
protected:

public:
    void copiar();
    
};





#endif /*MULTI_IMPRESSORA_H_*/