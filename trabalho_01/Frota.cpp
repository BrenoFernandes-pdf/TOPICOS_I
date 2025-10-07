#include "Frota.h"
#include <iostream>
#include <memory> // para usarmos make_unique

void Frota::addVeiculo(const std::string &modelo, const int quilometragem, const std::string &placa){
    auto NovoVeiculo = std::make_unique<Veiculo>(modelo, quilometragem, placa);
    //professor, como aqui ainda é o unique_ptr(ele não pode ser copiado para outra variável além da Novo Veículo)
    //Nesse sentido, devemos fazer um transferência de posse com o std::move para o nosso MapaDeVeiculos.
    mapaDeVeiculos[placa] = std::move(NovoVeiculo);
    std::cout << "INFO: Veiculo modelo " << modelo << ", km rodados: " << quilometragem << " KM e placa " << placa << " adicionado.\n";

}
void Frota::addMotorista(const std::string &nome, const std::string &cnh){
    auto novoMotorista = std::make_unique<Motorista>(nome, cnh);
    mapaDeMotoristas[nome] = std::move(novoMotorista);
    std::cout << "INFO: Motorista " << nome << " adicionado e mapeado com seu número da CNH: " << cnh << std::endl;

}

void Frota::atribuirVeiculo(const std::string &placaVeiculo,  const std::string &nome){
    auto itVeiculo = mapaDeVeiculos.find(placaVeiculo);
    auto itMotorista = mapaDeMotoristas.find(nome);

    if(itVeiculo == mapaDeVeiculos.end()){
        std::cout << "ERRO: Veiculo " << placaVeiculo << " não encontrado!\n";
        return;
    }
    if(itMotorista == mapaDeMotoristas.end()){
        std::cout << "ERRO: Motorista " << nome << " não encontrado!\n";
        return;
    }

    // .get() extrai o ponteiro bruto do unique_ptr
    Veiculo* veiculoPtr = itVeiculo->second.get();
    Motorista* motoristaPtr = itMotorista->second.get();

    if(mapaDeAtribuicoes.count(veiculoPtr)){
        std::cout << "ERRO: Veiculo " << placaVeiculo << " ja esta atribuido!\n";
        return;
    }

    mapaDeAtribuicoes[veiculoPtr] = motoristaPtr;
    motoristaPtr->addVeiculoAtribuido(veiculoPtr); //Chama o método privado do amigo! (classe Motorista tem friend class Frota)

     std::cout << "INFO: Veiculo modelo " << veiculoPtr->getModelo() << veiculoPtr->getKM() << " KM e placa " << veiculoPtr->getPlaca() <<
      " atrubuido a " << motoristaPtr->getNome() << " com CNH: " << motoristaPtr->getCNH() <<"\n";
}

void Frota::liberarVeiculo(const std::string &placaVeiculo){
    auto itVeiculo = mapaDeVeiculos.find(placaVeiculo);
    if(itVeiculo == mapaDeVeiculos.end()){
        std::cout << "ERRO: Veiculo " << placaVeiculo << " nao encontrado!\n";
        return;
    }

    Veiculo* veiculoPtr = itVeiculo->second.get();

    if(mapaDeAtribuicoes.count(veiculoPtr)) {
        Motorista* motoristaPtr = mapaDeAtribuicoes[veiculoPtr];
        motoristaPtr->rmVeiculoAtribuido(veiculoPtr);
        mapaDeAtribuicoes.erase(veiculoPtr);
        std::cout << "INFO: AGORA DISPONÍVEL: Veiculo modelo " << veiculoPtr->getModelo() << veiculoPtr->getKM() << " KM e placa " << veiculoPtr->getPlaca() <<std::endl;
    } else {
        std::cout << "INFO: Veiculo " << placaVeiculo << " ja estava livre.\n";
    }
}

void Frota::exibirStatusFrota() const {
    std::cout << "\n================ STATUS DA FROTA (" << "06 de Outubro de 2025" << ") ================\n";
    std::cout << "\n[VEICULOS TOTAIS: " << mapaDeVeiculos.size() << "]\n";
    //para iterar em um mapa, iteramos sobre pares de chave-valor
    for(const auto& par: mapaDeVeiculos){
        const std::string& placa = par.first;
        const std::unique_ptr<Veiculo>& veiculoPtr = par.second;
        std::cout << "  - Placa: " << placa << ", Modelo: " << veiculoPtr->getModelo() << " km rodados: " << veiculoPtr->getKM() << "km\n";
    }

    std::cout << "\n[MOTORISTAS: " << mapaDeMotoristas.size() << "]\n";
    for(const auto& par: mapaDeMotoristas){
        const std::string numCNH = par.first;
        const std::unique_ptr<Motorista>& motoristaPtr = par.second;
        std::cout << "  - Nome: " << motoristaPtr->getNome() << ", CNH: " << motoristaPtr->getCNH() << "\n";
        motoristaPtr->listarVeiculosAtribuidos();
        std::cout << "\n=======================================================================\n" << std::endl;
    }

    }

    void Frota::registrarRetornoVeiculo(const std::string &placaVeiculo, const int novaKM){
        auto itVeiculo = mapaDeVeiculos.find(placaVeiculo);
        if(itVeiculo == mapaDeVeiculos.end()){
            std::cout << "ERRO: Veiculo " << placaVeiculo << "nao encontrado!\n";
            return;
        }

        Veiculo* veiculoPtr = itVeiculo->second.get();
        if(novaKM >= veiculoPtr->getKM()){
            veiculoPtr->setQuilometragem(novaKM);
            std::cout << "INFO: Quilometragem do veiculo " << placaVeiculo << " atualizada para " << novaKM << "km.\n";
        }
        else{
            std::cout << "ERRO: Nova quilometragem menor do que a atual! Nova:" << novaKM << "antiga: "<< veiculoPtr->getKM() <<"\n";
        }
        
    }