#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <design.h>
#include <menuavl.h>

int main(){
    AVL *tree = createAVL();

    menuAVL(tree);

    deleteAVL(tree);

    return 0;
}