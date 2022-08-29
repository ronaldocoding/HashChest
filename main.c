#include "chestLib.h"
#include <curses.h>

static void showInsertItemMenu(Chest *chest, Item **items) {
    int optInsert;
    
    do
    {
        printf("---------ESTES SÃO OS ITENS DISPONÍVEIS PARA INSERÇÃO---------\n\n");
        for(int i = 0; i < MAX_CHEST_SLOTS; i++) {
            printf("[%d] %s\n", i+1, items[i]->name);
        }
        printf("[-1] VOLTAR AO MENU INICIAL\n\n");
        
        printf("SUA ESCOLHA: ");
        scanf("%d", &optInsert);
        
        if((optInsert > 0 || optInsert <= MAX_CHEST_SLOTS) && optInsert != -1)
        {
            printf("--------ESCOLHA A QUANTIDADE DE ITENS QUE DESEJA INSERIR--------\n\n");
            printf("NOME DO ITEM QUE VOCÊ ESCOLHEU: %s\n", items[optInsert-1]->name);
            printf("QUANTIDADE: ");
            scanf("%d", &items[optInsert-1]->quantity);
            
            if(items[optInsert-1]->pos == -1)
            {
                items[optInsert-1]->pos = hashFunction(items[optInsert-1]->key, items[optInsert-1]->name);
            }
            
            Item *newItem = createItem(items[optInsert-1]->name, items[optInsert-1]->quantity, items[optInsert-1]->key);
            
            int response = insertNode(chest, newItem, items[optInsert-1]->pos);
            
            if(response == 0)
            {
                printf("O BAÚ ESTÁ CHEIO!");
                break;
            }
            
            else if(response == 2 || response == 4)
            {
                printf("QUANTIDADE EXCEDE O LIMITE MÁXIMO DE ITENS POR SLOT: %d!\n\n", MAX_ITEMS_PER_SLOT);
            }
            
            else if(response == 3 || response == 5)
            {
                printf("ITEM SALVO COM SUCESSO!\n\n");
            }
            
            else if(response == 6)
            {
                printf("EITA! HOUVE COLISÃO, MAS FOI SALVO COM SUCESSO!\n\n");
            }
        }
        
    } while(optInsert != -1);
}

int main(int argc, const char * argv[])
{
    Chest * chest = createChest();
    
    // Cria vetor de itens
    char *itemsNames[MAX_CHEST_SLOTS] = {"LAVA FLUINDO", "AINDA LAVA", "AREIA", "CASCALHO", "MINERIO DE OURO", "MINERIO DE FERRO", "MINERIO DE CARVÃO", "MADEIRA DE CARVALHO", "FOLHAS DE CARVALHO", "ESPONJA", "VIDRO", "MINERIO DE LAPIS LAZULI", "BLOCO LAPIS LAZULI", "DISPENSADOR", "ARENITO", "BLOCO DE NOTAS", "CAMA", "TRILHO MOTORIZADO", "DETECTOR RAIL", "STICKY PISTON", "TEIA DE ARANHA", "DEAD SHRUB", "DEAD BUSH", "PISTAO", "CABECA DE PISTAO", "LA BRANCA", "DANDELION"};
    
    Item *items[MAX_CHEST_SLOTS];
    for(int i = 0; i < MAX_CHEST_SLOTS; i++)
    {
        items[i] = createItem(itemsNames[i], 0, i+10);
    }
    
    // Mostra menu
    int optMenu;
    do
    {
        printf("---------------------------HASH CHEST---------------------------\n\n");
        printf("OPÇÕES: \n\n");
        printf("[1] INSERIR ITEM NO BAÚ\n");
        printf("[2] REMOVER ITEM DO BAÚ\n");
        printf("[3] BUSCAR ITEM DO BAÚ\n");
        printf("[4] MOSTRAR BAÚ NO MODO HASH TABLE\n");
        printf("[5] MOSTRAR BAÚ NO MODO MINECRAFT\n");
        printf("[-1] PARA A EXECUÇÃO DO PROGRAMA\n\n");
        
        printf("SUA ESCOLHA: ");
        scanf("%d", &optMenu);
        
        switch(optMenu)
        {
            case 1:
            {
                showInsertItemMenu(chest, items);
                break;
            }
            case 2:
            {
                break;
            }
            case 3:
            {
                break;
            }
            case 4:
            {
                printChest(chest);
                break;
            }
            case 5:
            {
                break;
            }
            case -1:
            {
                break;
            }
            default:
            {
                break;
            }
        }
        
    } while(optMenu != -1);
    
    
    return 0;
}
