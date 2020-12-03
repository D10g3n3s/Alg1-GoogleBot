#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <design.h>
#include <menulist.h>
#include <menuavl.h>

int main(){
    // LINKED_LIST *list = createList();
    AVL *tree = createAVL();

    // menuList(list);
    menuAVL(tree);

    // deleteList(list);
    deleteAVL(tree);

    return 0;
}