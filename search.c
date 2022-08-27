#include "chestLib.h"
#include "handleCollision.c"

Result searchNode(Chest *chest, char itemName[NAME_SIZE], int pos)
{
  Result result;
  result.position = position;
  result.isAlone = true;

  Node *aux = chest.slots[position]->firstNode;

  while (aux != NULL)
  {
    if (strcmp(aux->item.name, name) != 0)
      result.item = aux->item;
    else
      result.isAlone = false;

    aux = aux->next;
  }

  if (result.item != NULL)
    return result;

  return NULL;
}
