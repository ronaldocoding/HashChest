#include <stdio.h>
#include <stdlib.h>
#include "chestLib.h"

int main(int argc, const char * argv[]) {
    Chest * chest = (Chest *) malloc(sizeof(Chest));
    initializeChest(chest);
    printf("%d\n", hashFunction(256, "PICKAXE"));
    return 0;
}
