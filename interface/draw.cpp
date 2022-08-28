#include "interfaceLib.h"

void moldura ( int x1, int x2, int y1, int y2){//funcao que imprime a moldura com as coordenadas dadas
	int i, j;

	for ( i = x1 ; i <= x2 ; i++){
		for ( j = y1 ; j <= y2 ; j++){
			gotoxy(i, j);
			if (i == x1 || i == x2)
				printf ("\xBA");
			else
				if (j == y1 || j == y2)
					printf ("\xCD");
				else
					printf (" ");
		}
	}

	gotoxy (x1, y1);
	printf ("\xC9");
	gotoxy (x1, y2);
	printf ("\xC8");
	gotoxy (x2, y1);
	printf ("\xBB");
	gotoxy (x2, y2);
	printf ("\xbc");

}

void  molduraTela (){
    purple();
    moldura(6, LARGURA-6, 4, ALTURA-3);
    moldura(7, LARGURA-7, 5, ALTURA-4);
}

void ImprimeAviao (int x, int y){
	//parametro x e y = coordenada para o ponto superior esquerdo, onde a partir dai sera imprimido
	gotoxy(x, y);
	printf ("         \xDA\xBF");
	y++;
	gotoxy(x, y);
	printf ("        \xDA  \xBF");
	y++;
	gotoxy(x, y);
	printf (" _______|  |_______");
	y++;
	gotoxy(x, y);
	printf ("/_______\\  /_______\\");
	y++;
	gotoxy(x, y);
	printf ("        |  |        ");
	y++;
	gotoxy(x, y);
	printf ("        |  |        ");
	y++;
	gotoxy(x, y);
	printf ("        \\  /");
	y++;
	gotoxy(x, y);
	printf ("       /_\\/_\\");
}

void empty ( int x1, int x2, int y1, int y2){//funcao que imprime a moldura com as coordenadas dadas
	int i, j;

	for ( i = x1 ; i <= x2 ; i++){
		for ( j = y1 ; j <= y2 ; j++){
			gotoxy(i, j);
			printf (" ");
		}
	}
}

void desenhaAviso(char aviso[100]){
	int length = 0;
	for (length=0; aviso[length]!= '\0';length++){

	}

	moldura( LARGURA/2 - length/2-6, LARGURA/2 + length/2+6, ALTURA/2-2, ALTURA/2+2);
	gotoxy(LARGURA/2 - length/2 + 1, ALTURA/2);
	printf("%s", aviso);

}

void transicaoFim (int x1, int x2, int y1, int y2, int ax, int ay){//aviao sai levando a moldura
	int a = ay, c = y2;
	do{
		moldura(x1, x2, y1, c);
		ImprimeAviao(ax, a);
		a-=3;
		c-=3;
		Sleep(1);
		system("CLS");
	}while (c >= 0);
}

void transicaoInicio (int x1, int x2, int y1, int y2, int ax, int ay){//aviao entra trazendo a moldura
	int a = ay, c = y2;
	do{
		moldura(x1, x2, c, y2);
		ImprimeAviao(ax, a);

		a-=3;
		if (c - 3 >= y1){
			c-=3;
		}else
			if (c - 3 >= y1)
				c--;

		Sleep(1);
		system("CLS");
	}while (a > 0);
	c-=2;
	moldura(x1, x2, c, y2);
}

void cabecaSteve (int x, int y) {
	int altura = 15, largura = 36;
	yellow ();

	moldura(x, x + largura, y,y + altura);
	//cabelo
	moldura(x, x + largura, y,y + altura/4);
	moldura(x + largura - 5, x + largura, y,y + altura/3);
	moldura(x, x + 5, y,y + altura/3);
	gotoxy(x+5,y);
	printf("\xCD");
	gotoxy(x+largura-5,y);
	printf("\xCD");
	gotoxy(x+5,y + altura/4 );
	printf("\xC9");
	gotoxy(x+largura-5,y + altura/4 );
	printf("\xBB");
	gotoxy(x,y + altura/3 );
	printf("\xCC");
	gotoxy(x+largura,y + altura/3 );
	printf("\xB9");
	empty(x+1, x+largura-1, y +1, y + altura/4-1);

	//barba
	moldura(x+largura/2-5,x+largura/2+5, y+altura-2,y + altura);
	moldura(x+largura/2-10,x+largura/2-5, y+altura-4,y + altura);
	moldura(x+largura/2+5,x+largura/2+10, y+altura-4,y + altura);
	empty(x+largura/2-9, x+largura/2+9, y+altura-1, y + altura-1);
	gotoxy(x+largura/2-5, y+altura-2);
	printf("\xC8");
	gotoxy(x+largura/2+5, y+altura-2);
	printf("\xBC");
	gotoxy(x+largura/2-10, y+altura);
	printf("\xCA");
	gotoxy(x+largura/2+10, y+altura);
	printf("\xCA");
	gotoxy(x+largura/2+5, y+altura);
	printf("\xCD");
	gotoxy(x+largura/2-5, y+altura);
	printf("\xCD");
	//olho
	yellow();
	moldura(x+5,x+largura/2-5, y+altura-8,y + altura-6);
	blue();
	moldura(x+8,x+largura/2-5, y+altura-8,y + altura-6);
	yellow();
	moldura(x+largura/2+5,x+largura-5, y+altura-8,y + altura-6);
	blue();
	moldura(x+largura/2+5,x+largura-8, y+altura-8,y + altura-6);

	//nariz
	red();
	moldura(x+largura/2-5,x+largura/2+5, y+altura-6,y + altura-4);

}

void desenhaBauFechado (int x, int y){
	yellow ();
	int altura = 15, largura = 30;

	moldura(x, x + largura, y,y + altura);
	moldura(x, x + largura, y,y + altura/2);

	gotoxy(x, y+altura/2);
	printf("\xCC");
	gotoxy(x+largura, y+altura/2);
	printf("\xB9");

	moldura(x+largura/2-2, x + largura/2+2, y+altura/2-1,y + altura/2+1);
}

void desenhaBauAberto (int x, int y){
	yellow ();
	int altura = 15, largura = 30;

	moldura(x, x + largura, y,y + altura);
    moldura(x, x + largura, y,y + altura/2);
    moldura(x + 2, x + largura -  2, y + 1,y + altura/2);
	gotoxy(x, y+altura/2);
	printf("\xCC");
	gotoxy(x+largura, y+altura/2);
	printf("\xB9");
	gotoxy(x + 2, y+altura/2);
	printf("\xCA");
	gotoxy(x+largura-2, y+altura/2);
	printf("\xCA");

    white();
	moldura(x+largura/2-2, x + largura/2+2, y-1,y);
}

void title (int x, int y){
	white();
	char text[5][100] = {" __    __  __  __   __  ______  ______  ______  ______  ______  ______ ",
	"/\\ \"-./  \\/\\ \\/\\ \"-.\\ \\/\\  ___\\/\\  ___\\/\\  == \\/\\  __ \\/\\  ___\\/\\__  _\\ ",
		"\\ \\ \\-./\\ \\ \\ \\ \\ \\-.  \\ \\  __\\\\ \\ \\___\\ \\  __<\\ \\  __ \\ \\  __\\\\/_/\\ \\/ ",
		" \\ \\_\\ \\ \\_\\ \\_\\ \\_\\\\\"\\_\\ \\_____\\ \\_____\\ \\_\\ \\_\\ \\_\\ \\_\\ \\_\\     \\ \\_\\ ",
		"  \\/_/  \\/_/\\/_/\\/_/ \\/_/\\/_____/\\/_____/\\/_/ /_/\\/_/\\/_/\\/_/      \\/_/ "
	};
	int i;


	for (i=0;i<5;i++){
		gotoxy(x, y+i);
		printf(text[i]);
	}


}

 void desenhaOpcoes (int escolhido) {
	char inserir[4][100] = { "  ___                  _     ",
							" |_ _|_ _  ___ ___ _ _(_)_ _ ",
							"  | || ' \\(_-</ -_) '_| | '_|",
							" |___|_||_/__/\\___|_| |_|_|  "},
	buscar[4][100]= { "  ___                      ",
							" | _ )_  _ ___ __ __ _ _ _ ",
							" | _ \\ || (_-</ _/ _` | '_|",
							" |___/\\_,_/__/\\__\\__,_|_|  "},
	remover[4][100]= { "  ___                           ",
							" | _ \\___ _ __  _____ _____ _ _ ",
							" |   / -_) '  \\/ _ \\ V / -_) '_|",
							" |_|_\\___|_|_|_\\___/\\_/\\___|_|  "},
	sair[4][50]= { "  ___       _     ",
							" / __| __ _(_)_ _ ",
							" \\__ \\/ _` | | '_|",
							" |___/\\__,_|_|_|  "};

	int i;


	green();
	for (i = 0;i<4;i++){
		green();
		if(escolhido == 0) white();
		gotoxy(20, 25+i);
		printf(inserir[i]);
		green();
		if(escolhido == 1) white();
		gotoxy(70, 25+i);
		printf(remover[i]);
		green();
		if(escolhido == 2) white();
		gotoxy(20, 30+i);
		printf(buscar[i]);
		green();
		if(escolhido == 3) white();
		gotoxy(70, 30+i);
		printf(sair[i]);
	}


}

void updateTextInScreen(char aviso[100]) {
    int length = 0;

	moldura( LARGURA/2 - length/2-6, LARGURA/2 + length/2+6, ALTURA/2-2, ALTURA/2+2);
	gotoxy(LARGURA/2 - length/2 + 1, ALTURA/2);
	printf("%s", aviso);
}
