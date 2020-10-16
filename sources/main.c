#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "design.h"
#include "menu.h"

int main(){
    LINKED_LIST *list = createList();

    menu(list);

    deleteList(list);

    return 0;
}