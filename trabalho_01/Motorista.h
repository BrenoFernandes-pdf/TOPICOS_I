#ifndef MOTORISTA_H_
#define MOTORISTA_H_

#include <string>
#include <list>
#include "Veiculo.h"

class Motorista
{
private:
    std::string nome;
    std::string cnh;
    // O "chaveiro" do motorista: uma lista de ponteiros para os veículos
    // que ele está usando, mas não possui.
    std::list<Veiculo*> veiculosAtribuidos;

private:
    void addVeiculoAtribuido(Veiculo* veiculo);
    void rmVeiculoAtribuido(Veiculo* veiculo);

public:
    Motorista(const std::string &nome, const std::string &cnh);
    ~Motorista();
    void listarVeiculosAtribuidos() const;
    // A classe Frota é "amiga". Isso dá a ela acesso aos nossos métodos privados.
    friend class Frota;
    std::string getCNH() const;
    std::string getNome() const;
};

#endif /* MOTORISTA_H_ */
