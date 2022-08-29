#include "chestLib.h"
#include <curses.h>
#include <unistd.h>

static void showInsertItemMenu(Chest *chest, Item **items) {
    int optInsert;
    
    do
    {
        printf("---------ESTES SÃO OS ITENS DISPONÍVEIS PARA INSERÇÃO---------\n\n");
        for(int i = 0; i < MAX_CHEST_SLOTS; i++)
        {
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
            
            Item *newItem = createItem(items[optInsert-1]->name, items[optInsert-1]->quantity, items[optInsert-1]->key, items[optInsert-1]->pos);
            
            int response = insertNode(chest, newItem, items[optInsert-1]->pos);
            
            if(response == 0)
            {
                printf("O BAÚ ESTÁ CHEIO!\n\n");
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

static void showRemoveItemMenu(Chest *chest, char **itemsNames) {
    if(chest->busySlots == 0)
    {
        printf("\n\nVOCÊ AINDA NÃO INSERIU NENHUM ITEM!\n\n");
    }
    else
    {
        int optRemove;
        
        do {
            printf("---------ESTES SÃO OS ITENS DISPONÍVEIS PARA REMOÇÃO---------\n\n");
            for(int i = 0; i < TABLE_SIZE; i++)
            {
                Node * aux = chest->slots[i]->firstNode;
                while(aux != NULL) {
                    printf("[%d] %s — QUANTIDADE: %d\n", aux->item->key, aux->item->name, aux->item->quantity);
                    aux = aux->next;
                }
            }
            printf("[-1] VOLTAR AO MENU INICIAL\n\n");
            printf("DIGITE O CODIGO DO ITEM QUE DESEJA REMOVER: ");
            scanf("%d", &optRemove);
            
            if(optRemove != -1)
            {
                printf("--------ESCOLHA A QUANTIDADE DE ITENS QUE DESEJA REMOVER--------\n\n");
                printf("NOME DO ITEM QUE VOCÊ ESCOLHEU: %s\n", itemsNames[optRemove-10]);
                printf("QUANTIDADE: ");
                int quantity;
                scanf("%d", &quantity);
                
                int response = removeNode(chest, itemsNames[optRemove-10], hashFunction(optRemove, itemsNames[optRemove-10]), quantity);
                
                if(response == 0)
                {
                    printf("O ITEM FOI COMPLETAMENTE REMOVIDO DO BAÚ!\n\n");
                }
                else if(response == 1) {
                    printf("A QUANTIDADE REQUISITADA FOI REMOVIDA DO BAÚ!\n\n");
                }
                else
                {
                    printf("ESSE ITEM NÃO ESTÁ NO BAÚ!\n\n");
                }
                
                if(chest->busySlots == 0)
                {
                    printf("TODOS OS ITENS FORAM REMOVIDOS DO BAÚ!\n\n");
                    break;
                }
            }
            
        } while(optRemove != -1);
    }
}

static void showSearchItemMenu(Chest *chest, char **itemsNames) {
    if(chest->busySlots == 0)
    {
        printf("\n\nVOCÊ AINDA NÃO INSERIU NENHUM ITEM!\n\n");
    }
    else
    {
        int optSearch;
        do {
            printf("---------ESTES SÃO OS ITENS DISPONÍVEIS PARA BUSCA---------\n\n");
            for(int i = 0; i < TABLE_SIZE; i++)
            {
                Node * aux = chest->slots[i]->firstNode;
                while(aux != NULL) {
                    printf("[%d] %s\n", aux->item->key, aux->item->name);
                    aux = aux->next;
                }
            }
            printf("[-1] VOLTAR AO MENU INICIAL\n\n");
            printf("DIGITE O CODIGO DO ITEM QUE DESEJA BUSCAR: ");
            scanf("%d", &optSearch);
            
            if(optSearch != -1)
            {
                Node *response = searchNode(chest, itemsNames[optSearch-10], hashFunction(optSearch, itemsNames[optSearch-10]));
                
                if(response == NULL)
                {
                    printf("\n\nO ITEM SOLICITADO NAO ESTA NO BAU!\n\n");
                }
                else
                {
                    printf("\n\nINFORMACOES DO ITEM ENCONTRADO:\n\n");
                    printf("NOME: %s\n", response->item->name);
                    printf("QUANTIDADE: %d\n", response->item->quantity);
                    printf("POSICAO NO BAU: %d\n", response->item->pos);
                    printf("CHAVE: %d\n", response->item->key);
                    if(response->previous != NULL || response->next != NULL)
                    {
                        printf("ATENCAO, O ITEM ESTA NA POSICAO %d DO BAU, MAS EXISTEM OUTROS ITENS NA MESMA POSICAO\n\n", response->item->pos);
                    }
                }
            }
        } while(optSearch != -1);
        
    }
}



int main(int argc, const char * argv[])
{
    Chest * chest = createChest();
    
    // Cria vetor de itens
    char *itemsNames[MAX_CHEST_SLOTS] = {"LAVA FLUINDO", "AINDA LAVA", "AREIA", "CASCALHO", "MINERIO DE OURO", "MINERIO DE FERRO", "MINERIO DE CARVÃO", "MADEIRA DE CARVALHO", "FOLHAS DE CARVALHO", "ESPONJA", "VIDRO", "MINERIO DE LAPIS LAZULI", "BLOCO LAPIS LAZULI", "DISPENSADOR", "ARENITO", "BLOCO DE NOTAS", "CAMA", "TRILHO MOTORIZADO", "DETECTOR RAIL", "STICKY PISTON", "TEIA DE ARANHA", "DEAD SHRUB", "DEAD BUSH", "PISTAO", "CABECA DE PISTAO", "LA BRANCA", "DANDELION"};
    
    Item *items[MAX_CHEST_SLOTS];
    for(int i = 0; i < MAX_CHEST_SLOTS; i++)
    {
        items[i] = createItem(itemsNames[i], 0, i+10, -1);
    }
    
    // Mostra menu
    int optMenu;
    do
    {
        printf("---------------------------HASH CHEST---------------------------\n\n");
        printf("OPÇÕES: \n\n");
        printf("[1] INSERIR ITENS NO BAÚ\n");
        printf("[2] REMOVER ITENS DO BAÚ\n");
        printf("[3] BUSCAR ITENS NO BAÚ\n");
        printf("[4] MOSTRAR BAÚ NO MODO HASH TABLE\n");
        printf("[5] MOSTRAR BAÚ NO MODO MINECRAFT\n");
        printf("[-1] PARA A EXECUÇÃO DO PROGRAMA\n\n");
        
        printf("SUA ESCOLHA: ");
        scanf("%d", &optMenu);
        printf("\e[1;1H\e[2J");
        
        switch(optMenu)
        {
            case 1:
            {
                showInsertItemMenu(chest, items);
                break;
            }
            case 2:
            {
                showRemoveItemMenu(chest, itemsNames);
                break;
            }
            case 3:
            {
                showSearchItemMenu(chest, itemsNames);
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
