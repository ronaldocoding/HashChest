#ifndef LIB_APP
#define LIB_APP

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


/*global var declaration*/
// opt = escolha do usuario
extern int opt;
// page = pagina atual
extern int page;

//itens do mine
extern int lista[31];

typedef struct telaInserir {
	int opt, qtd, page, escolheuItem, itemsPagina;
} telaInserir;

typedef struct telaRemover {
	int opt, page, escolheuItem;
} telaRemover;

typedef struct listagemEmTela {
	int opt, qtd, page, escolheuItem, itemsPagina;
} listagemEmTela;

extern telaInserir inserir;
extern listagemEmTela listagem;
extern telaRemover remover;

/* Functions Interface */

// Main functions
void createListaObjetos();

void showHome(int tecla);
void showInserir (int tecla);
void showBuscar (int tecla); //ok
void showRemover (int tecla); //ok

// utils screen
void gotoxy (int x, int y);
void showListItens(int tecla);
void controlaListagem(int tecla);
void showInstructions();
void controlPagination();

// colors
void green();
void blue();
void red();
void yellow();
void purple();
void white();

// draw in screen
void moldura( int x1, int x2, int y1, int y2);
void molduraTela ();
void ImprimeAviao (int x, int y);
void empty ( int x1, int x2, int y1, int y2);
void desenhaAviso(char *aviso);
void transicaoFim (int x1, int x2, int y1, int y2, int ax, int ay);
void transicaoInicio (int x1, int x2, int y1, int y2, int ax, int ay);
void cabecaSteve (int x, int y);
void desenhaBauFechado (int x, int y);
void desenhaBauAberto (int x, int y);
void title (int x, int y);
void desenhaOpcoes (int escolhido);
void updateTextInScreen(char *aviso);

#endif
