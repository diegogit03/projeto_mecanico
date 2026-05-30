#include <iostream>
#include <string>
using namespace std;

struct Cliente {
    int codigo;
    string nome;
    string endereco;
    string telefone;
    int codigo_cidade;
};

struct ListaDeClientes {
    Cliente clientes[100];
    int indiceDoUltimo;
};

void lerCliente(Cliente &c)
{
    cout << "Nome: ";
    getline(cin, c.nome);

    cout << "Endereco: ";
    getline(cin, c.endereco);

    cout << "Telefone: ";
    getline(cin, c.telefone);

    cout << "Codigo da cidade: ";
    cin >> c.codigo_cidade;
}

int buscarCliente(ListaDeClientes &lista, int codigo)
{
    int esquerda = 0;
    int direita = lista.indiceDoUltimo;

    while (esquerda <= direita)
    {
        int meio = esquerda + (direita - esquerda) / 2;

        if (lista.clientes[meio].codigo == codigo)
            return meio;

        if (lista.clientes[meio].codigo < codigo)
        {
            esquerda = meio + 1;
            continue;
        }

        direita = meio - 1;
    }

    return -1;
}

void cadastrarCliente(ListaDeClientes &lista, ListaDeCidades &listaCidades)
{
    Cliente novoCliente;

    cout << "Codigo do cliente: ";
    cin >> novoCliente.codigo;

    if (buscarCliente(lista, novoCliente.codigo) != -1)
    {
        cout << "CODIGO JA EXISTE!";
        return;
    }

    cin.ignore();

    lerCliente(novoCliente);

    int indiceDaCidade = buscarCidade(listaCidades, novoCliente.codigo_cidade);

    if (indiceDaCidade == -1)
    {
        cout << "CIDADE NAO ENCONTRADA!\n";
        return;
    }

    Cidade cidadeAssociada = listaCidades.cidades[indiceDaCidade];

    cout << "CIDADE ASSOCIADA: \n";
    cout << "NOME: " << cidadeAssociada.nome << "\n";
    cout << "UF: " << cidadeAssociada.UF << "\n";

    lista.clientes[lista.indiceDoUltimo] = novoCliente;
    lista.indiceDoUltimo++;
}
