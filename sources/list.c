#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <list.h>

typedef struct _node NODE;

struct  _node{
    SITE *site;
    NODE *next;
};

struct _linkedList{
    NODE *head;
    NODE *tail;
    int length;
};

// Funcation that creates a linked list
LINKED_LIST *createList(){
    LINKED_LIST *list = malloc(sizeof(LINKED_LIST));

    if (list != NULL){
        list->head = NULL;
        list->tail = NULL;
        list->length = 0;
    }

    return list;
}

// Function that return the length of a list
int listLength(LINKED_LIST *list){
    return list->length;
}

// Function that checks if list is empty
bool emptyList(LINKED_LIST *list){
    if (list != NULL && list->length == 0)
        return TRUE;

    return FALSE;
}

// Function that inserts in a list in a ordenated way
bool insertList(LINKED_LIST *list, SITE *site){
    if (list == NULL || site == NULL)
        return FALSE;
    
    NODE *data = malloc(sizeof(NODE));
    data->site = site;
    data->next = NULL;

    if (data == NULL)
        return FALSE;

    // If list is empty begin from the start of the list
    if (emptyList(list)){
        list->head = data;
        list->tail = data;
        list->length++;
        return TRUE;
    }

    // Searching for the right place to insert
    else {
        // Checking if the incoming data comes in the start of the list
        if (siteGetRevelance(data->site) > siteGetRevelance(list->head->site)){
            NODE *aux = list->head;
            list->head = data;
            list->head->next = aux;
            list->length++;
            aux = NULL;
            return TRUE;
        }

        NODE *prev = list->head;
        NODE *next = list->head->next;

        // Searching for the right place
        while (next != NULL && siteGetRevelance(data->site) <= siteGetRevelance(next->site)){
            prev = next;
            next = next->next;
        }

        // If the data is inserted in the end of the list
        if (next == NULL){
            prev->next = data;
            list->tail = data;
        }

        // Inserting in the right place
        else {
            data->next = next;
            prev->next = data;
        }
    }

    list->length++;
    return TRUE;
}

// Function that searchs for a site in the list based in a site name
SITE *searchList(LINKED_LIST *list, char *name){
    if (list != NULL){
        NODE *data;
        data = list->head;
        // We need to search for every site in the list, because they're ordenated by relevance not by name
        while (data != NULL){
            if (strcmp(siteGetName(data->site), name) == 0)
                return data->site;
            data = data->next;
        }
    }

    return NULL;
}

// Function that removes from the list based in a code
bool removeSite(LINKED_LIST *list, int code){
    if (list != NULL){
        NODE *prev = NULL;
        NODE *next = list->head;

        while (next != NULL && siteGetCode(next->site) < code){
            prev = next;
            next = next->next;
        }

        // In case the data is found
        if (next != NULL){
            // If the data is the init of the list
            if (next == list->head){
                list->head = next->next;
                next->next = NULL;
            }

            else {
                prev->next = next->next;
                next->next = NULL;
            }

            // Checking if the removed item is the end of the list
            if (next == list->tail)
                list->tail = prev;

            list->length--;
            next->site = NULL;
            free(next);
            return TRUE;
        }
    }

    return FALSE;
}

// Function that print the entire list
void printList(LINKED_LIST *list){
    NODE *data;

    if (list != NULL){
        data = list->head;

        while (data != NULL){
            printRelatedSite(data->site);
            data = data->next;
        }
    }
}

// Function that print the 5 most relevant sites
void printMostRelevant(LINKED_LIST *list){
    NODE *data = list->head;

    if (list != NULL){
        if (list->length >= 5){
            for (int i = 0; i < 5; i++){
                printRelatedSite(data->site);
                data = data->next;
            }
        }
        else {
            for (int i = 0; i < list->length; i++){
                printRelatedSite(data->site);
                data = data->next;
            }
        }
    }
}

// Function that deletes a list
bool deleteList(LINKED_LIST *list){
    if (list != NULL){
        NODE *data;

        while (list->head != NULL){
            data = list->head;
            list->head = list->head->next;
            data->site = NULL;
            free(data);
        }
        free(list);

        return TRUE;
    }

    else
        return FALSE;
}

// Function that searchs for a site based on the amount of nodes to iterate
SITE *listGetSite(LINKED_LIST *list, int amountLoop){
    if (list != NULL){
        NODE *data = list->head;
        for (int i = 0; i <= amountLoop; i++){
            if (i == amountLoop)
                return data->site;

            data = data->next;
        }
    }

    return NULL;
}

// Function that checks if the name of a site from given data alredy exists in the list
bool checkExistence(LINKED_LIST *list, char *name){
    // Trying to find the site in the list, if found the site alredy exists
    SITE *siteExists = NULL;
    siteExists = searchList(list, name);

    if (siteExists == NULL)
        return FALSE;
    else 
        return TRUE;
}