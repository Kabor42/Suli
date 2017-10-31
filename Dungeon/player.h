/* 
 * File:   player.h
 * Author: kabor
 *
 * Created on October 26, 2017, 6:12 PM
 */

#ifndef PLAYER_H
#define PLAYER_H
#include <stdio.h>
#include "inventory.h"

typedef enum SEX {
    MALE,
            FEMALE,
} SEX;

typedef enum DIRECTION {
    NORTH,
            SOUTH,
            EAST,
            WEST,
} DIRECTION;

typedef struct PLAYER {
    char *name;
    int age;
    SEX sex;
    INVENTORY *inv;
    double score;
    int strength;
    int dexterity;
    int agility;
    int luck;
    int health;
    int magic;
    int stamina;
    int x, y;
    DIRECTION dir;
} PLAYER;

/*
 * Creates new player
 */
PLAYER *new_player( char *name, SEX sex, int age);

char *print_sex(SEX sex);

/*
 * Frees up memory
 */
void destroy_player(PLAYER *player);

#endif /* PLAYER_H */

