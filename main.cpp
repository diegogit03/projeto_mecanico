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
    cout << " 0. Sair\n";
    cout << "----------------------------------------\n";
    cout << "Opcao: ";
}

int main()
{
    ListaDeCidades listaCidades = {};
    ListaDeServicos listaServicos = {};
    ListaDePecas listaPecas = {};
    ListaDeClientes listaClientes = {};
    ListaDeVeiculos listaVeiculos = {};
    ListaDeMecanicos listaMecanicos = {};
    ListaDeOrdemServicos listaOrdens = {};

    seed(listaCidades, listaServicos, listaPecas, listaClientes, listaVeiculos, listaMecanicos, listaOrdens);

    int opcao;
    do
    {
        exibirMenu();
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            cadastrarCidade(listaCidades);
            break;
        case 2:
            cadastrarServico(listaServicos);
            break;
        case 3:
            cadastrarPeca(listaPecas);
            break;
        case 4:
            cadastrarCliente(listaClientes, listaCidades);
            break;
        case 5:
            cadastrarVeiculo(listaVeiculos, listaClientes);
            break;
        case 6:
            cadastrarMecanico(listaMecanicos);
            break;
        case 7:
            cadastrarOrdemDeServico(
                listaOrdens,
                listaVeiculos,
                listaClientes,
                listaMecanicos,
                listaServicos,
                listaPecas
            );
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
