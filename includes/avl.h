#ifndef AVL_H
    #define AVL_H

    #include <site.h>
    #include <list.h>
    #include <utils.h>

    typedef struct _node NODE;
    typedef struct _avl AVL;

    AVL *createAVL();
    bool isEmpty(AVL *tree);
    void printStaticAVL(AVL *tree);
    void printInOrder(AVL *tree);
    int countNumNodes(AVL *tree);
    int treeHeight(AVL *tree);
    bool deleteAVL(AVL *tree);
    bool insertAVL(AVL *tree, SITE *site);
    SITE *searchTree(AVL *tree, int code);
    bool deleteNodeAVL(AVL *tree, int code);
    bool checkAVLExistence(AVL *tree, char *string);
    LINKED_LIST *createKeyWordList(AVL *tree, char *string);
    LINKED_LIST *createSuggestedList(AVL *tree, LINKED_LIST *listSites);

#endif