#include "chestLib.h"

void handleCollision(Node * newNode, int pos) {
    newNode->next = chest.slots[pos]->firstNode;
    chest.slots[pos]->firstNode = newNode;
}
