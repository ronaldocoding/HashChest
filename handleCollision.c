#include "chestLib.h"
#include <string.h>

int handleCollision(Chest * chest, Node * newNode, int pos)
{
    // Procura se um nó com esse nome já existe
    Node * existingNode = searchNode(chest, newNode->item->name, pos);

    // Caso exista
    if(existingNode != NULL)
    {
        // Testa se a quantidade a ser incrementada ultrapassa MAX_ITEMS_PER_SLOT
        if(existingNode->item->quantity + newNode->item->quantity > MAX_ITEMS_PER_SLOT)
        {
            free(newNode);
            return 4;
        }
        // Caso não ultrapasse, incrementa a quantidade de itens existentes
        existingNode->item->quantity += newNode->item->quantity;
        free(newNode);
        return 5;
    }
    
    // Caso não exista, insere novo nó no início da lista
    newNode->next = chest->slots[pos]->firstNode;
    chest->slots[pos]->firstNode->previous = newNode;
    chest->slots[pos]->firstNode = newNode;
    return 6;
}
