/*
    @brief Header para o arquivo Veiculo.cpp
    @autor Breno Fernandes

*/

#ifndef VEICULO_H_
#define VEICULO_H_

#include <string>

class Veiculo
{
private:
    std::string placa;
    std::string modelo;
    int quilometragem;

public:
    Veiculo(const std::string &modelo, int &quilometragem);
    ~Veiculo();
    void setQuilometragem(int &quilometragem);
    void setPlaca(std::string &placa);
    std::string getPlaca() const;
    std::string getModelo() const;
    std::string getQuilometragem() const;
};

#endif /* VEICULO_H_ */