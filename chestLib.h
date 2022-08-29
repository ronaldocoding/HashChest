#ifndef chestLib_h
#define chestLib_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define NAME_SIZE 100
#define TABLE_SIZE 31
#define MAX_CHEST_SLOTS 27
#define MAX_ITEMS_PER_SLOT 64

typedef struct Item
{
    char name[NAME_SIZE];
    int quantity;
    int key;
    int pos;
} Item;

typedef struct Node
{
    Item *item;
    struct Node *next;
    struct Node *previous;
} Node;

typedef struct Slot
{
    Node *firstNode;
} Slot;

typedef struct Chest
{
    Slot *slots[TABLE_SIZE];
    int busySlots;
} Chest;

// Utils functions
Item * createItem(char itemName[NAME_SIZE], int itemQuantity, int itemKey);
Node * createNode(Item *item);
Slot * createSlot(void);
Chest * createChest(void);
bool isChestFull(Chest *chest);
void printChest(Chest * chest);

// Main functions
int hashFunction(int key, char *name);
int handleCollision(Chest *chest, Node *newNode, int pos);
int insertNode(Chest *chest, Item *item, int pos);
int removeNode(Chest *chest, char itemName[NAME_SIZE], int pos, int deleteNum);
Node * searchNode(Chest *chest, char itemName[NAME_SIZE], int pos);


#endif /* chestLib_h */
