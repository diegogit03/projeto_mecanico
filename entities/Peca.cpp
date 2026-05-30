#include <iostream>
#include <string>
using namespace std;

struct Peca {
    int codigo;
    string descricao;
    int quant_estoque;
    int estoque_minimo;
    int estoque_maximo;
    float preco_unitario;
};

struct ListaDePecas {
    Peca pecas[100];
    int indiceDaUltima;
};

void lerPeca(Peca &p)
{
    cout << "Codigo da peca: ";
    cin >> p.codigo;

    cin.ignore();

    cout << "Descricao: ";
    getline(cin, p.descricao);

    cout << "Quantidade em estoque: ";
    cin >> p.quant_estoque;

    cout << "Estoque minimo: ";
    cin >> p.estoque_minimo;

    cout << "Estoque maximo: ";
    cin >> p.estoque_maximo;

    cout << "Preco unitario: ";
    cin >> p.preco_unitario;
}

int buscarPeca(ListaDePecas &lista, int codigo)
{
    int esquerda = 0;
    int direita = lista.indiceDaUltima;

    while (esquerda <= direita)
    {
        int meio = esquerda + (direita - esquerda) / 2;

        if (lista.pecas[meio].codigo == codigo)
            return meio;

        if (lista.pecas[meio].codigo < codigo)
        {
            esquerda = meio + 1;
            continue;
        }

        direita = meio - 1;
    }

    return -1;
}

void cadastrarPeca(ListaDePecas &lista)
{
    Peca novaPeca;
    lerPeca(novaPeca);
    lista.pecas[lista.indiceDaUltima] = novaPeca;
    lista.indiceDaUltima++;
}
