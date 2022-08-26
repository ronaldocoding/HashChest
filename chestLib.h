#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define NAME_SIZE 100
#define TABLE_SIZE 31

typedef struct Item {
    char name[NAME_SIZE];
    int quantity;
    int key;
} Item;

typedef struct Node {
    Item item;
    struct Node * next;
} Node;

typedef struct Slot {
    Node * firstNode;
} Slot;

typedef struct Chest {
    Slot * slots[TABLE_SIZE];
    int busySlots;
} Chest;

Chest chest;

// Utils functions
Node * createNode(Item item);
bool isChestFull();
void initializeChest();

// Main functions
int hashFunction(int key, char *name);
void handleCollision(Node * newNode, int pos);
void insertNode(Item item, int pos);
void removeNode(char itemName[NAME_SIZE], int pos);
int searchNode(int key);

#endif
