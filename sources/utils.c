#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function that reads a string of undefined size and allocates the exact size of heap memory 
char* readLine(FILE* input){
    char *str;

    str = (char*) malloc (32 * sizeof(char)); //Doing inicial allocation

    int pos = 0, tamanho = 32;
    
    do {
        // Reallocating the heap memory in case the word exceds the limit
        if (pos == tamanho) {
            str = realloc (str, 2 * tamanho);
            tamanho *= 2;
        }

        // Getting the chars
        str[pos] = (char) fgetc(input);
        if (str[pos] == '\r') pos--;
        pos++;

    } while (str[pos-1] != '\n' && !feof(input));

    str[pos-1] = '\0'; 
    str = realloc(str, pos);
    
    return str;
}

// Function that reads only one word
char* readWord(FILE* input){
    char *str;

    // Doing the inicial allocation
    str = (char*) malloc(32 * sizeof(char)); 

    int pos = 0, tamanho = 32;
    
    do {
        // Reallocating the size of the heap memory in case the words exceds the max limit
        if (pos == tamanho) {
            str = realloc(str, 2 * tamanho);
            tamanho *= 2;
        }

        // Reading the chars
        str[pos] = (char) fgetc(input);
        pos++;
        if (str[pos-1] == '\r' ) pos--;
        else if (str[pos-1] == '\n') break;

    } while (str[pos-1] != ' ' && !feof(input));

    str[pos-1] = '\0';
    str = realloc(str, pos);
    
    return str;
}

char* myStrndump(const char* string, int n) {
    int size = strlen(string)+1;

    if (n < size)
        size = n+1;

    char* result = malloc(size);

    if(result != NULL) {
        memcpy(result, string, size);
        result[size - 1] = '\0';
    }

    return result;
}