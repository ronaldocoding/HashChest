#include "interfaceLib.h"
#include "draw.h"
#include "utils.h"

#ifndef SEARCH_APP
#define SEARCH_APP
void showBuscar (int tecla) {
	molduraTela();

	char text[4][50] = {"  ___ _   _ ___  ___   _   ___  ",
	" | _ ) | | / __|/ __| /_\\ | _ \\ ",
		" | _ \\ |_| \\__ \\ (__ / _ \\|   /",
		" |___/\\___/|___/\\___/_/ \\_\\_|_\\"
	};
	int i, textLength = 32;
	int x = (LARGURA - textLength)/2, y = 2;
	white();
	for (i=0;i<4;i++){
		gotoxy(x, y+i);
		printf(text[i]);
	}

	showListItens();
}

#endif
