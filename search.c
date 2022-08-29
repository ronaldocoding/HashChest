#include "chestLib.h"
#include <string.h>

Node * searchNode(Chest * chest, char itemName[NAME_SIZE], int pos)
{
  Node * result = createNode(NULL), * aux = chest->slots[pos]->firstNode;

  while (aux != NULL)
  {
    if (!strcmp(aux->item->name, itemName))
    {
      result->item = aux->item;
      result->next = aux->next;
      result->previous = aux->previous;
      return result;
    }
    aux = aux->next;
  }

  return NULL;
}
