#include "utils.h"
#include "interfaceLib.h"
#include "draw.h"

#ifndef INSERT_APP
#define INTERT_APP
void showInserir (int tecla){
    int itemsPerPage = 7;

	if (tecla == 72){
		inserir.opt--;
		if(inserir.opt < 0) inserir.opt=0;

		if (inserir.opt < inserir.page * itemsPerPage){
				inserir.page-- ;
		}
	}
		if (tecla == 80){
			inserir.opt++;
			if(inserir.opt >30) inserir.opt=30;

			if (inserir.opt >= (inserir.page+1) * itemsPerPage ){
				inserir.page++;
			}
		}

		if (tecla == 77){
			inserir.page++;
			if (inserir.page > 31 / itemsPerPage) inserir.page =  31 / inserir.page;
			inserir.opt = inserir.page * itemsPerPage ;

		}

		if (tecla == 75){
			inserir.page--;
			if (inserir.page < 0) inserir.page = 0;
			inserir.opt = inserir.page * itemsPerPage;
		}

		if (tecla == 13){
			inserir.escolheuItem++;
		}
		molduraTela();

	char text[4][50] = {"  ___ _  _ ___ ___ ___ ___ ___  ",
	" |_ _| \\| / __| __| _ \\_ _| _ \\ ",
		"  | || .` \\__ \\ _||   /| ||   / ",
		" |___|_|\\_|___/___|_|_\\___|_|_\\ "
	};
	int i, textLength = 31;
	int x = (LARGURA - textLength)/2, y = 2;
	white();
	for (i=0;i<4;i++){
		gotoxy(x, y+i);
		printf(text[i]);
	}

	gotoxy((LARGURA - 69)/2, 8);
	printf ("Use as setas para escolher o item para inserir e ENTER para confirmar");


    showListItens();

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

	if(inserir.escolheuItem == 1){
		gotoxy((LARGURA - 30)/2, 9);
		printf ("QUANTIDADE: ");
		gotoxy((LARGURA)/2, 9);
		scanf("%d", &inserir.qtd);
		inserir.escolheuItem++;
	}

	if(inserir.escolheuItem == 2){
		if(inserir.qtd > 64){
			desenhaAviso("Quantidade excede o limite.");
			Sleep(2000);
			inserir.escolheuItem = 1;
		}else if(inserir.qtd < 0){
			desenhaAviso("Insira um numero v�lido!");
			Sleep(2000);
			inserir.escolheuItem = 1;
		}else{
			desenhaAviso("Salvo com sucesso!");
			Sleep(2000);
			page = HOME;
		}



	}
}

#endif

