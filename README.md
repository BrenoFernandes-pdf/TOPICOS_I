* Projeto 3: Frota de Veículos
 • Objetivo: Controlar veículos e motoristas em uma frota.
 • Classes: Veiculo, Motorista, Frota.
 • Modularização:
 • Veiculo.h / Veiculo.cpp → placa, modelo, quilometragem.
 • Motorista.h / Motorista.cpp → nome, CNH, veículos atribuídos.
 • Frota.h / Frota.cpp → gerencia lista de veículos e motoristas.
 • Construtores: inicializam veículo com modelo e quilometragem.
 • Destrutores: liberam memória de listas de veículos/motoristas.
 Exemplo de operação: adicionar veículo, associar motorista, registrar 
uso e atualizar quilometragem