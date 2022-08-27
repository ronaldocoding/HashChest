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

// opt = escolha do usuario
// page = pagina atual
int opt = 0, page = HOME;

//itens do mine
int lista[31];

void createListaObjetos (){
	int i;

	for (i = 0; i< 31;i++){
		lista[i] = i +1;
	}
}

typedef struct telaInserir {
	int opt, qtd, page, escolheuItem, itemsPagina;
} telaInserir;

typedef struct telaRemover {
	int opt, page, escolheuItem;
} telaRemover;


telaInserir inserir;
telaRemover remover;

// Main functions
//void showHome(int tecla);

#include "color.h"
#include "utils.h"
#include "draw.h"
#include "homeScreen.h"
#include "insertScreen.h"
#include "removeScreen.h"
#include "searchScreen.h"

#endif
