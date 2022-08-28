#include "chestLib.h"

Node * searchNode(Chest * chest, char itemName[NAME_SIZE], int pos)
{
  Node * result = NULL, * aux = chest->slots[pos]->firstNode;

  while (aux != NULL)
  {
    if (strcmp(aux->item->name, itemName) != 0) 
    {
      result->item = aux->item;
      return result;
    }
    aux = aux->next;
  }

  return result;
}
