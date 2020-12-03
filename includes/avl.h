#ifndef AVL_H
    #define AVL_H

    #include <site.h>
    #include <utils.h>

    typedef struct _node NODE;
    typedef struct _avl AVL;

    AVL *createAVL();
    bool isEmpty(AVL *tree);
    void printStaticAVL(AVL *tree);
    void printInfixOrder(AVL *tree);
    void printPostfixOrder(AVL *tree);
    void printPrefixOrder(AVL *tree);
    int countNumNodes(AVL *tree);
    int treeHeight(AVL *tree);
    bool deleteAVL(AVL *tree);
    bool insertAVL(AVL *tree, SITE *site);
    SITE* searchTree(AVL *tree, int code);
    bool deleteNodeAVL(AVL *tree, int code);
    bool checkExistence(AVL *tree, char *string);

#endif