#include "chestLib.h"
#include "chestLib.h"

int opt = 0, page = HOME;
telaInserir inserir;
telaRemover remover;
int lista[31];
listagemEmTela listagem;

int main(int argc, const char * argv[]) {
    chest = createChest();

    int pontIndice = 0;

	initializeHashCodes();
	initializeItensLib();

	char tecla = 0;

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
			showInserir(tecla, &pontIndice);
			break;
		case REMOVER:
			showRemover(tecla);
			break;
		case BUSCAR:
            molduraTela();
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
