#ifndef MOTORISTA_H_
#define MOTORISTA_H_

#include <string>
#include "Veiculo.h"

typedef struct{
    char categoria;
    std::string validade;
    int numCNH;
} CNH_t;

class Motorista
{
private:
    std::string nome;
    CNH_t cnh;
    std::vector<Veiculo> driver_Veiculos; //qual tipo de ponteiro usar unique_ptr?

public:
    Motorista(std::string nome, char categoria, std::string validade, int numCNH);
    ~Motorista();
    CNH_t getCNH();

};

#endif /* MOTORISTA_H_ */
