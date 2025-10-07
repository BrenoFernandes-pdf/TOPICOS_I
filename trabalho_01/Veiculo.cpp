#include <iostream>
#include "Veiculo.h"

Veiculo::Veiculo(const std::string &modelo, int quilometragem, const std::string &placa)
{
    this->modelo = modelo;
    this->quilometragem = quilometragem;
    this->placa = placa;
}

Veiculo::~Veiculo()
{
    std::cout << "Veículo " << this->modelo << " destruído, com a placa " << this->placa << "."<< std::endl;
    std::cout << "Com quilometragem igual a " << this->quilometragem << "km. rodados"
              << std::endl;
}

void Veiculo::setQuilometragem(int quilometragem)
{
    this->quilometragem = quilometragem;
}

std::string Veiculo::getPlaca() const {
    return this->placa;
}

std::string Veiculo::getModelo() const {
    return this->modelo;
}

int Veiculo::getKM() const {
    return this->quilometragem;
}