#include "chestLib.h"

int hashFunction(int key) {
    
    return (key & 0x7FFFFFFF) % TABLE_SIZE;
    
}
