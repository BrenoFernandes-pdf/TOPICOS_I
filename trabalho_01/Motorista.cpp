#include <iostream>
#include "Motorista.h"
#include <algorithm> // para usarmos std::erase
#include "Veiculo.h"


Motorista::Motorista(const std::string &nome, char &categoria, std::string &validade, const int &numCNH)
{
    this->nome = nome;
    this->cnh.categoria = categoria;
    this->cnh.validade = validade;
    this->cnh.numCNH = numCNH;
}

Motorista::~Motorista()
{
    std::cout << "Motorista destruído: " << this->nome
     << ", " << getCNH().categoria << ", " << getCNH().validade << ", " <<
     getCNH().numCNH << std::endl; 
}

CNH_t Motorista::getCNH() const
{
    return this->cnh;
}

int Motorista::getNumCNH() const {
    return getCNH().numCNH;
}

std::string Motorista::getNome() const {
    return this->nome;
}

void Motorista::addVeiculoAtribuido(Veiculo* veiculo){
    this->veiculosAtribuidos.push_back(veiculo);

}








