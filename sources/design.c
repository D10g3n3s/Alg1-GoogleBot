#include <stdio.h>
#include <stdlib.h>
#include <design.h>

void printHello(){
    printf("+------------------------------------------------+\n");
    printf("+                                                +\n");
    printf("+                   GOOGLE BOT                   +\n");
    printf("+                                                +\n");
}

void printOpc(){
    printf("+------------------------------------------------+\n");
    printf("+                   OPERAÇÕES:                   +\n");
    printf("+ [1]: Inserir site                              +\n");
    printf("+ [2]: Remover site                              +\n");
    printf("+ [3]: Inserir Palavra-chave                     +\n");
    printf("+ [4]: Atualizar Relevância                      +\n");
    printf("+ [5]: Imprimir lista                            +\n");
    printf("+ [6]: Sair                                      +\n");
    printf("+------------------------------------------------+\n");
    printf("  Digite sua opção: ");
}

void howInsert(){
    printf("+------------------------------------------------+\n");
    printf("+                 INSERIR SITE:                  +\n");
    printf("+    [1]: Inserir atráves de CSV                 +\n");
    printf("+    [2]: Inserir atráves do terminal            +\n");
    printf("+------------------------------------------------+\n");
    printf("  Como quer inserir: ");
}

void insertCSV(){
    printf("+------------------------------------------------+\n");
    printf("+                  INSERIR CSV:                  +\n");
    printf("+  Digite o nome do arquivo de texto com padrão  +\n");
    printf("+  CSV                                           +\n");
    printf("+------------------------------------------------+\n");
    printf("  Digite o nome do arquivo: ");
}

void csvFail(){
    printf("+------------------------------------------------+\n");
    printf("+  Não foi possivel abrir o arquivo CSV          +\n");
    printf("+------------------------------------------------+\n");
}

void csvSucess(){
    printf("+------------------------------------------------+\n");
    printf("+  Carregando CSV [...]                          +\n");
    printf("+  Arquivo CSV inserido com sucesso              +\n");
    printf("+------------------------------------------------+\n");
}

void insertManual(){
    printf("+------------------------------------------------+\n");
    printf("+                 INSERIR SITE:                  +\n");
    printf("+  Digite o site a ser inserido com padrão CSV   +\n");
    printf("+  Ex:                                           +\n");
    printf("+  codigo, nome, relvância, link, palavras-chave +\n");
    printf("+                                                +\n");
    printf("+  Ex com valores:                               +\n");
    printf("+  0001,YTB,900,https://...,video,musica         +\n");
    printf("+------------------------------------------------+\n");
}

void manualSucess(){
    printf("+------------------------------------------------+\n");
    printf("+  Novo site inserido com sucesso                +\n");
    printf("+------------------------------------------------+\n");
}

void manualFail(){
    printf("+------------------------------------------------+\n");
    printf("+  Não foi possível inserir o site               +\n");
    printf("+------------------------------------------------+\n");
}

void alredyExists(){
    printf("+------------------------------------------------+\n");
    printf("+  Código já existe na lista                     +\n");
    printf("+------------------------------------------------+\n");
}

void invalidValue(){
    printf("+------------------------------------------------+\n");
    printf("+  Digite um valor válido                        +\n");
    printf("+------------------------------------------------+\n");
}

void nonExiste(){
    printf("+------------------------------------------------+\n");
    printf("+  Código não existe na lista                    +\n");
    printf("+------------------------------------------------+\n");
}

void howRemove(){
    printf("+------------------------------------------------+\n");
    printf("+                 REMOVER SITE:                  +\n");
    printf("+  Digite o código do site a ser removido        +\n");
    printf("+------------------------------------------------+\n");
    printf("  Digite o código a ser removido: ");
}

void siteRemoved(){
    printf("+------------------------------------------------+\n");
    printf("+  Site removido com sucesso                     +\n");
    printf("+------------------------------------------------+\n");
}

void removeFail(){
    printf("+------------------------------------------------+\n");
    printf("+  Site não pode ser removido                    +\n");
    printf("+------------------------------------------------+\n");
}

void howNewKey(){
    printf("+------------------------------------------------+\n");
    printf("+             INSERIR PALAVRA-CHAVE:             +\n");
    printf("+  Nova palavra chave:                           +\n");
    printf("+------------------------------------------------+\n");
    printf("  Digite o código do site: ");
}

void newKeySucess(){
    printf("+------------------------------------------------+\n");
    printf("+  Palavra chave inserida                        +\n");
    printf("+------------------------------------------------+\n");
}

void newKeyFail(){
    printf("+------------------------------------------------+\n");
    printf("+  Não foi possível inserir                      +\n");
    printf("+------------------------------------------------+\n");
}

void maxWords(){
    printf("+------------------------------------------------+\n");
    printf("+  Não foi possível inserir máx de 10 palavras   +\n");
    printf("+  chave atingido                                +\n");
    printf("+------------------------------------------------+\n");
}

void howRelevance(){
    printf("+------------------------------------------------+\n");
    printf("+              ATUALIZAR RELEVÂNCIA:             +\n");
    printf("+------------------------------------------------+\n");
    printf("  Digite o código do site: ");
}

void relevanceChanged(){
    printf("+------------------------------------------------+\n");
    printf("+  Relevância atualizado com sucesso             +\n");
    printf("+------------------------------------------------+\n");
}

void equalRelevance(){
    printf("+------------------------------------------------+\n");
    printf("+  Não foi possível atualizar a relevância       +\n");
    printf("+------------------------------------------------+\n");
}

void invalidRelevance(){
    printf("+------------------------------------------------+\n");
    printf("+  O valor digitado não é uma relevancia válida  +\n");
    printf("+------------------------------------------------+\n");
}