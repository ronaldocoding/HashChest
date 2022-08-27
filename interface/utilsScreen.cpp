#include "interfaceLib.h"

void gotoxy (int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition (GetStdHandle (STD_OUTPUT_HANDLE), coord);
}

void showListItens() {
    int itemsPerPage = 7, altura = 2, i=0, y=-7;
    for (i = 0;i< itemsPerPage;i++ ){
		if (inserir.page*itemsPerPage+i < 31) {
			purple();
			if (inserir.page*itemsPerPage+i == inserir.opt) green();
			//moldura(LARGURA/2, LARGURA-10, ALTURA/2 + y, ALTURA/2 +altura + y);
			gotoxy(LARGURA/2 + 2,ALTURA/2 + altura/2 + y );
			white();
			printf("%d", lista[inserir.page*itemsPerPage+i]);
			y += altura+1;
		}

	}
}
