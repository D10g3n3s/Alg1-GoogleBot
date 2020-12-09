#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <design.h>
#include <menuavl.h>

enum {
    INSERT_DATA = 1,
    REMOVE_DATA,
    NEW_KEYWORD,
    UPDATE_RELEVANCE,
    SEARCH_KEYWORD,
    PRINT_TREE,
    EXIT
};

enum {
    INSERT_CSV = 1,
    INSERT_MANUAL
};

void avlAutoLoadCSV(AVL *tree){
    char *archive = "./googlebot.txt";
    FILE *fp = fopen(archive, "r");

    if (fp == NULL)
        csvFail();
    
    else {
        csvSucess();

        while(!feof(fp)){
            char *data;
            data = readLine(fp);

            if (strcmp(data, "") != 0) {
                bool exists = checkAVLExistence(tree, data);
                
                if (!exists)
                    insertAVL(tree, createSite(data));

                else 
                    alredyExists();
            }

            free(data);
        }
        
        fclose(fp);
    }
}

void avlCSV(AVL *tree){
    insertCSV();

    char *archive;
    archive = readLine(stdin);

    FILE *fp = fopen(archive, "r");

    if (fp == NULL)
        csvFail();
    
    else {
        csvSucess();

        while(!feof(fp)){
            char *data;
            data = readLine(fp);

            if (strcmp(data, "") != 0) {
                bool exists = checkAVLExistence(tree, data);
                
                if (!exists)
                    insertAVL(tree, createSite(data));

                else 
                    alredyExists();
            }

            free(data);
        }
        
        fclose(fp);
    }

    free(archive);
}

void avlManual(AVL *tree){
    insertManual();

    char *data;
    data = readLine(stdin);

    bool exists = checkAVLExistence(tree, data);

    if (!exists){
        bool inserted = insertAVL(tree, createSite(data));

        if(inserted)
            manualSucess();
        else
            manualFail();
    }
    else 
        alredyExists();

    free(data);
}

void avlMenuInsert(AVL *tree){
    howInsert();

    char *opc = readLine(stdin);
    int option = atoi(opc);
    free(opc);

    if (option == INSERT_CSV)
        avlCSV(tree);

    else if (option == INSERT_MANUAL)
        avlManual(tree);

    else 
        alredyExists();
}

void avlRemoveData(AVL *tree){
    howRemove();

    char *string = readLine(stdin);
    bool exists = checkAVLExistence(tree, string);
    int code = atoi(string);
    free(string);

    if (exists){
        bool removed = deleteNodeAVL(tree, code);

        if (removed)
            siteRemoved();
        else
            removeFail();
    }
    else 
        nonExiste();
}

void avlAddKeyWord(AVL *tree){
    howNewKey();

    char *string = readLine(stdin);
    bool exists = checkAVLExistence(tree, string);
    int code = atoi(string);
    free(string);

    if (exists) {
        printf("  Digite a nova palavra: ");
        char *newWord = readLine(stdin);
        siteSetKeyWord(searchTree(tree, code), newWord);
        free(newWord);
    }
    else
        nonExiste();
}

void avlUpdateRel(AVL *tree){
    howRelevance();

    char *string = readLine(stdin);
    bool exists = checkAVLExistence(tree, string);
    int code = atoi(string);
    free(string);

    if (exists) {
        printf("  Digite a nova relevância: ");
        char *newWord = readLine(stdin);
        int newRelevance = atoi(newWord);
        siteSetRelevance(searchTree(tree, code), newRelevance);
        free(newWord);
    }
    else
        nonExiste();
}

void avlSiteList(AVL *tree){
    // Discovering the keyword to be searched
    char *keyWordToFound = readWord(stdin);
    printf("Key Word to Found: %s\n", keyWordToFound);

    // Creating a linked list for the sites that has the keyword to be searched
    LINKED_LIST *listOfSites;
    listOfSites = createKeyWordList(tree, keyWordToFound);
    printList(listOfSites);

    free(keyWordToFound);
    deleteList(listOfSites);
}

void menuAVL(AVL *tree){
    bool isOver = FALSE;
    char *opc = NULL;

    printHello();

    avlAutoLoadCSV(tree);

    do {
        printOpc();

        opc = readLine(stdin);
        int operation = atoi(opc);
        free(opc);

        if(operation == INSERT_DATA)
            avlMenuInsert(tree);

        else if(operation == REMOVE_DATA)
            avlRemoveData(tree);

        else if(operation == NEW_KEYWORD)
            avlAddKeyWord(tree);

        else if(operation == UPDATE_RELEVANCE)
            avlUpdateRel(tree);

        else if(operation == SEARCH_KEYWORD)
            avlSiteList(tree);

        else if(operation == PRINT_TREE)
            printInOrder(tree);

        else if(operation == EXIT)
            isOver = TRUE;
        
        else
            invalidOption();

    } while(!isOver);
}
