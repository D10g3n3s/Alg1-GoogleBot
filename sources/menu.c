#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "design.h"

enum {
    INSERT_DATA = 1,
    REMOVE_DATA,
    NEW_KEYWORD,
    UPDATE_RELEVANCE,
    PRINT_LIST,
    EXIT
};

enum {
    INSERT_CSV = 1,
    INSERT_MANUAL
};

void CSV(LINKED_LIST *list){
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
                bool exists = checkExistence(list, data);
                
                if (!exists)
                    insertList(list, createSite(data));

                else 
                    alredyExists();
            }

            free(data);
        }
        
        fclose(fp);
    }

    free(archive);
}

void manual(LINKED_LIST *list){
    insertManual();

    char *data;
    data = readLine(stdin);

    bool exists = checkExistence(list, data);

    if (!exists){
        bool inserted = insertList(list, createSite(data));
        if(inserted)
            manualSucess();
        else
            manualFail();
    }
    else 
        invalidValue();

    free(data);
}

//Submenu function for insert data
void menuInsert(LINKED_LIST *list){
    howInsert();

    char *opc = readLine(stdin);
    int option = atoi(opc);
    free(opc);

    if (option == INSERT_CSV)
        CSV(list);

    else if (option == INSERT_MANUAL)
        manual(list);

    else 
        invalidValue();

}

//Function that remove a site of the list
void removeData(LINKED_LIST *list){
    howRemove();

    char *string = readLine(stdin);
    bool exists = checkExistence(list, string);
    int code = atoi(string);
    free(string);

    if (exists){
        bool removed = removeSite(list, code);
        if (removed)
            siteRemoved();
        else
            removeFail();
    }
    else 
        nonExiste();
}

void addKeyWord(LINKED_LIST *list){
    howNewKey();

    char *string = readLine(stdin);
    bool exists = checkExistence(list, string);
    int code = atoi(string);
    free(string);

    if (exists) {
        printf("  Digita a nova palavra: ");
        char *newWord = readWord(stdin);
        siteSetKeyWord(searchList(list, code), newWord);
        free(newWord);
    }
    else
        nonExiste();

}

//Functoin that set new relevance
void updateRel(LINKED_LIST *list){
    howRelevance();

    char *string = readLine(stdin);
    bool exists = checkExistence(list, string);
    int code = atoi(string);
    free(string);

    if (exists) {
        printf("  Digita a nova relevância: ");
        char *newWord = readLine(stdin);
        int newRelevance = atoi(newWord);
        siteSetRelevance(searchList(list, code), newRelevance);
        free(newWord);
    }
    else
        nonExiste();
}

void menu(LINKED_LIST *list){
    bool isOver = FALSE;
    char *opc = NULL;

    printHello();

    do {
        printOpc();

        opc = readLine(stdin);
        int operation = atoi(opc);
        free(opc);

        if(operation == INSERT_DATA)
            menuInsert(list);            
        
        else if(operation == REMOVE_DATA)
            removeData(list);

        else if(operation == NEW_KEYWORD)
            addKeyWord(list);

        else if(operation == UPDATE_RELEVANCE) 
            updateRel(list);

        else if(operation == PRINT_LIST)
            printList(list);

        else if(operation == EXIT)
            isOver = TRUE;
        
        else 
            printf("Insira um valor válido por favor\n");

    } while(!isOver);
}