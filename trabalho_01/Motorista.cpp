#include <iostream>
#include "Motorista.h"


Motorista::Motorista(std::string nome, char categoria, std::string validade, int numCNH)
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

void Motorista::atribuirVeiculo(Veiculo veiculo)
{
    this->driver_Veiculos.push_back(veiculo); //ver qual tipo de ponteiro
}

void Motorista::desvincularVeiculo(Veiculo veiculo)
{
    //this->driver_Veiculos.pop_back(veiculo); ver qual tipo de ponteiro
}

CNH_t Motorista::getCNH()
{
    return this->cnh;
}









