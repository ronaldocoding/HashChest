#include "chestLib.h"

int insertNode(Chest * chest, Item * item, int pos) {
  if (isChestFull()) {
    return 0;
  }
  Node * node = createNode(item);
  if (chest->slots[pos]->firstNode == NULL) {
    chest->slots[pos]->firstNode = node;
    chest->busySlots++;
    return 1;
  }
  return handleCollision();
}    
