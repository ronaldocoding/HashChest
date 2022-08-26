#include "chestLib.h"

int handleCollision(Chest * chest, Node * node, int pos) {
  node->next = chest->slots[pos]->firstNode;
  chest->slots[pos]->firstNode = node;
  return 2;
}
