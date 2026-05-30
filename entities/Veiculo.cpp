#include <iostream>
#include <string>
using namespace std;

struct Veiculo {
    string placa;
    string modelo;
    string marca;
    int ano;
    int codigo_cliente;
};

struct ListaDeVeiculos {
    Veiculo veiculos[100];
    int indiceDoUltimo;
};

void lerVeiculo(Veiculo &v)
{
    cout << "Modelo: ";
    getline(cin, v.modelo);

    cout << "Marca: ";
    getline(cin, v.marca);

    cout << "Ano: ";
    cin >> v.ano;

    cout << "Codigo do cliente: ";
    cin >> v.codigo_cliente;
}

int buscarVeiculo(ListaDeVeiculos &lista, string placa)
{
    for (int i = 0; i < lista.indiceDoUltimo; i++)
    {
        if (lista.veiculos[i].placa != placa)
            continue;

        return i;
    }

    return -1;
}

void cadastrarVeiculo(ListaDeVeiculos &lista, ListaDeClientes &listaClientes)
{
    Veiculo novoVeiculo;

    cin.ignore();

    cout << "Placa: ";
    getline(cin, novoVeiculo.placa);

    if (buscarVeiculo(lista, novoVeiculo.placa) != -1)
    {
        cout << "PLACA JA EXISTE!";
        return;
    }

    lerVeiculo(novoVeiculo);

    int indiceDoCliente = buscarCliente(listaClientes, novoVeiculo.codigo_cliente);

    if (indiceDoCliente == -1)
    {
        cout << "CLIENTE NAO ENCONTRADO!\n";
        return;
    }

    Cliente clienteAssociado = listaClientes.clientes[indiceDoCliente];

    cout << "CLIENTE ASSOCIADO: \n";
    cout << "NOME: " << clienteAssociado.nome << "\n";

    lista.veiculos[lista.indiceDoUltimo] = novoVeiculo;
    lista.indiceDoUltimo++;
}
