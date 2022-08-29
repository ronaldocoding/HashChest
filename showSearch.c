#include "chestLib.h"

void showBuscar(int tecla)
{
    //molduraTela();
	gotoxy((LARGURA - 30)/2, 10);
	printf ("Pressione M para voltar ao Menu");

	if(tecla == 109 || tecla == 77){ // caso m|M for pressionado
            page = HOME;
    }

	char text[4][50] = {"  ___ _   _ ___  ___   _   ___  ",
						" | _ ) | | / __|/ __| /_\\ | _ \\ ",
						" | _ \\ |_| \\__ \\ (__ / _ \\|   /",
						" |___/\\___/|___/\\___/_/ \\_\\_|_\\"};
	int i, textLength = 32;
	int x = (LARGURA - textLength) / 2, y = 2;

	white();
	for (i = 0; i < 4; i++)
	{
		gotoxy(x, y + i);
		printf(text[i]);
	}

	showListItens(tecla);

	if(listagem.escolheuItem == 2){
        desenhaAviso("Opa! Itens colidiram na posicao X");
        Sleep(2000);
        listagem.escolheuItem = 1;
	}

	if(listagem.escolheuItem == 1){
        desenhaAviso("O item esta na posicao X");
        Sleep(3000);
        listagem.escolheuItem = 1;
	}

	desenhaBauAberto(20, 15);
}
