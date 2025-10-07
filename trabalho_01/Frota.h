#ifndef FROTA_H_
#define FROTA_H_

#include <string>
#include <map>
#include <memory>
#include "Veiculo.h"
#include "Motorista.h"


class Frota {
public:
    void addVeiculo(const std::string &modelo, const int quilometragem, const std::string &placa);
    void addMotorista(const std::string &nome, const std::string &cnh);
    void atribuirVeiculo(const std::string &placaVeiculo, const std::string &cnh );
    void liberarVeiculo(const std::string &placaVeiculo);
    void exibirStatusFrota() const;
    void registrarRetornoVeiculo(const std::string &placaVeiculo, const int novaKM);


private:
    //Professor, quando usamos unique_ptr nos ajuda em liberar automaticamente
    //a memória após o uso daquele objeto no HEAP, é um ponteiro que faz isso de forma
    //automática.
    std::map<std::string, std::unique_ptr<Veiculo>> mapaDeVeiculos;
    std::map<std::string, std::unique_ptr<Motorista>> mapaDeMotoristas;

    // O mapa de atribuições ainda usa ponteiros brutos para referenciar.
    std::map<Veiculo*, Motorista*> mapaDeAtribuicoes;
};




#endif /*FROTA_H_*/ 