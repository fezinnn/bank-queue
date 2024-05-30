# Trabalho Prático 04 - Fila do Banco

Este repositório contém a implementação do Trabalho Prático 04 - Fila do Banco, que simula uma fila de atendimento de um banco com clientes gerais e prioritários.

## Integrantes
- Alan Andrade Vasconi de Souza - SC3038319
- Felipe Santos Lourenço - SC303867X
- Fernando Henrique de Castro Chagas - SC3037495

## Como Compilar

Para compilar o projeto, execute o comando:

make

## Como Executar

Para executar o programa, use o comando:

./bank_queue

## Descrição

O programa lê comandos de entrada para gerenciar duas filas (geral e prioritária) e simula o atendimento de clientes conforme as regras especificadas no trabalho prático. 

### Entrada
- `g nome`: Adiciona um cliente geral à fila com o nome especificado.
- `p nome`: Adiciona um cliente prioritário à fila com o nome especificado.
- `s`: Simula a liberação de um caixa, chamando o próximo cliente conforme as regras de atendimento.
- `f`: Finaliza o expediente e imprime a ordem em que os clientes foram atendidos.

### Saída
Ao finalizar o expediente (`f`), o programa imprime a ordem em que os clientes foram atendidos.

### Exemplo de Uso

Entrada:

g Alice
p Bob
g Charlie
s
g David
s
p Eve
s
f

Saída:

Bob
Alice
Eve

Explicação:

1. g Alice: Adiciona Alice à fila geral.
2. p Bob: Adiciona Bob à fila prioritária.
3. g Charlie: Adiciona Charlie à fila geral.
4. s: Libera um caixa. Como há um cliente na fila prioritária, Bob é atendido.
5. g David: Adiciona David à fila geral.
6. s: Libera um caixa. Como não há clientes na fila prioritária, Alice é atendida.
7. p Eve: Adiciona Eve à fila prioritária.
8. s: Libera um caixa. Eve, que está na fila prioritária, é atendida.
9. f: Finaliza o expediente e imprime a ordem de atendimento dos clientes.