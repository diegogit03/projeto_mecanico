#include <iostream>
#include <string>
using namespace std;

struct Cidade {
    int codigo;
    string nome;
    string UF;
};

struct ListaDeCidades {
    Cidade cidades[100];
    int indiceDaUltima;
};

void lerCidade(Cidade &c)
{
    cout << "Codigo da cidade: ";
    cin >> c.codigo;

    cin.ignore();

    cout << "Nome da cidade: ";
    getline(cin, c.nome);

    cout << "UF: ";
    getline(cin, c.UF);
}

int buscarCidade(ListaDeCidades &lista, int codigo)
{
    int esquerda = 0;
    int direita = lista.indiceDaUltima;

    while (esquerda <= direita)
    {
        int meio = esquerda + (direita - esquerda) / 2;

        if (lista.cidades[meio].codigo == codigo)
            return meio;

        if (lista.cidades[meio].codigo < codigo)
        {
            esquerda = meio + 1;
            continue;
        }

        direita = meio - 1;
    }

    return -1;
}

void cadastrarCidade(ListaDeCidades &lista)
{
    Cidade novaCidade;
    lerCidade(novaCidade);
    lista.cidades[lista.indiceDaUltima] = novaCidade;
    lista.indiceDaUltima++;
}
