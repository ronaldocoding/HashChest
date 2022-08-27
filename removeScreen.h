#include "interfaceLib.h"
#include "draw.h"

#ifndef REMOVE_APP
#define REMOVE_APP

void showRemover (int tecla) {
	molduraTela();

	char text[4][50] = {"  ___ ___ __  __  _____   _____ ___ ",
	" | _ \\ __|  \\/  |/ _ \\ \\ / / __| _ \\ ",
		" |   / _|| |\\/| | (_) \\ V /| _||   / ",
		" |_|_\\___|_|  |_|\\___/ \\_/ |___|_|_\\ "
	};
	int i, textLength = 41;
	int x = (LARGURA - textLength)/2, y = 2;
	white();
	for (i=0;i<4;i++){
		gotoxy(x, y+i);
		printf(text[i]);
	}

}

#endif
