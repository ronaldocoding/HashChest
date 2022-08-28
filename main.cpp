//
//  main.c
//  HashChest
//
//  Created by Ronaldo Costa on 28/08/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define NAME_SIZE 100
#define TABLE_SIZE 31
#define MAX_CHEST_SLOTS 27
#define MAX_ITEMS_PER_SLOT 64

typedef struct Item
{
    char name[NAME_SIZE];
    int quantity;
    int key;
} Item;

typedef struct Node
{
    Item *item;
    struct Node * next;
    struct Node * previous;
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
Item *createItem(char itemName[NAME_SIZE], int itemQuantity, int itemKey);
Node *createNode(Item *item);
Slot* createSlot(void);
Chest * createChest(void);
bool isChestFull(Chest *chest);
void printChest(Chest * chest);

// Main functions
int hashFunction(int key, char *name);
int handleCollision(Chest *chest, Node *newNode, int pos);
int insertNode(Chest *chest, Item *item, int pos);
int removeNode(Chest *chest, char itemName[NAME_SIZE], int pos, int deleteNum);
Node * searchNode(Chest *chest, char itemName[NAME_SIZE], int pos);

int main(int argc, const char * argv[]) {
    Chest * chest = createChest();
    Item * lavaFluindo = createItem("LAVA FLUINDO", 10, 10);
    Item * deadBush = createItem("DEAD BUSH", 10, 32);
    insertNode(chest, lavaFluindo, hashFunction(lavaFluindo->key, lavaFluindo->name));
    insertNode(chest, deadBush, hashFunction(deadBush->key, deadBush->name));
    printChest(chest);
    removeNode(chest, lavaFluindo->name, hashFunction(lavaFluindo->key, lavaFluindo->name), 1);
    printChest(chest);
    removeNode(chest, lavaFluindo->name, hashFunction(lavaFluindo->key, lavaFluindo->name), 9);
    printChest(chest);
    Item * moreDeadBush = createItem("DEAD BUSH", 54, 32);
    insertNode(chest, moreDeadBush, hashFunction(moreDeadBush->key, deadBush->name));
    printChest(chest);
    Item * cascalho = createItem("CASCALHO", 15, 13);
    insertNode(chest, cascalho, hashFunction(cascalho->key, cascalho->name));
    Item * folhasDeCarvalho = createItem("FOLHAS DE CARVALHO", 10, 18);
    insertNode(chest, folhasDeCarvalho, hashFunction(folhasDeCarvalho->key, folhasDeCarvalho->name));
    Item * laBlanca = createItem("LA BRANCA", 5, 35);
    insertNode(chest, laBlanca, hashFunction(laBlanca->key, laBlanca->name));
    printChest(chest);
    removeNode(chest, folhasDeCarvalho->name, hashFunction(folhasDeCarvalho->key, folhasDeCarvalho->name), 10);
    printChest(chest);
    removeNode(chest, laBlanca->name, hashFunction(laBlanca->key, laBlanca->name), 6);
    printChest(chest);
    return 0;
}

Item * createItem(char itemName[NAME_SIZE], int itemQuantity, int itemKey)
{
    Item * newItem = (Item *) malloc(sizeof(Item));
    strcpy(newItem->name, itemName);
    newItem->quantity = itemQuantity;
    newItem->key = itemKey;
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
    printf("-----------------------------------------------------------------CHEST--------------------------------------------------\n");
    printf("Number of busy slots: %d\n\n", chest->busySlots);
    for(int i = 0; i < TABLE_SIZE; i++) {
        printf("|%d| -> ", i);
        Node * aux = chest->slots[i]->firstNode;
        while(aux != NULL) {
            printf("|Item: %s Quantidade: %d Chave: %d| -> ", aux->item->name, aux->item->quantity, aux->item->key);
            aux = aux->next;
        }
        printf("NULL\n");
    }
    printf("------------------------------------------------------------------------------------------------------------------------\n");
}

int hashFunction(int key, char *name)
{
    /*
     * Chaveia com base no codigo do item no minecraft e o nome
     * dele seguindo os codigos ASCII das 3 primeiras letras
     */
    key = key * 1000000 + name[0] * 10000 + name[1] * 100 + name[2];

    //Ex: FOGO
    /*
        Hash code = 51707971

        51 -> cod. do item fogo no minecraft
        F -> 70
        O -> 79
        G -> 71
     */

    // retorna a posição de 0 a 31
    return (key & 0x7FFFFFFF) % TABLE_SIZE;
}

int insertNode(Chest * chest, Item * item, int pos)
{
    if (isChestFull(chest))
      return 0;

    if(item->quantity <= 0)
      return 1;

    if(item->quantity > 64)
      return 2;
  
    Node * newNode = createNode(item);
    if (chest->slots[pos]->firstNode == NULL) {
      chest->slots[pos]->firstNode = newNode;
      chest->busySlots++;
      return 3;
    }

    return handleCollision(chest, newNode, pos);
}

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

Node * searchNode(Chest * chest, char itemName[NAME_SIZE], int pos)
{
  Node * result = createNode(NULL), * aux = chest->slots[pos]->firstNode;

  while (aux != NULL)
  {
    if (!strcmp(aux->item->name, itemName))
    {
      result->item = aux->item;
      result->next = aux->next;
      result->previous = aux->previous;
      return result;
    }
    aux = aux->next;
  }

  return NULL;
}
