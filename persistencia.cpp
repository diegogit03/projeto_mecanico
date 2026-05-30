#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

struct DadosPersistidos {
    ListaDeCidades cidades;
    ListaDeServicos servicos;
    ListaDePecas pecas;
    ListaDeClientes clientes;
    ListaDeVeiculos veiculos;
    ListaDeMecanicos mecanicos;
    ListaDeOrdemServicos ordens;
};

string formatarPropriedadeParaPersistencia(const string &valor)
{
    if (valor.find(',') == string::npos && valor.find('"') == string::npos && valor.find('\n') == string::npos)
        return valor;

    string escape;
    for (char c : valor) {
        if (c == '"') escape += '"';
        escape += c;
    }
    return "\"" + escape + "\"";
}

vector<string> formatarPropriedadesParaPersistencia(const string &linha)
{
    vector<string> campos;
    string campo;
    bool emQuotes = false;

    for (size_t i = 0; i < linha.size(); i++) {
        if (linha[i] == '"') {
            if (emQuotes && i + 1 < linha.size() && linha[i + 1] == '"') {
                campo += '"';
                i++;
            } else {
                emQuotes = !emQuotes;
            }
        } else if (linha[i] == ',' && !emQuotes) {
            campos.push_back(campo);
            campo.clear();
        } else {
            campo += linha[i];
        }
    }
    campos.push_back(campo);
    return campos;
}

void persistirCidades(ListaDeCidades &lista)
{
    ofstream arquivo("data/cidades.txt");
    for (int i = 0; i < lista.indiceDaUltima; i++) {
        arquivo << formatarPropriedadeParaPersistencia(to_string(lista.cidades[i].codigo)) << ","
                << formatarPropriedadeParaPersistencia(lista.cidades[i].nome) << ","
                << formatarPropriedadeParaPersistencia(lista.cidades[i].UF) << "\n";
    }
}

void persistirServicos(ListaDeServicos &lista)
{
    ofstream arquivo("data/servicos.txt");
    for (int i = 0; i < lista.indiceDoUltimo; i++) {
        arquivo << formatarPropriedadeParaPersistencia(to_string(lista.servicos[i].codigo)) << ","
                << formatarPropriedadeParaPersistencia(lista.servicos[i].descricao) << ","
                << formatarPropriedadeParaPersistencia(to_string(lista.servicos[i].valor_mao_de_obra)) << "\n";
    }
}

void persistirPecas(ListaDePecas &lista)
{
    ofstream arquivo("data/pecas.txt");
    for (int i = 0; i < lista.indiceDaUltima; i++) {
        arquivo << formatarPropriedadeParaPersistencia(to_string(lista.pecas[i].codigo)) << ","
                << formatarPropriedadeParaPersistencia(lista.pecas[i].descricao) << ","
                << formatarPropriedadeParaPersistencia(to_string(lista.pecas[i].quant_estoque)) << ","
                << formatarPropriedadeParaPersistencia(to_string(lista.pecas[i].estoque_minimo)) << ","
                << formatarPropriedadeParaPersistencia(to_string(lista.pecas[i].estoque_maximo)) << ","
                << formatarPropriedadeParaPersistencia(to_string(lista.pecas[i].preco_unitario)) << "\n";
    }
}

void persistirClientes(ListaDeClientes &lista)
{
    ofstream arquivo("data/clientes.txt");
    for (int i = 0; i < lista.indiceDoUltimo; i++) {
        arquivo << formatarPropriedadeParaPersistencia(to_string(lista.clientes[i].codigo)) << ","
                << formatarPropriedadeParaPersistencia(lista.clientes[i].nome) << ","
                << formatarPropriedadeParaPersistencia(lista.clientes[i].endereco) << ","
                << formatarPropriedadeParaPersistencia(lista.clientes[i].telefone) << ","
                << formatarPropriedadeParaPersistencia(to_string(lista.clientes[i].codigo_cidade)) << "\n";
    }
}

void persistirVeiculos(ListaDeVeiculos &lista)
{
    ofstream arquivo("data/veiculos.txt");
    for (int i = 0; i < lista.indiceDoUltimo; i++) {
        arquivo << formatarPropriedadeParaPersistencia(lista.veiculos[i].placa) << ","
                << formatarPropriedadeParaPersistencia(lista.veiculos[i].modelo) << ","
                << formatarPropriedadeParaPersistencia(lista.veiculos[i].marca) << ","
                << formatarPropriedadeParaPersistencia(to_string(lista.veiculos[i].ano)) << ","
                << formatarPropriedadeParaPersistencia(to_string(lista.veiculos[i].codigo_cliente)) << "\n";
    }
}

void persistirMecanicos(ListaDeMecanicos &lista)
{
    ofstream arquivo("data/mecanicos.txt");
    for (int i = 0; i < lista.indiceDoUltimo; i++) {
        arquivo << formatarPropriedadeParaPersistencia(to_string(lista.mecanicos[i].codigo)) << ","
                << formatarPropriedadeParaPersistencia(lista.mecanicos[i].nome) << ","
                << formatarPropriedadeParaPersistencia(lista.mecanicos[i].especialidade) << ","
                << formatarPropriedadeParaPersistencia(lista.mecanicos[i].telefone) << "\n";
    }
}

void persistirOrdemServicos(ListaDeOrdemServicos &lista)
{
    ofstream arquivo("data/ordens.txt");
    for (int i = 0; i < lista.indiceDaUltima; i++) {
        arquivo << formatarPropriedadeParaPersistencia(to_string(lista.ordens[i].codigo)) << ","
                << formatarPropriedadeParaPersistencia(lista.ordens[i].placa_veiculo) << ","
                << formatarPropriedadeParaPersistencia(to_string(lista.ordens[i].codigo_mecanico)) << ","
                << formatarPropriedadeParaPersistencia(lista.ordens[i].data) << ","
                << formatarPropriedadeParaPersistencia(to_string(lista.ordens[i].codigo_servico)) << ","
                << formatarPropriedadeParaPersistencia(to_string(lista.ordens[i].codigo_peca)) << ","
                << formatarPropriedadeParaPersistencia(to_string(lista.ordens[i].quantidade_peca)) << "\n";
    }
}

void lerArquivo(ifstream &arquivo, ListaDeCidades &lista)
{
    string linha;
    while (getline(arquivo, linha)) {
        if (linha.empty()) continue;
        vector<string> campos = formatarPropriedadesParaPersistencia(linha);
        if (campos.size() >= 3) {
            Cidade obj;
            obj.codigo = stoi(campos[0]);
            obj.nome = campos[1];
            obj.UF = campos[2];
            lista.cidades[lista.indiceDaUltima++] = obj;
        }
    }
}

void lerArquivo(ifstream &arquivo, ListaDeServicos &lista)
{
    string linha;
    while (getline(arquivo, linha)) {
        if (linha.empty()) continue;
        vector<string> campos = formatarPropriedadesParaPersistencia(linha);
        if (campos.size() >= 3) {
            Servico obj;
            obj.codigo = stoi(campos[0]);
            obj.descricao = campos[1];
            obj.valor_mao_de_obra = stof(campos[2]);
            lista.servicos[lista.indiceDoUltimo++] = obj;
        }
    }
}

void lerArquivo(ifstream &arquivo, ListaDePecas &lista)
{
    string linha;
    while (getline(arquivo, linha)) {
        if (linha.empty()) continue;
        vector<string> campos = formatarPropriedadesParaPersistencia(linha);
        if (campos.size() >= 6) {
            Peca obj;
            obj.codigo = stoi(campos[0]);
            obj.descricao = campos[1];
            obj.quant_estoque = stoi(campos[2]);
            obj.estoque_minimo = stoi(campos[3]);
            obj.estoque_maximo = stoi(campos[4]);
            obj.preco_unitario = stof(campos[5]);
            lista.pecas[lista.indiceDaUltima++] = obj;
        }
    }
}

void lerArquivo(ifstream &arquivo, ListaDeClientes &lista)
{
    string linha;
    while (getline(arquivo, linha)) {
        if (linha.empty()) continue;
        vector<string> campos = formatarPropriedadesParaPersistencia(linha);
        if (campos.size() >= 5) {
            Cliente obj;
            obj.codigo = stoi(campos[0]);
            obj.nome = campos[1];
            obj.endereco = campos[2];
            obj.telefone = campos[3];
            obj.codigo_cidade = stoi(campos[4]);
            lista.clientes[lista.indiceDoUltimo++] = obj;
        }
    }
}

void lerArquivo(ifstream &arquivo, ListaDeVeiculos &lista)
{
    string linha;
    while (getline(arquivo, linha)) {
        if (linha.empty()) continue;
        vector<string> campos = formatarPropriedadesParaPersistencia(linha);
        if (campos.size() >= 5) {
            Veiculo obj;
            obj.placa = campos[0];
            obj.modelo = campos[1];
            obj.marca = campos[2];
            obj.ano = stoi(campos[3]);
            obj.codigo_cliente = stoi(campos[4]);
            lista.veiculos[lista.indiceDoUltimo++] = obj;
        }
    }
}

void lerArquivo(ifstream &arquivo, ListaDeMecanicos &lista)
{
    string linha;
    while (getline(arquivo, linha)) {
        if (linha.empty()) continue;
        vector<string> campos = formatarPropriedadesParaPersistencia(linha);
        if (campos.size() >= 4) {
            Mecanico obj;
            obj.codigo = stoi(campos[0]);
            obj.nome = campos[1];
            obj.especialidade = campos[2];
            obj.telefone = campos[3];
            lista.mecanicos[lista.indiceDoUltimo++] = obj;
        }
    }
}

void lerArquivo(ifstream &arquivo, ListaDeOrdemServicos &lista)
{
    string linha;
    while (getline(arquivo, linha)) {
        if (linha.empty()) continue;
        vector<string> campos = formatarPropriedadesParaPersistencia(linha);
        if (campos.size() >= 7) {
            OrdemServico obj;
            obj.codigo = stoi(campos[0]);
            obj.placa_veiculo = campos[1];
            obj.codigo_mecanico = stoi(campos[2]);
            obj.data = campos[3];
            obj.codigo_servico = stoi(campos[4]);
            obj.codigo_peca = stoi(campos[5]);
            obj.quantidade_peca = stoi(campos[6]);
            lista.ordens[lista.indiceDaUltima++] = obj;
        }
    }
}

void lerArquivo(const string &caminho, ListaDeCidades &lista)
{
    ifstream arquivo(caminho);
    if (arquivo.is_open())
        lerArquivo(arquivo, lista);
}

void lerArquivo(const string &caminho, ListaDeServicos &lista)
{
    ifstream arquivo(caminho);
    if (arquivo.is_open())
        lerArquivo(arquivo, lista);
}

void lerArquivo(const string &caminho, ListaDePecas &lista)
{
    ifstream arquivo(caminho);
    if (arquivo.is_open())
        lerArquivo(arquivo, lista);
}

void lerArquivo(const string &caminho, ListaDeClientes &lista)
{
    ifstream arquivo(caminho);
    if (arquivo.is_open())
        lerArquivo(arquivo, lista);
}

void lerArquivo(const string &caminho, ListaDeVeiculos &lista)
{
    ifstream arquivo(caminho);
    if (arquivo.is_open())
        lerArquivo(arquivo, lista);
}

void lerArquivo(const string &caminho, ListaDeMecanicos &lista)
{
    ifstream arquivo(caminho);
    if (arquivo.is_open())
        lerArquivo(arquivo, lista);
}

void lerArquivo(const string &caminho, ListaDeOrdemServicos &lista)
{
    ifstream arquivo(caminho);
    if (arquivo.is_open())
        lerArquivo(arquivo, lista);
}

DadosPersistidos lerPersistencia()
{
    DadosPersistidos dados = {};

    lerArquivo("data/cidades.txt", dados.cidades);
    lerArquivo("data/servicos.txt", dados.servicos);
    lerArquivo("data/pecas.txt", dados.pecas);
    lerArquivo("data/clientes.txt", dados.clientes);
    lerArquivo("data/veiculos.txt", dados.veiculos);
    lerArquivo("data/mecanicos.txt", dados.mecanicos);
    lerArquivo("data/ordens.txt", dados.ordens);

    return dados;
}
