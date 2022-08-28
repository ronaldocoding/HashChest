#ifndef chestLib_h
#define chestLib_h
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define NAME_SIZE 100
#define TABLE_SIZE 31

typedef struct Item
{
    char name[NAME_SIZE];
    int quantity;
    int key;
} Item;

typedef struct Result
{
    Item item;
    int position;
    bool isAlone;
} Result;

typedef struct Node
{
    Item *item;
    struct Node *next;
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

extern int hashCode[27];

// Utils functions
Item *createItem(char itemName[NAME_SIZE], int itemQuantity, int itemKey);
Node *createNode(Item *item);
bool isChestFull(Chest *chest);
void initializeChest(Chest *chest);

// Main functions
int hashFunction(int key, char *name);
int handleCollision(Chest *chest, Node *newNode, int pos);
int insertNode(Chest *chest, Item *item, int pos);
void removeNode(Chest *chest, char itemName[NAME_SIZE], int pos);
Result searchNode(Chest *chest, char itemName[NAME_SIZE], int pos);

#endif
