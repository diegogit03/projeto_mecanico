#include <iostream>
#include <string>
using namespace std;

struct Mecanico {
    int codigo;
    string nome;
    string especialidade;
    string telefone;
};

struct ListaDeMecanicos {
    Mecanico mecanicos[100];
    int indiceDoUltimo;
};

void lerMecanico(Mecanico &m)
{
    cout << "Nome: ";
    getline(cin, m.nome);

    cout << "Especialidade: ";
    getline(cin, m.especialidade);

    cout << "Telefone: ";
    getline(cin, m.telefone);
}

int buscarMecanico(ListaDeMecanicos &lista, int codigo)
{
    int esquerda = 0;
    int direita = lista.indiceDoUltimo;

    while (esquerda <= direita)
    {
        int meio = esquerda + (direita - esquerda) / 2;

        if (lista.mecanicos[meio].codigo == codigo)
            return meio;

        if (lista.mecanicos[meio].codigo < codigo)
        {
            esquerda = meio + 1;
            continue;
        }

        direita = meio - 1;
    }

    return -1;
}

void cadastrarMecanico(ListaDeMecanicos &lista)
{
    Mecanico novoMecanico;

    cout << "Codigo do mecanico: ";
    cin >> novoMecanico.codigo;

    if (buscarMecanico(lista, novoMecanico.codigo) != -1)
    {
        cout << "CODIGO JA EXISTE!";
        return;
    }

    cin.ignore();

    lerMecanico(novoMecanico);

    lista.mecanicos[lista.indiceDoUltimo] = novoMecanico;
    lista.indiceDoUltimo++;
}
