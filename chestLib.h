#ifndef CHEST_LIB
#define CHEST_LIB

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <windows.h>
#include <time.h>
#include <conio.h>

#define ALTURA 40
#define LARGURA 140
#define HOME 0
#define INSERIR 1
#define REMOVER 2
#define BUSCAR 3
#define SAIR 4

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

typedef struct telaInserir {
	int opt, qtd, page, escolheuItem, itemsPagina;
} telaInserir;

typedef struct telaRemover {
	int opt, page, escolheuItem;
} telaRemover;

typedef struct listagemEmTela {
	int opt, qtd, page, escolheuItem, itemsPagina;
} listagemEmTela;

int hashCodes[27];

/*global var declaration*/
// opt = escolha do usuario
extern int opt;
// page = pagina atual
extern int page;

//itens do mine
Item* itensMineCraft[27];

Chest* chest;

extern telaInserir inserir;
extern listagemEmTela listagem;
extern telaRemover remover;

/* Functions Interface */

// Main functions

void showHome(int tecla);
void showInserir (int tecla, int *pontIndice);
void showBuscar (int tecla); //ok
void showRemover (int tecla); //ok

// utils screen
void gotoxy (int x, int y);
void showListItens(int tecla);
void controlaListagem(int tecla);
void showInstructions();
void controlPagination();


// colors
void green();
void blue();
void red();
void yellow();
void purple();
void white();

// draw in screen
void moldura( int x1, int x2, int y1, int y2);
void molduraTela ();
void ImprimeAviao (int x, int y);
void empty ( int x1, int x2, int y1, int y2);
void desenhaAviso(char *aviso);
void transicaoFim (int x1, int x2, int y1, int y2, int ax, int ay);
void transicaoInicio (int x1, int x2, int y1, int y2, int ax, int ay);
void cabecaSteve (int x, int y);
void desenhaBauFechado (int x, int y);
void desenhaBauAberto (int x, int y);
void title (int x, int y);
void desenhaOpcoes (int escolhido);
void updateTextInScreen(char *aviso);

// Utils functions
Item *createItem(char itemName[NAME_SIZE], int itemQuantity, int itemKey);
Node *createNode(Item *item);
Slot* createSlot(void);
Chest * createChest();
bool isChestFull();
void printChest();
void initializeItensLib();
void initializeHashCodes();

// Main functions
int hashFunction(int key, char *name);
int handleCollision( Node *newNode, int pos);
int insertNode(Item *item, int pos);
int removeNode(char itemName[NAME_SIZE], int pos, int deleteNum);
Node * searchNode(char itemName[NAME_SIZE], int pos);


#endif /* chestLib_h */
