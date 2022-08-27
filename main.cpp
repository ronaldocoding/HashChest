#include "interface/interfaceLib.h"

int opt = 0, page = HOME;
telaInserir inserir;
telaRemover remover;
int lista[31];

int main() {

	char tecla = 0;
	createListaObjetos();
	int antPage = page;
	system("MODE 140, 40");
	system("title Minecraft");

	do
	{
		switch (page)
		{
		case HOME:
			showHome(tecla);
			break;
		case INSERIR:
			showInserir(tecla);
			break;
		case REMOVER:
			showRemover(tecla);
			break;
		case BUSCAR:
			showBuscar(tecla);
			break;
		default:
			page = SAIR;
			break;
		}

		if (tecla != 13 && antPage == page)
		{
			tecla = getch();
		}
		else
		{
			tecla = 0;
		}
		antPage = page;
		system("CLS");
	} while (page != SAIR);

	gotoxy(LARGURA, ALTURA);
	return 0;
}
