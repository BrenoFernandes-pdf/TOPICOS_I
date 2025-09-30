/*
    @brief Header para o arquivo Veiculo.cpp
    @autor Breno Fernandes

*/

#ifndef VEICULO_H_
#define VEICULO_H_

#include <string>

class Veiculo{
private:
    std::string placa;
    std::string modelo;
    int quilometragem;

public:
    Veiculo(std::string modelo, int quilometragem);
    ~Veiculo();
    void setPlaca(std::string placa);
    std::string getPlaca();
};

//fazer funções que saibam quais motoristas estão vinculados neste veículo!





#endif /* VEICULO_H_ */