#include "chestLib.h"
#include <string.h>

Item * createItem(char itemName[NAME_SIZE], int itemQuantity, int itemKey)
{
    Item * newItem = (Item *) malloc(sizeof(Item));
    strcpy(newItem->name, itemName);
    newItem->quantity = itemQuantity;
    newItem->key = itemKey;
    newItem->pos = -1;
    return newItem;
}

Node * createNode(Item * item)
{
    Node * newNode = (Node *) malloc(sizeof(Node));
    newNode->item = item;
    newNode->next = NULL;
    newNode->previous = NULL;
    return newNode;
}

Slot * createSlot(void) {
    Slot * newSlot = (Slot *) malloc(sizeof(Slot));
    newSlot->firstNode = NULL;
    return newSlot;
}

Chest * createChest(void)
{
    Chest * newChest = (Chest *) malloc(sizeof(Chest));
    for(int i = 0; i < TABLE_SIZE; i++) {
        newChest->slots[i] = createSlot();
    }
    newChest->busySlots = 0;
    return newChest;
}

bool isChestFull(Chest * chest)
{
    return chest->busySlots == MAX_CHEST_SLOTS;
}

void printChest(Chest * chest)
{
    printf("------------------------MODO HASH TABLE-------------------------\n");
    printf("NÚMERO DE SLOTS OCUPADOS: %d\n\n", chest->busySlots);
    for(int i = 0; i < TABLE_SIZE; i++) {
        printf("|%d| -> ", i);
        Node * aux = chest->slots[i]->firstNode;
        while(aux != NULL) {
            printf("|Item: %s Quantidade: %d Chave: %d| -> ", aux->item->name, aux->item->quantity, aux->item->key);
            aux = aux->next;
        }
        printf("NULL\n");
    }
    printf("----------------------------------------------------------------\n");
}
