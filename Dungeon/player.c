#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"
#include "inventory.h"

PLAYER *new_player( char *name, SEX sex, int age){
    PLAYER *new;
    new = (PLAYER*) malloc(sizeof(PLAYER));
    
    new->name = name;
    new->sex = sex;
    new->age = age;
    new->score = 0.0;
    
    new->strength = 4;
    new->dexterity = 4;
    new->agility = 8;
    new->luck = 2;
    
    new->health = 100;
    new->magic = 100;
    new->stamina = 100;
    
    new->x = 4;
    new->y = 4;
    new->dir = EAST;
    
    INVENTORY *inv;
    inv = new_inventory();
    inv_add_weapon( inv, "knife", RUSTY, 1, 10, 1, 0.5); // name, modifier, dmg, price, size, weight
    inv_add_armor( inv, "shield", RUSTY, 2, 5, 1, 1);
    inv_add_item( inv, "health potion", 0.1, 1, 10, 21); // name weight, size, price
    new->inv = inv;
    
    return new;
}

char *print_sex(SEX sex) {
    char *str;
    switch(sex){
        case MALE:
            str = (char*) malloc(sizeof(char) * (strlen("MALE")+1));
            strcpy(str, "MALE");
            break;
        case FEMALE:
            str = (char*) malloc(sizeof(char) * (strlen("FEMALE")+1));
            strcpy(str, "FEMALE");
            break;
        default:
            str = (char*) malloc(sizeof(char) * (strlen("UNKNOWN")+1));
            strcpy(str, "UNKNOWN");
            break;
    }
    return str;
}

void destroy_player(PLAYER *player){
    destroy_inventory(player->inv);
    free(player->name);
    free(player);
}