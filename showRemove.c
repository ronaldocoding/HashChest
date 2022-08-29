#include "chestLib.h"

void showRemover(int tecla)
{
	molduraTela();

	gotoxy((LARGURA - 30)/2, 10);
	printf ("Pressione M para voltar ao Menu");

	if(tecla == 109 || tecla == 77){  // caso m|M for pressionado
            page = HOME;
    }

	char text[4][50] = {"  ___ ___ __  __  _____   _____ ___ ",
						" | _ \\ __|  \\/  |/ _ \\ \\ / / __| _ \\ ",
						" |   / _|| |\\/| | (_) \\ V /| _||   / ",
						" |_|_\\___|_|  |_|\\___/ \\_/ |___|_|_\\ "};
	int i, textLength = 41;
	int x = (LARGURA - textLength) / 2, y = 2;
	white();
	for (i = 0; i < 4; i++)
	{
		gotoxy(x, y + i);
		printf(text[i]);
	}


			printChest();

	//desenhaBauAberto(20, 15);
}
