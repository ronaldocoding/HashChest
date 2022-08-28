#include "chestLib.h"
#include <string.h>

int removeNode(Chest * chest, char itemName[NAME_SIZE], int pos, int deleteNum)
{
    // Procura se um nó com esse nome já existe
    Node * existingNode = searchNode(chest, itemName, pos);

    // Caso exista
    if(existingNode != NULL)
    {
        // Caso a quantidade de itens a serem deletados seja maior ou igual a
        // quantidade atual
        if(deleteNum >= existingNode->item->quantity)
        {
            // Deleta nó

            // Caso seja o primeiro nó da lista
            if(existingNode->previous == NULL)
            {
                chest->slots[pos]->firstNode = existingNode->next;

                // Caso o primeiro e único nó da lista
                if(existingNode->next == NULL)
                {
                    chest->busySlots--;
                }

                // Caso seja o primeiro, mas não o único
                else
                {
                    existingNode->next->previous = NULL;
                }
            }

            // Caso não seja o primeiro nó da lista
            else
            {
                existingNode->previous->next = existingNode->next;

                // Caso não seja o primeiro nem o último
                if(existingNode->next != NULL)
                {
                    existingNode->next->previous = existingNode->previous;
                }
            }
            // Libera nó da memória
            free(existingNode);
            return 0;
        }

        // Caso a quantidade de itens a serem deletados não seja maior ou igual
        // a quantidade atual
        else {
            // Apenas decrementa quantidade atual
            existingNode->item->quantity -= deleteNum;
            return 1;
        }
    }

    // Caso o nó não exista
    else
    {
        return 2;
    }
}

// signated by: HRK
