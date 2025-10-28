/*  Trabalho01 - Disciplina TI0160 - TÓPICOS E PROJETOS EM ENGENHARIA DE COMPUTAÇÃO I (2025.2 - T02)
    Prof. Doutor Alexandre Coelho
    @author Breno Fernandes - Curso Engenharia de Computação

    @Projeto 3: Frota de Veículos
    @Objetivo: Controlar veículos e motoristas em uma frota.
*/


#include<iostream>
#include "Frota.h"


int main(){
    std::cout << ">> Iniciando sistema de gerneciamento de frota...\n\n";

    Frota minhaFrota;
    std::cout << "--- FASE 1: Montando a frota e contratando pessoal ---\n";
    minhaFrota.addVeiculo("HONDA CIVIC TYPE R", 1000, "ABC-1234");
    minhaFrota.addVeiculo("VOLVO EX90", 4321, "BRE-0000");
    minhaFrota.addVeiculo("Fusca 1300 GL 1982", 0, "FUS-7777");
    minhaFrota.addVeiculo("1969 Ford Mustang Mach 1", 7000, "MUS-1111");
    minhaFrota.addMotorista("Breno Fernandes","123456789-B");
    minhaFrota.addMotorista("Alexandre Rabbit", "987654321-E");
    minhaFrota.addMotorista("Max Verstappen", "112233445-F");

    // Estado inicial da Frota
    minhaFrota.exibirStatusFrota();

     // ===================================================================
    std::cout << "\n--- FASE 2: Iniciando as operacoes do dia ---\n";
    // ===================================================================
    minhaFrota.atribuirVeiculo("BRE-0000", "Breno Fernandes");
    minhaFrota.atribuirVeiculo("FUS-7777", "Max Verstappen");
    minhaFrota.atribuirVeiculo("MUS-1111", "Alexandre Rabbit");

    // Testando as regras de negócio e validações
    std::cout << "\n--- Tentativas com erro (esperado) ---\n";
    minhaFrota.atribuirVeiculo("FUS-7777", "Carlos");  // Erro: Veículo já está com Max Verstappen
    minhaFrota.atribuirVeiculo("XYZ-0000", "Alexandre Rabbit");  // Erro: Veículo não existe
    minhaFrota.atribuirVeiculo("ABC-1234", "Predo");    // Erro: Motorista não existe
    std::cout << "-------------------------------------\n";
    
    // Mostra o estado da frota após as primeiras atribuições
    minhaFrota.exibirStatusFrota();


    // ===================================================================
    std::cout << "\n--- FASE 3: Fim do turno ---\n";
    // ===================================================================
    std::cout << "\nMax Verstappen retorna o veiculo...\n";
    minhaFrota.liberarVeiculo("FUS-7777");
    //atualiza o KM do véiculo após o seu retorno
    minhaFrota.registrarRetornoVeiculo("FUS-7777", 1234);
    //erro proposital em tentar dimunuir o km de um Veículo 6000 menor do que o atual 7000
    minhaFrota.registrarRetornoVeiculo("MUS-1111", 6000);
    //agora validando:
    minhaFrota.registrarRetornoVeiculo("MUS-1111", 89763);
    
    // Tentando liberar um veículo que já está livre
    minhaFrota.liberarVeiculo("ABC-1234");

    // Mostra o estado final da frota
    minhaFrota.exibirStatusFrota();


    std::cout << "\n>>> Fim do escopo da main. O destrutor da 'minhaFrota' sera chamado agora,\n";
    std::cout << "    limpando toda a memoria alocada automaticamente (usando o make_unique).\n";
    
    // Ao chegar aqui, 'minhaFrota' é destruída. O destrutor chama o destrutor
    // do 'mapaDeVeiculos', que por sua vez chama o destrutor de cada 'unique_ptr',
    // que finalmente chama 'delete' em cada Veiculo/Motorista.
    return 0;
    
}
