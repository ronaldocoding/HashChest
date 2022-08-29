#include "chestLib.h"
#include <string.h>

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

bool isChestFull()
{
    return chest->busySlots == MAX_CHEST_SLOTS;
}

void printChest()
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

void initializeItensLib(){
    char names[100][27] = {{"LAVA FLUINDO"}, {"AINDA LAVA"}, {"AREIA"}, {"CASCALHO"},
                      {"MINERIO DE OURO"}, {"MINERIO DE FERRO"}, {"MINERIO DE CARVAO"},
                      {"MADEIRA DE CARVALHO"}, {"FOLHAS DE CARVALHO"}, {"ESPONJA"}, {"VIDRO"},
                      {"MINERIO DE LAPIS LAZULI"}, {"BLOCO LAPIS LAZULI"}, {"DISPENSADOR"},
                      {"ARENITO"}, {"BLOCO DE NOTAS"}, {"CAMA"}, {"TRILHO MOTORIZADO"}, {"DETECTOR RAIL"},
                      {"STICKY PISTON"}, {"TEIA DE ARANHA"}, {"DEAD SHRUB"}, {"DEAD BUSH"}, {"PISTAO"},
                      {"CABECA DE PISTAO"}, {"LA BRANCA"}, {"DANDELION"}};

    int keys[27] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
                30, 31, 32, 33, 34, 35, 37};

    for (int i = 0; i < 27; i++) {
      Item *item = createItem(names[i], 0, keys[i]);
      itensMineCraft[i] = item;
    }
}


int itemsPerPage = 7, altura = 2;

void gotoxy (int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition (GetStdHandle (STD_OUTPUT_HANDLE), coord);
}

void showListItens(int tecla) {
    int i=0, y=-7;

	controlaListagem(tecla);
    showInstructions();

    for (i = 0;i< itemsPerPage;i++ ){
		if (listagem.page*itemsPerPage+i < 31) {
			purple();
			if (listagem.page*itemsPerPage+i == listagem.opt) green();
			moldura(LARGURA/2, LARGURA-10, ALTURA/2 + y, ALTURA/2 +altura + y);
			gotoxy(LARGURA/2 + 2,ALTURA/2 + altura/2 + y );
			white();
			printf("%d", itensMineCraft[listagem.page*itemsPerPage+i]);
			y += altura+1;
		}

	}
	controlPagination();
}

void controlaListagem(int tecla){
	if (tecla == 119 || tecla == 87){ // caso w|W for pressionado
		listagem.opt--;

		if(listagem.opt < 0) listagem.opt=0;

		if (listagem.opt < listagem.page * itemsPerPage){
				listagem.page--;
		}
	}
		if (tecla == 115 || tecla == 83){ // caso s|S for pressionado
			listagem.opt++;
			if(listagem.opt >30) listagem.opt=30;

			if (listagem.opt >= (listagem.page+1) * itemsPerPage ){
				listagem.page++;
			}
		}

		if (tecla == 100 || tecla == 68){ // caso d|D for pressionado
			listagem.page++;
			if (listagem.page > 31 / itemsPerPage) listagem.page =  31 / listagem.page;
			listagem.opt = listagem.page * itemsPerPage ;

		}

		if (tecla == 97 || tecla == 65){ // caso a|A for pressionado
			listagem.page--;
			if (listagem.page < 0) listagem.page = 0;
			listagem.opt = listagem.page * itemsPerPage;
		}

		if (tecla == 13){ // enter
			listagem.escolheuItem++;
		}

        if(tecla == 109 || tecla == 77){ // caso m|M for pressionado
            page = HOME;
        }
}

void controlPagination() {
white();
	gotoxy(LARGURA/2, ALTURA/2 + 14);
	printf ("PAGINA %d de %d", listagem.page + 1, 31 / itemsPerPage + 1);
	if(listagem.page > 0){
		gotoxy(LARGURA-20, ALTURA/2 + 14);
		printf ("A <<");
	}

	if(listagem.page < 31 / itemsPerPage){
		gotoxy(LARGURA-16, ALTURA/2 + 14);
		printf (" >> D");
	}}

void showInstructions(){
    gotoxy((LARGURA - 69)/2, 8);
	printf ("Use WASD para escolher o item para inserir e ENTER para confirmar");

	gotoxy((LARGURA - 30)/2, 10);
	printf ("Pressione M para voltar ao Menu");
}

void initializeHashCodes (){
	int i;

	for (i = 0; i< MAX_CHEST_SLOTS;i++){
		hashCodes[i] = 0;
	}
}
