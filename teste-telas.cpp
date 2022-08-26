#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#define ALTURA 40
#define LARGURA 140
#define HOME 0
#define INSERIR 1
#define REMOVER 2
#define BUSCAR 3
#define SAIR 4

int opt = 0, page = HOME;
int lista[31];


typedef struct telaInserir {
	int opt, qtd, page, escolheuItem, itemsPagina;
} telaInserir; 

typedef struct telaRemover {
	int opt, page, escolheuItem;
} telaRemover; 


telaInserir inserir;
telaRemover remover;

void createListaObjetos (){
	int i;
	
	for (i = 0; i< 31;i++){
		lista[i] = i +1;
	}
} 

void gotoxy (int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition (GetStdHandle (STD_OUTPUT_HANDLE), coord);
}

void green () {
  printf("\033[1;32m");
}

void blue () {
  printf("\033[1;34m");
}


void red () {
  printf("\033[1;31m");
}

void yellow (){
  printf("\033[1;33m");
}

void purple () {
  printf("\033[1;35m");
}

void reset () {
  printf("\033[1;37m");
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

int title (int x, int y){
	reset();
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
		if(escolhido == 0) reset();
		gotoxy(20, 25+i);
		printf(inserir[i]);
		green();
		if(escolhido == 1) reset();
		gotoxy(70, 25+i);
		printf(remover[i]);
		green();
		if(escolhido == 2) reset();
		gotoxy(20, 30+i);
		printf(buscar[i]);
		green();
		if(escolhido == 3) reset();
		gotoxy(70, 30+i);
		printf(sair[i]);
	}
	
	
}

void showHome(int tecla){
molduraTela();
		cabecaSteve(30, 2);
		desenhaBauFechado(60, 6);
		title(50, 20);
	

		if (tecla == 72){
			opt-=2;
			if(opt < 0) opt+=2;
		}
		if (tecla == 80){
			opt+=2;
			if(opt >=4) opt-=2;
		}
		
		if (tecla == 77){
			opt++;
			if (opt>=4 )opt = 3;
		}
		
		if (tecla == 75){
			opt--;
			if (opt<0) opt = 0;
		}
	
		desenhaOpcoes(opt);
	
		if (tecla == 13){
			if (opt == 0){
				page = INSERIR;
				
				inserir.qtd = 0;
				inserir.opt = 0;
				inserir.page = 0;
				inserir.escolheuItem = 0;
			}
			
			if (opt == 1){
				page = REMOVER;
				
				remover.opt = 0;
				remover.page = 0;
				remover.escolheuItem = 0;
				opt = 0;
			}
			if(opt == 2) {
				page = BUSCAR;
			}
			if (opt == 3){
				page = SAIR;
			
				opt = 0;
			}
		}
		
		gotoxy(40, ALTURA-4);
		reset();
		printf(" Use as setas do teclado para mover e ENTER para selecionar ");
		gotoxy(0, ALTURA+1);
		printf("");
}

void showInserir (int tecla){
				
	int itemsPerPage = 7, altura = 2;
	
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
	reset();
	for (i=0;i<4;i++){
		gotoxy(x, y+i);
		printf(text[i]);
	}
	
	gotoxy((LARGURA - 69)/2, 8);
	printf ("Use as setas para escolher o item para inserir e ENTER para confirmar");
	
	
	y = -7;
	for (i = 0;i< itemsPerPage;i++ ){
		if (inserir.page*itemsPerPage+i < 31) {
			purple();
			if (inserir.page*itemsPerPage+i == inserir.opt) green();
			moldura(LARGURA/2, LARGURA-10, ALTURA/2 + y, ALTURA/2 +altura + y);
			gotoxy(LARGURA/2 + 2,ALTURA/2 + altura/2 + y );
			reset();
			printf("%d", lista[inserir.page*itemsPerPage+i]);
			y += altura+1;
		}
	
	}

	reset();
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
			desenhaAviso("Insira um numero válido!");
			Sleep(2000);
			inserir.escolheuItem = 1;
		}else{
			desenhaAviso("Salvo com sucesso!");
			Sleep(2000);
			page = HOME;
		}
		
		
		
	}
}

void showRemover (int tecla) {
	molduraTela();
	
	char text[4][50] = {"  ___ ___ __  __  _____   _____ ___ ",
	" | _ \\ __|  \\/  |/ _ \\ \\ / / __| _ \\ ",
		" |   / _|| |\\/| | (_) \\ V /| _||   / ",
		" |_|_\\___|_|  |_|\\___/ \\_/ |___|_|_\\ "
	};
	int i, textLength = 41;
	int x = (LARGURA - textLength)/2, y = 2;
	reset();
	for (i=0;i<4;i++){
		gotoxy(x, y+i);
		printf(text[i]);
	}
	
}

void showBuscar (int tecla) {
	molduraTela();
	
	char text[4][50] = {"  ___ _   _ ___  ___   _   ___  ",
	" | _ ) | | / __|/ __| /_\\ | _ \\ ",
		" | _ \\ |_| \\__ \\ (__ / _ \\|   /",
		" |___/\\___/|___/\\___/_/ \\_\\_|_\\"
	};
	int i, textLength = 32;
	int x = (LARGURA - textLength)/2, y = 2;
	reset();
	for (i=0;i<4;i++){
		gotoxy(x, y+i);
		printf(text[i]);
	}
}
int main (){
	char tecla = 0;
	createListaObjetos();
	int antPage = page;
	system ("MODE 140, 40");
	system ("title Minecraft");

	
	do{
		switch(page){
			case HOME: 	showHome(tecla); break;
			case INSERIR: showInserir(tecla); break;
			case REMOVER: showRemover(tecla); break;
			case BUSCAR: showBuscar(tecla); break;
			default: page = SAIR; break;
		}
	
		if(tecla!=13 && antPage == page){
			tecla = getch();
		
		}else{
			tecla = 0;
		}
		antPage = page;
		system ("CLS");
	}while(page != SAIR);

	gotoxy(LARGURA, ALTURA);
	return 0;
}
