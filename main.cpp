#include <iostream>
#include <string>

#include "entities/Cidade.cpp"
#include "entities/Servico.cpp"
#include "entities/Peca.cpp"
#include "entities/Cliente.cpp"
#include "entities/Veiculo.cpp"
#include "entities/Mecanico.cpp"
#include "entities/OrdemServico.cpp"
#include "seed.cpp"
#include "persistencia.cpp"

using namespace std;

void exibirMenu()
{
    cout << "\n========================================\n";
    cout << "    OFICINA MECANICA \n";
    cout << "========================================\n";
    cout << " 1. Cadastrar cidades\n";
    cout << " 2. Cadastrar servico\n";
    cout << " 3. Cadastrar peca\n";
    cout << " 4. Cadastrar cliente\n";
    cout << " 5. Cadastrar veiculo\n";
    cout << " 6. Cadastrar mecanico\n";
    cout << " 7. Cadastrar ordem de servico\n";
    cout << " 0. Sair\n";
    cout << "----------------------------------------\n";
    cout << "Opcao: ";
}

int main()
{
    DadosPersistidos dados = lerPersistencia();

    int opcao;
    do
    {
        exibirMenu();
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            cadastrarCidade(dados.cidades);
            persistirCidades(dados.cidades);
            break;
        case 2:
            cadastrarServico(dados.servicos);
            persistirServicos(dados.servicos);
            break;
        case 3:
            cadastrarPeca(dados.pecas);
            persistirPecas(dados.pecas);
            break;
        case 4:
            cadastrarCliente(dados.clientes, dados.cidades);
            persistirClientes(dados.clientes);
            break;
        case 5:
            cadastrarVeiculo(dados.veiculos, dados.clientes);
            persistirVeiculos(dados.veiculos);
            break;
        case 6:
            cadastrarMecanico(dados.mecanicos);
            persistirMecanicos(dados.mecanicos);
            break;
        case 7:
            cadastrarOrdemDeServico(
                dados.ordens,
                dados.veiculos,
                dados.clientes,
                dados.mecanicos,
                dados.servicos,
                dados.pecas
            );
            persistirOrdemServicos(dados.ordens);
            persistirPecas(dados.pecas);
            break;
        case 0:
            cout << "Saindo...\n";
            break;
        default:
            cout << "Opcao invalida!\n";
        }
    } while (opcao != 0);

    return 0;
}
