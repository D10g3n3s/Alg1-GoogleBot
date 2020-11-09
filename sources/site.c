#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "site.h"
#include "design.h"

struct _words{
    char **words;
    int amount;
};

struct _site{
    int code;
    char *name;
    int revelance;
    char *link;
    WORDS *keyWords;
};

// Function that creates a wordlist
WORDS* createWordList(){
    WORDS *list = malloc (sizeof(WORDS));
    list->words = NULL;
    list->amount = 0;

    return list;
}

// Function that particionates a string and saves it to the word list
bool getPartFromStr(char *sourceStr, int *sourcePos, char **destStr, char delimiter) {
    *destStr = NULL;
    bool is_end_of_part = FALSE;

    char c;
    int dest_pos = 0;
    do {
        c = sourceStr[*sourcePos];

        if (c == '\0') {
            *destStr = realloc(*destStr, (dest_pos + 1) * sizeof(char));
            (*destStr)[dest_pos] = '\0';
            return TRUE;
        }

        else if (c == delimiter) {
            is_end_of_part = TRUE;
            c = '\0';
        }

        *destStr = realloc(*destStr, (dest_pos + 1) * sizeof(char));
        (*destStr)[dest_pos] = c;

        (*sourcePos)++;
        dest_pos++;
    } while (!is_end_of_part);

    return FALSE;
}

// Function that parcionates a given string into its delimiters and save in a char** wordlist
WORDS *splitList(char *string, char delimiter){
    WORDS *splitList = createWordList();

    bool isOver = FALSE;

    int strPos = 0;

    do {
        splitList->words = realloc(splitList->words, (splitList->amount + 1) * sizeof(char*));
        char **curPart = &splitList->words[splitList->amount];

        isOver = getPartFromStr(string, &strPos, curPart, delimiter); 
        splitList->amount++;
    } while(!isOver);

    return splitList;
}

//Functions that creates a site
SITE* createSite(char *string){
    WORDS *csvList = splitList(string, ',');

    SITE *site = malloc(sizeof(SITE));
    if (site != NULL){
        site->code = atoi(csvList->words[0]);
        free(csvList->words[0]);
        site->name = csvList->words[1];
        site->revelance = atoi(csvList->words[2]);
        free(csvList->words[2]);
        site->link = csvList->words[3];

        site->keyWords = (WORDS*) malloc(sizeof(WORDS));
        site->keyWords->words = NULL;

        int wordCount = 0;
        for (int i = 4; i < csvList->amount; i++){
            if (wordCount <= 10){
                site->keyWords->words = realloc(site->keyWords->words, (wordCount + 1) * sizeof(char*));
                site->keyWords->words[wordCount] = csvList->words[i];
                wordCount++;
            }
            else {
                free(csvList->words[i]);
            }
        }

        site->keyWords->amount = wordCount;
    }

    free(csvList->words);
    free(csvList);

    return site;
}

//Function that deletes a site
bool deleteSite(SITE *site){
    if (site == NULL)
        return FALSE;

    for (int i = 0; i < site->keyWords->amount; i++){
        free(site->keyWords->words[i]);
    }
    free(site->keyWords->words);
    free(site->keyWords);
    free(site->link);
    free(site->name);
    free(site);

    return TRUE;
}

//Function that prints the informations of a site
void printSite(SITE *site){
    if (site != NULL){
        printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("+  Código: %d\n", site->code);
        printf("+  Nome: %s\n", site->name);
        printf("+  Relevância %d\n", site->revelance);
        printf("+  Link: %s\n", site->link);
        printf("+  KeyWords:                                     \n");
        for (int i = 0; i < site->keyWords->amount; i++)
            printf("+  [%d]: %s\n", i, site->keyWords->words[i]);
    }
}

//Função that gets a code from a site
int siteGetCode(SITE *site){
    if (site != NULL)
        return site->code;

    printf("Não foi possível achar o código do site\n");
    return ERROR;
}

//Function that gets the name of a site
char* siteGetName(SITE *site){
    if (site != NULL)
        return site->name;
    
    printf("Não foi possível recuperar o nome do site\n");
    return NULL;
}

//Function that gets the revelance of a site
int siteGetRevelance(SITE *site){
    if (site != NULL)
        return site->revelance;
    
    printf("Não foi possível recuperar a relevância do site\n");
    return ERROR;
}

//Function that returns the link of a site
char* siteGetLink(SITE *site){
    if (site != NULL)
        return site->link;
    
    printf("Não foi possível recurperar o link do site\n");
    return NULL;
}

//Function that gets the keywords of a site
char** siteGetKeyWords(SITE *site){
    if (site != NULL)
        return site->keyWords->words;

    printf("Não foi possível recuperar as palavras chaves do site\n");
    return NULL;
}

//Function that gets the amount of keywords of a site
int siteGetAmountKeyWords(SITE *site){
    if (site != NULL)
        return site->keyWords->amount;

    printf("Não foi possível recuperar a quantidade de palavras chave\n");
    return ERROR;
}

//Function that sets new relevance to a site
bool siteSetRelevance(SITE *site, int relevance){
    if (site == NULL)
        return FALSE;

    if (relevance < 0 || relevance > 1000){
        invalidRelevance();
        return FALSE;
    }

    if (site->revelance == relevance){ 
        equalRelevance();
        return FALSE;
    }

    site->revelance = relevance;
    relevanceChanged();
    return TRUE;
}

//Function that sets new keyword to a site
bool siteSetKeyWord(SITE *site, char *string){
    if (site == NULL || string == NULL){
        newKeyFail();
        return FALSE;
    }

    if (site->keyWords->amount >= 10){
        maxWords();
        return FALSE;
    }
    
    char *newWord = myStrndump(string, strlen(string));

    site->keyWords->amount++;
    site->keyWords->words = realloc(site->keyWords->words, site->keyWords->amount * sizeof(char*));
    site->keyWords->words[site->keyWords->amount - 1] = newWord;
    newKeySucess();
    return TRUE;
}