# MINI GOOGLEBOT
Projeto para a matéria SCC0202 - Algoritmos e Estruturas de Dados 1

## Autores
- [Diógenes Silva Pedro](github.com/D10g3n3s) - nUSP 11883476
- [Alexandre Lima Palles Rocha](https://github.com/Alexandre-Palles) - nUSP 11797038

## Compilador
Foi utilizado o padrão C99 para o projeto, além do compilador GCC (Gnu C Compiler).

## Estrutura Utilizada
Nosso programa se utiliza de duas estruturas de dados. Uma Árvore AVL e uma lista ligada.

### Árvore AVL
- a

### Lista Ligada
- a

## Complexidade da Estrutura
- Inserção do site no começo da lista: O(1)
- Inserção do site no meio ou no fim da lista: O(n)
- Exclusão do site: O(n)
- Busca na lista: O(n)

## Uso do programa
![](images/menu.png)

O programa inicia e mostra um menu com as opções:
- Inserção:
    - Inserção CSV: O usuário passa o nome de um arquivo de texto no tipo CSV para salvar os dados na lista
    - Inserção manual: O usuário escreve uma linha, no estilo CSV, para ser salva na lista
- Remoção:
    - O programa pede para o usuário o código de um site existente para removê-lo da lista
- Inserir Palavra-chave:
    - O usuário passa um código válido e uma palavra válida para ser adicionada como palavra chave de um site
- Atualizar Relevância:
    - O usuário passa um código válido e uma relevância para atualizar a relevância de um site
- Imprimir Lista:
    - O programa printa todos os sites da lista