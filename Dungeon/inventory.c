#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "inventory.h"

char *print_mod(MOD modifier){
    char *str;
    switch(modifier){
        case RUSTY:
            str = (char*) malloc(sizeof(char) * (strlen("Rusty")+1));
            strcpy(str, "Rusty");
            break;
        case BASE:
            str = (char*) malloc(sizeof(char) * (strlen("Base")+1));
            strcpy(str, "Base");
            break;
        case MILITARY:
            str = (char*) malloc(sizeof(char) * (strlen("Military")+1));
            strcpy(str, "Military");
            break;
        case EPIC:
            str = (char*) malloc(sizeof(char) * (strlen("Epic")+1));
            strcpy(str, "Epic");
            break;
        case LEGENDARY:
            str = (char*) malloc(sizeof(char) * (strlen("Legendary")+1));
            strcpy(str, "Legendary");
            break;
        default:
            str = (char*) malloc(sizeof(char) * (strlen("Unknown")+1));
            strcpy(str, "Unknown");
    }
    return str;
}

double parse_modifier(MOD modif){
    double m = 1;
    switch(modif){
        case RUSTY:
            m = 0.5;
            break;
        case BASE:
            m = 1;
            break;
        case MILITARY:
            m = 2;
            break;
        case EPIC:
            m = 4;
            break;
        case LEGENDARY:
            m = 8;
            break;
        default:
            m = 1;
    }
    return m;
}

INVENTORY *new_inventory(){
    INVENTORY *new;
    new = (INVENTORY*) malloc(sizeof(INVENTORY));
    new->armor = NULL;
    new->bagitems = NULL;
    new->weapon = NULL;
    new->items = 0;
    

    
    return new;
}

void inv_add_weapon( INVENTORY *inv, char *name, MOD modifier, double dmg, double price, int size, double weight){
    WEAPON *new;
    new = (WEAPON*) malloc(sizeof(WEAPON));
    new->modifier = modifier;
    new->dmg = dmg * parse_modifier(modifier);
    new->name = name;
    new->price = price;
    new->size = size;
    new->wearing = false;
    new->weight = weight;
    
    inv->weapon = new;
}

void inv_add_armor(INVENTORY *inv, char *name,MOD modifier, double def, double price, int size, double weight){
    ARMOR *new;
    new = (ARMOR*) malloc(sizeof(ARMOR));
    new->modifier = modifier;
    new->def = def * parse_modifier(modifier);
    new->name = name;
    new->price = price;
    new->size = size;
    new->weight = weight;
    new->wearing = false;
    
    inv->armor = new;
}

void inv_add_item(INVENTORY *inv, char *name, double weight, int size, int price, int q){
    
    inv->items += 1;
    BAG_ITEM **next = (BAG_ITEM**) realloc(inv->bagitems ,inv->items * sizeof(BAG_ITEM*));
    inv->bagitems = next;
        
    BAG_ITEM *new;
    new = (BAG_ITEM*) malloc(sizeof(BAG_ITEM));
    new->name = name;
    new->price = price;
    new->size = size;
    new->weight = weight;
    new->quantity = q;
    
    inv->bagitems[inv->items-1] = new;
}

void destroy_inventory(INVENTORY *inv){
    for(int i=0; i<inv->items;i++) {
        free(inv->bagitems[i]);
    }
    free(inv->bagitems);
    free(inv->armor);
    free(inv->weapon);
    free(inv);
}