void seed(
    ListaDeCidades &listaCidades,
    ListaDeServicos &listaServicos,
    ListaDePecas &listaPecas,
    ListaDeClientes &listaClientes,
    ListaDeVeiculos &listaVeiculos,
    ListaDeMecanicos &listaMecanicos,
    ListaDeOrdemServicos &listaOrdens
)
{
    listaCidades.cidades[listaCidades.indiceDaUltima++] = {1, "Sao Paulo", "SP"};
    listaCidades.cidades[listaCidades.indiceDaUltima++] = {2, "Campinas", "SP"};
    listaCidades.cidades[listaCidades.indiceDaUltima++] = {3, "Rio de Janeiro", "RJ"};
    listaCidades.cidades[listaCidades.indiceDaUltima++] = {4, "Belo Horizonte", "MG"};
    listaCidades.cidades[listaCidades.indiceDaUltima++] = {5, "Curitiba", "PR"};

    listaServicos.servicos[listaServicos.indiceDoUltimo++] = {1, "Troca de Oleo", 80.0f};
    listaServicos.servicos[listaServicos.indiceDoUltimo++] = {2, "Alinhamento", 120.0f};
    listaServicos.servicos[listaServicos.indiceDoUltimo++] = {3, "Balanceamento", 60.0f};
    listaServicos.servicos[listaServicos.indiceDoUltimo++] = {4, "Revisao Completa", 350.0f};
    listaServicos.servicos[listaServicos.indiceDoUltimo++] = {5, "Troca de Pastilhas de Freio", 150.0f};
    listaServicos.servicos[listaServicos.indiceDoUltimo++] = {6, "Troca de Pneus", 200.0f};

    listaPecas.pecas[listaPecas.indiceDaUltima++] = {1, "Oleo do Motor 5W30", 20, 5, 50, 35.90f};
    listaPecas.pecas[listaPecas.indiceDaUltima++] = {2, "Filtro de Oleo", 15, 3, 30, 25.50f};
    listaPecas.pecas[listaPecas.indiceDaUltima++] = {3, "Pastilha de Freio", 10, 2, 20, 89.90f};
    listaPecas.pecas[listaPecas.indiceDaUltima++] = {4, "Pneu 175/65 R14", 8, 4, 30, 299.90f};
    listaPecas.pecas[listaPecas.indiceDaUltima++] = {5, "Amortecedor", 6, 2, 15, 189.90f};
    listaPecas.pecas[listaPecas.indiceDaUltima++] = {6, "Correia Dentada", 5, 2, 10, 129.90f};

    listaClientes.clientes[listaClientes.indiceDoUltimo++] = {1, "Joao Silva", "Rua A, 123", "11999990001", 1};
    listaClientes.clientes[listaClientes.indiceDoUltimo++] = {2, "Maria Santos", "Rua B, 456", "11988880002", 2};
    listaClientes.clientes[listaClientes.indiceDoUltimo++] = {3, "Carlos Pereira", "Rua C, 789", "21977770003", 3};
    listaClientes.clientes[listaClientes.indiceDoUltimo++] = {4, "Ana Oliveira", "Rua D, 321", "31966660004", 4};
    listaClientes.clientes[listaClientes.indiceDoUltimo++] = {5, "Pedro Costa", "Rua E, 654", "41955550005", 5};
    listaClientes.clientes[listaClientes.indiceDoUltimo++] = {6, "Carla Souza", "Rua F, 987", "11944440006", 1};

    listaVeiculos.veiculos[listaVeiculos.indiceDoUltimo].placa = "ABC1D23";
    listaVeiculos.veiculos[listaVeiculos.indiceDoUltimo].modelo = "Gol";
    listaVeiculos.veiculos[listaVeiculos.indiceDoUltimo].marca = "Volkswagen";
    listaVeiculos.veiculos[listaVeiculos.indiceDoUltimo].ano = 2018;
    listaVeiculos.veiculos[listaVeiculos.indiceDoUltimo].codigo_cliente = 1;
    listaVeiculos.indiceDoUltimo++;

    listaVeiculos.veiculos[listaVeiculos.indiceDoUltimo].placa = "DEF2G34";
    listaVeiculos.veiculos[listaVeiculos.indiceDoUltimo].modelo = "Onix";
    listaVeiculos.veiculos[listaVeiculos.indiceDoUltimo].marca = "Chevrolet";
    listaVeiculos.veiculos[listaVeiculos.indiceDoUltimo].ano = 2020;
    listaVeiculos.veiculos[listaVeiculos.indiceDoUltimo].codigo_cliente = 2;
    listaVeiculos.indiceDoUltimo++;

    listaVeiculos.veiculos[listaVeiculos.indiceDoUltimo].placa = "GHI3H45";
    listaVeiculos.veiculos[listaVeiculos.indiceDoUltimo].modelo = "Civic";
    listaVeiculos.veiculos[listaVeiculos.indiceDoUltimo].marca = "Honda";
    listaVeiculos.veiculos[listaVeiculos.indiceDoUltimo].ano = 2019;
    listaVeiculos.veiculos[listaVeiculos.indiceDoUltimo].codigo_cliente = 3;
    listaVeiculos.indiceDoUltimo++;

    listaVeiculos.veiculos[listaVeiculos.indiceDoUltimo].placa = "JKL4J56";
    listaVeiculos.veiculos[listaVeiculos.indiceDoUltimo].modelo = "Corolla";
    listaVeiculos.veiculos[listaVeiculos.indiceDoUltimo].marca = "Toyota";
    listaVeiculos.veiculos[listaVeiculos.indiceDoUltimo].ano = 2021;
    listaVeiculos.veiculos[listaVeiculos.indiceDoUltimo].codigo_cliente = 4;
    listaVeiculos.indiceDoUltimo++;

    listaVeiculos.veiculos[listaVeiculos.indiceDoUltimo].placa = "MNO5K67";
    listaVeiculos.veiculos[listaVeiculos.indiceDoUltimo].modelo = "Fox";
    listaVeiculos.veiculos[listaVeiculos.indiceDoUltimo].marca = "Volkswagen";
    listaVeiculos.veiculos[listaVeiculos.indiceDoUltimo].ano = 2017;
    listaVeiculos.veiculos[listaVeiculos.indiceDoUltimo].codigo_cliente = 5;
    listaVeiculos.indiceDoUltimo++;

    listaMecanicos.mecanicos[listaMecanicos.indiceDoUltimo].codigo = 1;
    listaMecanicos.mecanicos[listaMecanicos.indiceDoUltimo].nome = "Roberto Lima";
    listaMecanicos.mecanicos[listaMecanicos.indiceDoUltimo].especialidade = "Motor";
    listaMecanicos.mecanicos[listaMecanicos.indiceDoUltimo].telefone = "11911110001";
    listaMecanicos.indiceDoUltimo++;

    listaMecanicos.mecanicos[listaMecanicos.indiceDoUltimo].codigo = 2;
    listaMecanicos.mecanicos[listaMecanicos.indiceDoUltimo].nome = "Fernando Santos";
    listaMecanicos.mecanicos[listaMecanicos.indiceDoUltimo].especialidade = "Suspensao";
    listaMecanicos.mecanicos[listaMecanicos.indiceDoUltimo].telefone = "11922220002";
    listaMecanicos.indiceDoUltimo++;

    listaMecanicos.mecanicos[listaMecanicos.indiceDoUltimo].codigo = 3;
    listaMecanicos.mecanicos[listaMecanicos.indiceDoUltimo].nome = "Paulo Oliveira";
    listaMecanicos.mecanicos[listaMecanicos.indiceDoUltimo].especialidade = "Freios";
    listaMecanicos.mecanicos[listaMecanicos.indiceDoUltimo].telefone = "11933330003";
    listaMecanicos.indiceDoUltimo++;

    listaMecanicos.mecanicos[listaMecanicos.indiceDoUltimo].codigo = 4;
    listaMecanicos.mecanicos[listaMecanicos.indiceDoUltimo].nome = "Marcos Costa";
    listaMecanicos.mecanicos[listaMecanicos.indiceDoUltimo].especialidade = "Eletrica";
    listaMecanicos.mecanicos[listaMecanicos.indiceDoUltimo].telefone = "11944440004";
    listaMecanicos.indiceDoUltimo++;

    listaMecanicos.mecanicos[listaMecanicos.indiceDoUltimo].codigo = 5;
    listaMecanicos.mecanicos[listaMecanicos.indiceDoUltimo].nome = "Ricardo Almeida";
    listaMecanicos.mecanicos[listaMecanicos.indiceDoUltimo].especialidade = "Funilaria";
    listaMecanicos.mecanicos[listaMecanicos.indiceDoUltimo].telefone = "11955550005";
    listaMecanicos.indiceDoUltimo++;

    listaOrdens.ordens[listaOrdens.indiceDaUltima].codigo = 1;
    listaOrdens.ordens[listaOrdens.indiceDaUltima].placa_veiculo = "ABC1D23";
    listaOrdens.ordens[listaOrdens.indiceDaUltima].codigo_mecanico = 1;
    listaOrdens.ordens[listaOrdens.indiceDaUltima].data = "15/05/2026";
    listaOrdens.ordens[listaOrdens.indiceDaUltima].codigo_servico = 1;
    listaOrdens.ordens[listaOrdens.indiceDaUltima].codigo_peca = 1;
    listaOrdens.ordens[listaOrdens.indiceDaUltima].quantidade_peca = 2;
    listaPecas.pecas[0].quant_estoque -= 2;
    listaOrdens.indiceDaUltima++;

    listaOrdens.ordens[listaOrdens.indiceDaUltima].codigo = 2;
    listaOrdens.ordens[listaOrdens.indiceDaUltima].placa_veiculo = "DEF2G34";
    listaOrdens.ordens[listaOrdens.indiceDaUltima].codigo_mecanico = 3;
    listaOrdens.ordens[listaOrdens.indiceDaUltima].data = "16/05/2026";
    listaOrdens.ordens[listaOrdens.indiceDaUltima].codigo_servico = 5;
    listaOrdens.ordens[listaOrdens.indiceDaUltima].codigo_peca = 3;
    listaOrdens.ordens[listaOrdens.indiceDaUltima].quantidade_peca = 1;
    listaPecas.pecas[2].quant_estoque -= 1;
    listaOrdens.indiceDaUltima++;

    listaOrdens.ordens[listaOrdens.indiceDaUltima].codigo = 3;
    listaOrdens.ordens[listaOrdens.indiceDaUltima].placa_veiculo = "GHI3H45";
    listaOrdens.ordens[listaOrdens.indiceDaUltima].codigo_mecanico = 2;
    listaOrdens.ordens[listaOrdens.indiceDaUltima].data = "17/05/2026";
    listaOrdens.ordens[listaOrdens.indiceDaUltima].codigo_servico = 2;
    listaOrdens.ordens[listaOrdens.indiceDaUltima].codigo_peca = 5;
    listaOrdens.ordens[listaOrdens.indiceDaUltima].quantidade_peca = 2;
    listaPecas.pecas[4].quant_estoque -= 2;
    listaOrdens.indiceDaUltima++;

    listaOrdens.ordens[listaOrdens.indiceDaUltima].codigo = 4;
    listaOrdens.ordens[listaOrdens.indiceDaUltima].placa_veiculo = "JKL4J56";
    listaOrdens.ordens[listaOrdens.indiceDaUltima].codigo_mecanico = 4;
    listaOrdens.ordens[listaOrdens.indiceDaUltima].data = "18/05/2026";
    listaOrdens.ordens[listaOrdens.indiceDaUltima].codigo_servico = 3;
    listaOrdens.ordens[listaOrdens.indiceDaUltima].codigo_peca = 4;
    listaOrdens.ordens[listaOrdens.indiceDaUltima].quantidade_peca = 4;
    listaPecas.pecas[3].quant_estoque -= 4;
    listaOrdens.indiceDaUltima++;

    listaOrdens.ordens[listaOrdens.indiceDaUltima].codigo = 5;
    listaOrdens.ordens[listaOrdens.indiceDaUltima].placa_veiculo = "MNO5K67";
    listaOrdens.ordens[listaOrdens.indiceDaUltima].codigo_mecanico = 5;
    listaOrdens.ordens[listaOrdens.indiceDaUltima].data = "19/05/2026";
    listaOrdens.ordens[listaOrdens.indiceDaUltima].codigo_servico = 4;
    listaOrdens.ordens[listaOrdens.indiceDaUltima].codigo_peca = 6;
    listaOrdens.ordens[listaOrdens.indiceDaUltima].quantidade_peca = 1;
    listaPecas.pecas[5].quant_estoque -= 1;
    listaOrdens.indiceDaUltima++;
}
