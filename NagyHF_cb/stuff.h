#ifndef __STUFF_H__
#define __STUFF_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#include "debugmalloc.h"

/** Rekord ID counter
 *
 * Reprsents a global counter for Rekord ID-s.
 */
extern int IDcntr;

/** Global variable for days in the month.
 */
extern const int hon[12];

/** Global variable for leap year days of the month.
 */
extern const int szhon[12];

/** Date struct
 *
 * Stores date consructed data.
 */
typedef struct Datum {
    int perc;     /**< Minute of the struct */
    int ora;      /**< Hour of thdate */
    int nap;      /**< Day part of the struct */
    int ho;       /**< Month part of the struct. */
    int ev;       /**< Year part of the struct. */
} Datum;

/** Entry data storage
 *
 * A global struct, where all data about an entry is stored.
 */
typedef struct Rekord {
    int ID;         /**< Unique ID for an entry. For simple access. */
    char *esemeny;  /**< Aztual entry text. */
    char *megj;     /**< Entry comments */
    char *hely;     /**< Entry place */
    Datum *date;    /**< Date when entry is actual. */
    struct Rekord *kov; /**< Pointer to next entry in the list */
} Rekord;

/** Free general linked list
 *
 * This function frees up a linked list from it's given root.
 * @param root pointer to linked list root.
 */
void freeLinkedList(Rekord *root);

/** Menu items
 *
 * Represents menu choices
 */
typedef enum menuItem {
    UJ,
    MODOSIT,
    TORLES,
    LISTA,
    KERES,
    MENT,
    KILEP
} menuItem;

/** Dynamic string read stdin
 *
 * Reads a string from stdin, and allocates it dynamically.
 * @return dynamically allocated string.
 */
char *beolvas();


/** Checks leap year
 *
 * @return if the year is a leap year
 */
bool szokoev(int ev);

/** Save function
 *
 * Saves data of linked list in textual form.
 * @param root root of the linked list to be saved.
 * @param fileName file name.
 * @param del delimiter.
 * @return true if save successful.
 */
bool mentes(Rekord *root, char *fileName, char del);


/** Deletes the last found match.
 *
 * Deletes the last found ID match in the list.
 * Since the IDs are unique, it's also the only entry in the list.
 * @see findID
 * @param root linked list root.
 * @param ID_rem ID to remove.
 * @return new pointer to the root.
 */
Rekord *torles(Rekord *root, int ID_rem);

/** Time global value
 *
 * Counts a comparable global value for a given Datum.
 * @param d datum struct.
 * @return global minute count.
 */
int getTimeVal(Datum d);

/** Compare dates
 *
 * Compare two dates and returns compared value.
 * @param d1 date 1.
 * @param d2 date 2.
 * @return -1 if d1 < d2, 1 if d1 > d2, 0 if equal;
 */
int datumOsszehas(Datum d1, Datum d2);

/** new ID
 *
 * Get a new unique ID.
 * @return new ID.
 */
int newID();

/** Day of the week.
 *
 * Counts the day of the week by getting a Julian number.
 * The reminder by 7 of a julian is the day of the week starting Sunday.
 * @param d Datum struct.
 * @return day of the week.
 */
int getDayOfTheWeek(Datum *d);

/** Read all rekords from file
 *
 * Reads every data from a file.
 * Assuming the records are stored line by line.
 * @param fileName name of save file.
 * @return linked list.
 */
Rekord *readFromFile(char *fileName);

#endif // __STUFF_H__

