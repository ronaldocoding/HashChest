#include "chestLib.h"
#include "chestLib.h"

void showRemover(int tecla)
{
int itemsPerPage = 7, altura = 2;

	if (tecla == 119 || tecla == 87){ // caso w|W for pressionado
		inserir.opt--;

		if(inserir.opt < 0) inserir.opt=0;

		if (inserir.opt < inserir.page * itemsPerPage){
				inserir.page--;
		}
	} if (tecla == 115 || tecla == 83){ // caso s|S for pressionado
			inserir.opt++;
			if(inserir.opt >30) inserir.opt=30;

			if (inserir.opt >= (inserir.page+1) * itemsPerPage ){
				inserir.page++;
			}
		}

		if (tecla == 100 || tecla == 68){ // caso d|D for pressionado
			inserir.page++;
			if (inserir.page > 31 / itemsPerPage) inserir.page =  31 / inserir.page;
			inserir.opt = inserir.page * itemsPerPage ;

		}

		if (tecla == 97 || tecla == 65){ // caso a|A for pressionado
			inserir.page--;
			if (inserir.page < 0) inserir.page = 0;
			inserir.opt = inserir.page * itemsPerPage;
		}

		if (tecla == 13){ // enter
			inserir.escolheuItem++;
		}

        if(tecla == 109 || tecla == 77){ // caso m|M for pressionado
            page = HOME;
        }

		molduraTela();

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


	gotoxy((LARGURA - 69)/2, 8);
	printf ("Use WASD para escolher o item para inserir e ENTER para confirmar");

	gotoxy((LARGURA - 30)/2, 10);
	printf ("Pressione M para voltar ao Menu");


	y = -7;
	gotoxy(LARGURA/2 + 2,ALTURA/2 + altura/2 + y );
	for (i = 0;i< itemsPerPage;i++ ){
		if (inserir.page*itemsPerPage+i < 31) {
			purple();
			if (inserir.page*itemsPerPage+i == inserir.opt) green();
			moldura(LARGURA/2, LARGURA-10, ALTURA/2 + y, ALTURA/2 +altura + y);
			gotoxy(LARGURA/2 + 2,ALTURA/2 + altura/2 + y );
			white();
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

	if(inserir.escolheuItem > 0){
		gotoxy((LARGURA - 30)/2, 9);
		printf ("QUANTIDADE A REMOVER: ");
		gotoxy((LARGURA) + 40, 9);
		scanf("%d", &inserir.qtd);

		if(tecla == 109 || tecla == 77){ // caso m|M for pressionado
            page = HOME;
	}


		Item* item = itensMineCraft[inserir.opt];
		item->quantity = inserir.qtd;


		if(hashCodes[inserir.opt] == 0) {
			hashCodes[inserir.opt] = hashFunction(item->key, item->name);
		}

		int response = insertNode(item, hashCodes[inserir.opt]);

		if(response == 0) {
			desenhaAviso("O bau esta cheio.");
			Sleep(2000);
			inserir.escolheuItem = 1;
		}

		if(response == 1) {
			desenhaAviso("Insira um numero valido!");
			Sleep(2000);
			inserir.escolheuItem = 1;
		}

		if(response == 2  || response == 4) {
			desenhaAviso("Quantidade excede o limite.");
			Sleep(2000);
			inserir.escolheuItem = 1;
		}

		if(response == 3 || response == 5){
			desenhaAviso("Removido com sucesso!");
			page = HOME;
            		Sleep(2000);

		}


		item->quantity = inserir.qtd;

		inserir.escolheuItem++;

	}


			//printChest();

	//desenhaBauAberto(20, 15);
}
