#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define NAME_SIZE 100 // Valor global
#define TABLE_SIZE 31 // Valor global

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

Slot * chest[TABLE_SIZE]; // Struct global

int hashFunction(int key);
void handleCollision(Node * newNode, int pos);
void insert(Item item, int pos);
void remove(char itemName[NAME_SIZE], int pos);
int search(int key);

#endif
