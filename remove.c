#include "chestLib.h"
#include <string.h>
#include <stdlib.h>

void removeNode(Chest * chest, char itemName[NAME_SIZE], int pos, int deleteNum) {
    if (deleteNum >= chest->slots[pos]->firstNode->item.quantity){
        if(chest){
            Node *ant, *remover, *initial;
            ant = remover = inicio = chest;
            if((chest).slots[pos]->firstNode->item.name == itemName){
                remover = chest->slots[pos]->firstNode->next;
                ant->next = NULL;
                free(ant);
            }
            else{
                while (remover->item.name != itemName && remover->next !=NULL){
                    ant = remover;
                    remover = remover->next;
                }
                if (remover->item.name == itemName){
                    if (remover->next !=NULL){
                        ant->next = remover->next;
                        remover->next = NULL;
                        free(remover);
                    } else if (remover->next == NULL) {
                        ant->next = NULL;
                        free(remover);
                    }
                } else {
                    printf("Elemento Inexistente!!");
                }
            }
        }

    }else {
        int equal = strcmp(chest->slots[pos]->firstNode->item.name, itemName);
        if(!equal) chest->slots[pos]->firstNode->item.quantity -= deleteNum;
    }
}
