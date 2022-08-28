#include "interfaceLib.h"

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
			printf("%d", lista[listagem.page*itemsPerPage+i]);
			y += altura+1;
		}

	}

	white();
	gotoxy(LARGURA/2, ALTURA/2 + 14);
	printf ("PAGINA %d de %d", inserir.page + 1, 31 / itemsPerPage + 1);
	if(inserir.page > 0){
		gotoxy(LARGURA-15, ALTURA/2 + 14);
		printf ("<<");
	}

	if(inserir.page < 31 / itemsPerPage){
		gotoxy(LARGURA-11, ALTURA/2 + 14);
		printf (">>");
	}
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

void showInstructions(){
    gotoxy((LARGURA - 69)/2, 8);
	printf ("Use WASD para escolher o item para inserir e ENTER para confirmar");

	gotoxy((LARGURA - 30)/2, 10);
	printf ("Pressione M para voltar ao Menu");
}

void createListaObjetos (){
	int i;

	for (i = 0; i< 31;i++){
		lista[i] = i +1;
	}
}
