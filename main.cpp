#include <iostream>
#include <string>

using namespace std;

class Cidade
{
public:
    int codigo;
    string nome;
    string UF;

public:
    Cidade()
    {
        codigo = 0;
        nome = "";
        UF = "";
    }

    Cidade(int c, string n, string uf)
    {
        codigo = c;
        nome = n;
        UF = uf;
    }

    void ler()
    {
        cout << "Codigo da cidade: ";
        cin >> codigo;

        cin.ignore();

        cout << "Nome da cidade: ";
        getline(cin, nome);

        cout << "UF: ";
        getline(cin, UF);
    }
};

class Servico
{
public:
    int codigo;
    string descricao;
    float valor_mao_de_obra;

public:
    Servico()
    {
        codigo = 0;
        descricao = "";
        valor_mao_de_obra = 0;
    }

    Servico(int c, string d, float v)
    {
        codigo = c;
        descricao = d;
        valor_mao_de_obra = v;
    }

    void ler()
    {
        cout << "Codigo do servico: ";
        cin >> codigo;

        cin.ignore();

        cout << "Descricao: ";
        getline(cin, descricao);

        cout << "Valor da mao de obra: ";
        cin >> valor_mao_de_obra;
    }
};

class Peca
{
public:
    int codigo;
    string descricao;
    int quant_estoque;
    int estoque_minimo;
    int estoque_maximo;
    float preco_unitario;

public:
    Peca()
    {
        codigo = 0;
        descricao = "";
        quant_estoque = 0;
        estoque_minimo = 0;
        estoque_maximo = 0;
        preco_unitario = 0;
    }

    Peca(int c, string d, int q, int emin, int emax, float p)
    {
        codigo = c;
        descricao = d;
        quant_estoque = q;
        estoque_minimo = emin;
        estoque_maximo = emax;
        preco_unitario = p;
    }

    void ler()
    {
        cout << "Codigo da peca: ";
        cin >> codigo;

        cin.ignore();

        cout << "Descricao: ";
        getline(cin, descricao);

        cout << "Quantidade em estoque: ";
        cin >> quant_estoque;

        cout << "Estoque minimo: ";
        cin >> estoque_minimo;

        cout << "Estoque maximo: ";
        cin >> estoque_maximo;

        cout << "Preco unitario: ";
        cin >> preco_unitario;
    }
};

class Cliente
{
public:
    int codigo;
    string nome;
    string endereco;
    string telefone;
    int codigo_cidade;

public:
    Cliente()
    {
        codigo = 0;
        nome = "";
        endereco = "";
        telefone = "";
        codigo_cidade = 0;
    }

    Cliente(int c, string n, string e, string t, int cc)
    {
        codigo = c;
        nome = n;
        endereco = e;
        telefone = t;
        codigo_cidade = cc;
    }
};

struct Veiculo
{
    string placa;
    string modelo;
    string marca;
    int ano;
    int codigo_cliente;
};

struct Mecanico
{
    int codigo;
    string nome;
    string especialidade;
    string telefone;
};

struct OrdemServico
{
    int codigo;
    string placa_veiculo;
    int codigo_mecanico;
    string data;
    int codigo_servico;
    int codigo_peca;
    int quantidade_peca;
};

Cidade cidades[100];
int indiceDaUltimaCidade = 0;

Servico servicos[100];
int indiceDoUltimoServico = 0;

Peca pecas[100];
int indiceDaUltimaPeca = 0;

Cliente clientes[100];
int indiceDoUltimoCliente = 0;

Veiculo veiculos[100];
int indiceDoUltimoVeiculo = 0;

Mecanico mecanicos[100];
int indiceDoUltimoMecanico = 0;

OrdemServico ordensDeServico[100];
int indiceDaUltimaOrdemDeServico = 0;

int buscarCidade(int codigo)
{
    int esquerda = 0;
    int direita = indiceDaUltimaCidade;

    while (esquerda <= direita)
    {
        int meio = esquerda + (direita - esquerda) / 2;

        if (cidades[meio].codigo == codigo)
            return meio;

        if (cidades[meio].codigo < codigo)
        {
            esquerda = meio + 1;
            continue;
        }

        direita = meio - 1;
    }

    return -1;
}

int buscarCliente(int codigo)
{
    int esquerda = 0;
    int direita = indiceDoUltimoCliente;

    while (esquerda <= direita)
    {
        int meio = esquerda + (direita - esquerda) / 2;

        if (clientes[meio].codigo == codigo)
            return meio;

        if (clientes[meio].codigo < codigo)
        {
            esquerda = meio + 1;
            continue;
        }

        direita = meio - 1;
    }

    return -1;
}

int buscarVeiculo(string placa)
{
    for (int i = 0; i < indiceDoUltimoVeiculo; i++) {
    	if (veiculos[i].placa != placa) continue;
    	
    	return i;
	}

    return -1;
}

int buscarMecanico(int codigo)
{
    int esquerda = 0;
    int direita = indiceDoUltimoMecanico;

    while (esquerda <= direita)
    {
        int meio = esquerda + (direita - esquerda) / 2;

        if (mecanicos[meio].codigo == codigo)
            return meio;

        if (mecanicos[meio].codigo < codigo)
        {
            esquerda = meio + 1;
            continue;
        }

        direita = meio - 1;
    }

    return -1;
}

void cadastrarCidade()
{
    Cidade novaCidade;
    novaCidade.ler();
    cidades[indiceDaUltimaCidade] = novaCidade;
    indiceDaUltimaCidade++;
}

void cadastrarServico()
{
    Servico novoServico;
    novoServico.ler();
    servicos[indiceDoUltimoServico] = novoServico;
    indiceDoUltimoServico++;
}

void cadastrarPeca()
{
    Peca novaPeca;
    novaPeca.ler();
    pecas[indiceDaUltimaPeca] = novaPeca;
    indiceDaUltimaPeca++;
}

void cadastrarCliente()
{
    Cliente novoCliente;
    
    cout << "Codigo do cliente: ";
    cin >> novoCliente.codigo;
    
    int indiceDoCliente = buscarCliente(novoCliente.codigo);
    
    if (indiceDoCliente != -1) {
    	cout << "C�DIGO J� EXISTE!";
    	return;
	}

    cin.ignore();

    cout << "Nome: ";
    getline(cin, novoCliente.nome);

    cout << "Endereco: ";
    getline(cin, novoCliente.endereco);

    cout << "Telefone: ";
    getline(cin, novoCliente.telefone);

    cout << "Codigo da cidade: ";
    cin >> novoCliente.codigo_cidade;

    int indiceDaCidade = buscarCidade(novoCliente.codigo_cidade);

    if (indiceDaCidade == -1)
    {
        cout << "CIDADE NÃO ENCONTRADA!\n";
        return;
    }

    Cidade cidadeAssociada = cidades[indiceDaCidade];

    cout << "CIDADE ASSOCIADA: \n";
    cout << "NOME: " << cidadeAssociada.nome <<"\n";
    cout << "UF: " << cidadeAssociada.UF <<"\n";

    clientes[indiceDoUltimoCliente] = novoCliente;
    indiceDoUltimoCliente++;
}

void cadastrarVeiculo()
{
    struct Veiculo novoVeiculo;

    cin.ignore();

    cout << "Placa: ";
    getline(cin, novoVeiculo.placa);
    
    int indiceDoVeiculo = buscarVeiculo(novoVeiculo.placa);
    
    if (indiceDoVeiculo != -1) {
    	cout << "PLACA J� EXISTE!";
    	return;
	}
    
    cout << "Modelo: ";
    getline(cin, novoVeiculo.modelo);
    
    cout << "Marca: ";
    getline(cin, novoVeiculo.marca);
    
    cout << "Ano: ";
    cin >> novoVeiculo.ano;

    cout << "Codigo do cliente: ";
    cin >> novoVeiculo.codigo_cliente;

    int indiceDoCliente = buscarCliente(novoVeiculo.codigo_cliente);

    if (indiceDoCliente == -1)
    {
        cout << "CLIENTE N�O ENCONTRADO!\n";
        return;
    }

    Cliente clienteAssociado = clientes[indiceDoCliente];

    cout << "CLIENTE ASSOCIADO: \n";
    cout << "NOME: " << clienteAssociado.nome <<"\n";

    veiculos[indiceDoUltimoVeiculo] = novoVeiculo;
    indiceDoUltimoVeiculo++;
}

void cadastrarMecanico()
{
    struct Mecanico novoMecanico;
    
    cout << "Codigo do mecanico: ";
    cin >> novoMecanico.codigo;
    
    int indiceDoMecanico = buscarMecanico(novoMecanico.codigo);
    
    if (indiceDoMecanico != -1) {
    	cout << "C�DIGO JA EXISTE!";
    	return;
	}

    cin.ignore();

    cout << "Nome: ";
    getline(cin, novoMecanico.nome);
    
    cout << "Especialidade: ";
    getline(cin, novoMecanico.especialidade);

    cout << "Telefone: ";
    getline(cin, novoMecanico.telefone);

    mecanicos[indiceDoUltimoMecanico] = novoMecanico;
    indiceDoUltimoMecanico++;
}

void cadastrarOrdemDeServico()
{
    struct OrdemServico novaOrdemDeServico;
    
    cout << "Codigo da ordem de servico: ";
    cin >> novaOrdemDeServico.codigo;
    
    int indiceDaOrdemDeServico = buscarOrdemServico(novaOrdemDeServico.codigo);
    
    if (indiceDaOrdemDeServico != -1) {
    	cout << "C�DIGO JA EXISTE!";
    	return;
	}

    cin.ignore();

    cout << "Placa: ";
    getline(cin, novaOrdemDeServico.placa_veiculo);
    
    int indiceDoVeiculo = buscarVeiculo(novaOrdemDeServico.placa_veiculo);
    
    if (indiceDoVeiculo == -1) {
    	cout << "PLACA NAO EXISTE!";
    	return;
	}
	
	struct Veiculo veiculoAssociado = veiculos[indiceDoVeiculo];
	
	int indiceDoCliente = buscarCliente(veiculoAssociado.codigo_cliente);
	Cliente clienteAssociadoAoVeiculo = clientes[indiceDoCliente];
	
	cout << "VEICULO ASSOCIADO: \n";
	cout << "MODELO: " << veiculoAssociado.modelo <<"\n";
	cout << "CLIENTE: " << veiculoAssociado.modelo <<"\n";
    
    cout << "C�digo mecanico: ";
    getline(cin, novaOrdemDeServico.codigo_mecanico);
    
    int indiceDoMecanico = buscarMecanico(novaOrdemDeServico.codigo_mecanico);
    
    if (indiceDoMecanico == -1) {
    	cout << "C�DIGO DO MECANICO N�O EXISTE!";
    	return;
	}
	
	struct Mecanico mecanicoAssociado = mecanicos[indiceDoMecanico];
	
	cout << "MECANICO ASSOCIADO: \n";
	cout << "NOME: " << mecanicoAssociado.nome <<"\n";

    mecanicos[indiceDaUltimaOrdemDeServico] = novoMecanico;
    indiceDaUltimaOrdemDeServico++;
}

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
    int opcao;
    do
    {
        exibirMenu();
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            cadastrarCidade();
            break;
        case 2:
            cadastrarServico();
            break;
        case 3:
            cadastrarPeca();
            break;
        case 4:
            cadastrarCliente();
            break;
        case 5:
        	cadastrarVeiculo();
        	break;
        case 6:
        	cadastrarMecanico();
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
