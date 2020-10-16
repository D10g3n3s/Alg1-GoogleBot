#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

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

//Funcation that creates a linked list
LINKED_LIST* createList(){
    LINKED_LIST *list = malloc(sizeof(LINKED_LIST));

    if (list != NULL){
        list->head = NULL;
        list->tail = NULL;
        list->length = 0;
    }

    return list;
}

//Function that return the length of a list
int listLength(LINKED_LIST *list){
    return list->length;
}

//Function that checks if list is empty
bool emptyList(LINKED_LIST *list){
    if (list != NULL && list->length == 0)
        return TRUE;

    return FALSE;
}

//Function that inserts in a list in a ordenated way
bool insertList(LINKED_LIST *list, SITE *site){
    if (list == NULL || site == NULL)
        return FALSE;
    
    NODE *data = malloc(sizeof(NODE));
    data->site = site;
    data->next = NULL;

    if (data == NULL)
        return FALSE;

    //If list is empty begin from the start of the list
    if (emptyList(list)){
        list->head = data;
        list->tail = data;
        list->length++;
        return TRUE;
    }

    //Searching for the right place to insert
    else {
        //Checking if the incoming data comes in the start of the list
        if (siteGetCode(data->site) < siteGetCode(list->head->site)){
            NODE *aux = list->head;
            list->head = data;
            list->head->next = aux;
            list->length++;
            aux = NULL;
            return TRUE;
        }

        NODE *prev = list->head;
        NODE *next = list->head->next;

        //Searching for the right place
        while (next != NULL && siteGetCode(data->site) >= siteGetCode(next->site)){
            prev = next;
            next = next->next;
        }

        //If the data is inserted in the end of the list
        if (next == NULL){
            prev->next = data;
            list->tail = data;
        }

        //Inserting in the right place
        else {
            data->next = next;
            prev->next = data;
        }
    }

    list->length++;
    return TRUE;
}

//Function that searchs for a site in the list based in a code
SITE* searchList(LINKED_LIST *list, int code){
    NODE *data;

    if (list != NULL){
        data = list->head;
        while (data != NULL){
            if (siteGetCode(data->site) == code)
                return data->site;
            data = data->next;
        }
    }

    return NULL;
}

//Function that removes from the list based in a code
bool removeSite(LINKED_LIST *list, int code){
    if (list != NULL){
        NODE *prev = NULL;
        NODE *next = list->head;

        while (next != NULL && siteGetCode(next->site) != code){
            prev = next;
            next = next->next;
        }

        //In case the data is found
        if (next != NULL){
            //If the data is the init of the list
            if (next == list->head){
                list->head = next->next;
                next->next = NULL;
            }

            else {
                prev->next = next->next;
                next->next = NULL;
            }

            //Checking if the removed item is the end of the list
            if (next == list->tail)
                list->tail = prev;

            list->length--;
            deleteSite(next->site);
            free(next);
            return TRUE;
        }
    }

    return FALSE;
}

//Function that print the entire list
void printList(LINKED_LIST *list){
    NODE *data;

    if (list != NULL){
        data = list->head;

        while (data != NULL){
            printSite(data->site);
            data = data->next;
        }
    }
    printf("\n");
}

//Function that deletes a list
bool deleteList(LINKED_LIST *list){
    if (list != NULL){
        NODE *data;

        while (list->head != NULL){
            data = list->head;
            list->head = list->head->next;
            deleteSite(data->site);
            free(data);
        }
        free(list);

        return TRUE;
    }

    else
        return FALSE;
}

//Function that checks if a code from given data alredy exists in the list
bool checkExistence(LINKED_LIST *list, char *string){
    //Discovering the code of given data
    char *checkExistance = myStrndump(string, 4);
    int code = atoi(checkExistance);
    free(checkExistance);

    //Trying to find the site in the list, if found code alredy existes
    SITE* siteExiste = NULL;
    siteExiste = searchList(list, code);

    if (siteExiste == NULL)
        return FALSE;
    else 
        return TRUE;
}