#include <iostream>
#include "Veiculo.h"

Veiculo::Veiculo(const std::string &modelo, int &quilometragem)
{
    this->modelo = modelo;
    this->quilometragem = quilometragem;
}

Veiculo::~Veiculo()
{
    std::cout << "Veículo " << this->modelo << " destruído" << std::endl;
    std::cout << "Com quilometragem igual a " << this->quilometragem
              << std::endl;
}

void Veiculo::setQuilometragem(int &quilometragem)
{
    this->quilometragem = quilometragem;
}

void Veiculo::setPlaca(std::string &placa){
    this->placa = placa;
}

std::string Veiculo::getPlaca() const {
    return this->placa;
}

std::string Veiculo::getModelo() const {
    return this->modelo;
}
