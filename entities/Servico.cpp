#include <iostream>
#include <string>
using namespace std;

struct Servico {
    int codigo;
    string descricao;
    float valor_mao_de_obra;
};

struct ListaDeServicos {
    Servico servicos[100];
    int indiceDoUltimo;
};

void lerServico(Servico &s)
{
    cout << "Codigo do servico: ";
    cin >> s.codigo;

    cin.ignore();

    cout << "Descricao: ";
    getline(cin, s.descricao);

    cout << "Valor da mao de obra: ";
    cin >> s.valor_mao_de_obra;
}

int buscarServico(ListaDeServicos &lista, int codigo)
{
    int esquerda = 0;
    int direita = lista.indiceDoUltimo;

    while (esquerda <= direita)
    {
        int meio = esquerda + (direita - esquerda) / 2;

        if (lista.servicos[meio].codigo == codigo)
            return meio;

        if (lista.servicos[meio].codigo < codigo)
        {
            esquerda = meio + 1;
            continue;
        }

        direita = meio - 1;
    }

    return -1;
}

void cadastrarServico(ListaDeServicos &lista)
{
    Servico novoServico;
    lerServico(novoServico);
    lista.servicos[lista.indiceDoUltimo] = novoServico;
    lista.indiceDoUltimo++;
}
