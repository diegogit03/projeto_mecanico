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
    cout << " 8. Consultar peca\n";
    cout << " 9. Relatorio de pecas abaixo do estoque minimo\n";
    cout << " 0. Sair\n";
    cout << "----------------------------------------\n";
    cout << "Opcao: ";
}

int main()
{
    ListaDeCidades cidades = {};
    ListaDeServicos servicos = {};
    ListaDePecas pecas = {};
    ListaDeClientes clientes = {};
    ListaDeVeiculos veiculos = {};
    ListaDeMecanicos mecanicos = {};
    ListaDeOrdemServicos ordens = {};
    seed(cidades, servicos, pecas, clientes, veiculos, mecanicos, ordens);

    int opcao;
    do
    {
        exibirMenu();
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            cadastrarCidade(cidades);
            break;
        case 2:
            cadastrarServico(servicos);
            break;
        case 3:
            cadastrarPeca(pecas);
            break;
        case 4:
            cadastrarCliente(clientes, cidades);
            break;
        case 5:
            cadastrarVeiculo(veiculos, clientes);
            break;
        case 6:
            cadastrarMecanico(mecanicos);
            break;
        case 7:
            cadastrarOrdemDeServico(
                ordens,
                veiculos,
                clientes,
                mecanicos,
                servicos,
                pecas
            );
            break;
        case 8:
            consultarPeca(pecas);
            break;
        case 9:
            relatorioPecasAbaixoDoEstoqueMinimo(pecas);
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
