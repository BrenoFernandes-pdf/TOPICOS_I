#ifndef MOTORISTA_H_
#define MOTORISTA_H_

#include <string>
#include <vector>
#include "Veiculo.h"

typedef struct
{
    char categoria;
    std::string validade;
    int numCNH;
} CNH_t;

class Motorista
{
private:
    std::string nome;
    CNH_t cnh;
    std::vector<Veiculo*> veiculosAtribuidos;

private:
    void addVeiculoAtribuido(Veiculo* veiculo);
    void rmVeiculoAtribuido(Veiculo* veiculo);

public:
    Motorista(const std::string &nome, char &categoria, std::string &validade, const int &numCNH);
    ~Motorista();
    void listarVeiculosAtribuidos() const;
    // A classe Frota é "amiga" e tem permissão especial para chamar os acima abaixo(mesmo eles sendo private)
    friend class Frota;
    CNH_t getCNH() const;
    std::string getNome() const;
    int getNumCNH() const;
};

#endif /* MOTORISTA_H_ */
