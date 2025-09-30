#include <iostream>
#include "Veiculo.h"


Veiculo::Veiculo(std::string modelo, int quilometragem)
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

void Veiculo::setPlaca(std::string placa)
{
    this->placa = placa;
}

std::string Veiculo::getPlaca()
{
    return this->placa;
}



