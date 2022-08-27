#include "chestLib.h"

struct Result searchNode(Chest *chest, char itemName[NAME_SIZE], int pos)
{
  Result result;
  result.position = pos;
  result.isAlone = true;

  Node *aux = chest->slots[pos]->firstNode;

  while (aux != NULL)
  {
    if (strcmp(aux->item->name, itemName) != 0)
      result.item = *aux->item;
    else
      result.isAlone = false;

    aux = aux->next;
  }

  if (result.item.key)
    return result;

  return result; //corrigir esse retorno para equivalente a NULL
}
