#include <iostream>
#include <string>
using namespace std;

struct OrdemServico {
    int codigo;
    string placa_veiculo;
    int codigo_mecanico;
    string data;
    int codigo_servico;
    int codigo_peca;
    int quantidade_peca;
};

struct ListaDeOrdemServicos {
    OrdemServico ordens[100];
    int indiceDaUltima;
};

int buscarOrdemServico(ListaDeOrdemServicos &lista, int codigo)
{
    int esquerda = 0;
    int direita = lista.indiceDaUltima;

    while (esquerda <= direita)
    {
        int meio = esquerda + (direita - esquerda) / 2;

        if (lista.ordens[meio].codigo == codigo)
            return meio;

        if (lista.ordens[meio].codigo < codigo)
        {
            esquerda = meio + 1;
            continue;
        }

        direita = meio - 1;
    }

    return -1;
}

void cadastrarOrdemDeServico(
    ListaDeOrdemServicos &lista,
    ListaDeVeiculos &listaVeiculos,
    ListaDeClientes &listaClientes,
    ListaDeMecanicos &listaMecanicos,
    ListaDeServicos &listaServicos,
    ListaDePecas &listaPecas
)
{
    OrdemServico novaOrdem;

    cout << "Codigo da ordem de servico: ";
    cin >> novaOrdem.codigo;

    if (buscarOrdemServico(lista, novaOrdem.codigo) != -1)
    {
        cout << "CODIGO JA EXISTE!";
        return;
    }

    cin.ignore();

    cout << "Placa do veiculo: ";
    getline(cin, novaOrdem.placa_veiculo);

    int indiceDoVeiculo = buscarVeiculo(listaVeiculos, novaOrdem.placa_veiculo);
    if (indiceDoVeiculo == -1)
    {
        cout << "PLACA NAO ENCONTRADA!";
        return;
    }

    Veiculo veiculoAssociado = listaVeiculos.veiculos[indiceDoVeiculo];
    int indiceDoCliente = buscarCliente(listaClientes, veiculoAssociado.codigo_cliente);
    if (indiceDoCliente == -1)
    {
        cout << "CLIENTE NAO ENCONTRADO!";
        return;
    }

    Cliente clienteAssociado = listaClientes.clientes[indiceDoCliente];

    cout << "MODELO: " << veiculoAssociado.modelo << "\n";
    cout << "CLIENTE: " << clienteAssociado.nome << "\n";

    cout << "Codigo do mecanico: ";
    cin >> novaOrdem.codigo_mecanico;

    int indiceDoMecanico = buscarMecanico(listaMecanicos, novaOrdem.codigo_mecanico);
    if (indiceDoMecanico == -1)
    {
        cout << "MECANICO NAO ENCONTRADO!";
        return;
    }

    Mecanico mecanicoAssociado = listaMecanicos.mecanicos[indiceDoMecanico];

    cout << "NOME: " << mecanicoAssociado.nome << "\n";
    cout << "ESPECIALIDADE: " << mecanicoAssociado.especialidade << "\n";

    cin.ignore();

    cout << "Data: ";
    getline(cin, novaOrdem.data);

    cout << "Codigo do servico: ";
    cin >> novaOrdem.codigo_servico;

    int indiceDoServico = buscarServico(listaServicos, novaOrdem.codigo_servico);
    if (indiceDoServico == -1)
    {
        cout << "SERVICO NAO ENCONTRADO!";
        return;
    }

    Servico servicoAssociado = listaServicos.servicos[indiceDoServico];

    cout << "DESCRICAO: " << servicoAssociado.descricao << "\n";
    cout << "VALOR MAO DE OBRA: " << servicoAssociado.valor_mao_de_obra << "\n";

    cout << "Codigo da peca: ";
    cin >> novaOrdem.codigo_peca;

    int indiceDaPeca = buscarPeca(listaPecas, novaOrdem.codigo_peca);
    if (indiceDaPeca == -1)
    {
        cout << "PECA NAO ENCONTRADA!";
        return;
    }

    Peca pecaAssociada = listaPecas.pecas[indiceDaPeca];

    cout << "DESCRICAO: " << pecaAssociada.descricao << "\n";

    cout << "Quantidade de pecas: ";
    cin >> novaOrdem.quantidade_peca;

    if (novaOrdem.quantidade_peca > pecaAssociada.quant_estoque)
    {
        cout << "ESTOQUE INSUFICIENTE! ESTOQUE ATUAL: " << pecaAssociada.quant_estoque;
        return;
    }

    listaPecas.pecas[indiceDaPeca].quant_estoque -= novaOrdem.quantidade_peca;

    lista.ordens[lista.indiceDaUltima] = novaOrdem;
    lista.indiceDaUltima++;
}
