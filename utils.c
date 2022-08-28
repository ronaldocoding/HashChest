#include "chestLib.h"
#include<string.h>

Item * createItem(char itemName[NAME_SIZE], int itemQuantity, int itemKey) {
    Item * newItem = (Item *) malloc(sizeof(Item));
    strcpy(newItem->name, itemName);
    newItem->quantity = itemQuantity;
    newItem->key = itemKey;
    return newItem;
}

Node * createNode(Item * item) {
    Node * newNode = (Node *) malloc(sizeof(Node));
    newNode->item = item;
    newNode->next = NULL;
    newNode->previous = NULL;
    return newNode;
}

bool isChestFull(Chest * chest) {
    return chest->busySlots == MAX_CHEST_SLOTS;
}

void initializeChest(Chest * chest) {
    for(int i = 0; i < TABLE_SIZE; i++) {
        chest->slots[i]->firstNode = NULL;
    }
    chest->busySlots = 0;
}
