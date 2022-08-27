#include "chestLib.h"

int handleCollision(Chest * chest, Node * newNode, int pos) {
    newNode->next = chest->slots[pos]->firstNode;
    chest->slots[pos]->firstNode = newNode;
    return 2;
}
