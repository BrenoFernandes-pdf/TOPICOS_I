#ifndef MOTORISTA_H_
#define MOTORISTA_H_

#include <string>
#include "Veiculo.h"
#include <vector>

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
    void atribuirVeiculo(Veiculo veiculo);
    void desvincularVeiculo(Veiculo veiculo);
    CNH_t getCNH();

};

#endif /* MOTORISTA_H_ */
