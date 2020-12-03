#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <list.h>
#include <design.h>
#include <menu.h>
#include <avl.h>

int main(){
    LINKED_LIST *list = createList();
    AVL *tree = createAVL();

    menu(list, tree);

    deleteList(list);
    deleteAVL(tree);

    return 0;
}