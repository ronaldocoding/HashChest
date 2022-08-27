#include "interfaceLib.h"

void showHome(int tecla)
{
    molduraTela();
    cabecaSteve(30, 2);
    desenhaBauFechado(60, 6);
    title(50, 20);

    if (tecla == 119 || tecla == 87){ // caso w|W for pressionado
			opt-=2;
			if(opt < 0) opt+=2;
		}
		if (tecla == 115 || tecla == 83){ // caso s|S for pressionado
			opt+=2;
			if(opt >=4) opt-=2;
		}

		if (tecla == 100 || tecla == 68){ // caso d|D for pressionado
			opt++;
			if (opt>=4 )opt = 3;
		}

		if (tecla == 97 || tecla == 65){ // caso a|A for pressionado
			opt--;
			if (opt<0) opt = 0;
		}
    desenhaOpcoes(opt);

    if (tecla == 13)
    {
        if (opt == 0)
        {
            page = INSERIR;

            inserir.qtd = 0;
            inserir.opt = 0;
            inserir.page = 0;
            inserir.escolheuItem = 0;
        }

        if (opt == 1)
        {
            page = REMOVER;

            remover.opt = 0;
            remover.page = 0;
            remover.escolheuItem = 0;
            opt = 0;
        }
        if (opt == 2)
        {
            page = BUSCAR;
        }
        if (opt == 3)
        {
            page = SAIR;

            opt = 0;
        }
    }

    gotoxy(40, ALTURA - 4);
    white();
    printf(" Use WASD para mover e ENTER para selecionar ");
    gotoxy(0, ALTURA + 1);
    printf("");
}
