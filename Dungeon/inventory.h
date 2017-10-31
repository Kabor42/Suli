/* 
 * File:   inventory.h
 * Author: kabor
 *
 * Created on October 26, 2017, 6:13 PM
 */

#ifndef INVENTORY_H
#define INVENTORY_H
#include <stdbool.h>

typedef enum MOD{
    RUSTY,
            BASE,
            MILITARY,
            RARE,
            EPIC,
            LEGENDARY,
} MOD;

typedef struct BAG_ITEM{
    char *name;
    double weight;
    int size;
    double price;
    int quantity;
} BAG_ITEM;

typedef struct ARMOR{
    char *name;
    double def;
    int size;
    double weight;
    MOD modifier;
    bool wearing;
    double price;
} ARMOR;
typedef struct WEAPON{
    char *name;
    double dmg;
    int size;
    double weight;
    MOD modifier;
bool wearing;    
double price;
} WEAPON;
typedef struct INVENTORY{
    int items;
    BAG_ITEM **bagitems;
    WEAPON *weapon;
    ARMOR *armor;
} INVENTORY;

char *print_mod(MOD modifier);

/*
 * Parse modifier
 * 
 * This function is parsing real values to modify
 * weapons and armors damage and defense
 * Also modifies price
 */
double parse_modifier(MOD modif);

/*
 * New inventory
 * 
 * This function creates an empty inventory.
 * Empty means NULL is all of its contains.
 */
INVENTORY *new_inventory();

/*
 * Adds new weapon to the given inventory pointer,
 * to its weapon slot.
 * @params
 *  INVENTORY *inv, inventory pointer
 *  cahr *name, item name
 *  MOD modifier, modifier value
 *  double dmg, base damage
 *  double price, base price
 *  int size, size in bag if unequipped
 *  weight --> weight in inventory if unequipped
 */
void inv_add_weapon( INVENTORY *inv, char *name, MOD modifier, double dmg, double price, int size, double weight);

/*
 * Adds armor to the given inventory
 */
void inv_add_armor(INVENTORY *inv, char *name,MOD modifier, double def, double price, int size, double weight);

/*
 * Adds misc item to inventory
 */
void inv_add_item(INVENTORY *inv, char *name, double weight, int size, int price, int q);

/*
 * Cleans up inventory from memory
 */
void destroy_inventory(INVENTORY *inv);

#endif /* INVENTORY_H */

