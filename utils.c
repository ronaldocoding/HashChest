#include "chestLib.h"

Node * createNode(Item item) {
    Node * newNode = (Node *) malloc(sizeof(Node));
    newNode->item = item;
    newNode->next = NULL;
    return newNode;
}

bool isChestFull() {
    //return busySlots == TABLE_SIZE;
}

void initializeChest() {
    for(int i = 0; i < TABLE_SIZE; i++) {
        chest.slots[i]->firstNode = NULL;
    }
    chest.busySlots = 0;
}
