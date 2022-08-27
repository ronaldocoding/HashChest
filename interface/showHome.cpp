#include "interfaceLib.h"

void showHome(int tecla)
{
    molduraTela();
    cabecaSteve(30, 2);
    desenhaBauFechado(60, 6);
    title(50, 20);

    if (tecla == 72)
    {
        opt -= 2;
        if (opt < 0)
            opt += 2;
    }
    if (tecla == 80)
    {
        opt += 2;
        if (opt >= 4)
            opt -= 2;
    }

    if (tecla == 77)
    {
        opt++;
        if (opt >= 4)
            opt = 3;
    }

    if (tecla == 75)
    {
        opt--;
        if (opt < 0)
            opt = 0;
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
    printf(" Use as setas do teclado para mover e ENTER para selecionar ");
    gotoxy(0, ALTURA + 1);
    printf("");
}
