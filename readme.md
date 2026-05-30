# Sistema de Gerenciamento de Oficina Mecânica — Enunciado

## Objetivo

Desenvolver um programa em **C++** utilizando **estruturas (`struct`)** para simular arquivos sequenciais de uma aplicação de gerenciamento de uma oficina mecânica.

---

# Estruturas (Tabelas)

## 1. Cidades

Campos:

- `codigo`
- `nome`
- `UF`

---

## 2. Clientes

Campos:

- `codigo`
- `nome`
- `endereco`
- `telefone`
- `codigo_cidade`

---

## 3. Veículos

Campos:

- `placa`
- `modelo`
- `marca`
- `ano`
- `codigo_cliente`

---

## 4. Serviços

Campos:

- `codigo`
- `descricao`
- `valor_mao_de_obra`

---

## 5. Peças

Campos:

- `codigo`
- `descricao`
- `quant_estoque`
- `estoque_minimo`
- `estoque_maximo`
- `preco_unitario`

---

## 6. Mecânicos

Campos:

- `codigo`
- `nome`
- `especialidade`
- `telefone`

---

## 7. Ordens de Serviço

Campos:

- `codigo`
- `placa_veiculo`
- `codigo_mecanico`
- `data`
- `codigo_servico`
- `codigo_peca`
- `quantidade_peca`

---

# Funcionalidades

---

## 1) Leitura de Dados

Criar funções específicas para leitura dos dados das seguintes estruturas:

- Cidades
- Serviços
- Peças

---

## 2) Inclusão de Clientes

Criar uma função para inclusão de novos registros na tabela de Clientes.

### Regras

#### 2.1)

Garantir que o código do cliente informado:

- **não exista previamente** na tabela de Clientes.

#### 2.2)

Ao informar o código da cidade:

- buscar o código na tabela de Cidades;
- exibir:
  - nome da cidade;
  - UF.

---

## 3) Inclusão de Veículos

Criar uma função para inclusão de novos registros na tabela de Veículos.

### Regras

#### 3.1)

Garantir que a placa do veículo:

- **não exista previamente** na tabela de Veículos.

#### 3.2)

Ao informar o código do cliente:

- buscar o cliente na tabela de Clientes;
- exibir o nome do cliente.

---

## 4) Inclusão de Mecânicos

Criar uma função para inclusão de novos registros na tabela de Mecânicos.

---

## 5) Abertura de Ordem de Serviço

Criar uma função para abertura de uma Ordem de Serviço.

### Regras

#### 5.1)

Ao informar a placa do veículo:

- buscar na tabela de Veículos;
- exibir:
  - modelo;
  - nome do cliente.

---

#### 5.2)

Ao informar o código do mecânico:

- buscar na tabela de Mecânicos;
- exibir:
  - nome;
  - especialidade.

---

#### 5.3)

Ao informar o código do serviço:

- buscar na tabela de Serviços;
- exibir:
  - descrição;
  - valor da mão de obra.

---

#### 5.4)

Ao informar o código da peça:

- buscar na tabela de Peças;
- exibir:
  - descrição.

---

#### 5.5)

Ao informar a quantidade de peças:

- verificar se o estoque é suficiente;
- não permitir quantidade maior do que a disponível.

---

#### 5.6)

A quantidade utilizada:

- deve ser subtraída do estoque.

---

## 6) Consulta de Peças

Criar uma função para consultar os dados de uma peça específica.

### Exibir

- todos os dados da peça;
- valor total em estoque:

Valor\ Total = quant_estoque \times preco_unitario

---

## 7) Relatório de Peças Abaixo do Estoque Mínimo

Criar uma função para listar peças com estoque abaixo do mínimo.

### Exibir

- código;
- descrição;
- quantidade em estoque;
- estoque máximo;
- quantidade a ser comprada;
- valor da compra.

---

### 7.1.1) Quantidade a ser comprada

Quantidade\ a\ Comprar = estoque_maximo - quant_estoque

---

### 7.2)

Ao final do relatório:

- exibir o valor total gasto na compra das peças.

---

## 8) Valor Total Arrecadado

Criar uma função para exibir o valor total arrecadado com todas as ordens de serviço.

### Cálculo do valor de cada ordem

A soma deve considerar:

- valor da mão de obra;
- valor das peças utilizadas.

Valor\ da\ Ordem = valor_mao_de_obra + (quantidade \times preco_unitario)

---

# Observações Gerais

- Todas as funções devem ser chamadas através de um **menu de opções** implementado na função `main()`.
- Não utilizar variáveis globais.
- Utilizar estruturas (`struct`) para representar as tabelas.
- As buscas devem ser realizadas de forma aleatória.
- Garantir todas as validações especificadas nos itens anteriores.
