#include "chestLib.h"
#include <string.h>
#include <math.h>

int hashFunction(int key, char *name)
{
    key = name[0] * pow(128, 3) + name[1] * pow(128, 2) + name[2] * pow(128, 1) + name[3] * pow(128, 0);
    
    // retorna a posição de 0 a 30
    return (key & 0x7FFFFFFF) % TABLE_SIZE;
}
