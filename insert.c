#include "chestLib.h"

int insertNode(Chest * chest, Item * item, int pos)
{
    if (isChestFull(chest))
    {
        free(item);
        return 0;
    }

    if(item->quantity <= 0)
    {
        free(item);
        return 1;
    }

    if(item->quantity > 64)
    {
        free(item);
        return 2;
    }
  
    Node * newNode = createNode(item);
    if (chest->slots[pos]->firstNode == NULL) {
        chest->slots[pos]->firstNode = newNode;
        chest->busySlots++;
        return 3;
    }

    return handleCollision(chest, newNode, pos);
}
