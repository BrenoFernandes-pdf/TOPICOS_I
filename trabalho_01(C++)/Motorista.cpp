#include <iostream>
#include "Motorista.h"
#include "Veiculo.h"


Motorista::Motorista(const std::string &nome, const std::string &cnh)
{
    this->nome = nome;
    this->cnh = cnh;
}

Motorista::~Motorista()
{
    std::cout << "Motorista destruído: " << this->nome
     << ", CNH: " << getCNH() << "\n"; 
}

std::string Motorista::getCNH() const
{
    return this->cnh;
}

std::string Motorista::getNome() const {
    return this->nome;
}

void Motorista::addVeiculoAtribuido(Veiculo* veiculo){
    this->veiculosAtribuidos.push_back(veiculo);
}

void Motorista::rmVeiculoAtribuido(Veiculo* veiculo){
    this->veiculosAtribuidos.remove(veiculo);
}

void Motorista::listarVeiculosAtribuidos() const{
    std::cout << "--> Veiculos atualmente com o motorista '" << this->nome << "':\n";

    if(this->veiculosAtribuidos.empty()){
        std::cout << "    - Nenhum veiculo atribuido.\n";
    }
    else {

    for(const Veiculo* veiculoPtr : this->veiculosAtribuidos){
        if(veiculoPtr){
            std::cout << "    - Veiculo | Placa: " << veiculoPtr->getPlaca()
                << ", Modelo: " << veiculoPtr->getModelo() << "\n";   
        }
    }

}
}







