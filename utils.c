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
    return newNode;
}

bool isChestFull(Chest * chest) {
    return chest->busySlots == TABLE_SIZE;
}

void initializeChest(Chest * chest) {
    int i;
    for(i = 0; i < TABLE_SIZE; i++) {
        chest->slots[i]->firstNode = NULL;
    }
    chest->busySlots = 0;
}
