#include "chestLib.h"

void handleCollision(Node * newNode, int pos) {
    newNode->next = chest[pos]->firstNode;
    chest[pos]->firstNode = newNode;
}
