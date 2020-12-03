#ifndef LINKEDLIST_H
    #define LINKEDLIST_H

    #include <site.h>
    #include <utils.h>

    typedef struct _linkedList LINKED_LIST;

    LINKED_LIST* createList();
    int listLength(LINKED_LIST *list);
    bool emptyList(LINKED_LIST *list);
    bool insertList(LINKED_LIST *list, SITE *site);
    SITE* searchList(LINKED_LIST *list, int code);
    bool removeSite(LINKED_LIST *list, int code);
    void printList(LINKED_LIST *list);
    bool deleteList(LINKED_LIST *list);
    bool checkExistence(LINKED_LIST *list, char* string);

#endif