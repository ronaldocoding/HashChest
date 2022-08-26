#include "chestLib.h"
#include <string.h>

int hashFunction(int key, char *name) {
    /* 
     * Chaveia com base no codigo do item no minecraft e o nome
     * dele seguindo os codigos ASCII das 3 primeiras letras
     */
    key = key * 1000000 + name[0] * 10000 + name[1] * 100 + name[2]; 

    //Ex: FOGO
    /* 
        Hash code = 51707971

        51 -> cod. do item fogo no minecraft
        F -> 70
        O -> 79
        G -> 71
     */

    // retorna a posição de 0 a 31
    return (key & 0x7FFFFFFF) % TABLE_SIZE;
}
