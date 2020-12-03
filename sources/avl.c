#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <avl.h>
#include <design.h>

struct _node{
    // Site of the node
    SITE *site; 
    // Balance Factor
    int bf; 
    // Nodes to the childrens
    NODE *left;
    NODE *right;
};

struct _avl{
    // root of the tree
    NODE *root;
};

// Function that creates a new AVL tree
AVL *createAVL(){
    AVL *tree = malloc(sizeof(AVL));

    if (tree != NULL)
        tree->root = NULL;

    return tree;
}

// Function that checks if the tree is empty
bool isEmpty(AVL *tree){
    if (tree == NULL || tree->root == NULL)
        return TRUE;
    
    return FALSE;
}

// Auxiliar function to infix order print
void infixAux(NODE *node){
    if (node != NULL){
        infixAux(node->left);
        printSite(node->site);
        infixAux(node->right);
    }
}

// Function that prints the tree in infix order
void printInfixOrder(AVL *tree){
    if (tree != NULL)
        infixAux(tree->root);
}

// Auxiliar function to the count the number of nodes from a tree
int countNodes(NODE *node){
    if (node == NULL)
        return 0;
    return (1 + countNodes(node->left) + countNodes(node->right));
}

// Function that count the number of nodes of a tree
int countNumNodes(AVL *tree){
    if (tree != NULL)
        return countNodes(tree->root);
    
    return 0;
}

// Auxiliar function to check the height of a tree
int height(NODE *node){
    if (node == NULL)
        return 0;

    int leftHeight = 1 + height(node->left);
    int rightHeight = 1 + height(node->right);

    if (leftHeight > rightHeight)
        return leftHeight;
    else
        return rightHeight;
}

// Function that returns the height of a tree
int treeHeight(AVL *tree){
    if (tree != NULL)
        return height(tree->root);

    return 0;
}

// Auxiliar function that creates a node with given site
NODE *createNode(SITE *site){
    NODE *newnode = malloc(sizeof(NODE));

    if (newnode != NULL){
        newnode->site = site;
        newnode->bf = 0;
        newnode->left = NULL;
        newnode->right = NULL;
    }

    return newnode;
}

// Auxiliar function that does a simple right rotation
NODE* rotationRight(NODE *node){
    NODE *aux = node->left;
    node->left = aux->right;
    aux->right = node;

    return aux;
}

// Auxiliar function that does a simple left rotation
NODE* rotationLeft(NODE *node){
    NODE *aux = node->right;
    node->right = aux->left;
    aux->left = node;

    return aux;
}

// Auxiliar function that does a double rotation a simple to the right and after to the left
NODE* rotationRightLeft(NODE *node){
    node->right = rotationRight(node->right);
    node = rotationLeft(node);
    
    return node;
}

// Auxiliar function that does a double rotation a simple to the left and after to the right
NODE* rotationLeftRight(NODE *node){
    node->left = rotationLeft(node->left);
    node = rotationRight(node);

    return node;
}

// Auxiliar function to insert a site into the tree
NODE* insertNode(NODE *node, SITE *site, int *flag){
    if (node != NULL && site != NULL){
        // Finding the right place to insert the node
        if (siteGetCode(node->site) > siteGetCode(site)){
            node->left = insertNode(node->left, site, flag);
            if (*flag == 1){
                switch(node->bf){
                    case -1:
                        node->bf = 0;
                        *flag = 0;
                        break;

                    case 0:
                        node->bf = 1;
                        *flag = 1;
                        break;

                    case 1:
                        if (node->left->bf == 1){
                            node = rotationRight(node);
                            node->right->bf = 0;
                            node->bf = 0;
                        }
                        else {
                            node = rotationLeftRight(node);
                            if (node->bf == -1){
                                node->left->bf = 1;
                                node->right->bf = 0;
                                node->bf = 0;
                            }
                            else if (node->bf == 1){
                                node->left->bf = 0;
                                node->right->bf = -1;
                                node->bf = 0;
                            }
                            // node->bf == 0
                            else {
                                node->left->bf = 0;
                                node->right->bf = 0;
                                node->bf = 0;
                            }
                        }
                        *flag = 0;
                        break;
                }
            }
        }
        else if (siteGetCode(node->site) < siteGetCode(site)){
            node->right = insertNode(node->right, site, flag);
            if (*flag == 1){
                switch(node->bf){
                    case 1:
                        node->bf = 0;
                        *flag = 0;
                        break;

                    case 0:
                        node->bf = -1;
                        *flag = 1;
                        break;

                    case -1:
                        if (node->right->bf == -1){
                            node = rotationLeft(node);
                            node->left->bf = 0;
                            node->bf = 0;
                        }
                        else {
                            node = rotationRightLeft(node);
                            if (node->bf == -1){
                                node->left->bf = 1;
                                node->right->bf = 0;
                                node->bf = 0;
                            }
                            else if (node->bf == 1){
                                node->left->bf = 0;
                                node->right->bf = -1;
                                node->bf = 0;
                            }
                            // node->bf == 0
                            else {
                                node->left->bf = 0;
                                node->right->bf = 0;
                                node->bf = 0;
                            }
                        }
                        *flag = 0;
                        break;
                }
            }
        }
        else
            alredyExists();
    }
    else {
        node = createNode(site);
        *flag = 1;
    }

    return node;
}

// Function that inserts a site into the tree
bool insertAVL(AVL* tree, SITE *site){
    if (tree != NULL && site != NULL){
        int flag = 0;
        tree->root = insertNode(tree->root, site, &flag);
        return TRUE;
    }

    return FALSE;
}

// Auxiliar functoin to search for a node into the tree
SITE* search(NODE *node, int code){
    if (node == NULL)
        return NULL;
    // Returning the site if it exists
    else if (siteGetCode(node->site) == code)
        return node->site;
    // Going deeper into the left side of the tree
    else if (siteGetCode(node->left->site) > code)
        return search(node->left, code);
    // Going deeper into the right side of the tree
    else
        return search(node->right, code);
}

// Function that searchs for a site into the tree given a code
SITE* searchTree(AVL *tree, int code){
    if (tree != NULL)
        return search(tree->root, code);

    return NULL;    
}

bool checkAVLExistence(AVL *tree, char *string){
    // Discovering the code of given data
    char *exists = myStrndump(string, 4);
    int code = atoi(exists);
    free(exists);

    SITE* siteExists = NULL;
    siteExists = searchTree(tree, code);

    if (siteExists == NULL)
        return FALSE;
    else
        return TRUE;
}

// Function that does the balance to the left of a tree after some node being removed
NODE* leftBalance(NODE *node, int *height){
    if (node != NULL){
        switch (node->bf){
            // Height has changed
            case 1:
                node->bf = 0;
                break;

            // Height hasn't changed
            case 0:
                node->bf = -1;
                *height = 0;
                break;
            
            // Height has changed and the tree isn't balanced anymore
            case -1:
                if (node->right->bf <= 0){
                    node = rotationLeft(node);
                    // Height hasn't changed after the rotation
                    if (node->bf == 0){
                        node->left->bf = -1;
                        node->bf = 1;
                        // Setting this flag to 0 says we don't need to check for other changes
                        *height = 0;
                    }

                    // Height has changed after the rotation
                    else {
                        node->left->bf = 0;
                        node->bf = 0;
                    }
                }
                else {
                    node = rotationRightLeft(node);
                    if (node->bf == 1){
                        node->left->bf = 0;
                        node->right->bf = -1;
                    }
                    else if (node->bf == -1){
                        node->left->bf = 1;
                        node->right->bf = 0;
                    }
                    // node->bf == 0
                    else {
                        node->left->bf = 0;
                        node->right->bf = 0;
                    }
                    node->bf = 0;
                }
                break;
        }
    }

    return node;
}

// Function that does the balance to the right of a tree after some node being removed
NODE* rightBalance(NODE* node, int *height){
    if (node != NULL){
        switch (node->bf){
            // Height has changed
            case -1:
                node->bf = 0;
                break;

            // Height hasn't changed
            case 0:
                node->bf = 1;
                *height = 0;
                break;

            // Height has changed and the tree isn't balanced anymore
            case 1:
                if (node->left->bf >= 0){
                    node = rotationRight(node);
                    // Height hasn't change after the rotation
                    if (node->bf == 0){
                        node->left->bf = 1;
                        node->bf = -1;
                        // Setting this flag to 0 says we don't need to check for others changes
                        *height = 0; 
                    }
                    
                    // Height has changed after the rotation
                    else {
                        node->right->bf = 0;
                        node->bf = 0;
                    }
                }
                else {
                    node = rotationLeftRight(node);
                    if (node->bf == 1){
                        node->left->bf = 0;
                        node->right->bf = -1;
                    }
                    else if (node->bf == -1){
                        node->left->bf = 1;
                        node->right->bf = 0;
                    }
                    // node->bf == 0
                    else {
                        node->left->bf = 0;
                        node->right->bf = 0;
                    }
                    node->bf = 0;
                }
                break;
        }
    }

    return node;
}

// Function that recursively searches for the biggest node into the left subtree
NODE* searchRemove(NODE* node, NODE *keyNode, int *height){
    if (node->right != NULL){
        node->right = searchRemove(node->right, keyNode, height);

        // After removing the right node, balancing the tree
        if (*height == 1)
            node = rightBalance(node, height);
    }
    else {
        keyNode->site = node->site;
        NODE *aux;
        aux = node;
        node = node->left;
        deleteSite(aux->site);
        free(aux);
        // Setting this flag for 1 causes the tree to checks for any necessary balancing
        *height = 1;
    }

    return node;
}

// Auxiliar function to delete a site from a tree
NODE* deleteNode(NODE* node, int code, int *height){
    NODE *aux;

    if (node == NULL)
        *height = 0;
    else if (siteGetCode(node->site) > code){
        node->left = deleteNode(node->left, code, height);
        if (*height == 1)
            node = leftBalance(node, height);
    }
    else if (siteGetCode(node->site) < code){
        node->right = deleteNode(node->right, code, height);
        if (*height == 1)
            node = rightBalance(node, height);
    }
    // Found the site we want to remove from the tree
    else {
        if (node->right == NULL){
            aux = node;
            node = node->left;
            deleteSite(aux->site);
            free(aux);
            *height = 1;
        }
        else if (node->left == NULL){
            aux = node;
            node = node->right;
            *height = 1;
        }
        else {
            node->left = searchRemove(node->left, node, height);
            if (*height == 1)
                node = leftBalance(node, height);
        }
    }

    return node;
}

// Function that deletes a site from the tree given it's code
bool deleteNodeAVL(AVL *tree, int code){
    if (tree != NULL){
        int height = 0;
        tree->root = deleteNode(tree->root, code, &height);
        return TRUE;
    }

    return FALSE;
}

// Auxiliar function to delete the leaves of a tree
void delete(NODE *node){
    if (node != NULL){
        delete(node->left);
        delete(node->right);
        deleteSite(node->site);
        free(node);
        node = NULL;
    }
}

// Function that deletes a AVL tree
bool deleteAVL(AVL *tree){
    if (tree != NULL){
        delete(tree->root);
        free(tree);
        tree = NULL;
        return TRUE;
    }

    return FALSE;
}